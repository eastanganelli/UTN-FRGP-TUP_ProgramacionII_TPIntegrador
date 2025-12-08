#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
#include <cstring>
#include <iostream>

#include "../controller/validation.h"

using namespace std;

class Producto {
private:
    static const unsigned int CODIGO_SIZE = 9;
    static const unsigned int CODIGOPROVEEDOR_SIZE = 12;
    static const unsigned int DESCRIPCION_SIZE = 64;
    static const unsigned int PRECIO_SIZE = 6;
    static const unsigned int STOCK_SIZE = 6;

    static const unsigned int COL_Codigo = 13;
    static const unsigned int COL_CodigoProveedor = 14;
    static const unsigned int COL_Descripcion = 66;
    static const unsigned int COL_Precio = 8;
    static const unsigned int COL_Stock = 8;

    char codigo[CODIGO_SIZE];
    char codigoProveedor[CODIGOPROVEEDOR_SIZE];
    char descripcion[DESCRIPCION_SIZE];
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

    static unsigned int ColCodigoSize();
    static unsigned int ColCodigoProveedorSize();
    static unsigned int ColDescripcionSize();
    static unsigned int ColPrecioSize();
    static unsigned int ColStockSize();

    // Setters
    void setDescripcion(string d);
    void setPrecio(float p);
    void setStock(unsigned int s);

    // Métodos
    bool operator==(const Producto& otro);
    bool IsEmpty();
    void Print();

    static Producto NuevoProducto();
    static void ModificarProducto(Producto& producto);
    static unsigned int EliminarProducto(Producto& producto);
};

#endif // PRODUCTO_H
