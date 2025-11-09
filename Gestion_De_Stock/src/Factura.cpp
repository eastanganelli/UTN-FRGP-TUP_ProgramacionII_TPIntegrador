#include "Factura.h"

Factura::Factura(const char _tipoFactura) : tipoFactura(_tipoFactura) {

}

Factura::~Factura() {

}

char Factura::getTipoFactura() { return this->tipoFactura; }
float Factura::getTotalIVA() { return this->totalIVA; }

std::ostream& operator<<(std::ostream& os, Factura* obj) {
    os << "--- FACTURA TIPO " << obj->getTipoFactura() << " ---" << std::endl;
    os << "Total IVA: $" << obj->getTotalIVA() << std::endl;
    os << "---------------------------------" << std::endl;
    return os;
}
