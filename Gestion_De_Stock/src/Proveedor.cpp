#include "Proveedor.h"

Proveedor::Proveedor(string _cuit, string _nombreRazon, unsigned int _rubro, string _direccion, string _correo, string _telefono, string _celular, bool _alta)
    : DatosPersonales(_alta, _direccion, _correo, _telefono, _celular) {
    strcpy(this->cuit, _cuit.c_str());
    strcpy(this->nombreRazon, _nombreRazon.c_str());
    this->rubro = _rubro;
    this->cuit[11] = '\0';
}

Proveedor::~Proveedor() {

}

bool Proveedor::getAlta() {
    return this->alta;
}

string Proveedor::getCuit() {
    return string(this->cuit);
}

string Proveedor::getNombreRazon() {
    return this->nombreRazon;
}

unsigned int Proveedor::getRubro() {
    return this->rubro;
}

string Proveedor::getRubroNombre() {
    switch(this->rubro) {
    case 1:
        return "Textil";
    case 2:
        return "Calzado";
    case 3:
        return "Gastronomia";
    case 4:
        return "Automotor";
    case 5:
        return "Libreria";
    case 6:
        return "Indumentaria";
    }
}

void Proveedor::setAlta(bool alta) {
    this->alta = alta;
}

void Proveedor::setRubro(unsigned int rubro) {
    this->rubro = rubro;
}

void Proveedor::setNombreRazon(string nombre) {
    strcpy(this->nombreRazon, nombre.c_str());
}

string Proveedor::toString() {
    string estadoStr = this->alta ? "Activo" : "Inactivo";
    return "CUIT: " + getCuit() + " | Nombre/Razon: " + getNombreRazon() + " | Rubro: " + getRubroNombre() +
           " | Direccion: " + this->direccion + " | Correo: " + this->correo +
           " | Telefono: " + this->telefono + " | Celular: " + this->celular +
           " | Codigo Razon Social: " + to_string(this->codigoRazonSocial) +
           " | Estado: " + estadoStr;
}
