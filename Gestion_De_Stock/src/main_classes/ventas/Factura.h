#ifndef FACTURA_H
#define FACTURA_H

#include <cstdio>
#include <iostream>

using namespace std;

#include "Comprobante.h"

#include "../../menu/menu_utils.h"
#include "../../controller/modals.h"
#include "../../manager/manager_producto.h"
#include "../../manager/manager_cliente.h"
#include "../../manager/ventas/manager_nota_de_credito.h"

class Factura : public Comprobante {
private:
    static const unsigned int TIPOFACTURA_SIZE = 8;
    static const unsigned int CAE_SIZE = 15;
    static const unsigned int VENCIMIENTOCAE_SIZE = 10;

    static const unsigned int COL_TipoFactura = 12;
    static const unsigned int COL_CAE = 20;
    static const unsigned int COL_VencimientoCAE = 18;
    static const unsigned int COL_FechaCAE = 15;
    static const unsigned int COL_TotalSinIVA = 15;

    char cae[CAE_SIZE];
    Fecha vencimientoCAE;

    void ObtenerCAE();

public:
    /** Crea una factura con numero y cliente opcional. */
    Factura(unsigned int _id = 0, string _cliente = "");
    /** Destructor de factura. */
    ~Factura();

    /** Obtiene el CAE asignado. */
    string getCAE();
    /** Obtiene el vencimiento del CAE. */
    Fecha getVencimientoCAE();
    /** Calcula total sin IVA. */
    float TotalSinIVA();

    static unsigned int ColTipoFacturaSize();
    static unsigned int ColCAESize();
    static unsigned int ColVencimientoCAESize();

    /** Intenta facturar generando CAE y vencimiento. */
    bool Facturar();

    /** Compara igualdad entre facturas. */
    bool operator==(const Factura& otra);
    /** Indica si la factura esta vacia. */
    bool IsEmpty();
    /** Imprime datos de la factura. */
    void Print();
    /** Reservado para futuras ayudas CRUD. */
};

#endif // FACTURA_H