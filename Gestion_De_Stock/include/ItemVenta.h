#ifndef ITEMVENTA_H
#define ITEMVENTA_H

#include "Comprobante.h"

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class ItemVenta {
private:
    int idItem;
    int idVenta;
    int idProducto;
    int cantidad;
    float precioUnitario;
    float precioTotal;
    string condicionIVA;

public:
    // Getters
    int getIDItem();
    int getIDVenta();
    int getIDProducto();
    int getCantidad();
    float getPrecioUnitario();
    float getPrecioTotal();
    string getCondicionIVA();

    // Setters
    void setIDItem(int id);
    void setIDVenta(int id);
    void setIDProducto(int id);
    void setCantidad(int cant);
    void setPrecioUnitario(float precio);
    void setPrecioTotal(float precio);
    void setCondicionIVA(string condicion);

    // Métodos
    void cargar();
    bool escribirDisco(int pos);
    bool leerDisco(int pos);
};


std::ostream& operator<<(std::ostream& os, const ItemVenta& obj);

#endif // ITEMVENTA_H
