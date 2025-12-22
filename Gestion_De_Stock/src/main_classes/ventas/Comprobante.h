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
    /** Calcula el total de todos los items. */
    float Total();
    /** Compara igualdad con otro comprobante. */
    bool IsEqual(const Comprobante& otro);
    /** Indica si el comprobante esta vacio. */
    bool IsEmpty();

public:
    /** Crea un comprobante con numero y cliente opcional. */
    Comprobante(unsigned int _numero = 0, string _clienteDNI = "");
    /** Destructor de comprobante. */
    ~Comprobante();

    /** Obtiene el numero de comprobante. */
    unsigned int getNumero();
    /** Obtiene el DNI del cliente. */
    string getClienteDNI();
    /** Obtiene la fecha de emision. */
    Fecha& getFechaEmision();

    static unsigned int ColNumeroSize();
    static unsigned int ColClienteDNISize();
    static unsigned int ColFechaEmisionSize();
    static unsigned int ColMontoTotalSize();
    static unsigned int ColTipoSize();

    /** Actualiza el DNI del cliente. */
    void setClienteDNI(string dni);
    /** Actualiza la fecha de emision. */
    void setFechaEmision(Fecha& fecha);

    /** Agrega un item si no esta duplicado y hay espacio. */
    bool AgregarItem(const Item& it);
    /** Elimina un item por codigo. */
    bool EliminarItem(const string codigo);
    /** Devuelve cantidad de items. */
    unsigned int CantidadItems();
    /** Devuelve puntero al item en indice. */
    Item* ObtenerItem(unsigned int index);
    /** Devuelve copia de todos los items. */
    GenericArray<Item>* ObtenerTodosLosItems();
    /** Limpia todos los items. */
    void LimpiarItems();
};

#endif // COMPROBANTE_H
