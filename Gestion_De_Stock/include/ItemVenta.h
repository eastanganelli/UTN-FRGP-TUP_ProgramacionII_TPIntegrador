#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Item {
private:
    int idItem;
    int idProducto;
    int cantidad;
    float precioUnitario;
    float precioTotal;

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

#endif // ITEM_H
