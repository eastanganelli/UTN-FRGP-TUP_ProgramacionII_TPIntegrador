#include "manager_nota_de_credito.h"

NotaDeCreditoManager::NotaDeCreditoManager(const string& notasPath)
    : FileSystem<NotaDeCredito>(notasPath) { }

NotaDeCreditoManager::~NotaDeCreditoManager() { }

GenericArray<NotaDeCredito> NotaDeCreditoManager::Listar() {
    GenericArray<NotaDeCredito> notas;
    const unsigned int cantidad = this->Count();
    for(unsigned int i = 0; i < cantidad; i++) {
        NotaDeCredito* aux = this->At(i);
        notas + (*aux);
        delete aux;
    }
    return notas;
}

bool NotaDeCreditoManager::Existe(unsigned int codigo) {
    unsigned int index;
    return this->Indice(codigo, index);
}

bool NotaDeCreditoManager::Indice(unsigned int codigo, unsigned int& index) {
    GenericArray<NotaDeCredito> notas = this->Listar();
    for(unsigned int i = 0; i < notas.Size(); i++) {
        if(notas[i]->getNumero() == codigo) {
            index = i;
            return true;
        }
    }
    return false;
}

bool NotaDeCreditoManager::Agregar(NotaDeCredito& nota) {
    if(this->Existe(nota.getNumero())) {
        Warning mi_warning("Creacion de Nota de Credito", "Ya existe una nota con numero " + to_string(nota.getNumero()) + ".");
        mi_warning.Show();
        return false;
    }
    return this->New(nota);
}

bool NotaDeCreditoManager::Modificar(unsigned int numero, NotaDeCredito* nota) {
    unsigned int index;
    if(!this->Indice(numero, index)) {
        Error mi_error("Modificacion de Nota de Credito", "No se encontro nota con numero " + to_string(numero) + ".");
        mi_error.Show();
        return false;
    }
    return this->Update(index, *nota);
}

bool NotaDeCreditoManager::Eliminar(unsigned int numero) {
    unsigned int index;
    if(!this->Indice(numero, index)) {
        Error mi_error("Eliminacion de Nota de Credito", "No se encontro nota con numero " + to_string(numero) + ".");
        mi_error.Show();
        return false;
    }
    return this->Delete(index);
}

NotaDeCredito* NotaDeCreditoManager::operator[](unsigned int numero) {
    unsigned int index;
    if(!this->Indice(numero, index)) {
        Warning mi_warning("Busqueda de Nota de Credito", "No se encontro nota con numero " + to_string(numero) + ".");
        mi_warning.Show();
        return nullptr;
    }
    return this->At(index);
}

GenericArray<NotaDeCredito> NotaDeCreditoManager::BuscarPorCliente(string clienteDNI) {
    GenericArray<NotaDeCredito> resultados;
    const unsigned int cantidad = this->Count();
    if(cantidad == 0) {
        Warning mi_warning("Busqueda de Notas", "No hay notas de credito registradas.");
        mi_warning.Show();
        return resultados;
    }
    for(unsigned int i = 0; i < cantidad; i++) {
        NotaDeCredito* aux = this->At(i);
        if(aux->getClienteDNI().find(clienteDNI) != string::npos) {
            resultados + (*aux);
        }
        delete aux;
    }
    if(resultados.Size() == 0) {
        Warning mi_warning("Busqueda de Notas", "No se encontraron notas para el cliente " + clienteDNI + ".");
        mi_warning.Show();
    }
    return resultados;
}

GenericArray<NotaDeCredito> NotaDeCreditoManager::BuscarPorMotivo(string motivo) {
    GenericArray<NotaDeCredito> resultados;
    const unsigned int cantidad = this->Count();
    if(cantidad == 0) {
        Warning mi_warning("Busqueda de Notas", "No hay notas de credito registradas.");
        mi_warning.Show();
        return resultados;
    }
    for(unsigned int i = 0; i < cantidad; i++) {
        NotaDeCredito* aux = this->At(i);
        if(aux->getMotivoAnulacion().find(motivo) != string::npos) {
            resultados + (*aux);
        }
        delete aux;
    }
    if(resultados.Size() == 0) {
        Warning mi_warning("Busqueda de Notas", "No se encontraron notas con motivo que contenga " + motivo + ".");
        mi_warning.Show();
    }
    return resultados;
}

