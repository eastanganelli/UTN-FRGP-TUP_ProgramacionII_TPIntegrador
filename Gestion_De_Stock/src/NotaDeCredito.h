#ifndef NOTADECREDITO_H
#define NOTADECREDITO_H

#include "Comprobante.h"
#include "Producto.h"

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class NotaDeCredito : public Comprobante {
private:
    char motivoAnulacion[257];

public:
    // Getters
    string getMotivoAnulacion();

    // Setters
    void setMotivoAnulacion(const string m);

    // Metodos
    void agregarItem(Producto*& item);
    void operator+(Producto*& item);
    void eliminarItem(Producto*& item);
    void operator-(Producto*& item);
};

#endif // NOTADECREDITO_H
