#include "NotaDeCredito.h"

string NotaDeCredito::getMotivoAnulacion() {
    return this->motivoAnulacion;
}

void NotaDeCredito::setMotivoAnulacion(const string m) {
    strcpy(this->motivoAnulacion, m.c_str());
}
