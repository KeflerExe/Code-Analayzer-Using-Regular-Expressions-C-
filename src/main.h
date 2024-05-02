// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Joel Oscar Martín Gutiérrez
// Correo: alu0101473840@ull.es
// Fecha: 25/10/2022
// Archivo: main.h
// Contiene la clase Main encargada de crear objetos tipo main y de proporcionar métodos para los mismos.

#include <iostream>

#ifndef MAIN_H
#define MAIN_H

// Clase Main, encargada de crear y manejar los objetos tipo Main
class Main {  
 public:
  // Constructor
  Main() : pertenece_{false} {}

  // Método para establecer que main exista en caso de ello
  void EstableceQueMainExiste();

  // Sobrecarga de operadores
  friend std::ofstream& operator<<(std::ofstream& salida, const Main& main);
 private:
  bool pertenece_;
};

#endif