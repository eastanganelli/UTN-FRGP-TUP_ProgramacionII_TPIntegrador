#ifndef TIPORESPONSABLEMANAGER_H
#define TIPORESPONSABLEMANAGER_H

#include "../main_classes/tipo_responsable.h"
#include "../controller/generic_array.h"
#include "../file_manager/file_system.h"

#include "../controller/modals.h"

using namespace std;

class TipoResponsableManager : public FileSystem<TipoResponsable> {
private:
    GenericArray<TipoResponsable> Listar();
    bool Existe(TipoResponsable& condicion_iva);

public:
    TipoResponsableManager(const string& condicion_ivaPath = "condicion_ivas.dat");
    ~TipoResponsableManager();
    unsigned int Cantidad();
    bool Modificar(unsigned int codigo, TipoResponsable* condicion_iva);
    void ListarPorDescripcion();
    void ListarPorPorcentaje();
    TipoResponsable* operator[](unsigned int codigo);
    GenericArray<TipoResponsable> PorcentajeMayorA(float minimo);

    static void Imprimir(GenericArray<TipoResponsable>& condicion_ivas);
};

#endif // TIPORESPONSABLEMANAGER_H
