#include "nota_de_credito.h"
#include "../../manager/manager_producto.h"
#include "../../menu/menu_utils.h"
#include "../../controller/modals.h"
#include <cstdio>

NotaDeCredito::NotaDeCredito(unsigned int _id, string _cliente, string _motivoAnulacion)
    : Comprobante(_id, _cliente) {
    strcpy(this->motivoAnulacion, _motivoAnulacion.c_str());
}

NotaDeCredito::~NotaDeCredito() { }

string NotaDeCredito::getMotivoAnulacion() { return this->motivoAnulacion; }

unsigned int NotaDeCredito::ColMotivoAnulacionSize() { return COL_MotivoAnulacion; }

float NotaDeCredito::TotalSinIVA() { return this->Total(); }

void NotaDeCredito::setMotivoAnulacion(string m) { strcpy(this->motivoAnulacion, m.c_str()); }

bool NotaDeCredito::operator==(NotaDeCredito& nota) {
    return this->IsEqual(nota) && Validation::IsEqual(this->motivoAnulacion, nota.motivoAnulacion);
}

bool NotaDeCredito::IsEmpty() {
    return Validation::IsEmpty(this->motivoAnulacion) && this->Comprobante::IsEmpty();
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

NotaDeCredito NotaDeCredito::NuevoNotaDeCredito(unsigned int numero, ProductoManager& pm) {
    NotaDeCredito n(numero, "");
    string dni = InputBox("DNI del cliente: ");
    n.setClienteDNI(dni);
    string motivo = InputBox("Motivo de la nota de credito: ");
    n.setMotivoAnulacion(motivo);

    // Agregar items a la nota (si se quiere devolver stock)
    while (true) {
        string codigo = InputBox("Codigo producto (vaciar para terminar): ");
        if (codigo.length() == 0) break;
        Producto* p = pm[codigo];
        if (p == nullptr) { Warning w("Producto no encontrado", "No existe producto con ese codigo."); w.Show(); w.WaitForKey(); continue; }
        unsigned int cantidad = InputNumber("Cantidad a devolver: ");
        if (cantidad == 0) { Warning w("Cantidad invalida", "Ingrese cantidad mayor a 0."); w.Show(); w.WaitForKey(); continue; }
        Item it(codigo.c_str(), cantidad, p->getPrecio());
        if (!n.AgregarItem(it)) { Warning w("Item duplicado", "El item ya existe en la nota."); w.Show(); w.WaitForKey(); continue; }
        // aumentar stock
        Producto aux = *p; aux.setStock(p->getStock() + cantidad); pm.Modificar(aux.getCodigo(), &aux);
    }
    return n;
}

void NotaDeCredito::ModificarNotaDeCredito(NotaDeCredito& nota, ProductoManager& pm) {
    unsigned int opcion = 0;
    do {
        rlutil::cls();
        cout << "-- Modificar Nota de Credito (ID: " << nota.getNumero() << ") --\n";
        cout << "1) Agregar Item\n2) Eliminar Item\n3) Terminar\n";
        opcion = InputNumber("Seleccione accion: ");
        switch(opcion) {
            case 1: {
                string codigo = InputBox("Codigo producto: ");
                Producto* p = pm[codigo];
                if (p == nullptr) { Warning w("Producto no encontrado", "No existe producto con ese codigo."); w.Show(); w.WaitForKey(); break; }
                unsigned int cantidad = InputNumber("Cantidad a devolver: ");
                if (cantidad == 0) { Warning w("Cantidad invalida", "Ingrese cantidad mayor a 0."); w.Show(); w.WaitForKey(); break; }
                Item it(codigo.c_str(), cantidad, p->getPrecio());
                if (!nota.AgregarItem(it)) { Warning w("Item duplicado", "El item ya existe en la nota."); w.Show(); w.WaitForKey(); break; }
                Producto aux = *p; aux.setStock(p->getStock() + cantidad); pm.Modificar(aux.getCodigo(), &aux);
                break;
            }
            case 2: {
                string codigo = InputBox("Codigo del item a eliminar: ");
                const Item* pit = nullptr;
                for (unsigned int i = 0; i < nota.CantidadItems(); i++) {
                    const Item* it = nota.ObtenerItem(i);
                    if (Validation::IsEqual(it->getCodigo(), codigo)) { pit = it; break; }
                }
                if (pit == nullptr) { Warning w("Item no encontrado", "No hay item con ese codigo en la nota."); w.Show(); w.WaitForKey(); break; }
                Item temp = *pit;
                if (nota.EliminarItem(codigo)) {
                    Producto* p = pm[temp.getCodigo()];
                    if (p != nullptr) { Producto aux = *p; aux.setStock(p->getStock() - temp.getCantidad()); pm.Modificar(aux.getCodigo(), &aux); }
                }
                break;
            }
            case 3: break;
            default: { Warning w("Opcion invalida", "Seleccione una opcion valida."); w.Show(); w.WaitForKey(); break; }
        }
    } while (opcion != 3);
    rlutil::cls();
}

unsigned int NotaDeCredito::EliminarNotaDeCredito(NotaDeCredito& nota, ProductoManager& pm) {
    Warning w("Eliminar Nota de Credito", "Esta seguro que desea eliminar esta nota? Esto revertira los cambios en stock registrados.");
    if (w.ShowYesNo()) {
        for (unsigned int i = 0; i < nota.CantidadItems(); i++) {
            const Item* it = nota.ObtenerItem(i);
            Producto* p = pm[it->getCodigo()];
            if (p != nullptr) { Producto aux = *p; aux.setStock(p->getStock() - it->getCantidad()); pm.Modificar(aux.getCodigo(), &aux); }
        }
        return 1;
    }
    return 0;
}