#ifndef PRODUCTO_H
#define PRODUCTO_H

#include "Proveedor.h"

#include <iostream>
#include <cstring>

using namespace std;

class Producto {
private:
    unsigned int id;
    char codigoProveedor[11];
    char descripcion[256];
    float precio;
    unsigned int stock;

public:
    // Getters
    unsigned int getID();
    string getCodigoProveedor();
    string getDescripcion();
    float getPrecio();
    unsigned int getStock();

    // Setters
    void setID(unsigned int id);
    void setDescripcion(string& d);
    void setPrecio(float p);
    void setStock(unsigned int s);

    // Métodos
    
};



#endif // PRODUCTO_H
