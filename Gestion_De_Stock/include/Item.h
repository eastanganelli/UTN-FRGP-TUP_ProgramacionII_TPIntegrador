#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Item {
private:
    unsigned int id;
    unsigned int codigoProducto;
    char descripcion[100];
    unsigned int cantidad;
    float precioUnitario;
    float precioTotal;

public:
    // Getters
    unsigned int getID();
    unsigned int getCodigoProducto();
    unsigned int getCantidad();
    float getPrecioUnitario();
    float getPrecioTotal();

    // Setters
    void setID(unsigned int id);
    void setCodigoProducto(unsigned int id);
    void setCantidad(unsigned int cant);
    void setPrecioUnitario(float precio);
    void setPrecioTotal(float precio);

    // Métodos

};

std::ostream& operator<<(std::ostream& os, Item* obj);

#endif // ITEM_H
