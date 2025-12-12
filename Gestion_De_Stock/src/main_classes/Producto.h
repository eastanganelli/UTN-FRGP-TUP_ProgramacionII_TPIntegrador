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

    static const unsigned int COL_Codigo = 15;
    static const unsigned int COL_CodigoProveedor = 15;
    static const unsigned int COL_Descripcion = 70;
    static const unsigned int COL_Precio = 10;
    static const unsigned int COL_Stock = 10;

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

    static unsigned int GetCodigoSize();
    static unsigned int GetCodigoProveedorSize();
    static unsigned int GetDescripcionSize();
    static unsigned int GetPrecioSize();
    static unsigned int GetStockSize();

    static unsigned int ColCodigoSize();
    static unsigned int ColCodigoProveedorSize();
    static unsigned int ColDescripcionSize();
    static unsigned int ColPrecioSize();
    static unsigned int ColStockSize();

    // Setters
    void setDescripcion(string d);
    void setPrecio(float p);
    void setStock(unsigned int s);
    void setCodigo(const string& c);
    void setCodigoProveedor(const string& c);

    // Generador de codigo alfanumerico
    static string GenerarCodigo();

    // Métodos
    bool operator==(const Producto& otro);
    bool IsEmpty();
    void Print();

    // interactive UI methods moved to menu layer
};

#endif // PRODUCTO_H
