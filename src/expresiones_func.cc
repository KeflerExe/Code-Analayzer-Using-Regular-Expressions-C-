// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Joel Oscar Martín Gutiérrez
// Correo: alu0101473840@ull.es
// Fecha: 25/10/2022
// Archivo: expresiones_func.cc
// Contiene las diferentes funciones que son llamadas desde el main encargadas de realizar ciertas funciones

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cassert>

/*
 * Comprueba que los argumentos introducidos por línea de comandos sean los 
 * correctos, además de proporcionar ayuda en caso de que el usuario no sepa como se han de introducir los argumentos.
 */
void Usage(int argc, char *argv[]) {
  if (argc != 3) {
    std::string parametro_introducido = argv[1];
    if (parametro_introducido == "--help") {
      std::cout << "--Expresiones" << std::endl;
      std::cout << "Modo de uso: ./expresiones_main fichero_entrada1 fichero_salida1" << std::endl;
      std::cout << "fichero_entrada1: Fichero de texto de origen." << std::endl;
      std::cout << "fichero_salida1: Fichero de texto destino donde escribir el resultado del programa." << std::endl;
      exit(EXIT_SUCCESS);
    } else {
      std::cout << "--Expresiones " << std::endl;
      std::cout << "Modo de uso: ./expresiones_main fichero_entrada1 fichero_salida1" << std::endl << "Pruebe ./expresiones_main --help para más información" << std::endl;
      exit(EXIT_FAILURE);
    }
  }   
}