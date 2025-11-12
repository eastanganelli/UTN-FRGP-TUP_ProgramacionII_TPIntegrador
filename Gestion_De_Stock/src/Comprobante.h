#ifndef COMPROBANTE_H
#define COMPROBANTE_H

#define ITEMS_MAX 20

#include "Item.h"
#include "Fecha.h"
#include "Cliente.h"

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Comprobante {
private:
    const unsigned int id;
    const unsigned int cantidadMaxItems;
    unsigned int cantidadItems;
    Item items[ITEMS_MAX];

protected:
    Fecha creado;
    unsigned int codigoCliente;

    float getPrecioTotal();

public:
    Comprobante(unsigned int _id);
    ~Comprobante();

    // Getters
    unsigned int getID();
    unsigned int getCodigoCliente();
    unsigned int getCantidadItems();
    Fecha& getFecha();

    // Setters
    void setCodigoCliente(unsigned int codigo);

    // Métodos
    void operator+(Item& item);
    void operator-(Item& item);
    Item& operator[](unsigned int index);
    void mostrar();
};

#endif // COMPROBANTE_H
