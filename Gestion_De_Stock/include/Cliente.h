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
    TipoResponsable* razonSocial;

public:
    Cliente(bool _alta = false, string& _nombre, string& _apellido, string& _DNI, unsigned int _id, string& _cuilCuit, TipoResponsable* _razonSocial);
    Cliente(bool _alta = false, string& _telefono_I, string& _nombre, string& _apellido, string& _DNI, unsigned int _id, string& _cuilCuit, TipoResponsable* _razonSocial);
    Cliente(bool _alta = false, string& _telefono_I, string& _telefono_II, string& _nombre, string& _apellido, string& _DNI, unsigned int _id, string& _cuilCuit, TipoResponsable* _razonSocial);
    ~Cliente();

    // Getters
    int getID();
    string getDNI();
    string getNombre();
    string getApellido();
    string getCuilCuit();
    TipoResponsable* getRazonSocial();

    // Setters
    void setDNI(const string& dni);
    void setNombre(const string& n);
    void setApellido(const string& a);
    void setCuilCuit(const string& cuilCuit);
    void setRazonSocial(TipoResponsable* rs);

    // Métodos
    //void cargar();
    //bool escribirDisco(int pos);
    //bool leerDisco(int pos);
};

std::ostream& operator<<(std::ostream& os, const Cliente& obj);

#endif // CLIENTE_H```
