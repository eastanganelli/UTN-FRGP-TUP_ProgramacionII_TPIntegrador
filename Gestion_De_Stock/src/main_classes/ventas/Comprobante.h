#ifndef COMPROBANTE_H
#define COMPROBANTE_H

#include <string>
#include <cstring>

#include "../../controller/fecha.h"
#include "../../controller/validation.h"
#include "Item.h"

using namespace std;

class Comprobante {
private:
    static const unsigned int ITEMS_MAX = 20;
    static const unsigned int CLIENTEDNI_SIZE = 9;
    static const unsigned int NUMERO_SIZE = 5;
    static const unsigned int MONTO_SIZE = 10;

    static const unsigned int COL_Numero = 8;
    static const unsigned int COL_ClienteDNI = 12;
    static const unsigned int COL_FechaEmision = 15;
    static const unsigned int COL_MontoTotal = 12;
    static const unsigned int COL_Tipo = 15;

    unsigned int numero;
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

    static unsigned int ColNumeroSize();
    static unsigned int ColClienteDNISize();
    static unsigned int ColFechaEmisionSize();
    static unsigned int ColMontoTotalSize();
    static unsigned int ColTipoSize();

    // Setters
    void setClienteDNI(string dni);
    void setFechaEmision(Fecha& fecha);

    // Items
    bool AgregarItem(const Item& it);
    bool EliminarItem(const string codigo);
    unsigned int CantidadItems();
    Item* ObtenerItem(unsigned int index);
    GenericArray<Item>* ObtenerTodosLosItems();
    void LimpiarItems();
};

#endif // COMPROBANTE_H
