#include "Cliente.h"

int Cliente::getIDCliente() { return this->idCliente; }
const char* Cliente::getCorreo() { return this->correo; }
const char* Cliente::getCuilCuit() { return this->cuilCuit; }
bool Cliente::getAlta() { return this->alta; }
int Cliente::getIDTipoResponsable() { return this->idTipoResponsable; }

void Cliente::setIDCliente(int id) { this->idCliente = id; }
void Cliente::setCorreo(const char* c) { strcpy(this->correo, c); }
void Cliente::setCuilCuit(const char* c) { strcpy(this->cuilCuit, c); }
void Cliente::setAlta(bool a) { this->alta = a; }
void Cliente::setIDTipoResponsable(int id) { this->idTipoResponsable = id; }

void Cliente::cargar() {
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
}

void Cliente::mostrar() {
    std::cout << "ID Cliente: " << this->idCliente << std::endl;
    std::cout << "Nombre: " << this->nombre << " " << this->apellido << std::endl;
    std::cout << "Correo: " << this->correo << std::endl;
    std::cout << "CUIL/CUIT: " << this->cuilCuit << std::endl;
    std::cout << "Estado: " << (this->alta ? "Activo" : "Inactivo") << std::endl;
}

bool Cliente::escribirDisco(int pos) {
    // Implementación de escritura en archivo binario aquí
    std::cout << "Simulando escritura de Cliente en disco..." << std::endl;
    return true;
}

bool Cliente::leerDisco(int pos) {
    // Implementación de lectura desde archivo binario aquí
    std::cout << "Simulando lectura de Cliente desde disco..." << std::endl;
    return true;
}

std::ostream& operator<<(std::ostream& os, const Cliente& obj) {
    os << obj.getCuilCuit;
    return os;
}