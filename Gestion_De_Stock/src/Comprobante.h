#ifndef COMPROBANTE_H
#define COMPROBANTE_H

#define ITEMS_MAX 20

#include "Item.h"
#include "Fecha.h"

#include <cstring>

using namespace std;

class Comprobante {
private:
    const unsigned int numero;
    const unsigned int cantidadMaxItems;
    char clienteDNI[8];
    unsigned int cantidadItems;
    Item items[ITEMS_MAX];

protected:
    Fecha creado;
    unsigned int codigoCliente;

    float TotalSinIVA();
    unsigned int CantidadItems();

public:
    Comprobante(unsigned int _numero = 0, string _clienteDNI = "");
    ~Comprobante();

    // Getters
    unsigned int getNumero();
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
