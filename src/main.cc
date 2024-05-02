// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Joel Oscar Martín Gutiérrez
// Correo: alu0101473840@ull.es
// Fecha: 25/10/2022
// Archivo: main.cc
// Contiene la implementacion de la clase Main donde se implementan los métodos proporcionados por la misma.

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cassert>

#include "main.h"

// Método que establece que main existe
void Main::EstableceQueMainExiste() {
  pertenece_ = true;
}

// Sobrecarga del operador de salida
std::ofstream& operator<<(std::ofstream& salida, const Main& main) {
  salida << "MAIN:" << std::endl;
  if (main.pertenece_ == true) {
    salida << "true" << std::endl;   
  } else {
    salida << "false" << std::endl;
  }
  return salida;
}