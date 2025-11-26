#include "tiporesponsables_manager.h"

TipoResponsableManager::TipoResponsableManager(const string& condicion_ivaPath)
    : FileSystem<TipoResponsable>(condicion_ivaPath) { }

TipoResponsableManager::~TipoResponsableManager() { }

GenericArray<TipoResponsable> TipoResponsableManager::Listar() {
    GenericArray<TipoResponsable> condicion_ivas;
    const unsigned int cantidad = this->Count();
    for(unsigned int i = 0; i < cantidad; i++) {
        TipoResponsable* aux = this->At(i);
        condicion_ivas + (*aux);
        delete aux;
    }
    return condicion_ivas;
}

bool TipoResponsableManager::Existe(TipoResponsable& condicion_iva) {
    const unsigned int cantidad = this->Count();
    unsigned int i = 0;
    while(i < cantidad) {
        TipoResponsable* aux = this->At(i);
        if(*aux == condicion_iva) {
            return true;
        }
        i++;
    }
    return false;
}

unsigned int TipoResponsableManager::Cantidad() {
    return this->Count();
}

bool TipoResponsableManager::Modificar(unsigned int codigo, TipoResponsable* condicion_iva) {
    unsigned int index = 0;
    if(!this->IndexOf(*condicion_iva, index)) {
        Error mi_error("Modificacion de Condicion IVA", "Condicion IVA con codigo " + to_string(codigo) + " no encontrada.");
        mi_error.Show();
        return false;
    }
    return this->Update(index, *condicion_iva);
}

void TipoResponsableManager::ListarPorDescripcion() {
    GenericArray<TipoResponsable> condicion_ivas = this->Listar();
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
    TipoResponsableManager::Imprimir(condicion_ivas);
}

void TipoResponsableManager::ListarPorPorcentaje() {
    GenericArray<TipoResponsable> condicion_ivas = this->Listar();
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
    TipoResponsableManager::Imprimir(condicion_ivas);
}

TipoResponsable* TipoResponsableManager::operator[](unsigned int codigo) {
    TipoResponsable* condicion_iva = this->At(codigo);
    if(condicion_iva == nullptr || condicion_iva->IsEmpty()) {
        Warning mi_warning("Busqueda de Condicion IVA", "No se encontro condicion IVA con codigo " + to_string(codigo) + ".");
        mi_warning.Show();
        return nullptr;
    }
    return condicion_iva;
}

GenericArray<TipoResponsable> TipoResponsableManager::PorcentajeMayorA(float minimo) {
    GenericArray<TipoResponsable> resultados;
    const unsigned int cantidad = this->Count();
    if(cantidad == 0) {
        Warning mi_warning("Busqueda de Condiciones IVA", "No hay condiciones IVA registradas.");
        mi_warning.Show();
        return resultados;
    }
    for(unsigned int i = 0; i < cantidad; i++) {
        TipoResponsable* aux = this->At(i);
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

void TipoResponsableManager::ImprimirHeader() {
    rlutil::saveDefaultColor();
    rlutil::setBackgroundColor(rlutil::BLUE);
    rlutil::setColor(rlutil::WHITE);
    printf("%-*s%-*s%-*s%-*s\n",
           TipoResponsable::GetCodigoLength(), "Cod.",
           TipoResponsable::GetDescripcionLength(), "Descripcion",
           TipoResponsable::GetPorcentajeLength(), "IVA %",
           TipoResponsable::GetTipoFacturacionLength(), "Tipo");
    rlutil::resetColor();
}

void TipoResponsableManager::Imprimir(GenericArray<TipoResponsable>& condicion_ivas) {
    for(unsigned int i = 0; i < condicion_ivas.Size(); i++) {
        condicion_ivas[i]->Print();
    }
}

void TipoResponsableManager::Splitter(char Separator) {
    const unsigned int totalLength = TipoResponsable::GetCodigoLength() +
                                        TipoResponsable::GetDescripcionLength() +
                                        TipoResponsable::GetPorcentajeLength() +
                                        TipoResponsable::GetTipoFacturacionLength();
    for(unsigned int i = 0; i < totalLength; i++) {
        printf("%c", Separator);
    }
    printf("\n");
}