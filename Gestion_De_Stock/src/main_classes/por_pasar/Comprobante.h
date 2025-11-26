#ifndef COMPROBANTE_H
#define COMPROBANTE_H

#define ITEMS_MAX 20

#include "Fecha.h"

#include <string>
#include <cstring>
#include "Item.h"

using namespace std;

class Comprobante {
private:
    unsigned int numero;
    char clienteDNI[9];
    float monto;
    unsigned int cantidadItems;
    Fecha fechaEmision;

    Item items[ITEMS_MAX];

    void CargarFecha();

protected:
    Fecha creado;

    float Total();
    unsigned int CantidadItems();

public:
    Comprobante(unsigned int _numero = 0, string _clienteDNI = "", float _monto = 0.0f, unsigned int _cantidadItems = 0);
    ~Comprobante();

    // Getters
    unsigned int getNumero();
    string getClienteDNI();
    Fecha& getFechaEmision();
    unsigned int getCantidadItems();

    // Setters
    void setClienteDNI(string dni);
    void setMonto(float m);
    void setCantidadItems(unsigned int c);

    // Métodos
    void mostrar();
    // Items
    bool AddItem(const Item& it); // false if duplicate or full
    bool RemoveItem(const char* codigo);
    unsigned int GetItemsCount();
    const Item* GetItem(unsigned int index) const;
    void ClearItems();
};

#endif // COMPROBANTE_H
