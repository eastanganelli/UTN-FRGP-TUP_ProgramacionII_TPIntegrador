#include "factura.h"

#include "../../manager/manager_producto.h"
#include "../../manager/manager_cliente.h"
#include "../../manager/ventas/manager_factura.h"
#include "../../manager/ventas/manager_nota_de_credito.h"
#include "../../menu/menu_utils.h"
#include "../../controller/modals.h"
#include <cstdio>
#include <iostream>

Factura::Factura(unsigned int _id, string _cliente) : Comprobante(_id, _cliente) {
    this->cae[0] = '\0';
    this->vencimientoCAE = Fecha();
}

Factura::~Factura() { }

void Factura::ObtenerCAE() {
    srand(time(NULL));
    const char caracteres[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int num_caracteres = sizeof(caracteres) - 1;
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < (int)Factura::CAE_SIZE; ++i) {
        this->cae[i] = caracteres[rand() % num_caracteres];
    }
}

string Factura::getCAE() { return string(this->cae); }

Fecha Factura::getVencimientoCAE() { return this->vencimientoCAE; }

float Factura::TotalSinIVA() { return this->Total(); }

unsigned int Factura::ColTipoFacturaSize() { return Factura::TIPOFACTURA_SIZE + 2; }

unsigned int Factura::ColCAESize() { return Factura::CAE_SIZE + 2; }

unsigned int Factura::ColVencimientoCAESize() { return Factura::VENCIMIENTOCAE_SIZE + 2; }

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
    cout << "Factura ID: " + to_string(this->getNumero()) << endl
        << "Cliente: " + this->getClienteDNI() << endl
        << "Fecha Emision: " + this->getFechaEmision().toString() << endl
        << "Monto: " + to_string(this->TotalSinIVA()) << endl
        << "Cantidad de Items: " + to_string(this->CantidadItems()) << endl
        << "CAE: " + this->getCAE() + "\nVencimiento CAE:" + this->vencimientoCAE.toString() + "\n";
}

bool Factura::Facturar() {
    if (!Validation::IsEmpty(this->cae)) return true;

    if (Validation::IsEmpty(this->getClienteDNI())) return false;
    if (this->CantidadItems() == 0) return false;

    this->ObtenerCAE();
    this->vencimientoCAE = Fecha::Hoy();

    return !Validation::IsEmpty(this->cae);
}