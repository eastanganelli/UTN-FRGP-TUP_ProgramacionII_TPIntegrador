#ifndef COMPROBANTE_H
#define COMPROBANTE_H

#include "Fecha.h"
#include "Cliente.h"

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Comprobante {
protected:
    int idComprobante;
    Cliente cliente;
    Fecha fechaComprobante;

public:
    // Getters
    int getIDComprobante();
    const Cliente& getCliente();
    Fecha getFechaComprobante();

    // Setters
    void setIDComprobante(int id);
    void setCliente(const Cliente& c);
    void setFechaComprobante(Fecha f);

    // Métodos
    void mostrar();
};

#endif // COMPROBANTE_H
