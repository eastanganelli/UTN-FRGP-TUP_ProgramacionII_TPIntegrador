#include "Factura.h"

Factura::Factura(unsigned int _id, char _tipoFactura) : Comprobante(_id), tipoFactura(_tipoFactura) {

}

Factura::~Factura() {

}

char Factura::getTipoFactura() {
    return this->tipoFactura;
}

void Factura::TotalSinIVA() {

}

void Factura::TotalConIVA() {

}

void Factura::CantidadItems() {

}

std::ostream& operator<<(std::ostream& os, Factura* obj) {
    /*os << "--- FACTURA TIPO " << obj->getTipoFactura() << " ---" << std::endl;
    os << "Total IVA: $" << obj->getTotalIVA() << std::endl;
    os << "---------------------------------" << std::endl;*/
    return os;
}
