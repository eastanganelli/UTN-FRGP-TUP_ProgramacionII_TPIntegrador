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
    int idVenta;
    Cliente cliente;
    Fecha fechaVenta;

public:
    // Getters
    int getIDVenta();
    const Cliente& getCliente();
    Fecha getFechaVenta();

    // Setters
    void setIDVenta(int id);
    void setCliente(const Cliente& c);
    void setFechaVenta(Fecha f);

    // Métodos
    void cargar();
    void mostrar();
};

#endif // COMPROBANTE_H