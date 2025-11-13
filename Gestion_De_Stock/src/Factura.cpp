#include "Factura.h"

#include <iostream>

Factura::Factura(unsigned int _id, string _cliente, float _monto, unsigned int _cantidadItems, char _tipoFactura) : Comprobante(_id, _cliente, _monto, _cantidadItems) {
    this->tipoFactura = _tipoFactura;
    this->cae[0] = '\0';
    this->vencimientoCAE.CargarFecha();
    this->ObtenerCAE();
}

Factura::~Factura() {

}

void Factura::ObtenerCAE() {
    const char caracteres[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int num_caracteres = sizeof(caracteres) - 1;
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < 15; ++i) {
        this->cae[i] = caracteres[rand() % num_caracteres];
    }
    this->cae[15] = '\0';
}

char Factura::getTipoFactura() {
    return this->tipoFactura;
}

string Factura::getCAE() {
    return string(this->cae);
}

Fecha Factura::getVencimientoCAE() {
    return this->vencimientoCAE;
}

void Factura::setTipoFactura(char t) {
    this->tipoFactura = t;
}

float Factura::TotalSinIVA() {
    return this->Total();
}

float Factura::TotalConIVA() {
    switch(this->tipoFactura) {
    case 'A':
    case 'a':
        return this->Total();
    case 'B':
    case 'b':
        return this->Total() * 1.21f;
    case 'C':
    case 'c':
        return this->Total() * 1.10f;

    }
}

string Factura::toString() {
    string msj = "Factura ID: " + to_string(this->getNumero()) +
                 "\nCliente: " + this->getClienteDNI() +
                 "\Fecha Emision: " + this->getFechaEmision().toString() +
                 "\nMonto: " + to_string(this->TotalSinIVA()) +
                 "\nCantidad de Items: " + to_string(this->getCantidadItems()) +
                 "\nTipo de Factura: " + this->getTipoFactura() +
                 "\nCAE: " + this->getCAE() + "\nVencimiento CAE:" + this->vencimientoCAE.toString() + "\n";
    return msj;
}
