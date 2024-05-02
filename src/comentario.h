// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Joel Oscar Martín Gutiérrez
// Correo: alu0101473840@ull.es
// Fecha: 25/10/2022
// Archivo: comentario.h
// Contiene la clase Comentario encargada de crear objetos tipo comentario y de proporcionar métodos para los mismos.

#include <iostream>

#ifndef COMENTARIO_H
#define COMENTARIO_H

// Clase Comentario, encargada de crear y manejar los objetos tipo comentario
class Comentario {  
 public:
  // Constructor
  Comentario() : linea_{}, multilinea_{} {}

  // Métodos encargados de modificar u obtener información de los objetos tipo comentario
  void InsertaComentarioMultilinea(const std::string& linea_extraida_archivo, const int linea);
  void InsertaComentarioDeUnaLinea(const std::string& linea_extraida_archivo, const int linea);
  void LimpiaComentarioMultilinea();
  void LimpiaComentarioDeUnaLinea();
  void ImprimeComentarioMultilinea(const std::string& nombre_archivo_destino) const;
  void ImprimeComentarioDeUnaLinea(const std::string& nombre_archivo_destino) const;
  bool CompruebaSiHayComentarioMultilinea() const;
  bool CompruebaSiHayComentarioDeUnaLinea() const;
  
  // Sobrecarga de operadores
  friend std::ofstream& operator<<(std::ofstream& salida, const Comentario& comentarios);
 private:
  std::vector<std::pair<std::string, int>> multilinea_;
  std::pair<std::string, int> linea_;
};

#endif