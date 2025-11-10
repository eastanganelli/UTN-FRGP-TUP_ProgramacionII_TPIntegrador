#include "Comprobante.h"

Comprobante::Comprobante(unsigned int _id) : id(_id) {

}

Comprobante::~Comprobante() {

}

unsigned int Comprobante::getID() {
    return this->id;
}

const Cliente* Comprobante::getCliente() {
    return this->cliente;
}

Fecha& Comprobante::getFecha() {
    return this->creado;
}

void Comprobante::setCliente(Cliente*& c) {
    this->cliente = c;
}

void Comprobante::setFecha(Fecha f) {
    this->creado = f;
}

void Comprobante::mostrar() {
    cout << "---------------------------------" << endl;
    cout << "ID Venta: " << this->id << endl;
    // cout << "Cliente: " << this->cliente << endl;
    cout << "Fecha de Comprobante: ";
    //this->fechaComprobante.mostrar();
    cout << endl;
}
