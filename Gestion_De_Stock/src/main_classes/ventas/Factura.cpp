#include "factura.h"

#include <iostream>

Factura::Factura(unsigned int _id, string _cliente) : Comprobante(_id, _cliente) {
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
    for (int i = 0; i < Factura::CAE_SIZE; ++i) {
        this->cae[i] = caracteres[rand() % num_caracteres];
    }
}

string Factura::getCAE() { return string(this->cae); }

Fecha Factura::getVencimientoCAE() { return this->vencimientoCAE; }

float Factura::TotalSinIVA() { return this->Total(); }

unsigned int Factura::GetTipoFacturaLength() { return Factura::TIPOFACTURA_SIZE; }

unsigned int Factura::GetCAELength() { return Factura::CAE_SIZE; }

unsigned int Factura::GetVencimientoCAELength() { return Factura::VENCIMIENTOCAE_SIZE; }

bool Factura::operator==(const Factura& otra) {
    return Validation::IsEqual(this->cae, otra.cae)
        && this->vencimientoCAE == otra.vencimientoCAE
        && this->IsEqual(otra);
}

bool Factura::IsEmpty() {
    return Validation::IsEmpty(this->cae)
        && this->vencimientoCAE == Fecha()
        && this->Comprobante::IsEmpty();
}

void Factura::Print() {
    cout << "Factura ID: " + to_string(this->getNumero()) +
                 "\nCliente: " + this->getClienteDNI() +
                 "\nFecha Emision: " + this->getFechaEmision().toString() +
                 "\nMonto: " + to_string(this->TotalSinIVA()) +
                 "\nCantidad de Items: " + to_string(this->CantidadItems()) +
                 "\nCAE: " + this->getCAE() + "\nVencimiento CAE:" + this->vencimientoCAE.toString() + "\n";
}
