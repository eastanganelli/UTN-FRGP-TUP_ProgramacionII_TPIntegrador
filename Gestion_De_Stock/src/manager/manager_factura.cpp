#include "manager_factura.h"

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

void FacturaManager::ListarPorCliente() {
    GenericArray<Factura> facturas = this->Listar();
    if(facturas.Size() == 0) {
        Warning mi_warning("Listado de Facturas", "No se encontraron facturas para mostrar.");
        mi_warning.Show();
        return;
    }
    for(unsigned int i = 0; i < facturas.Size(); i++) {
        for(unsigned int j = i + 1; j < facturas.Size(); j++) {
            if(facturas[i]->getClienteDNI() > facturas[j]->getClienteDNI()) {
                facturas.Swap(facturas[i], facturas[j]);
            }
        }
    }
    FacturaManager::Imprimir(facturas);
}

void FacturaManager::ListarPorFecha() {
    GenericArray<Factura> facturas = this->Listar();
    if(facturas.Size() == 0) {
        Warning mi_warning("Listado de Facturas", "No se encontraron facturas para mostrar.");
        mi_warning.Show();
        return;
    }
    for(unsigned int i = 0; i < facturas.Size(); i++) {
        for(unsigned int j = i + 1; j < facturas.Size(); j++) {
            if(facturas[i]->getFechaEmision() > facturas[j]->getFechaEmision()) {
                facturas.Swap(facturas[i], facturas[j]);
            }
        }
    }
    FacturaManager::Imprimir(facturas);
}

void FacturaManager::ListarPorMonto() {
    GenericArray<Factura> facturas = this->Listar();
    if(facturas.Size() == 0) {
        Warning mi_warning("Listado de Facturas", "No se encontraron facturas para mostrar.");
        mi_warning.Show();
        return;
    }
    for(unsigned int i = 0; i < facturas.Size(); i++) {
        for(unsigned int j = i + 1; j < facturas.Size(); j++) {
            if(facturas[i]->TotalSinIVA() > facturas[j]->TotalSinIVA()) {
                facturas.Swap(facturas[i], facturas[j]);
            }
        }
    }
    FacturaManager::Imprimir(facturas);
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

GenericArray<Factura> FacturaManager::BuscarPorCAE(string cae) {
    GenericArray<Factura> resultados;
    const unsigned int cantidad = this->Count();
    if(cantidad == 0) {
        Warning mi_warning("Busqueda de Facturas", "No hay facturas registradas.");
        mi_warning.Show();
        return resultados;
    }
    for(unsigned int i = 0; i < cantidad; i++) {
        Factura* aux = this->At(i);
        if(aux->getCAE().find(cae) != string::npos) {
            resultados + (*aux);
        }
        delete aux;
    }
    if(resultados.Size() == 0) {
        Warning mi_warning("Busqueda de Facturas", "No se encontraron facturas con CAE " + cae + ".");
        mi_warning.Show();
    }
    return resultados;
}

GenericArray<Factura> FacturaManager::BuscarPorRangoFecha(Fecha fechaInicio, Fecha fechaFin) {
    GenericArray<Factura> resultados;
    const unsigned int cantidad = this->Count();
    if(cantidad == 0) {
        Warning mi_warning("Busqueda de Facturas", "No hay facturas registradas.");
        mi_warning.Show();
        return resultados;
    }
    for(unsigned int i = 0; i < cantidad; i++) {
        Factura* aux = this->At(i);
        if(aux->getFechaEmision() >= fechaInicio && aux->getFechaEmision() <= fechaFin) {
            resultados + (*aux);
        }
        delete aux;
    }
    if(resultados.Size() == 0) {
        Warning mi_warning("Busqueda de Facturas", "No se encontraron facturas en el rango de fechas especificado.");
        mi_warning.Show();
    }
    return resultados;
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
//    header->AddCell("Monto", 10);
//    header->AddCell("Items", 6);
//    header->AddCell("Tipo", 6);
    header->AddCell("CAE", 16);
    mi_tabla.AddRow(header);

    for(unsigned int i = 0; i < altura; i++) {
        Tabling::Row* row = new Tabling::Row(columnas);
        row->AddCell(to_string(facturas[i]->getNumero()), 6);
        row->AddCell(facturas[i]->getClienteDNI(), 9);
        row->AddCell(facturas[i]->getFechaEmision().toString(), 12);
//        row->AddCell(to_string(facturas[i]->Total()), 10);
//        row->AddCell(to_string(facturas[i]->GetItemsCount()), 6);
//        Factura-specific fields: dynamic cast
        Factura* f = facturas[i];
//        row->AddCell(string(1, f->getTipoFactura()), 6);
        row->AddCell(f->getCAE(), 16);
        mi_tabla.AddRow(row);
    }
    mi_tabla.Print();
}
