#include "Proveedor.h"

Proveedor::Proveedor(unsigned int _id, string _cuit, string _nombreRazon, string _rubro, string _direccion, string _correo, string _telefono, string _celular, unsigned int _codigoRazonSocial, bool _alta)
    : DatosPersonales(_alta, _direccion, _correo, _telefono, _celular, _codigoRazonSocial), id(_id) {
    strcpy(this->cuit, _cuit.c_str());
    strcpy(this->nombreRazon, _nombreRazon.c_str());
    strcpy(this->rubro, _rubro.c_str());
}

Proveedor::~Proveedor() {

}

int Proveedor::getID() {
    return this->id;
}

bool Proveedor::getAlta() {
    return this->alta;
}

string Proveedor::getCuit() {
    return string(this->cuit);
}

string Proveedor::getRubro() {
    return string(this->rubro);
}

string Proveedor::getNombreRazon() {
    return string(this->nombreRazon);
}

void Proveedor::setCuit(string& cuit) {
    strcpy(this->cuit, cuit.c_str());
}

void Proveedor::setRubro(string& rubro) {
    strcpy(this->rubro, rubro.c_str());
}

void Proveedor::setNombreRazon(string& nombre) {
    strcpy(this->nombreRazon, nombre.c_str());
}
