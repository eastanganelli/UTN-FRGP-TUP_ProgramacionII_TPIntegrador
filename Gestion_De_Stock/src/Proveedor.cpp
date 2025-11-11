#include "../include/Proveedor.h"

Proveedor::Proveedor(string _cuit, string _nombreRazon, string _rubro, string _direccion, string _correo, string _telefono, string _celular, unsigned int _codigoRazonSocial, bool _alta)
    : DatosPersonales(_alta, _direccion, _correo, _telefono, _celular, _codigoRazonSocial) {
    strcpy(this->cuit, _cuit.c_str());
    strcpy(this->nombreRazon, _nombreRazon.c_str());
    strcpy(this->rubro, _rubro.c_str());
}

Proveedor::~Proveedor() {

}

bool Proveedor::getAlta() {
    return this->alta;
}

string Proveedor::getCuit() {
    return string(this->cuit, 11);
}

string Proveedor::getRubro() {
    return string(this->rubro);
}

string Proveedor::getNombreRazon() {
    return string(this->nombreRazon);
}

void Proveedor::setRubro(string rubro) {
    strcpy(this->rubro, rubro.c_str());
}

void Proveedor::setNombreRazon(string nombre) {
    strcpy(this->nombreRazon, nombre.c_str());
}
