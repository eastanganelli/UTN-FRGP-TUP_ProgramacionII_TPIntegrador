#include "Persona.h"

const string& Persona::getNombre() { return this->nombre; }
const string& Persona::getApellido() { return this->apellido; }
const string& Persona::getTelefono() { return this->telefono; }
const string& Persona::getCelular() { return this->celular; }


void Persona::setNombre(const char* n) { strcpy(this->nombre, n); }
void Persona::setApellido(const char* a) { strcpy(this->apellido, a); }
void Persona::setTelefono(const char* t) { strcpy(this->telefono, t); }
void Persona::setCelular(const char* c) { strcpy(this->celular, c); }

void Persona::setNombre(const string& n) { this->nombre = n; }
void Persona::setApellido(const string& a) { this->apellido = a; }
void Persona::setTelefono(const string& t) { this->telefono = t; }
void Persona::setCelular(const string& c) { this->celular = c; }