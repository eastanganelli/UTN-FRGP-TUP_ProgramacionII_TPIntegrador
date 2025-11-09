#include "Cliente.h"

Cliente::Cliente(string& _nombre, string& _apellido, string& _DNI, unsigned int _id, string& _cuilCuit, TipoResponsable* _razonSocial, bool _alta)
    : Persona(_nombre, _apellido, _DNI), id(_id) {
    strcpy(this->cuilCuit, _cuilCuit.c_str());
    this->razonSocial = _razonSocial;
    this->alta = _alta;
}

Cliente::Cliente(string& _nombre, string& _apellido, string& _DNI, string& _telefono_I, unsigned int _id, string& _cuilCuit, TipoResponsable* _razonSocial, bool _alta)
    : Persona(_nombre, _apellido, _DNI, _telefono_I), id(_id) {
    strcpy(this->cuilCuit, _cuilCuit.c_str());
    this->razonSocial = _razonSocial;
    this->alta = _alta;
}

Cliente::Cliente(string& _nombre, string& _apellido, string& _DNI, string& _telefono_I, string& _telefono_II, unsigned int _id, string& _cuilCuit, TipoResponsable* _razonSocial, bool _alta)
    : Persona(_nombre, _apellido, _DNI, _telefono_I, _telefono_II), id(_id) {
    strcpy(this->cuilCuit, _cuilCuit.c_str());
    this->razonSocial = _razonSocial;
    this->alta = _alta;
}

Cliente::~Cliente() {
    this->razonSocial = nullptr;
}

int Cliente::getID() {
    return this->id;
}

const string Cliente::getCuilCuit() {
    return this->cuilCuit;
}

TipoResponsable* Cliente::getRazonSocial() {
    return this->razonSocial;
}

void Cliente::setCuilCuit(const string& c) {
    strcpy(this->cuilCuit, c.c_str());
}

void Cliente::setRazonSocial(TipoResponsable* rs) {
    this->razonSocial = rs;
}

/**void Cliente::cargar() {
    std::cout << "ID Cliente: ";
    std::cin >> this->idCliente;
    std::cout << "Nombre: ";
    std::cin >> this->nombre;
    std::cout << "Apellido: ";
    std::cin >> this->apellido;
    std::cout << "Correo: ";
    std::cin >> this->correo;
    std::cout << "CUIL/CUIT: ";
    std::cin >> this->cuilCuit;
    this->alta = true; // Por defecto al cargar
}**/

/**void Cliente::mostrar() {
    std::cout << "ID Cliente: " << this->idCliente << std::endl;
    std::cout << "Nombre: " << this->nombre << " " << this->apellido << std::endl;
    std::cout << "Correo: " << this->correo << std::endl;
    std::cout << "CUIL/CUIT: " << this->cuilCuit << std::endl;
    std::cout << "Estado: " << (this->alta ? "Activo" : "Inactivo") << std::endl;
}**/

/**bool Cliente::escribirDisco(int pos) {
    // Implementación de escritura en archivo binario aquí
    std::cout << "Simulando escritura de Cliente en disco..." << std::endl;
    return true;
}**/

/**bool Cliente::leerDisco(int pos) {
    // Implementación de lectura desde archivo binario aquí
    std::cout << "Simulando lectura de Cliente desde disco..." << std::endl;
    return true;
}**/

std::ostream& operator<<(std::ostream& os, const Cliente& obj) {
    //os << obj.getCuilCuit;
    return os;
}
