#include "NotaDeCredito.h"

int NotaDeCredito::getIDFacturaOriginal() { return _idFacturaOriginal; }
const string& NotaDeCredito::getMotivoAnulacion() { return _motivoAnulacion; }

void NotaDeCredito::setIDFacturaOriginal(int id) { _idFacturaOriginal = id; }
void NotaDeCredito::setMotivoAnulacion(const char* m) { strcpy(_motivoAnulacion, m); }
void NotaDeCredito::setMotivoAnulacion(const string& m) { _motivoAnulacion = m; }

void NotaDeCredito::operator++(const Producto& item) {
    this->agregarItem(item);
}
void NotaDeCredito::agregarItem(const Producto& item) {
    items.push_back(item);
}
void NotaDeCredito::operator--(const Producto& item) {
    this->eliminarItem(item);
}
void NotaDeCredito::eliminarItem(const Producto& item) {
    items.erase(remove(items.begin(), items.end(), item), items.end());
}

std::ostream& operator<<(std::ostream& os, const NotaDeCredito& obj) {
    os << "--- NOTA DE CREDITO ---" << std::endl;
    os << static_cast<const Comprobante&>(obj); // Llama al operador del padre
    os << "Factura Original Afectada: " << obj.getIDFacturaOriginal() << std::endl;
    os << "Motivo: " << obj.getMotivoAnulacion() << std::endl;
    os << "---------------------------------" << std::endl;
    return os;
}