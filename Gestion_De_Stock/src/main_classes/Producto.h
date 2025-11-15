#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
#include <cstring>

using namespace std;

class Producto {
private:
    char codigo[9];
    char codigoProveedor[12];
    char descripcion[256];
    float precio;
    unsigned int stock;

    void generarCodigoProducto(char* codigo);

public:
    // Constructor y Desctructor
    Producto(string _codigo = "", string _codigoProveedor = "", string _descripcion = "", float _precio = 0, unsigned int _stock = 0);
    ~Producto();

    // Getters
    string getCodigo();
    string getCodigoProveedor();
    string getDescripcion();
    float getPrecio();
    unsigned int getStock();

    // Setters
    void setDescripcion(string d);
    void setPrecio(float p);
    void setStock(unsigned int s);

    // Métodos
    string toString();
};

#endif // PRODUCTO_H
