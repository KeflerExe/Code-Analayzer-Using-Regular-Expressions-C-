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
// Contiene la clase Variable encargada de crear objetos tipo variable y de proporcionar métodos para los mismos.

#include "return.h"

void Return::ExtractorDeDatos(const std::string& linea_extraida_archivo, const int contador_lineas) {
  std::string string_auxiliar;
  for (int iterador = 7; iterador < linea_extraida_archivo.size() - 1; ++iterador) {
    string_auxiliar = string_auxiliar + linea_extraida_archivo[iterador];
  }
  IntroduceDatosEnVector(string_auxiliar, contador_lineas);
}

void Return::IntroduceDatosEnVector(const std::string& devolucion_return, const int contador_lineas) {
  returns_.push_back(std::make_pair(contador_lineas, devolucion_return));
}

std::ofstream& operator<<(std::ofstream& salida, const Return& returns) { 
  salida << "RETURNS: " << std::endl;
  for (int iterador = 0; iterador < returns.returns_.size(); ++iterador) {
    salida << "[Línea " << returns.returns_[iterador].first << "] " << returns.returns_[iterador].second << std::endl;
  }
  return salida;
}
