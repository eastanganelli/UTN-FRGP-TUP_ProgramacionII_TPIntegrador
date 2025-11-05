#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <cstring>

using namespace std;

class Producto {
private:
    int idProducto;
    string nombre;
    string descripcion;
    float precio;
    int stock;

public:
    // Getters
    int getIDProducto();
    const string& getNombre();
    const string& getDescripcion();
    float getPrecio();
    int getStock();

    // Setters
    void setIDProducto(int id);
    void setNombre(const char* n);
    void setNombre(const string& n);
    void setDescripcion(const char* d);
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