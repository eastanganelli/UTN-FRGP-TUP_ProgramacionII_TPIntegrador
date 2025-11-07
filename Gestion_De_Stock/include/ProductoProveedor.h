#ifndef PRODUCTO_PROVEEDOR_H
#define PRODUCTO_PROVEEDOR_H

#include <iostream>
#include <cstring>

using namespace std;

class ProductoProveedor
{

    private:
        int idProducto;
        int idProveedor;
        float precioProveedor;

    public:

    // Getters
    int getIdProducto();
    int getIdProveedor();
    float getPrecioProveedor();
    
    // Setters
    void setIdProducto(int id);
    void setIdProveedor(int id);
    void setPrecioProveedor(float precio);
    
    // Metodos
    void cargar();
    bool escribirDisco(int pos);
    bool leerDisco(int pos);
    
        
};

#endif // PRODUCTO_PROVEEDOR_H
