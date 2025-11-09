#include "DatosPersonales.h"

DatosPersonales::DatosPersonales(string& _nombre, string& _apellido, string& _DNI) {
    strcpy(this->nombre, _nombre.c_str());
    strcpy(this->apellido, _apellido.c_str());
    strcpy(this->DNI, _DNI.c_str());
    this->telefono[0][0] = { '\0' };
    this->telefono[1][0] = { '\0' };
}

DatosPersonales::DatosPersonales(string& _nombre, string& _apellido, string& _DNI, string& _telefono_I) {
    strcpy(this->nombre, _nombre.c_str());
    strcpy(this->apellido, _apellido.c_str());
    strcpy(this->DNI, _DNI.c_str());
    strcpy(this->telefono[0], _telefono_I.c_str());
    this->telefono[1][0] = { '\0' };
}

DatosPersonales::DatosPersonales(string& _nombre, string& _apellido, string& _DNI, string& _telefono_I, string& _telefono_II) {
    strcpy(this->nombre, _nombre.c_str());
    strcpy(this->apellido, _apellido.c_str());
    strcpy(this->DNI, _DNI.c_str());
    strcpy(this->telefono[0], _telefono_I.c_str());
    strcpy(this->telefono[1], _telefono_II.c_str());
}

DatosPersonales::~DatosPersonales() {
}

bool DatosPersonales::getAlta() {
    return this->alta;
}

string DatosPersonales::getCorreo() {
    return string(this->correo);
}

string DatosPersonales::getTelefono(int posicion) {
    return string(this->telefono[posicion]);
}

void DatosPersonales::setAlta(bool a) {
    this->alta = a;
}

void DatosPersonales::setCorreo(const string& c) {
    strcpy(this->correo, c.c_str());
}

void DatosPersonales::setTelefono(const string& t, int posicion) {
    strcpy(this->telefono[posicion], t.c_str());
}
