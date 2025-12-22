#include "manager_factura.h"

#include <cstdio>

#include "../manager_producto.h"

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

bool FacturaManager::Existe(unsigned int codigo) {
    unsigned int index;
    return this->Indice(codigo, index);
}

bool FacturaManager::Indice(unsigned int codigo, unsigned int& index) {
    GenericArray<Factura> facturas = this->Listar();
    for(unsigned int i = 0; i < facturas.Size(); i++) {
        if(facturas[i]->getNumero() == codigo) {
            index = i;
            return true;
        }
    }
    return false;
}

bool FacturaManager::Agregar(Factura& factura) {
    if(this->Existe(factura.getNumero())) {
        Warning mi_warning("Agregar Factura", "La factura con numero " + to_string(factura.getNumero()) + " ya existe.");
        mi_warning.Show();
        return false;
    }
    return this->New(factura);
}

bool FacturaManager::Modificar(unsigned int numero, Factura* factura) {
    unsigned int index;
    if(!this->Indice(numero, index)) {
        Error mi_error("Modificacion de Factura", "Factura con numero " + to_string(numero) + " no encontrada.");
        mi_error.Show();
        return false;
    }
    return this->Update(index, *factura);
}

bool FacturaManager::Eliminar(unsigned int numero) {
    unsigned int index;
    if(!this->Indice(numero, index)) {
        Error mi_error("Eliminacion de Factura", "Factura con numero " + to_string(numero) + " no encontrada.");
        mi_error.Show();
        return false;
    }
    return this->Delete(index);
}

Factura* FacturaManager::operator[](unsigned int numero) {
    unsigned int index;
    if(!this->Indice(numero, index)) {
        Warning mi_warning("Busqueda de Factura", "Factura con numero " + to_string(numero) + " no encontrada.");
        mi_warning.Show();
        return nullptr;
    }
    return this->At(index);
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

void FacturaManager::Imprimir(GenericArray<Factura>& facturas) {
    if(facturas.Size() == 0) {
        Warning mi_warning("Listado de Facturas", "No se encontraron facturas para mostrar.");
        mi_warning.Show();
        return;
    }

    const unsigned int altura = facturas.Size(), columnas = 4;
    Tabling::Table mi_tabla(altura, columnas);

    Tabling::Row* header = new Tabling::Row(columnas);
    header->AddCell("ID", 6);
    header->AddCell("Cliente", 9);
    header->AddCell("Fecha", 12);
    header->AddCell("CAE", 16);
    mi_tabla.AddRow(header);

    for(unsigned int i = 0; i < altura; i++) {
        Tabling::Row* row = new Tabling::Row(columnas);
        row->AddCell(to_string(facturas[i]->getNumero()), 6);
        row->AddCell(facturas[i]->getClienteDNI(), 9);
        row->AddCell(facturas[i]->getFechaEmision().toString(), 12);
        Factura* f = facturas[i];
        row->AddCell(f->getCAE(), 16);
        mi_tabla.AddRow(row);
    }
    mi_tabla.Print();
}

bool FacturaManager::ExportCSV(const string& comprobantesPath, const string& itemsPath, bool append, bool includeHeader) {
    const char* mode = append ? "a" : "w";

    FILE* compFile = fopen(comprobantesPath.c_str(), mode);
    if(compFile == nullptr) {
        Error mi_error("Exportar Ventas", "No se pudo abrir o crear " + comprobantesPath + ".");
        mi_error.Show();
        return false;
    }

    FILE* itemsFile = fopen(itemsPath.c_str(), mode);
    if(itemsFile == nullptr) {
        fclose(compFile);
        Error mi_error("Exportar Ventas", "No se pudo abrir o crear " + itemsPath + ".");
        mi_error.Show();
        return false;
    }

    if(includeHeader) {
        fprintf(compFile, "tipo,numero,cliente_dni,fecha_emision,total_sin_iva,cantidad_items,extra1,extra2\n");
        fprintf(itemsFile, "nro_comprobante,cod_producto,nombre_producto,cantidad,precio_unitario,sub_total\n");
    }

    ProductoManager pm;

    const unsigned int total = this->Count();
    for(unsigned int i = 0; i < total; i++) {
        Factura* f = this->At(i);
        if(f == nullptr) { continue; }

        const string fecha = f->getFechaEmision().toString();
        const string cae = f->getCAE();
        const string venc = f->getVencimientoCAE().toString();
        const unsigned int itemsCount = f->CantidadItems();

        fprintf(compFile,
                "Factura,%u,\"%s\",\"%s\",%.2f,%u,\"%s\",\"%s\"\n",
                f->getNumero(),
                f->getClienteDNI().c_str(),
                fecha.c_str(),
                f->TotalSinIVA(),
                itemsCount,
                cae.c_str(),
                venc.c_str());

        for(unsigned int j = 0; j < itemsCount; j++) {
            Item* it = f->ObtenerItem(j);
            if(it == nullptr) { continue; }
            const float totalItem = it->getCantidad() * it->getPrecioUnitario();
            Producto* prod = pm[it->getCodigo()];
            string nombreProd = prod ? prod->getDescripcion() : "";
            if (prod) { delete prod; }
            fprintf(itemsFile,
                    "%u,\"%s\",\"%s\",%u,%.2f,%.2f\n",
                    f->getNumero(),
                    it->getCodigo().c_str(),
                    nombreProd.c_str(),
                    it->getCantidad(),
                    it->getPrecioUnitario(),
                    totalItem);
        }

        delete f;
    }

    fclose(compFile);
    fclose(itemsFile);

    Informational ok("Exportar Ventas", "Se exportaron facturas a " + comprobantesPath + " y sus items a " + itemsPath + ".");
    ok.Show();
    return true;
}