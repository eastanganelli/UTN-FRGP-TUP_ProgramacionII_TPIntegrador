#include "NotaDeCredito.h"

int NotaDeCredito::getIDFacturaOriginal() { return this->idFacturaOriginal; }
const string& NotaDeCredito::getMotivoAnulacion() { return this->motivoAnulacion; }

void NotaDeCredito::setIDFacturaOriginal(int id) { this->idFacturaOriginal = id; }
void NotaDeCredito::setMotivoAnulacion(const string& m) { strcpy(this->motivoAnulacion, m.c_str()); }

void NotaDeCredito::operator+(Producto*& item) {
    this->agregarItem(item);
}
void NotaDeCredito::agregarItem(Producto*& item) {
    this->items.push_back(item);
}
void NotaDeCredito::operator-(Producto*& item) {
    this->eliminarItem(item);
}
void NotaDeCredito::eliminarItem(Producto*& item) {
    // this->items.erase(remove(this->items.begin(), this->items.end(), *item), this->items.end());
}

std::ostream& operator<<(std::ostream& os, const NotaDeCredito& obj) {
    /*os << "--- NOTA DE CREDITO ---" << std::endl;
    // os << static_cast<const Comprobante&>(obj); // Llama al operador del padre
    os << "Factura Original Afectada: " << obj.getIDFacturaOriginal() << std::endl;
    os << "Motivo: " << obj.getMotivoAnulacion() << std::endl;
    os << "---------------------------------" << std::endl;*/
    return os;
}
