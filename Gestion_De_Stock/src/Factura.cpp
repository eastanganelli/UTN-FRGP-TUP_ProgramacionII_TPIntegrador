#include "Factura.h"

Factura::Factura(unsigned int _id, string _cliente, char _tipoFactura) : Comprobante(_id, _cliente) {
    this->tipoFactura = _tipoFactura;
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
