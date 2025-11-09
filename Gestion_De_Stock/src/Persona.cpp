#include "Persona.h"

Persona::Persona(string& _nombre, string& _apellido, string& _DNI) {
    strcpy(this->nombre, _nombre.c_str());
    strcpy(this->apellido, _apellido.c_str());
    strcpy(this->DNI, _DNI.c_str());
    this->telefono[0] = '\0';
    this->telefono[1] = '\0';
}

Persona::Persona(string& _nombre, string& _apellido, string& _DNI, string& _telefono_I) {
    strcpy(this->nombre, _nombre.c_str());
    strcpy(this->apellido, _apellido.c_str());
    strcpy(this->DNI, _DNI.c_str());
    strcpy(this->telefono[0], _telefono_I.c_str());
    this->telefono[1] = '\0';
}

Persona::Persona(string& _nombre, string& _apellido, string& _DNI, string& _telefono_I, string& _telefono_II) {
    strcpy(this->nombre, _nombre.c_str());
    strcpy(this->apellido, _apellido.c_str());
    strcpy(this->DNI, _DNI.c_str());
    strcpy(this->telefono[0], _telefono_I.c_str());
    strcpy(this->telefono[1], _telefono_II.c_str());
}

Persona::~Persona() {

}

string Persona::getDNI() {
    return string(this->DNI);
}

string Persona::getNombre() {
    return string(this->nombre);
}

string Persona::getApellido() {
    return string(this->apellido);
}

string Persona::getTelefono(int posicion) {
    return string(this->telefono[posicion]);
}

void Persona::setDNI(const string& dni) {
    strcpy(this->DNI, dni.c_str());
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
