#ifndef FACTURA_H
#define FACTURA_H

#include "Comprobante.h"

#include <cstring>

using namespace std;

class Factura : public Comprobante {
private:
    char tipoFactura; // 'A', 'B', 'C'
    char cae[16];
    Fecha vencimientoCAE;


public:
    Factura(unsigned int _id = 0, string _cliente = "", float _monto = 0.0f, unsigned int _cantidadItems = 0, char _tipoFactura = 'B');
    ~Factura();

    // Getters
    char getTipoFactura();
    const char getCAE();
    Fecha getVencimientoCAE();

    // Setters
    void setTipoFactura(char t);
    void setTotalIVA(float iva);

    // Métodos
    float TotalSinIVA();
    void TotalConIVA();
    string toString();
};

#endif // FACTURA_H
