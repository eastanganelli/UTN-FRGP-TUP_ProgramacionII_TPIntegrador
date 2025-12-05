#ifndef TIPORESPONSABLEMANAGER_H
#define TIPORESPONSABLEMANAGER_H

#include "../../rlutil.h"
#include "../main_classes/tipo_responsable.h"
#include "../controller/generic_array.h"
#include "../file_manager/file_system.h"

#include "../controller/modals.h"
#include "../controller/table/table.h"

using namespace std;

class TipoResponsableManager : public FileSystem<TipoResponsable> {
private:
    GenericArray<TipoResponsable> Listar();
    bool Existe(string c);
    bool Indice(string c, unsigned int& index);
    bool Existe(TipoResponsable& condicion_iva);

public:
    TipoResponsableManager(const string& condicion_ivaPath = "tipo_responsable.dat");
    ~TipoResponsableManager();

    bool Agregar(TipoResponsable& condicion_iva);
    bool Modificar(string codigo, TipoResponsable* condicion_iva);
    bool Eliminar(string codigo);
    TipoResponsable* operator[](string codigo);
    GenericArray<TipoResponsable> PorcentajeMayorA(float minimo);
    unsigned int Cantidad();

    void ListarPorDescripcion();
    void ListarPorPorcentaje();

    static void Imprimir(GenericArray<TipoResponsable>& condicion_ivas);
};

#endif // TIPORESPONSABLEMANAGER_H
