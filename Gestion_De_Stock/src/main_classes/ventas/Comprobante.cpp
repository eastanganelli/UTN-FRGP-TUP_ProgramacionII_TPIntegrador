#include "Comprobante.h"

Comprobante::Comprobante(unsigned int _numero, string _clienteDNI) : numero(_numero) {
    this->clienteDNI[0] = '\0';
    strcpy(this->clienteDNI, _clienteDNI.c_str());
    this->fechaEmision.CargarFecha();
    this->itemsActuales = 0;
}

Comprobante::~Comprobante() { }

unsigned int Comprobante::getNumero() { return this->numero; }

string Comprobante::getClienteDNI() { return string(this->clienteDNI); }

Fecha &Comprobante::getFechaEmision() { return this->fechaEmision; }

unsigned int Comprobante::ColNumeroSize() { return COL_Numero; }

unsigned int Comprobante::ColClienteDNISize() { return COL_ClienteDNI; }

unsigned int Comprobante::ColFechaEmisionSize() { return COL_FechaEmision; }

unsigned int Comprobante::ColMontoTotalSize() { return COL_MontoTotal; }

unsigned int Comprobante::ColTipoSize() { return COL_Tipo; }

float Comprobante::Total() {
    float total = 0.0f;
    for (unsigned int i = 0; i < this->itemsActuales; i++) {
        total += this->items[i].getCantidad() * this->items[i].getPrecioUnitario();
    }
    return total;
}

void Comprobante::setClienteDNI(string dni) {
    strcpy(this->clienteDNI, dni.c_str());
}

bool Comprobante::IsEqual(const Comprobante& otro) {
    return Validation::IsEqual(this->clienteDNI, otro.clienteDNI)
        && this->numero == otro.numero
        && this->fechaEmision == otro.fechaEmision;
}

bool Comprobante::IsEmpty() {
    return Validation::IsEmpty(this->clienteDNI)
        && this->numero == 0
        && this->itemsActuales == 0
        && this->fechaEmision == Fecha();
}

bool Comprobante::AgregarItem(const Item& it) {
    for (unsigned int i = 0; i < this->itemsActuales; i++) {
        if (this->items[i] == it) {
            return false; // duplicate
        }
    }
    if (this->itemsActuales >= ITEMS_MAX) return false;
    this->items[this->itemsActuales] = it;
    this->itemsActuales++;
    return true;
}

bool Comprobante::EliminarItem(const string codigo) {
    for (unsigned int i = 0; i < this->itemsActuales; i++) {
        if (Validation::IsEqual(this->items[i].getCodigo(), codigo)) {
            for (unsigned int j = i; j + 1 < this->itemsActuales; j++) {
                this->items[j] = this->items[j+1];
            }
            this->itemsActuales--;
            return true;
        }
    }
    return false;
}

unsigned int Comprobante::CantidadItems() {
    return this->itemsActuales;
}

const Item* Comprobante::ObtenerItem(unsigned int index) const {
    if (index >= this->itemsActuales) return nullptr;
    return &this->items[index];
}

void Comprobante::LimpiarItems() {
    this->itemsActuales = 0;
    for (unsigned int i = 0; i < ITEMS_MAX; i++) {
        this->items[i] = Item();
    }
}
