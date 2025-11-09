#include "Persona.h"

string Persona::getNombre() {
    return string(this->nombre);
}

string Persona::getApellido() {
    return string(this->apellido);
}

string Persona::getTelefono(int posicion) {
    return string(this->telefono[posicion]);
}

void Persona::setNombre(const string& n) {
    strcpy(this->nombre, n.c_str());
}

void Persona::setApellido(const string& a) {
    strcpy(this->apellido, a.c_str());
}

void Persona::setTelefono(const string& t, int posicion) {
    strcpy(this->telefono[posicion], t.c_str());
}
