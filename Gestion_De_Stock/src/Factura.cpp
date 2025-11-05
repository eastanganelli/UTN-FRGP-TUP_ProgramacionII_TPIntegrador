#include "Factura.h"

char Factura::getTipoFactura() { return this->tipoFactura; }
float Factura::getTotalIVA() { return this->totalIVA; }

void Factura::setTipoFactura(char t) { this->tipoFactura = t; }
void Factura::setTotalIVA(float iva) { this->totalIVA = iva; }

std::ostream& operator<<(std::ostream& os, const Factura& obj) {
    os << "--- FACTURA TIPO " << obj.getTipoFactura() << " ---" << std::endl;
    os << "Total IVA: $" << obj.getTotalIVA() << std::endl;
    os << "---------------------------------" << std::endl;
    return os;
}