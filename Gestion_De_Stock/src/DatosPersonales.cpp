#include "DatosPersonales.h"

DatosPersonales::DatosPersonales(bool _alta, string _direccion, string _correo, string _telefono_I, string _telefono_II) {
    this->alta = _alta;
    strcpy(this->direccion, _direccion.c_str());
    strcpy(this->correo, _correo.c_str());
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
