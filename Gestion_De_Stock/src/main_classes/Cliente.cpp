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

unsigned int Cliente::GetDniSize() {
    return DNI_SIZE;
}

unsigned int Cliente::GetNombreSize() {
    return NOMBRE_SIZE;
}

unsigned int Cliente::GetApellidoSize() {
    return APELLIDO_SIZE;
}

unsigned int Cliente::GetCuilCuitSize() {
    return CUIL_CUIT_SIZE;
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

bool Cliente::operator==(Cliente& cliente) {
    return strcmp(this->DNI, cliente.DNI) && strcmp(this->cuilCuit, cliente.cuilCuit)
        && strcmp(this->apellido, cliente.apellido) && strcmp(this->nombre, cliente.nombre)
        && strcmp(this->correo, cliente.correo) && strcmp(this->direccion, cliente.direccion)
        && strcmp(this->celular, cliente.celular) && strcmp(this->telefono, cliente.telefono)
        && this->codigoRazonSocial == cliente.codigoRazonSocial && this->alta == cliente.alta;
}

bool Cliente::IsEmpty() {
    return Validation::IsEmpty(this->DNI) && Validation::IsEmpty(this->nombre)
        && Validation::IsEmpty(this->apellido) && Validation::IsEmpty(this->cuilCuit)
        && DatosPersonales::IsEmpty();
}

void Cliente::Print() {
     printf("%-*s%-*s%-*s%-*s%-*s%-*s%-*s%-*s%-*s\n",
               Cliente::GetDniSize(), this->getDNI().c_str(),
               Cliente::GetApellidoSize(), this->getApellido().c_str(),
               Cliente::GetNombreSize(), this->getNombre().c_str(),
               Cliente::GetCuilCuitSize(), this->getCuilCuit().c_str(),
               DatosPersonales::GetCorreoSize(), this->getCorreo().c_str(),
               DatosPersonales::GetTelefonoSize(), this->getTelefono().c_str(),
               DatosPersonales::GetCelularSize(), this->getCelular().c_str(),
               DatosPersonales::GetDireccionSize(), this->getDireccion().c_str(),
               DatosPersonales::GetEstadoSize(), this->Estado().c_str());
}