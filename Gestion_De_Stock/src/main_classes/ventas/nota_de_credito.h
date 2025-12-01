#ifndef NOTADECREDITO_H
#define NOTADECREDITO_H

#include "Comprobante.h"
#include "../producto.h"

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class NotaDeCredito : public Comprobante {
private:
    char motivoAnulacion[256];

public:
    NotaDeCredito(unsigned int _id = 0, string _cliente = "", string _motivoAnulacion = "");
    ~NotaDeCredito();

    // Getters
    string getMotivoAnulacion();
    float TotalSinIVA();

    // Setters
    void setMotivoAnulacion(string m);

    // Metodos
    string toString();
};

#endif // NOTADECREDITO_H
