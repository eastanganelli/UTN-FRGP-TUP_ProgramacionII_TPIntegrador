#include "Comprobante.h"

Comprobante::Comprobante(unsigned int _numero, string _clienteDNI, float _monto, unsigned int _cantidadItems) : numero(_numero) {
    strcpy(this->clienteDNI, _clienteDNI.c_str());
    this->fechaEmision.CargarFecha();
    this->monto = _monto;
    this->cantidadItems = _cantidadItems;
    this->clienteDNI[8] = '\0';
}

Comprobante::~Comprobante() {

}

unsigned int Comprobante::getNumero() {
    return this->numero;
}

string Comprobante::getClienteDNI() {
    return string(this->clienteDNI);
}

Fecha &Comprobante::getFechaEmision() {
    return this->fechaEmision;
}

float Comprobante::Total() {
    return this->monto;
}

unsigned int Comprobante::getCantidadItems() {
    return this->cantidadItems;
}

void Comprobante::setClienteDNI(string dni) {
    strcpy(this->clienteDNI, dni.c_str());
}

void Comprobante::setMonto(float m) {
    this->monto = m;
}

void Comprobante::setCantidadItems(unsigned int c) {
    this->cantidadItems = c;
}
