#include "Comprobante.h"

int Comprobante::getIDVenta() { return this->idVenta; }
const Cliente& Comprobante::getCliente() { return this->cliente; }
Fecha Comprobante::getFechaVenta() { return this->fechaVenta; }
const string& Comprobante::getCAE() { return this->cae; }
Fecha Comprobante::getVencimientoCAE() { return this->vencimientoCAE; }

void Comprobante::setIDVenta(int id) { this->idVenta = id; }
void Comprobante::setCliente(const Cliente& c) { this->cliente = c; }
void Comprobante::setFechaVenta(Fecha f) { this->fechaVenta = f; }
void Comprobante::setCAE(const char* c) { strcpy(this->cae, c); }
void Comprobante::setCAE(const string& c) { this->cae = c; }
void Comprobante::setVencimientoCAE(Fecha f) { this->vencimientoCAE = f; }

void Comprobante::cargar() {
    cout << "ID Venta: ";
    cin >> this->idVenta;
    cout << "Cliente: " << endl;
    this->cliente.cargar();
    cout << "Fecha de Venta:" << endl;
    this->fechaVenta.cargar();
    // Otros campos como CAE se generarían automáticamente
}

void Comprobante::mostrar() {
    cout << "---------------------------------" << endl;
    cout << "ID Venta: " << this->idVenta << endl;
    // cout << "Cliente: " << this->cliente << endl;
    cout << "Fecha de Venta: ";
    this->fechaVenta.mostrar();
    cout << endl;
    cout << "CAE: " << this->cae << endl;
}