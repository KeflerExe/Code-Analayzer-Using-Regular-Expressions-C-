// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Joel Oscar Martín Gutiérrez
// Correo: alu0101473840@ull.es
// Fecha: 25/10/2022
// Archivo: bucle.cc
// Contiene la implementacion de la clase Bucle donde se implementan los métodos proporcionados por la misma.

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cassert>

#include "bucle.h"

// Método encargado de insertar los bucles en el atributo bucles_ 
void Bucle::InsertaLosBucles(const std::string& linea_extraida_archivo, const int contador_lineas) {
  if (linea_extraida_archivo[0] == 'f') {
    bucles_.push_back(std::make_pair(false, contador_lineas));
  }
  if (linea_extraida_archivo[0] == 'w') {
    bucles_.push_back(std::make_pair(true, contador_lineas));
  }
}

// Sobrecarga del operador de salida para imprimir los bucles 
std::ofstream& operator<<(std::ofstream& salida, const Bucle& bucles) {
  bool comprueba_si_hay_while = false;
  bool comprueba_si_hay_for = false;
  for (int iterador = 0; iterador < bucles.bucles_.size(); ++iterador) {
    if (bucles.bucles_[iterador].first == false) {
      comprueba_si_hay_for = true;
    } else {
      comprueba_si_hay_while = true;
    }
  }
  if (comprueba_si_hay_for == true) {
    salida << "BUCLES FOR ENCONTRADOS:" << std::endl;
    for (int iterador = 0; iterador < bucles.bucles_.size(); ++iterador) {
      if (bucles.bucles_[iterador].first == false) {
        salida << "[Línea " << bucles.bucles_[iterador].second << "]" << " BUCLE: for" << std::endl;
      } else {
        comprueba_si_hay_while = true;
      }
    }
  }
  if (comprueba_si_hay_while == true) {
    salida << std::endl;
    salida << "BUCLES WHILE ENCONTRADOS:" << std::endl;
    for (int iterador = 0; iterador < bucles.bucles_.size(); ++iterador) {
      if (bucles.bucles_[iterador].first == true) {
        salida << "[Línea " << bucles.bucles_[iterador].second << "]" << " BUCLE: while" << std::endl;
      }
    }
  } 
  return salida;
}    