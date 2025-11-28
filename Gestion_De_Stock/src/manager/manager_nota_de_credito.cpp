#include "manager_notadecredito.h"

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

unsigned int NotaDeCreditoManager::Cantidad() {
    return this->Count();
}

bool NotaDeCreditoManager::Modificar(unsigned int numero, NotaDeCredito* nota) {
    const unsigned int cantidad = this->Count();
    for(unsigned int i = 0; i < cantidad; i++) {
        NotaDeCredito* aux = this->At(i);
        if(aux != nullptr && aux->getNumero() == numero) {
            unsigned int index = i;
            delete aux;
            return this->Update(index, *nota);
        }
        delete aux;
    }
    Error mi_error("Modificacion de Nota de Credito", "Nota con numero " + to_string(numero) + " no encontrada.");
    mi_error.Show();
    return false;
}

NotaDeCredito* NotaDeCreditoManager::operator[](unsigned int numero) {
    const unsigned int cantidad = this->Count();
    NotaDeCredito* aux = nullptr;
    for(unsigned int i = 0; i < cantidad; i++) {
        aux = this->At(i);
        if(aux != nullptr && aux->getNumero() == numero) {
            break;
        }
        delete aux;
        aux = nullptr;
    }
    if(aux == nullptr) {
        Warning mi_warning("Busqueda de Nota de Credito", "No se encontro nota con numero " + to_string(numero) + ".");
        mi_warning.Show();
    }
    return aux;
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

GenericArray<NotaDeCredito> NotaDeCreditoManager::BuscarPorItemCodigo(string codigo) {
    GenericArray<NotaDeCredito> resultados;
    const unsigned int cantidad = this->Count();
    if(cantidad == 0) {
        Warning mi_warning("Busqueda de Notas", "No hay notas de credito registradas.");
        mi_warning.Show();
        return resultados;
    }
    for(unsigned int i = 0; i < cantidad; i++) {
        NotaDeCredito* aux = this->At(i);
        unsigned int itemsCount = aux->CantidadItems();
        for(unsigned int j = 0; j < itemsCount; j++) {
            const Item* it = aux->ObtenerItem(j);
            if(it != nullptr && it->getCodigo().find(codigo) != string::npos) {
                resultados + (*aux);
                break;
            }
        }
        delete aux;
    }
    if(resultados.Size() == 0) {
        Warning mi_warning("Busqueda de Notas", "No se encontraron notas con items que contengan " + codigo + ".");
        mi_warning.Show();
    }
    return resultados;
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