GenericArray<NotaDeCredito> NotaDeCreditoManager::BuscarPorRangoFecha(Fecha fechaInicio, Fecha fechaFin) {
    GenericArray<NotaDeCredito> resultados;
    const unsigned int cantidad = this->Count();
    if(cantidad == 0) {
        Warning mi_warning("Busqueda de Notas", "No hay notas de credito registradas.");
        mi_warning.Show();
        return resultados;
    }
    for(unsigned int i = 0; i < cantidad; i++) {
        NotaDeCredito* aux = this->At(i);
        Fecha fechaNota = aux->getFechaEmision();
        if(fechaNota >= fechaInicio && fechaNota <= fechaFin) {
            resultados + (*aux);
        }
        delete aux;
    }
    if(resultados.Size() == 0) {
        Warning mi_warning("Busqueda de Notas", "No se encontraron notas en el rango de fechas indicado.");
        mi_warning.Show();
    }
    return resultados;
}

unsigned int NotaDeCreditoManager::Cantidad() { return this->Count(); }

void NotaDeCreditoManager::ListarPorCliente() {
    GenericArray<NotaDeCredito> notas = this->Listar();
    if(notas.Size() == 0) {
        Warning mi_warning("Listado de Notas", "No hay notas de credito registradas.");
        mi_warning.Show();
        return;
    }
    Imprimir(notas);
}

void NotaDeCreditoManager::ListarPorFecha() {
    GenericArray<NotaDeCredito> notas = this->Listar();
    if(notas.Size() == 0) {
        Warning mi_warning("Listado de Notas", "No hay notas de credito registradas.");
        mi_warning.Show();
        return;
    }
    for(unsigned int i = 0; i < notas.Size() - 1; i++) {
        for(unsigned int j = 0; j < notas.Size() - i - 1; j++) {
            if(notas[j]->getFechaEmision() > notas[j + 1]->getFechaEmision()) {
                notas.Swap(notas[j], notas[j + 1]);
            }
        }
    }
    Imprimir(notas);
}

void NotaDeCreditoManager::Imprimir(GenericArray<NotaDeCredito>& notas) {
    if(notas.Size() == 0) {
        Warning mi_warning("Listado de Notas", "No se encontraron notas de credito para mostrar.");
        mi_warning.Show();
        return;
    }

    const unsigned int altura = notas.Size(), columnas = 6;
    Tabling::Table mi_tabla(altura, columnas);

    Tabling::Row* header = new Tabling::Row(columnas);
    header->AddCell("ID", 6);
    header->AddCell("Cliente", 9);
    header->AddCell("Fecha", 12);
    header->AddCell("Monto", 10);
    header->AddCell("Items", 6);
    header->AddCell("Motivo", 20);
    mi_tabla.AddRow(header);

    for(unsigned int i = 0; i < altura; i++) {
        Tabling::Row* row = new Tabling::Row(columnas);
        row->AddCell(to_string(notas[i]->getNumero()), 6);
        row->AddCell(notas[i]->getClienteDNI(), 9);
        row->AddCell(notas[i]->getFechaEmision().toString(), 12);
        row->AddCell(to_string(notas[i]->TotalSinIVA()), 10);
        row->AddCell(to_string(notas[i]->CantidadItems()), 6);
        row->AddCell(notas[i]->getMotivoAnulacion(), 20);
        mi_tabla.AddRow(row);
    }
    mi_tabla.Print();
}

bool NotaDeCreditoManager::ExportCSV(const string& comprobantesPath, const string& itemsPath, bool append, bool includeHeader) {
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
        NotaDeCredito* n = this->At(i);
        if(n == nullptr) { continue; }

        const string fecha = n->getFechaEmision().toString();
        const unsigned int itemsCount = n->CantidadItems();

        fprintf(compFile,
                "NotaDeCredito,%u,\"%s\",\"%s\",%.2f,%u,\"%s\",\"\"\n",
                n->getNumero(),
                n->getClienteDNI().c_str(),
                fecha.c_str(),
                n->TotalSinIVA(),
                itemsCount,
                n->getMotivoAnulacion().c_str());

        for(unsigned int j = 0; j < itemsCount; j++) {
            Item* it = n->ObtenerItem(j);
            if(it == nullptr) { continue; }
            const float totalItem = it->getCantidad() * it->getPrecioUnitario();
            Producto* prod = pm[it->getCodigo()];
            string nombreProd = prod ? prod->getDescripcion() : "";
            if (prod) { delete prod; }
            fprintf(itemsFile,
                "%u,\"%s\",\"%s\",%u,%.2f,%.2f\n",
                n->getNumero(),
                it->getCodigo().c_str(),
                nombreProd.c_str(),
                it->getCantidad(),
                it->getPrecioUnitario(),
                totalItem);
        }

        delete n;
    }

    fclose(compFile);
    fclose(itemsFile);

    Informational ok("Exportar Ventas", "Se exportaron notas de credito a " + comprobantesPath + " y sus items a " + itemsPath + ".");
    ok.Show();
    return true;
}
