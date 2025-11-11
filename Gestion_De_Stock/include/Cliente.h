#ifndef CLIENTE_H
#define CLIENTE_H

#include "DatosPersonales.h"
#include "TipoResponsable.h"

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Cliente : public DatosPersonales {
private:
    const unsigned int id;
    char DNI[8];
    char nombre[20];
    char apellido[25];
    char cuilCuit[11];

public:
    Cliente(unsigned int _id = 0, string _nombre = "", string _apellido = "", string _DNI = "", string _cuilCuit = "", string direccion = "", string correo = "", string _telefono = "", string _celular = "", unsigned int _codigoRazonSocial = 0, bool _alta = false);
    ~Cliente();

    // Getters
    int getID();
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
    //void cargar();
    //bool escribirDisco(int pos);
    //bool leerDisco(int pos);
};

std::ostream& operator<<(std::ostream& os, Cliente* obj);

#endif // CLIENTE_H
