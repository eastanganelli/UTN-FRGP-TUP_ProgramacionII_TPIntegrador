#include "../include/DatosPersonales.h"

DatosPersonales::DatosPersonales(bool _alta, string _direccion, string _correo, string _telefono, string _celular, unsigned int _codigoRazonSocial) {
    this->alta = _alta;
    strcpy(this->direccion, _direccion.c_str());
    strcpy(this->correo, _correo.c_str());
    strcpy(this->telefono, _telefono.c_str());
    strcpy(this->celular, _celular.c_str());
    this->codigoRazonSocial = _codigoRazonSocial;
}

DatosPersonales::~DatosPersonales() {
    this->correo[0] = '\0';
    this->celular[0] = '\0';
    this->telefono[0] = '\0';
    this->direccion[0] = '\0';
}

bool DatosPersonales::getAlta() {
    return this->alta;
}

string DatosPersonales::getCorreo() {
    return string(this->correo);
}

string DatosPersonales::getDireccion() {
    return string(this->direccion);
}

string DatosPersonales::getTelefono() {
    return string(this->telefono);
}

string DatosPersonales::getCelular() {
    return string(this->celular);
}

unsigned int DatosPersonales::getCodigoRazonSocial() {
    return this->codigoRazonSocial;
}

void DatosPersonales::setAlta(bool a) {
    this->alta = a;
}

void DatosPersonales::setCorreo(const string& c) {
    strcpy(this->correo, c.c_str());
}

void DatosPersonales::setDireccion(const string& d) {
    strcpy(this->direccion, d.c_str());
}

void DatosPersonales::setTelefono(const string& t) {
    strcpy(this->telefono, t.c_str());
}

void DatosPersonales::setCelular(const string& c) {
    strcpy(this->celular, c.c_str());
}

void DatosPersonales::setCodigoRazonSocial(unsigned int codigo) {
    this->codigoRazonSocial = codigo;
}
