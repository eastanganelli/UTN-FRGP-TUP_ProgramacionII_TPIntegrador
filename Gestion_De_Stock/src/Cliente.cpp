#include "Cliente.h"

Cliente::Cliente(unsigned int _id, string _nombre, string _apellido, string _DNI, string _cuilCuit, string direccion, string correo, string _telefono, string _celular, unsigned int _codigoRazonSocial, bool _alta)
    : id(_id), DatosPersonales(_alta, direccion, correo, _telefono, _celular, _codigoRazonSocial) {
    strcpy(this->nombre, _nombre.c_str());
    strcpy(this->apellido, _apellido.c_str());
    strcpy(this->DNI, _DNI.c_str());
    strcpy(this->cuilCuit, _cuilCuit.c_str());
}

int Cliente::getID() {
    return this->id;
}

string Cliente::getDNI() {
    return string(this->DNI);
}

string Cliente::getNombre() {
    return string(this->nombre);
}

string Cliente::getApellido() {
    return string(this->apellido);
}

void Cliente::setDNI(const string& dni) {
    strcpy(this->DNI, dni.c_str());
}

void Cliente::setNombre(const string& n) {
    strcpy(this->nombre, n.c_str());
}

void Cliente::setApellido(const string& a) {
    strcpy(this->apellido, a.c_str());
}

string Cliente::getCuilCuit() {
    return string(this->cuilCuit);
}

void Cliente::setCuilCuit(const string& c) {
    strcpy(this->cuilCuit, c.c_str());
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

std::ostream& operator<<(std::ostream& os, Cliente* obj) {
    //os << obj.getCuilCuit;
    return os;
}
