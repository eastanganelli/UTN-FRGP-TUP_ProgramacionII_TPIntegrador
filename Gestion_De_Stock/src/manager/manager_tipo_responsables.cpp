#include "manager_tipo_responsables.h"

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

bool TipoResponsableManager::Existe(string codigo) {
    unsigned int index = 0;
    return this->Indice(codigo, index);
}

bool TipoResponsableManager::Indice(string codigo, unsigned int& index) {
    GenericArray<TipoResponsable> condicion_ivas = this->Listar();
    for(unsigned int i = 0; i < condicion_ivas.Size(); i++) {
        if(Validation::IsEqual(condicion_ivas[i]->getCodigo(), codigo)) {
            index = i;
            return true;
        }
    }
    return false;
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

bool TipoResponsableManager::Agregar(TipoResponsable& condicion_iva) {
    if(this->Existe(condicion_iva.getCodigo())) {
        Warning mi_warning("Creacion de Condicion IVA", "La condicion IVA con codigo " + condicion_iva.getCodigo() + " ya existe.");
        mi_warning.Show();
        return false;
    }
    return this->New(condicion_iva);
}

bool TipoResponsableManager::Modificar(string codigo, TipoResponsable* condicion_iva) {
    unsigned int index = 0;
    if(!this->Indice(condicion_iva->getCodigo(), index)) {
        Error mi_error("Modificacion de Condicion IVA", "Condicion IVA con codigo " + codigo + " no encontrada.");
        mi_error.Show();
        return false;
    }
    return this->Update(index, *condicion_iva);
}

bool TipoResponsableManager::Eliminar(string codigo) {
    unsigned int index = 0;
    if(!this->Indice(codigo, index)) {
        Error mi_error("Eliminacion de Condicion IVA", "Condicion IVA con codigo " + codigo + " no encontrada.");
        mi_error.Show();
        return false;
    }
    return this->Delete(index);
}

TipoResponsable* TipoResponsableManager::operator[](string codigo) {
    unsigned int index = 0;
    if(!this->Indice(codigo, index)) {
        Warning mi_warning("Busqueda de Condicion IVA", "Condicion IVA con codigo " + codigo + " no encontrada.");
        mi_warning.Show();
        return nullptr;
    }
    return this->At(index);
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

unsigned int TipoResponsableManager::Cantidad() { return this->Count(); }


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
    mi_header->AddCell("Cod.", TipoResponsable::ColCodigoSize());
    mi_header->AddCell("Tipo Responsable", TipoResponsable::ColDescripcionSize());
    mi_header->AddCell("% IVA", TipoResponsable::ColPorcentajeSize());
    mi_header->AddCell("Tipo", TipoResponsable::ColTipoFacturacion());

    mi_tabla.AddRow(mi_header);

    for(unsigned int i = 0; i < tipo_responsables.Size(); i++) {
        Tabling::Row* mi_fila = new Tabling::Row(columnas);
        mi_fila->AddCell(tipo_responsables[i]->getCodigo(), TipoResponsable::ColCodigoSize());
        mi_fila->AddCell(tipo_responsables[i]->getDescripcion(), TipoResponsable::ColDescripcionSize());

        string porcentaje = Validation::ToFixedDecimal(tipo_responsables[i]->getPorcentaje(), 1);
        mi_fila->AddCell(porcentaje, TipoResponsable::ColPorcentajeSize());

        string tipo = Validation::ToUpper(string(1, tipo_responsables[i]->getTipoFacturacion()));
        mi_fila->AddCell(tipo, TipoResponsable::ColTipoFacturacion());

        mi_tabla.AddRow(mi_fila);
    }
    mi_tabla.Print();
}
