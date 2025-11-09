#ifndef CLIENTE_H
#define CLIENTE_H

#include "Persona.h"
#include "TipoResponsable.h"

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Cliente : public Persona {
private:
    const unsigned int id;
    char cuilCuit[11];
    TipoResponsable* razonSocial;

public:
    Cliente(string& _nombre, string& _apellido, string& _DNI, unsigned int _id, string& _cuilCuit, TipoResponsable* _razonSocial, bool _alta = false);
    Cliente(string& _nombre, string& _apellido, string& _DNI, string& _telefono_I, unsigned int _id, string& _cuilCuit, TipoResponsable* _razonSocial, bool _alta = false);
    Cliente(string& _nombre, string& _apellido, string& _DNI, string& _telefono_I, string& _telefono_II, unsigned int _id, string& _cuilCuit, TipoResponsable* _razonSocial, bool _alta = false);
    ~Cliente();

    // Getters
    int getID();
    const string getCuilCuit();
    TipoResponsable* getRazonSocial();

    // Setters
    void setCuilCuit(const string& cuilCuit);
    void setRazonSocial(TipoResponsable* rs);

    // Métodos
    //void cargar();
    //bool escribirDisco(int pos);
    //bool leerDisco(int pos);
};

std::ostream& operator<<(std::ostream& os, const Cliente& obj);

#endif // CLIENTE_H```
