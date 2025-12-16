#include "factura.h"

#include "../../manager/manager_producto.h"
#include "../../manager/manager_cliente.h"
#include "../../manager/ventas/manager_factura.h"
#include "../../manager/ventas/manager_nota_de_credito.h"
#include "../../menu/menu_utils.h"
#include "../../controller/modals.h"
#include <cstdio>
#include <iostream>

Factura::Factura(unsigned int _id, string _cliente) : Comprobante(_id, _cliente) {
    this->cae[0] = '\0';
    this->vencimientoCAE = Fecha();
}

Factura::~Factura() { }

void Factura::ObtenerCAE() {
    const char caracteres[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int num_caracteres = sizeof(caracteres) - 1;
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < (int)Factura::CAE_SIZE; ++i) {
        this->cae[i] = caracteres[rand() % num_caracteres];
    }
}

string Factura::getCAE() { return string(this->cae); }

Fecha Factura::getVencimientoCAE() { return this->vencimientoCAE; }

float Factura::TotalSinIVA() { return this->Total(); }

unsigned int Factura::ColTipoFacturaSize() { return Factura::TIPOFACTURA_SIZE + 2; }

unsigned int Factura::ColCAESize() { return Factura::CAE_SIZE + 2; }

unsigned int Factura::ColVencimientoCAESize() { return Factura::VENCIMIENTOCAE_SIZE + 2; }

bool Factura::operator==(const Factura& otra) {
    return Validation::IsEqual(this->cae, otra.cae)
        && this->vencimientoCAE == otra.vencimientoCAE
        && this->IsEqual(otra);
}

bool Factura::IsEmpty() {
    return Validation::IsEmpty(this->cae)
        && this->vencimientoCAE == Fecha()
        && this->Comprobante::IsEmpty();
}

void Factura::Print() {
    cout << "Factura ID: " + to_string(this->getNumero()) +
                 "\nCliente: " + this->getClienteDNI() +
                 "\nFecha Emision: " + this->getFechaEmision().toString() +
                 "\nMonto: " + to_string(this->TotalSinIVA()) +
                 "\nCantidad de Items: " + to_string(this->CantidadItems()) +
                 "\nCAE: " + this->getCAE() + "\nVencimiento CAE:" + this->vencimientoCAE.toString() + "\n";
}

Factura Factura::NuevoFactura(unsigned int numero, ProductoManager& pm, ClienteManager& clientes) {
    if (numero == 0) {
        unsigned int maxNum = 0;
        FacturaManager fm;
        NotaDeCreditoManager nm;

        unsigned int fc = fm.Count();
        for (unsigned int i = 0; i < fc; ++i) {
            Factura* ff = fm.At(i);
            if (ff != nullptr) {
                if (ff->getNumero() > maxNum) maxNum = ff->getNumero();
                delete ff;
            }
        }

        unsigned int nc = nm.Count();
        for (unsigned int i = 0; i < nc; ++i) {
            NotaDeCredito* nn = nm.At(i);
            if (nn != nullptr) {
                if (nn->getNumero() > maxNum) maxNum = nn->getNumero();
                delete nn;
            }
        }
        numero = maxNum + 1;
    }

    Factura f(numero, "");

    string dni;
    while (true) {
        dni = InputBox("DNI del cliente: ");
        if (dni.size() == 0) {
            Warning w("DNI invalido", "Debe ingresar un DNI valido."); w.Show(); w.WaitForKey(); continue;
        }
        Cliente* c = clientes[dni];
        if (c == nullptr) {
            Warning w("Cliente no encontrado", "No existe cliente con ese DNI. Ingrese uno existente."); w.Show(); w.WaitForKey();
            continue;
        }
        // found
        delete c;
        break;
    }
    f.setClienteDNI(dni);

    f.getFechaEmision() = Fecha::Hoy();

    while (true) {
        string codigo = InputBox("Codigo producto (vaciar para terminar): ");
        if (codigo.length() == 0) break;
        Producto* p = pm[codigo];
        if (p == nullptr) { Warning w("Producto no encontrado", "No existe producto con ese codigo."); w.Show(); w.WaitForKey(); continue; }
        unsigned int stock = p->getStock();
        unsigned int cantidad = InputNumber("Cantidad: ");
        if (cantidad == 0 || cantidad > stock) { Warning w("Cantidad invalida", "Cantidad debe ser >0 y <= stock disponible."); w.Show(); w.WaitForKey(); continue; }
        Item it(codigo.c_str(), cantidad, p->getPrecio());
        if (!f.AgregarItem(it)) { Warning w("Item duplicado", "El item ya existe en la factura."); w.Show(); w.WaitForKey(); continue; }
        Producto aux = *p;
        aux.setStock(stock - cantidad);
        pm.Modificar(aux.getCodigo(), &aux);
    }

    if (f.CantidadItems() > 0) {
        if (!f.Facturar()) {
            Warning w("Facturacion", "No se pudo generar CAE para la factura."); w.Show(); w.WaitForKey();
        }
    } else {
        Informational i("Factura guardada", "Factura creada sin items. No puede ser facturada hasta agregar items."); i.Show(); i.WaitForKey();
    }

    return f;
}

