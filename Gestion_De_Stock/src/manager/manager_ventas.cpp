#include "manager_ventas.h"
#include <iostream>

VentaManager::VentaManager() : facturas(), notas() { }

VentaManager::~VentaManager() { }

bool VentaManager::ConvertirFacturaANota(unsigned int numeroFactura, const string& motivo) {
    Factura* f = facturas[numeroFactura];
    // if (f == nullptr) return false;

    // unsigned int newId = notas.Count() + 1;
    // NotaDeCredito nota(newId, f->getClienteDNI(), motivo);

    // unsigned int items = f->GetItemsCount();
    // for (unsigned int i = 0; i < items; ++i) {
    //     const Item* it = f->GetItem(i);
    //     if (it != nullptr) nota.AddItem(*it);
    // }

    // nota.setMonto(nota.TotalSinIVA());
    // bool saved = notas.New(nota);

    // if (!saved) {
    //     delete f;
    //     return false;
    // }

    // unsigned int cantidad = facturas.Count();
    // for (unsigned int i = 0; i < cantidad; ++i) {
    //     Factura* aux = facturas.At(i);
    //     if (aux != nullptr && aux->getNumero() == numeroFactura) {
    //         delete aux;
    //         facturas.Delete(i);
    //         break;
    //     }
    //     delete aux;
    // }

    delete f;
    return true;
}

void VentaManager::ImprimirComprobantesPorCliente(const string& clienteDNI) {
    GenericArray<Factura> fact = facturas.BuscarPorCliente(clienteDNI);
    GenericArray<NotaDeCredito> nots = notas.BuscarPorCliente(clienteDNI);

    cout << "\n--- Facturas del cliente " << clienteDNI << " ---\n";
    if (fact.Size() > 0) FacturaManager::Imprimir(fact);
    else cout << "No se encontraron facturas para el cliente." << endl;

    cout << "\n--- Notas de Credito del cliente " << clienteDNI << " ---\n";
    if (nots.Size() > 0) NotaDeCreditoManager::Imprimir(nots);
    else cout << "No se encontraron notas de credito para el cliente." << endl;
}

void VentaManager::ImprimirTodos() {
    GenericArray<Factura> todasFacturas;
    unsigned int fc = facturas.Count();
    for (unsigned int i = 0; i < fc; ++i) {
        Factura* f = facturas.At(i);
        if (f != nullptr) {
            todasFacturas + (*f);
            delete f;
        }
    }

    GenericArray<NotaDeCredito> todasNotas;
    unsigned int nc = notas.Count();
    for (unsigned int i = 0; i < nc; ++i) {
        NotaDeCredito* n = notas.At(i);
        if (n != nullptr) {
            todasNotas + (*n);
            delete n;
        }
    }

    cout << "\n==== Todas las Facturas ====\n";
    if (todasFacturas.Size() > 0) FacturaManager::Imprimir(todasFacturas);
    else cout << "No hay facturas registradas." << endl;

    cout << "\n==== Todas las Notas de Credito ====\n";
    if (todasNotas.Size() > 0) NotaDeCreditoManager::Imprimir(todasNotas);
    else cout << "No hay notas de credito registradas." << endl;
}
