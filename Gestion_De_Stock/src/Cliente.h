#ifndef CLIENTE_H
#define CLIENTE_H

#include "DatosPersonales.h"

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Cliente : public DatosPersonales {
private:
    char DNI[8];
    char nombre[20];
    char apellido[20];
    char cuilCuit[11];

public:
    Cliente(string _nombre = "", string _apellido = "", string _DNI = "", string _cuilCuit = "", string direccion = "", string correo = "", string _telefono = "", string _celular = "", unsigned int _codigoRazonSocial = 0, bool _alta = false);
    ~Cliente();

    // Getters
    string getDNI();
    string getNombre();
    string getApellido();
    string getCuilCuit();

    // Setters
    void setDNI(const string& dni);
    void setNombre(const string& n);
    void setApellido(const string& a);
    void setCuilCuit(const string& cuilCuit);

    // Métodos

};

std::ostream& operator<<(std::ostream& os, Cliente* obj);

#endif // CLIENTE_H

/*
 *     std::cout << "Cliente: " << aux->getNombre() << " " << aux->getApellido()
              << " | DNI: " << aux->getDNI() << " | CUIL/CUIT: " << aux->getCuilCuit()
              << " | Dir: " << aux->getDireccion() << " | Correo: " << aux->getCorreo()
              << " | Tel: " << aux->getTelefono() << " | Cel: " << aux->getCelular()
              << " | Cod Razon Soc: " << aux->getCodigoRazonSocial()
              << " | Alta: " << (aux->getAlta() ? "Si" : "No") << std::endl;
 */
