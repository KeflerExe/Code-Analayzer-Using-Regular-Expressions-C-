// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Joel Oscar Martín Gutiérrez
// Correo: alu0101473840@ull.es
// Fecha: 25/10/2022
// Archivo: bucle.h
// Contiene la clase Bucle encargada de crear objetos tipo bucle y de proporcionar métodos para los mismos.

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cassert>

#ifndef BUCLE_H
#define BUCLE_H

class Bucle {  
 public:
  // Constructor
  Bucle() : bucles_{} {}

  // Método para insertar los bucles en el vector bucles_
  void InsertaLosBucles(const std::string& linea_extraida_archivo, const int contador_lineas);

  // Sobrecarga de operadores
  friend std::ofstream& operator<<(std::ofstream& salida, const Bucle& bucles);
 private:
  std::vector<std::pair<bool, int>> bucles_;
};

#endif