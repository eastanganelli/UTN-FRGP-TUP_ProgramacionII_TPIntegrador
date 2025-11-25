#include "condicioniva_manager.h"

CondicionIVAManager::CondicionIVAManager(const string& condicion_ivaPath)
    : FileSystem<CondicionIVA>(condicion_ivaPath) { }

CondicionIVAManager::~CondicionIVAManager() { }

bool CondicionIVAManager::Existe(CondicionIVA& condicion_iva) {
    const unsigned int cantidad = this->Count();
    unsigned int i = 0;
    while(i < cantidad) {
        CondicionIVA* aux = this->At(i);
        if(*aux == condicion_iva) {
            return true;
        }
        i++;
    }
    return false;
}

unsigned int CondicionIVAManager::Cantidad() {
    return this->Count();
}

bool CondicionIVAManager::Modificar(unsigned int codigo, CondicionIVA* condicion_iva) {
    unsigned int index = 0;
    if(!this->IndexOf(*condicion_iva, index)) {
        Error mi_error("Modificacion de Condicion IVA", "Condicion IVA con codigo " + to_string(codigo) + " no encontrada.");
        mi_error.Show();
        return false;
    }
    return this->Update(index, *condicion_iva);
}

void CondicionIVAManager::ListarPorDescripcion() {
    GenericArray<CondicionIVA> condicion_ivas = this->Listar();
    if(condicion_ivas.Size() == 0) {
        Warning mi_warning("Listado de Condiciones IVA", "No se encontraron condiciones IVA para mostrar.");
        mi_warning.Show();
        return;
    }
    for(unsigned int i = 0; i < condicion_ivas.Size(); i++) {
        for(unsigned int j = i + 1; j < condicion_ivas.Size(); j++) {
            if(condicion_ivas[i]->getDescripcion() > condicion_ivas[j]->getDescripcion()) {
                condicion_ivas.Swap(condicion_ivas[i], condicion_ivas[j]);
            }
        }
    }
    CondicionIVAManager::Imprimir(condicion_ivas);
}

void CondicionIVAManager::ListarPorPorcentaje() {
    GenericArray<CondicionIVA> condicion_ivas = this->Listar();
    if(condicion_ivas.Size() == 0) {
        Warning mi_warning("Listado de Condiciones IVA", "No se encontraron condiciones IVA para mostrar.");
        mi_warning.Show();
        return;
    }
    for(unsigned int i = 0; i < condicion_ivas.Size(); i++) {
        for(unsigned int j = i + 1; j < condicion_ivas.Size(); j++) {
            if(condicion_ivas[i]->getPorcentaje() > condicion_ivas[j]->getPorcentaje()) {
                condicion_ivas.Swap(condicion_ivas[i], condicion_ivas[j]);
            }
        }
    }
    CondicionIVAManager::Imprimir(condicion_ivas);
}

CondicionIVA* CondicionIVAManager::operator[](unsigned int codigo) {
    CondicionIVA* condicion_iva = this->At(codigo);
    if(condicion_iva == nullptr || condicion_iva->IsEmpty()) {
        Warning mi_warning("Busqueda de Condicion IVA", "No se encontro condicion IVA con codigo " + to_string(codigo) + ".");
        mi_warning.Show();
        return nullptr;
    }
    return condicion_iva;
}

GenericArray<CondicionIVA> CondicionIVAManager::PorcentajeMayorA(float minimo) {
    GenericArray<CondicionIVA> resultados;
    const unsigned int cantidad = this->Count();
    if(cantidad == 0) {
        Warning mi_warning("Busqueda de Condiciones IVA", "No hay condiciones IVA registradas.");
        mi_warning.Show();
        return resultados;
    }
    for(unsigned int i = 0; i < cantidad; i++) {
        CondicionIVA* aux = this->At(i);
        if(aux->getPorcentaje() > minimo) {
            resultados + (*aux);
        }
        delete aux;
    }
    if(resultados.Size() == 0) {
        Warning mi_warning("Busqueda de Condiciones IVA", "No se encontraron condiciones IVA con porcentaje mayor a " + to_string(minimo) + "%.");
        mi_warning.Show();
    }
    return resultados;
}