#include "NotaDeCredito.h"

NotaDeCredito::NotaDeCredito(unsigned int _id, string _cliente, float _monto, unsigned int _cantidadItems, string _motivoAnulacion)
    : Comprobante(_id, _cliente, _monto, _cantidadItems) {
    strcpy(this->motivoAnulacion, _motivoAnulacion.c_str());
}

NotaDeCredito::~NotaDeCredito() {

}

string NotaDeCredito::getMotivoAnulacion() {
    return this->motivoAnulacion;
}

float NotaDeCredito::TotalSinIVA() {
    return this->Total();
}

unsigned int NotaDeCredito::CantidadItems() {
    return this->getCantidadItems();
}

void NotaDeCredito::setMotivoAnulacion(string m) {
    strcpy(this->motivoAnulacion, m.c_str());
}

string NotaDeCredito::toString() {
    string resultado = "Nota de Credito Nro: " + to_string(this->getNumero()) +
                       "\nCliente DNI: " + this->getClienteDNI() +
                       "\nMonto: " + to_string(this->TotalSinIVA()) +
                       "\nCantidad de Items: " + to_string(this->CantidadItems()) +
                       "\nFecha de Emision: " + this->getFechaEmision().toString() +
                       "\nMotivo de Anulacion: " + this->getMotivoAnulacion();
    return resultado;
}
