#include "Comprobante.h"

Comprobante::Comprobante(unsigned int _numero, string _clienteDNI) : numero(_numero), cantidadMaxItems(ITEMS_MAX) {
    strcpy(this->clienteDNI, _clienteDNI.c_str());
    this->cantidadItems = 0;
}

Comprobante::~Comprobante() {

}

float Comprobante::TotalSinIVA() {
    float total = 0.0f;
    for (unsigned int i = 0; i < this->cantidadItems; i++) {
        total += this->items[i].getPrecioTotal();
    }
    return total;
}

unsigned int Comprobante::CantidadItems() {
    unsigned int totalItems = 0;
    for (unsigned int i = 0; i < this->cantidadItems; i++) {
        totalItems += this->items[i].getCantidad();
    }
    return totalItems;
}

unsigned int Comprobante::getNumero() {
    return this->numero;
}

unsigned int Comprobante::getCodigoCliente() {
    return this->codigoCliente;
}

unsigned int Comprobante::getCantidadItems() {
    return this->cantidadItems;
}

Fecha& Comprobante::getFecha() {
    return this->creado;
}

void Comprobante::setCodigoCliente(unsigned int c) {
    this->codigoCliente = c;
}

void Comprobante::operator+(Item& item) {
    if (this->cantidadItems < this->cantidadMaxItems) {
        this->items[this->cantidadItems] = item;
        this->cantidadItems++;
    } else {
        cerr << "No se pueden agregar más items al comprobante." << endl;
    }
}

void Comprobante::operator-(Item& item) {
    for (unsigned int i = 0; i < this->cantidadItems; i++) {
        // if (this->items[i].g() == item.getID()) {
        //     for (unsigned int j = i; j < this->cantidadItems - 1; j++) {
        //         this->items[j] = this->items[j + 1];
        //     }
        //     this->cantidadItems--;
        //     return;
        // }
    }
    cerr << "Item no encontrado en el comprobante." << endl;
}

Item& Comprobante::operator[](unsigned int index) {
    if (index < this->cantidadItems) {
        return this->items[index];
    } else {
        cerr << "Índice fuera de rango." << endl;
        return this->items[0];
    }
}

void Comprobante::mostrar() {
    cout << "---------------------------------" << endl;
    cout << "ID Venta: " << this->numero << endl;
    // cout << "Cliente: " << this->cliente << endl;
    cout << "Fecha de Comprobante: ";
    //this->fechaComprobante.mostrar();
    cout << endl;
}
