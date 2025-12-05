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
    static unsigned int const MOTIVOANULACION_SIZE = 255;

    char motivoAnulacion[255];

public:
    NotaDeCredito(unsigned int _id = 0, string _cliente = "", string _motivoAnulacion = "");
    ~NotaDeCredito();

    // Getters
    string getMotivoAnulacion();
    float TotalSinIVA();

    // Setters
    void setMotivoAnulacion(string m);

    // Metodos
    bool operator==(NotaDeCredito& nota);
    bool IsEmpty();
    string toString();
};

#endif // NOTADECREDITO_H
