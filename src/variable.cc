// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Joel Oscar Martín Gutiérrez
// Correo: alu0101473840@ull.es
// Fecha: 25/10/2022
// Archivo: variable.cc
// Contiene la implementacion de la clase Variable donde se implementan los métodos proporcionados por la misma.

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cassert>

#include "variable.h"

// Método encargado de insertar en el vector enteros los valores correspondientes
void Variable::InsertarEnteros(const std::string& identificador_variable, const int valor_variable) {
  enteros_.push_back(std::make_pair(identificador_variable, valor_variable));
}

// Método encargado de insertar en el vector decimales los valores correspondientes
void Variable::InsertarDecimales(const std::string& identificador_variable, const double valor_variable) {
  decimales_.push_back(std::make_pair(identificador_variable, valor_variable));
}

// Método encargado de insertar en el vector lineas los valores correspondientes
void Variable::InsertarLineas(const int contador_lineas, const bool diferenciador) {
  lineas_.push_back(std::make_pair(contador_lineas, diferenciador));
}

// Método encargado de extraer los tipos, nombres y valores de las variables extraidas del fichero de origen
void Variable::ExtractorDeDatos(const std::string& linea_extraida_archivo, const int contador_lineas) {
  std::string identificador_variable;
  std::string valor_variable_string;
  char const* signos_asignacion = "{=;";
  int posicion_digitos = linea_extraida_archivo.find_first_of(signos_asignacion);
  if (linea_extraida_archivo[posicion_digitos] == ';') {
    posicion_digitos = linea_extraida_archivo.size() - 1;
  } else {
    posicion_digitos += 1;
  }
  if (linea_extraida_archivo[posicion_digitos] == ' ') {
    posicion_digitos += 1;
  }
  if (linea_extraida_archivo[0] == 'i') {
    for (int iterador = 4; iterador < linea_extraida_archivo.size() - 1; ++iterador) {
      if (linea_extraida_archivo[iterador] != ' ' && linea_extraida_archivo[iterador] != '=' && linea_extraida_archivo[iterador] != '{')  {
        identificador_variable = identificador_variable + linea_extraida_archivo[iterador];
      } else {
        break;
      }
    }
    for (int iterador = posicion_digitos; iterador < linea_extraida_archivo.size() - 1; ++iterador) {
      if (posicion_digitos == std::string::npos) {
        break;
      }
      if (linea_extraida_archivo[iterador] != ' ' && linea_extraida_archivo[iterador] != '}' && linea_extraida_archivo[iterador] != ';' ) {
        valor_variable_string = valor_variable_string + linea_extraida_archivo[iterador];
      } 
    }
    int valor_variable = 0;
    if (valor_variable_string.empty() == false) {
      valor_variable = std::stoi(valor_variable_string);
    }
    InsertarEnteros(identificador_variable, valor_variable);
    InsertarLineas(contador_lineas, false);
  }
  if (linea_extraida_archivo[0] == 'd') {
    for (int iterador = 7; iterador < linea_extraida_archivo.size() - 1; ++iterador) {
      if (linea_extraida_archivo[iterador] != ' ' && linea_extraida_archivo[iterador] != '=' && linea_extraida_archivo[iterador] != '{')  {
        identificador_variable = identificador_variable + linea_extraida_archivo[iterador];
      } else {
        break;
      }
    }
    for (int iterador = posicion_digitos; iterador < linea_extraida_archivo.size() - 1; ++iterador) {
      if (posicion_digitos == std::string::npos) {
        break;
      }
      if (linea_extraida_archivo[iterador] != ' ' && linea_extraida_archivo[iterador] != '}' && linea_extraida_archivo[iterador] != ';' ) {
        valor_variable_string = valor_variable_string + linea_extraida_archivo[iterador];
      } 
    }
    double valor_variable = 0;
    if (valor_variable_string.empty() == false) {
      valor_variable = std::atof(valor_variable_string.c_str());
    }
    InsertarDecimales(identificador_variable, valor_variable);
    InsertarLineas(contador_lineas, true);
  }
}

// Sobrecarga del operador de salida para imprimir las variables 
std::ofstream& operator<<(std::ofstream& salida, const Variable& variable) { 
  if (variable.enteros_.size() != 0) {
    salida << "VARIABLES INT ENCONTRADAS:" << std::endl;
    int posicion_vector_enteros{0};
    for (int iterador = 0; iterador < variable.lineas_.size(); ++iterador) {
      if (variable.lineas_[iterador].second == false) {
        if (variable.enteros_[posicion_vector_enteros].second != 0) {
          salida << "[Línea " << variable.lineas_[iterador].first << "]" << " INT: " << variable.enteros_[posicion_vector_enteros].first << " = " << variable.enteros_[posicion_vector_enteros].second << std::endl;
        } else {
          salida << "[Línea " << variable.lineas_[iterador].first << "]" << " INT: " << variable.enteros_[posicion_vector_enteros].first << std::endl;       
        }  
        posicion_vector_enteros += 1;
      }
    }    
  }
  if (variable.decimales_.size() != 0) {
    salida << std::endl;
    salida << "VARIABLES DOUBLE ENCONTRADAS:" << std::endl;
    int posicion_vector_decimales{0};
    for (int iterador = 0; iterador < variable.lineas_.size(); ++iterador) {
      if (variable.lineas_[iterador].second == true) {
        if (variable.decimales_[posicion_vector_decimales].second != 0) {
          salida << "[Línea " << variable.lineas_[iterador].first << "]" << " DOUBLE: " << variable.decimales_[posicion_vector_decimales].first << " = " << variable.decimales_[posicion_vector_decimales].second << std::endl;
        } else {
          salida << "[Línea " << variable.lineas_[iterador].first << "]" << " DOUBLE: " << variable.decimales_[posicion_vector_decimales].first << std::endl;
        }
        posicion_vector_decimales += 1;
      }
    }
  }
  return salida;
}