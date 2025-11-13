#include "Factura.h"

#include <iostream>

Factura::Factura(unsigned int _id, string _cliente, float _monto, unsigned int _cantidadItems, char _tipoFactura) : Comprobante(_id, _cliente, _monto, _cantidadItems) {
    this->tipoFactura = _tipoFactura;
    this->cae[0] = '\0';
    this->vencimientoCAE = Fecha();
}

Factura::~Factura() {

}

void Factura::ObtenerCAE() {

    this->vencimientoCAE = Fecha();
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
    string msj = "Factura ID: " + to_string(this->getNumero()) +
                 "\nCliente: " + this->getClienteDNI() +
                 "\nMonto: " + to_string(this->TotalSinIVA()) +
                 "\nCantidad de Items: " + to_string(this->getCantidadItems()) +
                 "\nTipo de Factura: " + this->getTipoFactura() +
                 "\nCAE: " + this->getCAE() + "\n";
    return msj;
}
