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

bool Comprobante::AddItem(const Item& it) {
    unsigned int count = this->getCantidadItems();
    for (unsigned int i = 0; i < count; i++) {
        if (strncmp(this->items[i].codigo, it.codigo, 9) == 0) {
            return false; // duplicate
        }
    }
    if (count >= ITEMS_MAX) return false;
    this->items[count] = it;
    this->setCantidadItems(count + 1);
    return true;
}

bool Comprobante::RemoveItem(const char* codigo) {
    unsigned int count = this->getCantidadItems();
    for (unsigned int i = 0; i < count; i++) {
        if (strncmp(this->items[i].codigo, codigo, 9) == 0) {
            for (unsigned int j = i; j + 1 < count; j++) {
                this->items[j] = this->items[j+1];
            }
            this->setCantidadItems(count - 1);
            return true;
        }
    }
    return false;
}

unsigned int Comprobante::GetItemsCount() {
    return this->getCantidadItems();
}

const Item* Comprobante::GetItem(unsigned int index) const {
    if (index >= this->getCantidadItems()) return nullptr;
    return &this->items[index];
}

void Comprobante::ClearItems() {
    this->setCantidadItems(0);
}
