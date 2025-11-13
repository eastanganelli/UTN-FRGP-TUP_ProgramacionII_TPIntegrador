#ifndef FACTURA_H
#define FACTURA_H

#include "Comprobante.h"

#include <iostream>
#include <cstring>

using namespace std;

class Factura : public Comprobante {
private:
    char tipoFactura; // 'A', 'B', 'C'
    float total;
    float totalIVA;
    char cae[15];
    Fecha vencimientoCAE;


public:
    Factura(unsigned int _id = 0, string _cliente = "", char _tipoFactura = 'B');
    ~Factura();

    // Getters
    char getTipoFactura();
    const char getCAE();
    Fecha getVencimientoCAE();

    // Setters
    void setTipoFactura(char t);
    void setTotalIVA(float iva);

    // Métodos
    void TotalSinIVA();
    void TotalConIVA();
    void CantidadItems();
};

#endif // FACTURA_H
