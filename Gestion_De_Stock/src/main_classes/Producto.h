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
    /** Crea un producto con datos opcionales y stock inicial. */
    Producto(string _codigo = "", string _codigoProveedor = "", string _descripcion = "", float _precio = 0, unsigned int _stock = 0);
    /** Destructor de producto. */
    ~Producto();

    /** Obtiene el codigo interno. */
    string getCodigo();
    /** Obtiene el codigo del proveedor. */
    string getCodigoProveedor();
    /** Obtiene la descripcion. */
    string getDescripcion();
    /** Obtiene el precio unitario. */
    float getPrecio();
    /** Obtiene el stock disponible. */
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

    /** Actualiza la descripcion. */
    void setDescripcion(string d);
    /** Actualiza el precio. */
    void setPrecio(float p);
    /** Actualiza el stock. */
    void setStock(unsigned int s);
    /** Fija el codigo interno. */
    void setCodigo(const string& c);
    /** Fija el codigo de proveedor. */
    void setCodigoProveedor(const string& c);

    /** Genera un codigo alfanumerico de producto. */
    static string GenerarCodigo();

    /** Compara igualdad por campos. */
    bool operator==(const Producto& otro);
    /** Indica si el producto esta vacio. */
    bool IsEmpty();
    /** Imprime el producto en consola. */
    void Print();

};

#endif // PRODUCTO_H
