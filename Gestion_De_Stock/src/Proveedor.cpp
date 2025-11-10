#include "Proveedor.h"

Proveedor::Proveedor(unsigned int _id, string _cuit, string _nombreRazon, string _telefono, string _celular, unsigned int _codigoRazonSocial, bool _alta)
    : DatosPersonales(_telefono, _celular), alta(_alta), id(_id), codigoRazonSocial(_codigoRazonSocial) {
    strcpy(this->cuit, _cuit.c_str());
    strcpy(this->nombreRazon, _nombreRazon.c_str());
    strcpy(this->rubro, "");
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

unsigned int Proveedor::getCodigoRazonSocial() {
    return this->codigoRazonSocial;
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

void Proveedor::setCodigoRazonSocial(unsigned int rs) {
    this->codigoRazonSocial = rs;
}

