#ifndef PRODUCTO_H
#define PRODUCTO_H

#include "Proveedor.h"

#include <iostream>
#include <cstring>

using namespace std;

class Producto {
private:
    char codigo[8];
    char codigoProveedor[11];
    char descripcion[256];
    float precio;
    unsigned int stock;

public:
    // Getters
    string getCodigo();
    string getCodigoProveedor();
    string getDescripcion();
    float getPrecio();
    unsigned int getStock();

    // Setters
    void setCodigo(string c);
    void setDescripcion(string& d);
    void setPrecio(float p);
    void setStock(unsigned int s);

    // Métodos
    
};



#endif // PRODUCTO_H
