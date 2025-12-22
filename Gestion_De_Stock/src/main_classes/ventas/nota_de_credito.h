#ifndef NOTADECREDITO_H
#define NOTADECREDITO_H

#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

#include "Comprobante.h"
#include "../producto.h"

#include "../../menu/menu_utils.h"
#include "../../controller/modals.h"
#include "../../manager/manager_producto.h"

class NotaDeCredito : public Comprobante {
private:
    static unsigned int const MOTIVOANULACION_SIZE = 120;

    static unsigned int const COL_MotivoAnulacion = 125;

    char motivoAnulacion[120];

public:
    /** Crea una nota de credito con cliente y motivo. */
    NotaDeCredito(unsigned int _id = 0, string _cliente = "", string _motivoAnulacion = "");
    /** Destructor de nota de credito. */
    ~NotaDeCredito();

    /** Obtiene el motivo de anulacion. */
    string getMotivoAnulacion();
    /** Calcula total sin IVA. */
    float TotalSinIVA();

    static unsigned int ColMotivoAnulacionSize();

    /** Actualiza el motivo de anulacion. */
    void setMotivoAnulacion(string m);

    /** Compara igualdad entre notas. */
    bool operator==(NotaDeCredito& nota);
    /** Indica si la nota esta vacia. */
    bool IsEmpty();
    /** Devuelve representacion en texto. */
    string toString();
};

#endif // NOTADECREDITO_H
