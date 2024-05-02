// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Joel Oscar Martín Gutiérrez
// Correo: alu0101473840@ull.es
// Fecha: 25/10/2022
// Archivo: return.h
// Contiene la clase Return encargada de crear objetos tipo return y de proporcionar métodos para los mismos.

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cassert>

#ifndef RETURN_H
#define RETURN_H

// Clase Return, encargada de crear y manejar los objetos tipo return
class Return {  
 public:
  // Constructor 
  Return() : returns_{} {}

  // Métodos para crear o modificar los atributos de la clase variable
  void ExtractorDeDatos(const std::string& linea_extraida_archivo, const int contador_lineas);
  void IntroduceDatosEnVector(const std::string& devolucion_return, const int contador_lineas);

  // Sobrecarga de operadores
  friend std::ofstream& operator<<(std::ofstream& salida, const Return& returns);
 private:
  std::vector<std::pair<int, std::string>> returns_;
};

#endif