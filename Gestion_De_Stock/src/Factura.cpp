#include "Factura.h"

#include <iostream>

Factura::Factura(unsigned int _id, string _cliente, char _tipoFactura) : Comprobante(_id, _cliente) {
    this->tipoFactura = _tipoFactura;
    this->cae[15] = '\0';
}

Factura::~Factura() {

}

char Factura::getTipoFactura() {
    return this->tipoFactura;
}

void Factura::TotalSinIVA() {
    this->TotalSinIVA();
}

void Factura::TotalConIVA() {

}

void Factura::CantidadItems() {

}

string Factura::toString() {
    return "";
}
