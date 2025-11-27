#ifndef COMPROBANTE_H
#define COMPROBANTE_H

#include <string>
#include <cstring>

#include "../fecha.h"
#include "../../controller/validation.h"
#include "Item.h"

using namespace std;

class Comprobante {
private:
    static const unsigned int ITEMS_MAX = 20;
    static const unsigned int CLIENTEDNI_SIZE = 9;
    static const unsigned int NUMERO_SIZE = 5;
    static const unsigned int MONTO_SIZE = 10;

    const unsigned int numero;
    unsigned int itemsActuales;
    char clienteDNI[CLIENTEDNI_SIZE];
    Fecha fechaEmision;
    Item items[ITEMS_MAX];

protected:
    float Total();
    bool IsEqual(const Comprobante& otro);
    bool IsEmpty();

public:
    Comprobante(unsigned int _numero = 0, string _clienteDNI = "");
    ~Comprobante();

    // Getters
    unsigned int getNumero();
    string getClienteDNI();
    Fecha& getFechaEmision();

    // Setters
    void setClienteDNI(string dni);

    // Items
    bool AgregarItem(const Item& it);
    bool EliminarItem(const string codigo);
    unsigned int CantidadItems();
    const Item* ObtenerItem(unsigned int index) const;
    void LimpiarItems();
};

#endif // COMPROBANTE_H
