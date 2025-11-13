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
    NotaDeCredito(unsigned int _id = 0, string _cliente = "", string _motivoAnulacion = "");
    ~NotaDeCredito();

    // Getters
    string getMotivoAnulacion();

    // Setters
    void setMotivoAnulacion(string m);

    // Metodos
    void agregarItem(Producto*& item);
    void operator+(Producto*& item);
    void eliminarItem(Producto*& item);
    void operator-(Producto*& item);
};

#endif // NOTADECREDITO_H
