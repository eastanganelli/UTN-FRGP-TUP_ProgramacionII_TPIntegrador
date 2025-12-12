#include "Cliente.h"
#include "../controller/modals.h"
#include <algorithm>

Cliente::Cliente(string _nombre, string _apellido, string _DNI, string _cuilCuit, string direccion, string correo, string _telefono, string _celular, bool _alta)
    : DatosPersonales(_alta, direccion, correo, _telefono, _celular) {
    this->DNI[0] = '\0';
    this->nombre[0] = '\0';
    this->apellido[0] = '\0';
    this->cuilCuit[0] = '\0';
    strcpy(this->nombre, _nombre.c_str());
    strcpy(this->apellido, _apellido.c_str());
    strcpy(this->DNI, _DNI.c_str());
    strcpy(this->cuilCuit, _cuilCuit.c_str());
}

Cliente::~Cliente() { }

string Cliente::getDNI() { return string(this->DNI); }

string Cliente::getNombre() { return string(this->nombre); }

string Cliente::getApellido() { return string(this->apellido); }

string Cliente::getCuilCuit() { return string(this->cuilCuit); }

unsigned int Cliente::GetDniSize() { return DNI_SIZE; }

unsigned int Cliente::GetNombreSize() { return NOMBRE_SIZE; }

unsigned int Cliente::GetApellidoSize() { return APELLIDO_SIZE; }

unsigned int Cliente::GetCuilCuitSize() { return CUIL_CUIT_SIZE; }

void Cliente::setDNI(const string& dni) { strcpy(this->DNI, dni.c_str()); }

void Cliente::setNombre(const string& n) { strcpy(this->nombre, n.c_str()); }

void Cliente::setApellido(const string& a) { strcpy(this->apellido, a.c_str()); }

void Cliente::setCuilCuit(const string& c) { strcpy(this->cuilCuit, c.c_str()); }

bool Cliente::operator==(Cliente& cliente) {
    return Validation::IsEqual(this->DNI, cliente.DNI)           && Validation::IsEqual(this->cuilCuit, cliente.cuilCuit)
        && Validation::IsEqual(this->apellido, cliente.apellido) && Validation::IsEqual(this->nombre, cliente.nombre)
        && this->IsEqual(cliente);
}

bool Cliente::IsEmpty() {
    return Validation::IsEmpty(this->DNI) && Validation::IsEmpty(this->nombre)
        && Validation::IsEmpty(this->apellido) && Validation::IsEmpty(this->cuilCuit)
        && this->DatosPersonales::IsEmpty();
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

// Interactive methods moved to menu layer (cliente_menu)