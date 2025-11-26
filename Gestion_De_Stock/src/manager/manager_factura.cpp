#include "manager_factura.h"

#include <iomanip>

FacturaManager::FacturaManager(const string& facturaPath)
    : FileSystem<Factura>(facturaPath) { }

FacturaManager::~FacturaManager() { }

GenericArray<Factura> FacturaManager::Listar() {
    GenericArray<Factura> facturas;
    const unsigned int cantidad = this->Count();
    for(unsigned int i = 0; i < cantidad; i++) {
        Factura* aux = this->At(i);
        facturas + (*aux);
        delete aux;
    }
    return facturas;
}

unsigned int FacturaManager::Cantidad() {
    return this->Count();
}

bool FacturaManager::Modificar(unsigned int numero, Factura* factura) {
    const unsigned int cantidad = this->Count();
    for(unsigned int i = 0; i < cantidad; i++) {
        Factura* aux = this->At(i);
        if(aux != nullptr && aux->getNumero() == numero) {
            unsigned int index = i;
            delete aux;
            return this->Update(index, *factura);
        }
        delete aux;
    }
    Error mi_error("Modificacion de Factura", "Factura con numero " + to_string(numero) + " no encontrada.");
    mi_error.Show();
    return false;
}

Factura* FacturaManager::operator[](unsigned int numero) {
    const unsigned int cantidad = this->Count();
    Factura* aux = nullptr;
    for(unsigned int i = 0; i < cantidad; i++) {
        aux = this->At(i);
        if(aux != nullptr && aux->getNumero() == numero) {
            break;
        }
        delete aux;
        aux = nullptr;
    }
    if(aux == nullptr) {
        Warning mi_warning("Busqueda de Factura", "No se encontro factura con numero " + to_string(numero) + ".");
        mi_warning.Show();
    }
    return aux;
}

GenericArray<Factura> FacturaManager::BuscarPorCliente(string clienteDNI) {
    GenericArray<Factura> resultados;
    const unsigned int cantidad = this->Count();
    if(cantidad == 0) {
        Warning mi_warning("Busqueda de Facturas", "No hay facturas registradas.");
        mi_warning.Show();
        return resultados;
    }
    for(unsigned int i = 0; i < cantidad; i++) {
        Factura* aux = this->At(i);
        if(aux->getClienteDNI().find(clienteDNI) != string::npos) {
            resultados + (*aux);
        }
        delete aux;
    }
    if(resultados.Size() == 0) {
        Warning mi_warning("Busqueda de Facturas", "No se encontraron facturas para el cliente " + clienteDNI + ".");
        mi_warning.Show();
    }
    return resultados;
}

GenericArray<Factura> FacturaManager::BuscarPorItemCodigo(string codigo) {
    GenericArray<Factura> resultados;
    const unsigned int cantidad = this->Count();
    if(cantidad == 0) {
        Warning mi_warning("Busqueda de Facturas", "No hay facturas registradas.");
        mi_warning.Show();
        return resultados;
    }
    for(unsigned int i = 0; i < cantidad; i++) {
        Factura* aux = this->At(i);
        unsigned int itemsCount = aux->GetItemsCount();
        for(unsigned int j = 0; j < itemsCount; j++) {
            const Item* it = aux->GetItem(j);
            if(it != nullptr && it->getCodigo().find(codigo) != string::npos) {
                resultados + (*aux);
                break;
            }
        }
        delete aux;
    }
    if(resultados.Size() == 0) {
        Warning mi_warning("Busqueda de Facturas", "No se encontraron facturas con items que contengan " + codigo + ".");
        mi_warning.Show();
    }
    return resultados;
}

void FacturaManager::Imprimir(GenericArray<Factura>& facturas) {
    if(facturas.Size() == 0) {
        Warning mi_warning("Listado de Facturas", "No se encontraron facturas para mostrar.");
        mi_warning.Show();
        return;
    }

    const unsigned int altura = facturas.Size(), columnas = 7;
    Tabling::Table mi_tabla(altura, columnas);

    Tabling::Row* header = new Tabling::Row(columnas);
    header->AddCell("ID", 6);
    header->AddCell("Cliente", 9);
    header->AddCell("Fecha", 12);
    header->AddCell("Monto", 10);
    header->AddCell("Items", 6);
    header->AddCell("Tipo", 6);
    header->AddCell("CAE", 16);
    mi_tabla.AddRow(header);

    for(unsigned int i = 0; i < altura; i++) {
        Tabling::Row* row = new Tabling::Row(columnas);
        row->AddCell(to_string(facturas[i]->getNumero()), 6);
        row->AddCell(facturas[i]->getClienteDNI(), 9);
        row->AddCell(facturas[i]->getFechaEmision().toString(), 12);
        row->AddCell(to_string(facturas[i]->Total()), 10);
        row->AddCell(to_string(facturas[i]->GetItemsCount()), 6);
        // Factura-specific fields: dynamic cast
        Factura* f = facturas[i];
        row->AddCell(string(1, f->getTipoFactura()), 6);
        row->AddCell(f->getCAE(), 16);
        mi_tabla.AddRow(row);
    }
    mi_tabla.Print();

    // Additionally, print items per factura for clarity
    for(unsigned int i = 0; i < altura; i++) {
        Factura* f = facturas[i];
        if(f->GetItemsCount() > 0) {
            cout << "\nItems de Factura " << f->getNumero() << ":\n";
            for(unsigned int j = 0; j < f->GetItemsCount(); j++) {
                const Item* it = f->GetItem(j);
                if(it != nullptr) cout << "  - " << it->toString() << "\n";
            }
        }
    }
}
