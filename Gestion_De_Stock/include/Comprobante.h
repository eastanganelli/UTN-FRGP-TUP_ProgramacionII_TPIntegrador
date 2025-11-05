#ifndef COMPROBANTE_H
#define COMPROBANTE_H

#include "Fecha.h"

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Comprobante {
protected:
    int idVenta;
    int idCliente;
    Fecha fechaVenta;
    bool aprobado;

public:
    // Getters
    int getIDVenta();
    int getIDCliente();
    Fecha getFechaVenta();
    bool getAprobado();

    // Setters
    void setIDVenta(int id);
    void setIDCliente(int id);
    void setFechaVenta(Fecha f);
    void setAprobado(bool a);

    // Métodos
    void cargar();
    void mostrar();
    bool escribirDisco(int pos);
    bool leerDisco(int pos);
};

#endif // COMPROBANTE_H