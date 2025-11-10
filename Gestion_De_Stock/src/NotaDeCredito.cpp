#include "NotaDeCredito.h"

int NotaDeCredito::getIDFacturaOriginal() { return this->idFacturaOriginal; }
string NotaDeCredito::getMotivoAnulacion() { return this->motivoAnulacion; }

void NotaDeCredito::setIDFacturaOriginal(int id) { this->idFacturaOriginal = id; }
void NotaDeCredito::setMotivoAnulacion(const string& m) { strcpy(this->motivoAnulacion, m.c_str()); }


std::ostream& operator<<(std::ostream& os, NotaDeCredito* obj) {
    /*os << "--- NOTA DE CREDITO ---" << std::endl;
    // os << static_cast<const Comprobante&>(obj); // Llama al operador del padre
    os << "Factura Original Afectada: " << obj.getIDFacturaOriginal() << std::endl;
    os << "Motivo: " << obj.getMotivoAnulacion() << std::endl;
    os << "---------------------------------" << std::endl;*/
    return os;
}
