#include "datos_personales.h"

DatosPersonales::DatosPersonales(bool _alta, string _direccion, string _correo, string _telefono, string _celular) {
    this->alta = _alta;
    strcpy(this->direccion, _direccion.c_str());
    strcpy(this->correo, _correo.c_str());
    strcpy(this->telefono, _telefono.c_str());
    strcpy(this->celular, _celular.c_str());
    this->codigoRazonSocial = 0;
}

DatosPersonales::~DatosPersonales() {
    this->correo[0] = '\0';
    this->celular[0] = '\0';
    this->telefono[0] = '\0';
    this->direccion[0] = '\0';
}

bool DatosPersonales::IsEqual(const DatosPersonales& otro) {
    return Validation::IsEqual(this->correo, otro.correo) && Validation::IsEqual(this->direccion, otro.direccion)
        && Validation::IsEqual(this->telefono, otro.telefono) && Validation::IsEqual(this->celular, otro.celular)
        && this->alta == otro.alta;
}

bool DatosPersonales::IsEmpty() {
    return Validation::IsEmpty(this->correo) && Validation::IsEmpty(this->direccion)
        && Validation::IsEmpty(this->telefono) && Validation::IsEmpty(this->celular);
}

bool DatosPersonales::getAlta() { return this->alta; }

string DatosPersonales::Estado() { return (this->alta ? "Alta" : "Baja"); }

string DatosPersonales::getCorreo() { return string(this->correo); }

string DatosPersonales::getDireccion() { return string(this->direccion); }

string DatosPersonales::getTelefono() { return string(this->telefono); }

string DatosPersonales::getCelular() { return string(this->celular); }

unsigned int DatosPersonales::GetCorreoSize() { return CORREO_SIZE; }

unsigned int DatosPersonales::GetDireccionSize() { return DIRECCION_SIZE; }

unsigned int DatosPersonales::GetTelefonoSize() { return TELEFONO_SIZE; }

unsigned int DatosPersonales::GetCelularSize() { return CELULAR_SIZE; }

unsigned int DatosPersonales::GetEstadoSize() { return ESTADO_SIZE; }

void DatosPersonales::setAlta(bool a) { this->alta = a; }

void DatosPersonales::setCorreo(const string& c) { strcpy(this->correo, c.c_str()); }

void DatosPersonales::setDireccion(const string& d) { strcpy(this->direccion, d.c_str()); }

void DatosPersonales::setTelefono(const string& t) { strcpy(this->telefono, t.c_str()); }

void DatosPersonales::setCelular(const string& c) { strcpy(this->celular, c.c_str()); }