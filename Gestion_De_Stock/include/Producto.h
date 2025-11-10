#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <cstring>

using namespace std;

class Producto {
private:
    int id;
    char nombre[20];
    char descripcion[256];
    float precio;
    unsigned int stock;

public:
    // Getters
    int getID();
    string getNombre();
    string getDescripcion();
    float getPrecio();
    unsigned int getStock();

    // Setters
    void setID(int id);
    void setNombre(const string& n);
    void setDescripcion(const string& d);
    void setPrecio(float p);
    void setStock(int s);

    // Métodos
    
};



#endif // PRODUCTO_H
