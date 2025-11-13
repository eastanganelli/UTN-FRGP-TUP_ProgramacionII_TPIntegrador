#include "NotaDeCredito.h"

NotaDeCredito::NotaDeCredito(unsigned int _id, string _cliente, string _motivoAnulacion) : Comprobante(_id, _cliente) {
    strcpy(this->motivoAnulacion, _motivoAnulacion.c_str());
}

NotaDeCredito::~NotaDeCredito() {

}

string NotaDeCredito::getMotivoAnulacion() {
    return this->motivoAnulacion;
}

void NotaDeCredito::setMotivoAnulacion(string m) {
    strcpy(this->motivoAnulacion, m.c_str());
}
