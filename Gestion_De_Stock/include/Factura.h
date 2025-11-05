#ifndef FACTURA_H
#define FACTURA_H

#include "Comprobante.h"

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Factura : public Comprobante {
private:
    char _tipoFactura; // 'A', 'B', 'C'
    float _totalIVA;
    string cae;
    Fecha vencimientoCAE;

public:
    // Getters
    char getTipoFactura();
    float getTotalIVA();
    const string& getCAE();
    Fecha getVencimientoCAE();

    // Setters
    void setTipoFactura(char t);
    void setTotalIVA(float iva);
    void setCAE(const char* c);
    void setCAE(const string& c);
    void setVencimientoCAE(Fecha f);

    // Métodos
    void mostrar();
};


std::ostream& operator<<(std::ostream& os, const Factura& obj);

#endif // FACTURA_H