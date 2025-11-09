#include "Comprobante.h"

unsigned int Comprobante::getIDComprobante() { return this->idComprobante; }
const Cliente& Comprobante::getCliente() { return this->cliente; }
Fecha Comprobante::getFechaComprobante() { return this->fechaComprobante; }

void Comprobante::setCliente(const Cliente& c) { this->cliente = c; }
void Comprobante::setFechaComprobante(Fecha f) { this->fechaComprobante = f; }

void Comprobante::mostrar() {
    cout << "---------------------------------" << endl;
    cout << "ID Venta: " << this->idComprobante << endl;
    // cout << "Cliente: " << this->cliente << endl;
    cout << "Fecha de Comprobante: ";
    //this->fechaComprobante.mostrar();
    cout << endl;
}
