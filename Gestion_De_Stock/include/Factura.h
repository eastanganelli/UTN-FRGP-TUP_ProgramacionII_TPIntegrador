#ifndef FACTURA_H
#define FACTURA_H

#include "Comprobante.h"

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Factura : public Comprobante {
    char tipoFactura; // 'A', 'B', 'C'
    float totalIVA;
    char cae[14];
    Fecha vencimientoCAE;

public:
    Factura(char _tipoFactura = 'B');
    ~Factura();

    // Getters
    char getTipoFactura();
    float getTotalIVA();
    const char getCAE();
    Fecha getVencimientoCAE();

    // Setters
    void setTipoFactura(char t);
    void setTotalIVA(float iva);

    // Métodos
};


std::ostream& operator<<(std::ostream& os, const Factura& obj);

#endif // FACTURA_H
