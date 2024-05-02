// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Joel Oscar Martín Gutiérrez
// Correo: alu0101473840@ull.es
// Fecha: 25/10/2022
// Archivo: comentario.cc
// Contiene la implementacion de la clase Comentario donde se implementan los métodos proporcionados por la misma.

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cassert>

#include "comentario.h"

// Método encargado de comprobar si existe un comentario multilinea o no
bool Comentario::CompruebaSiHayComentarioMultilinea() const {
  if (multilinea_.empty() == true) {
    return false;
  } else {
    return true;
  }
}

// Método encargado de comprobar si existe un comentario de una linea o no
bool Comentario::CompruebaSiHayComentarioDeUnaLinea() const {
  if (linea_.first.empty() == true) {
    return false;
  } else {
    return true;
  }
}

// Método encargado de insertar un comentario multilinea en el vector multilinea
void Comentario::InsertaComentarioMultilinea(const std::string& linea_extraida_archivo, const int linea) {
  multilinea_.push_back(std::make_pair(linea_extraida_archivo, linea));
}

// Método encargado de insertar un comentario de una linea en el vector linea
void Comentario::InsertaComentarioDeUnaLinea(const std::string& linea_extraida_archivo, const int linea) {
  linea_.first = linea_extraida_archivo;
  linea_.second = linea;
}

// Método encargado de limpiar el vector multilinea_
void Comentario::LimpiaComentarioMultilinea() {
  multilinea_.clear();
}

// Método encargado de limpiar el vector linea_
void Comentario::LimpiaComentarioDeUnaLinea() {
  linea_.first.clear();
}

void Comentario::ImprimeComentarioMultilinea(const std::string& nombre_archivo_destino) const {
  std::ofstream archivo_destino;
  archivo_destino.open(nombre_archivo_destino, std::ios_base::app);
  archivo_destino << "[Líneas " << multilinea_[0].second << "-" << multilinea_[multilinea_.size() - 1].second << "]" << std::endl;
  for (int iterador = 0; iterador < multilinea_.size(); ++iterador) {
    archivo_destino << multilinea_[iterador].first << std::endl;
  }
  archivo_destino.close();
}

void Comentario::ImprimeComentarioDeUnaLinea(const std::string& nombre_archivo_destino) const {
  std::ofstream archivo_destino;
  archivo_destino.open(nombre_archivo_destino, std::ios_base::app);
  archivo_destino << "[Línea " << linea_.second << "] " << linea_.first << std::endl;
  archivo_destino.close();
}

// Sobrecarga del operador de salida para imprimir los comentarios
std::ofstream& operator<<(std::ofstream& salida, const Comentario& comentarios) {
  if (comentarios.CompruebaSiHayComentarioDeUnaLinea() == true) {
    salida << "[Línea " << comentarios.linea_.second << "] " << comentarios.linea_.first << std::endl;
  }
  if (comentarios.CompruebaSiHayComentarioMultilinea() == true) {
      salida << "[Líneas " << comentarios.multilinea_[0].second << "-" << comentarios.multilinea_[comentarios.multilinea_.size() - 1].second << "]" << std::endl;
    for (int iterador = 0; iterador < comentarios.multilinea_.size(); ++iterador) {
      salida << comentarios.multilinea_[iterador].first << std::endl;
    }    
  }
  return salida;
}