#ifndef NOTADECREDITO_H
#define NOTADECREDITO_H

#include "Comprobante.h"
#include "Producto.h"

#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

class NotaDeCredito : public Comprobante {
private:
    int idFacturaOriginal;
    char motivoAnulacion[256];
    // items;

public:
    // Getters
    int getIDFacturaOriginal();
    string getMotivoAnulacion();

    // Setters
    void setIDFacturaOriginal(int id);
    void setMotivoAnulacion(const string& m);

    // Metodos
    void agregarItem(Producto*& item);
    void operator+(Producto*& item);
    void eliminarItem(Producto*& item);
    void operator-(Producto*& item);
};

std::ostream& operator<<(std::ostream& os, NotaDeCredito* obj);

#endif // NOTADECREDITO_H