bool Factura::Facturar() {
    if (this->CantidadItems() == 0) {
        Warning w("Facturar Factura", "No se puede facturar una factura sin items.");
        w.Show();
        return false;
    }
    this->ObtenerCAE();
    this->vencimientoCAE.CargarFecha();
    Informational i("Factura emitida", "CAE generado correctamente.");
    i.Show();
    return true;
}

void Factura::ModificarFactura(Factura& factura, ProductoManager& pm) {
    unsigned int opcion = 0;
    string entrada;
    do {
        rlutil::cls();
        cout << "-- Modificar Factura (ID: " << factura.getNumero() << ") --\n";
        cout << "1) Agregar Item\n";
        cout << "2) Modificar Item\n";
        cout << "3) Eliminar Item\n";
        cout << "4) Facturar\n";
        cout << "5) Terminar\n";
        opcion = InputNumber("Seleccione accion: ");
        switch(opcion) {
            case 1: {
                string codigo = InputBox("Codigo producto: ");
                Producto* p = pm[codigo];
                if (p == nullptr) { Warning w("Producto no encontrado", "No existe producto con ese codigo."); w.Show(); w.WaitForKey(); break; }
                unsigned int cantidad = InputNumber("Cantidad: ");
                if (cantidad == 0 || cantidad > p->getStock()) { Warning w("Cantidad invalida", "Cantidad invalida o stock insuficiente."); w.Show(); w.WaitForKey(); break; }
                Item it(codigo.c_str(), cantidad, p->getPrecio());
                if (!factura.AgregarItem(it)) { Warning w("Item duplicado", "El item ya existe en la factura."); w.Show(); w.WaitForKey(); break; }
                Producto aux = *p; aux.setStock(p->getStock() - cantidad); pm.Modificar(aux.getCodigo(), &aux);
                break;
            }
            case 2: {
                unsigned int idx = InputNumber("Indice de item (0-based): ");
                const Item* pit = factura.ObtenerItem(idx);
                if (pit == nullptr) { Warning w("Item no encontrado", "Indice invalido."); w.Show(); w.WaitForKey(); break; }
                Item mutableItem = *pit;
                Item::ModificarItem(mutableItem, pm);
                factura.EliminarItem(mutableItem.getCodigo());
                factura.AgregarItem(mutableItem);
                break;
            }
            case 3: {
                string codigo = InputBox("Codigo del item a eliminar: ");
                const Item* pit = nullptr;
                for (unsigned int i = 0; i < factura.CantidadItems(); i++) {
                    const Item* it = factura.ObtenerItem(i);
                    if (Validation::IsEqual(it->getCodigo(), codigo)) { pit = it; break; }
                }
                if (pit == nullptr) { Warning w("Item no encontrado", "No hay item con ese codigo en la factura."); w.Show(); w.WaitForKey(); break; }
                Item temp = *pit;
                if (factura.EliminarItem(codigo)) {
                    Producto* p = pm[temp.getCodigo()];
                    if (p != nullptr) { Producto aux = *p; aux.setStock(p->getStock() + temp.getCantidad()); pm.Modificar(aux.getCodigo(), &aux); }
                }
                break;
            }
            case 4: {
                if (factura.Facturar()) {
                    rlutil::cls();
                    Informational i("Factura facturada", "Se genero CAE para la factura.");
                    i.Show(); i.WaitForKey();
                }
                break;
            }
            case 5: break;
            default: { Warning w("Opcion invalida", "Seleccione una opcion valida."); w.Show(); w.WaitForKey(); break; }
        }
    } while (opcion != 5);
    rlutil::cls();
}

unsigned int Factura::EliminarFactura(Factura& factura, ProductoManager& pm) {
    Warning w("Eliminar Factura", "Esta seguro que desea eliminar esta factura? Esto restaurara el stock de sus items.");
    if (w.ShowYesNo()) {
        for (unsigned int i = 0; i < factura.CantidadItems(); i++) {
            const Item* it = factura.ObtenerItem(i);
            Producto* p = pm[it->getCodigo()];
            if (p != nullptr) { Producto aux = *p; aux.setStock(p->getStock() + it->getCantidad()); pm.Modificar(aux.getCodigo(), &aux); }
        }
        return 1;
    }
    return 0;
}
