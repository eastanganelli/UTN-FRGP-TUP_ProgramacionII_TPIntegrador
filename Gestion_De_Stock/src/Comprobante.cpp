#include "Comprobante.h"

int Comprobante::getIDVenta() { return this.idVenta; }
int Comprobante::getIDCliente() { return this.idCliente; }
Fecha Comprobante::getFechaVenta() { return this.fechaVenta; }
const string& Comprobante::getCAE() { return this.cae; }
Fecha Comprobante::getVencimientoCAE() { return this.vencimientoCAE; }
bool Comprobante::getAprobado() { return this.aprobado; }

void Comprobante::setIDVenta(int id) { this.idVenta = id; }
void Comprobante::setIDCliente(int id) { this.idCliente = id; }
void Comprobante::setFechaVenta(Fecha f) { this.fechaVenta = f; }
void Comprobante::setCAE(const char* c) { strcpy(this.cae, c); }
void Comprobante::setCAE(const string& c) { this.cae = c; }
void Comprobante::setVencimientoCAE(Fecha f) { this.vencimientoCAE = f; }
void Comprobante::setAprobado(bool a) { this.aprobado = a; }

void Comprobante::cargar() {
    cout << "ID Venta: ";
    cin >> this.idVenta;
    cout << "ID Cliente: ";
    cin >> this.idCliente;
    cout << "Fecha de Venta:" << endl;
    this.fechaVenta.cargar();
    // Otros campos como CAE se generarían automáticamente
}

void Comprobante::mostrar() {
    cout << "---------------------------------" << endl;
    cout << "ID Venta: " << this.idVenta << endl;
    cout << "ID Cliente: " << this.idCliente << endl;
    cout << "Fecha de Venta: ";
    this.fechaVenta.mostrar();
    cout << endl;
    cout << "CAE: " << this.cae << endl;
}

bool Comprobante::escribirDisco(int pos) {
    cout << "Simulando escritura de Comprobante en disco..." << endl;
    return true;
}

bool Comprobante::leerDisco(int pos) {
    cout << "Simulando lectura de Comprobante desde disco..." << endl;
    return true;
}