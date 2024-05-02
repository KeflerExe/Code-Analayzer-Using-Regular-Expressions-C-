// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Joel Oscar Martín Gutiérrez
// Correo: alu0101473840@ull.es
// Fecha: 25/10/2022
// Archivo: expresiones_main.cc
// Contiene la función main del proyecto que usa las diferentes clases y llama a otras funciones
// para realizar las operaciones requeridas por el usuario.

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cassert>
#include <regex>

#include "variable.h"
#include "bucle.h"
#include "main.h"
#include "comentario.h"   
#include "return.h"

// Función main: encargada de crear los objetos de las clases y de llamar al resto de funciones y métodos necesarios para el funcionamiento del programa.
int main (int argc, char *argv[]) {
  Usage(argc, argv);
  int contador_lineas{1};
  int linea_inicio_comentario_multilinea{0};
  int linea_final_comentario_multilinea{0};
  int linea_inicio_comentario_linea{0};
  int auxiliar_imprimir_cabecera{0};
  bool comentario_de_descripcion_multilinea = false;
  bool comentario_de_descripcion_linea = false;
  std::string nombre_archivo_origen = argv[1];
  std::string nombre_archivo_destino = argv[2];
  std::string linea_extraida_archivo;
  Variable variables;
  Bucle bucles; 
  Main main;
  Comentario comentarios;
  Return returns;
  std::smatch coincidencias;
  std::regex expresion_variable("^(\\s)*(int|double)(\\s)+[^(]+(\\s)*;");
  std::regex expresion_bucles("^(\\s)*(for|while)(\\s)*(.)*\\)");
  std::regex expresion_main("^(\\s)*int(\\s)+main(\\s)*[(](.)*[)](\\s)*\\{");
  std::regex expresion_inicio_comentario_multilinea("^(\\s)*(\\/(\\*)+)(\\s)*(.)*");
  std::regex expresion_final_comentario_multilinea("(.)*(\\*)+\\/(\\s)*$");
  std::regex expresion_comentario_linea("\\/\\/(.)*");
  std::regex expresion_return("^(\\s)*return(\\s)*(.)*;");
  std::regex expresion_borra_espacios(R"(\s+)");
  std::ifstream archivo_origen;
  std::ofstream archivo_destino;
  archivo_origen.open(nombre_archivo_origen);
  archivo_destino.open(nombre_archivo_destino, std::ios_base::app);
  archivo_destino << "PROGRAMA: " << nombre_archivo_origen << std::endl;
  while (getline(archivo_origen, linea_extraida_archivo)) { 
    if (std::regex_search(linea_extraida_archivo, expresion_inicio_comentario_multilinea) == true) {
      linea_inicio_comentario_multilinea = contador_lineas;
      if (linea_inicio_comentario_multilinea == 1) {
        comentario_de_descripcion_multilinea = true;
      }
      if (comentario_de_descripcion_multilinea == true) {
        archivo_destino << "DESCRIPCION: " << std::endl;
        while (std::regex_search(linea_extraida_archivo, expresion_final_comentario_multilinea) == false) {
          archivo_destino << linea_extraida_archivo << std::endl;
          getline(archivo_origen, linea_extraida_archivo);
          contador_lineas += 1;
        }
        archivo_destino << linea_extraida_archivo << std::endl << std::endl;
      } else {
        while (std::regex_search(linea_extraida_archivo, expresion_final_comentario_multilinea) == false) {
          comentarios.InsertaComentarioMultilinea(linea_extraida_archivo, contador_lineas);
          getline(archivo_origen, linea_extraida_archivo);
          contador_lineas += 1;
        }
        comentarios.InsertaComentarioMultilinea(linea_extraida_archivo, contador_lineas);
      }
      linea_final_comentario_multilinea = contador_lineas;
    }
    if (std::regex_search(linea_extraida_archivo, coincidencias, expresion_comentario_linea) == true) {
      linea_inicio_comentario_linea = contador_lineas;
      if (linea_inicio_comentario_linea == 1) {
        comentario_de_descripcion_linea = true;
      }
      if (comentario_de_descripcion_linea == true) {
        archivo_destino << "DESCRIPCIÓN: " << std::endl;
        archivo_destino << coincidencias[0] << std::endl << std::endl;
      } else {
        comentarios.InsertaComentarioDeUnaLinea(coincidencias[0], contador_lineas);
      }
    }
    linea_extraida_archivo = std::regex_replace(linea_extraida_archivo, expresion_borra_espacios, " ");
    if (linea_extraida_archivo[0] == ' ') {
      linea_extraida_archivo.erase(0, 1);
    }
    if (std::regex_search(linea_extraida_archivo, coincidencias, expresion_return)) {
      returns.ExtractorDeDatos(coincidencias[0], contador_lineas);
    }
    if (std::regex_search(linea_extraida_archivo, coincidencias, expresion_variable) == true) {
      variables.ExtractorDeDatos(coincidencias[0], contador_lineas);
    }
    if (std::regex_search(linea_extraida_archivo, coincidencias, expresion_bucles) == true) {
      bucles.InsertaLosBucles(coincidencias[0], contador_lineas);
    }
    if (std::regex_search(linea_extraida_archivo, expresion_main) == true) {
      main.EstableceQueMainExiste();
    }
    if (comentarios.CompruebaSiHayComentarioDeUnaLinea() == true || comentarios.CompruebaSiHayComentarioMultilinea() == true ||  comentario_de_descripcion_linea == true || comentario_de_descripcion_multilinea == true) {
      auxiliar_imprimir_cabecera += 1;
      if (auxiliar_imprimir_cabecera == 1) {
        archivo_destino << "COMENTARIOS: " << std::endl;
      }
    }
    if (comentario_de_descripcion_multilinea == true) {
      archivo_destino << "[Línea " << linea_inicio_comentario_multilinea << "-" << linea_final_comentario_multilinea << "] DESCRIPCIÓN" << std::endl;
    }
    if (comentario_de_descripcion_linea == true) {
      archivo_destino << "[Línea " << linea_inicio_comentario_linea << "] DESCRIPCIÓN" << std::endl;
    }
    archivo_destino << comentarios;
    comentarios.LimpiaComentarioMultilinea();
    comentarios.LimpiaComentarioDeUnaLinea();
    comentario_de_descripcion_multilinea = false;
    comentario_de_descripcion_linea = false;
    contador_lineas += 1;
  }
  archivo_origen.close();
  archivo_destino << std::endl;
  archivo_destino << variables << std::endl;
  archivo_destino << bucles << std::endl;
  archivo_destino << main << std::endl;
  archivo_destino << returns << std::endl;
  archivo_destino.close();
}