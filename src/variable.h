// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Joel Oscar Martín Gutiérrez
// Correo: alu0101473840@ull.es
// Fecha: 25/10/2022
// Archivo: variable.h
// Contiene la clase Variable encargada de crear objetos tipo variable y de proporcionar métodos para los mismos.

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cassert>

#ifndef VARIABLE_H
#define VARIABLE_H

// Clase Variable, encargada de crear y manejar los objetos tipo variable
class Variable {  
 public:
  // Constructor 
  Variable() : enteros_{}, decimales_{}, lineas_{} {}

  // Métodos para crear o modificar los atributos de la clase variable
  void ExtractorDeDatos(const std::string& linea_extraida_archivo, const int contador_lineas);
  void InsertarEnteros(const std::string& identificador_variable, const int valor_variable);
  void InsertarDecimales(const std::string& identificador_variable, const double valor_variable);
  void InsertarLineas(const int contador_lineas, const bool diferenciador);

  // Sobrecarga de operadores
  friend std::ofstream& operator<<(std::ofstream& salida, const Variable& variable);
 private:
  std::vector<std::pair<std::string, int>> enteros_;
  std::vector<std::pair<std::string, double>> decimales_;
  std::vector<std::pair<int, bool>> lineas_;
};

void Usage(int argc, char *argv[]);

#endif