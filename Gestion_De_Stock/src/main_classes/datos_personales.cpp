#include "datos_personales.h"

DatosPersonales::DatosPersonales(bool _alta, string _direccion, string _correo, string _telefono, string _celular, string _codigoRazonSocial) {
    this->alta = _alta;
    this->correo[0] = '\0';
    this->celular[0] = '\0';
    this->telefono[0] = '\0';
    this->direccion[0] = '\0';
    this->codigoRazonSocial[0] = '\0';
    strcpy(this->direccion, _direccion.c_str());
    strcpy(this->correo, _correo.c_str());
    strcpy(this->telefono, _telefono.c_str());
    strcpy(this->celular, _celular.c_str());
    strcpy(this->codigoRazonSocial, _codigoRazonSocial.c_str());
}

DatosPersonales::~DatosPersonales() {
    this->correo[0] = '\0';
    this->celular[0] = '\0';
    this->telefono[0] = '\0';
    this->direccion[0] = '\0';
    this->codigoRazonSocial[0] = '\0';
}

bool DatosPersonales::IsEqual(const DatosPersonales& otro) {
    return Validation::IsEqual(this->correo, otro.correo) && Validation::IsEqual(this->direccion, otro.direccion)
        && Validation::IsEqual(this->telefono, otro.telefono) && Validation::IsEqual(this->celular, otro.celular)
        && Validation::IsEqual(this->codigoRazonSocial, otro.codigoRazonSocial) && this->alta == otro.alta;
}

bool DatosPersonales::IsEmpty() {
    return Validation::IsEmpty(this->correo) && Validation::IsEmpty(this->direccion)
        && Validation::IsEmpty(this->telefono) && Validation::IsEmpty(this->celular)
        && Validation::IsEmpty(this->codigoRazonSocial);
}

bool DatosPersonales::getAlta() { return this->alta; }

string DatosPersonales::Estado() { return (this->alta ? "Alta" : "Baja"); }

string DatosPersonales::getCorreo() { return string(this->correo); }

string DatosPersonales::getDireccion() { return string(this->direccion); }

string DatosPersonales::getTelefono() { return string(this->telefono); }

string DatosPersonales::getCelular() { return string(this->celular); }

string DatosPersonales::getCodigoRazonSocial() { return string(this->codigoRazonSocial, CODIGORAZONSOCIAL_SIZE); }

unsigned int DatosPersonales::GetCorreoSize() { return CORREO_SIZE; }

unsigned int DatosPersonales::GetDireccionSize() { return DIRECCION_SIZE; }

unsigned int DatosPersonales::GetTelefonoSize() { return TELEFONO_SIZE; }

unsigned int DatosPersonales::GetCelularSize() { return CELULAR_SIZE; }

unsigned int DatosPersonales::GetEstadoSize() { return ESTADO_SIZE; }

unsigned int DatosPersonales::GetCodigoRazonSocialSize() { return CODIGORAZONSOCIAL_SIZE; }

unsigned int DatosPersonales::ColCorreoSize() { return COL_CORREO; }

unsigned int DatosPersonales::ColDireccionSize() { return COL_DIRECCION; }

unsigned int DatosPersonales::ColTelefonoSize() { return COL_TELEFONO; }

unsigned int DatosPersonales::ColCelularSize() { return COL_CELULAR; }

unsigned int DatosPersonales::ColEstadoSize() { return COL_ESTADO; }

unsigned int DatosPersonales::ColCodigoRazonSocialSize() { return COL_CODIGO_RAZON_SOCIAL; }

void DatosPersonales::setAlta(bool a) { this->alta = a; }

void DatosPersonales::setCorreo(const string& c) { strcpy(this->correo, c.c_str()); }

void DatosPersonales::setDireccion(const string& d) { strcpy(this->direccion, d.c_str()); }

void DatosPersonales::setTelefono(const string& t) { strcpy(this->telefono, t.c_str()); }

void DatosPersonales::setCelular(const string& c) { strcpy(this->celular, c.c_str()); }

void DatosPersonales::setCodigoRazonSocial(const string& codigo) { strcpy(this->codigoRazonSocial, codigo.c_str()); }
