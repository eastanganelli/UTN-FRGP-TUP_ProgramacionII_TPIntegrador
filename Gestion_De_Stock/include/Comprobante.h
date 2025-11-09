#ifndef COMPROBANTE_H
#define COMPROBANTE_H

#include "Fecha.h"
#include "Cliente.h"

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Comprobante {
private:
    const unsigned int id;

protected:
    Cliente* cliente;
    Fecha creado;

public:
    Comprobante(unsigned int _id);
    ~Comprobante();

    // Getters
    unsigned int getID();
    const Cliente* getCliente();
    Fecha& getFecha();

    // Setters
    void setCliente(Cliente*& c);
    void setFecha(Fecha f);

    // Métodos
    void mostrar();
};

#endif // COMPROBANTE_H
