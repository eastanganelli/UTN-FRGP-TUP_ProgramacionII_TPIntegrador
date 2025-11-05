#include "Factura.h"

char Factura::getTipoFactura() { return _tipoFactura; }
float Factura::getTotalIVA() { return _totalIVA; }

void Factura::setTipoFactura(char t) { _tipoFactura = t; }
void Factura::setTotalIVA(float iva) { _totalIVA = iva; }

void Factura::mostrar() {
    std::cout << "--- FACTURA TIPO " << _tipoFactura << " ---" << std::endl;
    Comprobante::mostrar(); // Llama al método del padre
    std::cout << "Total IVA: $" << _totalIVA << std::endl;
    std::cout << "---------------------------------" << std::endl;
}


std::ostream& operator<<(std::ostream& os, const Factura& obj) {
    os << "--- FACTURA TIPO " << obj.getTipoFactura() << " ---" << std::endl;
    os << "Total IVA: $" << obj.getTotalIVA() << std::endl;
    os << "---------------------------------" << std::endl;
    return os;
}