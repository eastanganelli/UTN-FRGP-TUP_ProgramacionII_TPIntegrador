#ifndef FACTURA_H
#define FACTURA_H

#include "Comprobante.h"

#include <cstring>

using namespace std;

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
    Factura(unsigned int _id = 0, string _cliente = "");
    ~Factura();

    // Getters
    string getCAE();
    Fecha getVencimientoCAE();
    float TotalSinIVA();

    static unsigned int ColTipoFacturaSize();
    static unsigned int ColCAESize();
    static unsigned int ColVencimientoCAESize();

    // Setters
    bool Facturar();

    // Métodos
    bool operator==(const Factura& otra);
    bool IsEmpty();
    void Print();
    
    // CRUD helpers
};

#endif // FACTURA_H