#include "Cliente.h"

Cliente::Cliente(string _nombre, string _apellido, string _DNI, string _cuilCuit, string direccion, string correo, string _telefono, string _celular, bool _alta)
    : DatosPersonales(_alta, direccion, correo, _telefono, _celular) {
    strcpy(this->nombre, _nombre.c_str());
    strcpy(this->apellido, _apellido.c_str());
    strcpy(this->DNI, _DNI.c_str());
    strcpy(this->cuilCuit, _cuilCuit.c_str());
    this->DNI[8] = '\0';
    this->cuilCuit[11] = '\0';
}

Cliente::~Cliente() {

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

string Cliente::getCuilCuit() {
    return string(this->cuilCuit);
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

void Cliente::setCuilCuit(const string& c) {
    strcpy(this->cuilCuit, c.c_str());
}

string Cliente::toString() {
    string resultado = "Cliente: " + getNombre() + " " + getApellido() +
                       " | DNI: " + getDNI() +
                       " | CUIL/CUIT: " + getCuilCuit() +
                       " | Dir: " + getDireccion() +
                       " | Correo: " + getCorreo() +
                       " | Tel: " + getTelefono() +
                       " | Cel: " + getCelular() +
                       " | Alta: " + (getAlta() ? "Si" : "No");
    return resultado;
}
