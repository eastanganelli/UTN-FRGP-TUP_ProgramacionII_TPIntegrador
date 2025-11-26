#include "manager_tiporesponsables.h"
#include <iomanip>

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

void TipoResponsableManager::Imprimir(GenericArray<TipoResponsable>& tipo_responsables) {
    if(tipo_responsables.Size() == 0) {
        Warning mi_warning("Listado de Condiciones IVA", "No se encontraron condiciones IVA para mostrar.");
        mi_warning.Show();
        return;
    }

    const unsigned int altura = tipo_responsables.Size(),
                        columnas = 4;
    Tabling::Table mi_tabla(altura, columnas);

    Tabling::Row* mi_header = new Tabling::Row(4);
    mi_header->AddCell("Cod.", TipoResponsable::GetCodigoLength());
    mi_header->AddCell("Tipo Responsable", TipoResponsable::GetDescripcionLength());
    mi_header->AddCell("% IVA", TipoResponsable::GetPorcentajeLength());
    mi_header->AddCell("Tipo", TipoResponsable::GetTipoFacturacionLength());

    mi_tabla.AddRow(mi_header);

    for(unsigned int i = 0; i < tipo_responsables.Size(); i++) {
        Tabling::Row* mi_fila = new Tabling::Row(columnas);
        mi_fila->AddCell(tipo_responsables[i]->getCodigo(), TipoResponsable::GetCodigoLength());
        mi_fila->AddCell(tipo_responsables[i]->getDescripcion(), TipoResponsable::GetDescripcionLength());

        string porcentaje = Validation::ToFixedDecimal(tipo_responsables[i]->getPorcentaje(), 1);
        mi_fila->AddCell(porcentaje, TipoResponsable::GetPorcentajeLength());

        string tipo = Validation::ToUpper(string(1, tipo_responsables[i]->getTipoFacturacion()));
        mi_fila->AddCell(tipo, TipoResponsable::GetTipoFacturacionLength());

        mi_tabla.AddRow(mi_fila);
    }
    mi_tabla.Print();
}
