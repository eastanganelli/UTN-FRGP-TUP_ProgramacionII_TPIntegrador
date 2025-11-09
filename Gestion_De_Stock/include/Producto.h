#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <cstring>

using namespace std;

class Producto {
private:
    int idProducto;
    char nombre[20];
    char descripcion[256];
    float precio;
    int stock;

public:
    // Getters
    int getIDProducto();
    string getNombre();
    string getDescripcion();
    float getPrecio();
    int getStock();

    // Setters
    void setIDProducto(int id);
    void setNombre(const string& n);
    void setDescripcion(const string& d);
    void setPrecio(float p);
    void setStock(int s);

    // Métodos
    void cargar();
    void mostrar();
    bool escribirDisco(int pos);
    bool leerDisco(int pos);
};



#endif // PRODUCTO_H
