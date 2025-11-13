#include "Factura.h"

#include <iostream>

Factura::Factura(unsigned int _id, string _cliente, float _monto, unsigned int _cantidadItems, char _tipoFactura) : Comprobante(_id, _cliente, _monto, _cantidadItems) {
    this->tipoFactura = _tipoFactura;
    this->cae[0] = '\0';
    this->vencimientoCAE = Fecha();
}

Factura::~Factura() {

}

char Factura::getTipoFactura() {
    return this->tipoFactura;
}

string Factura::getCAE() {
    return string(this->cae);
}

float Factura::TotalSinIVA() {
    return this->Total();
}

void Factura::TotalConIVA() {

}

string Factura::toString() {
    return "";
}
