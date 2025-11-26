#include "Proveedor.h"

Proveedor::Proveedor(string _cuit, string _nombreRazon, unsigned int _rubro, string _direccion, string _correo, string _telefono, string _celular, bool _alta)
    : DatosPersonales(_alta, _direccion, _correo, _telefono, _celular) {
    this->alta = _alta;
    this->codigoRazonSocial = 0;
    this->cuit[0] = '\0';
    this->nombreRazon[0] = '\0';
    strcpy(this->cuit, _cuit.c_str());
    strcpy(this->nombreRazon, _nombreRazon.c_str());
    this->rubro = _rubro;
}

Proveedor::~Proveedor() { }

bool Proveedor::getAlta() { return this->alta; }

string Proveedor::getCuit() { return string(this->cuit); }

string Proveedor::getNombreRazon() { return this->nombreRazon; }

unsigned int Proveedor::getRubro() {  return this->rubro; }

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
    default:
        break;
    }
    return "Indumentaria";
}

unsigned int Proveedor::GetCuitLength() { return Proveedor::CUIT_SIZE; }

unsigned int Proveedor::GetNombreRazonLength() { return Proveedor::NOMBRE_RAZON_SIZE; }

void Proveedor::setAlta(bool alta) { this->alta = alta; }

void Proveedor::setRubro(unsigned int rubro) { this->rubro = rubro; }

void Proveedor::setNombreRazon(string nombre) { strcpy(this->nombreRazon, nombre.c_str()); }

bool Proveedor::operator==(const Proveedor& otro) {
    return Validation::IsEqual(this->cuit, otro.cuit) && Validation::IsEqual(this->nombreRazon, otro.nombreRazon)
        && this->rubro == otro.rubro && this->IsEqual(otro);
}

bool Proveedor::IsEmpty() {
    return Validation::IsEmpty(this->cuit) && Validation::IsEmpty(this->nombreRazon)
        && this->rubro == 0 && this->DatosPersonales::IsEmpty();
}

void Proveedor::Print() {
    cout << "CUIT: " + this->getCuit() +
           " | Nombre/Razon: " + this->getNombreRazon() +
           " | Rubro: " + this->getRubroNombre() +
           " | Direccion: " + this->getDireccion() +
           " | Correo: " + this->getCorreo() +
           " | Telefono: " + this->getTelefono() +
           " | Celular: " + this->getCelular() +
           " | Estado: " + (this->getAlta() ? string("Activo") : string("Inactivo"));
}
