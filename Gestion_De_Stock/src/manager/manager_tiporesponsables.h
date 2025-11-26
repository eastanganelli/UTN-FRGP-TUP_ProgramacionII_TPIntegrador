#ifndef TIPORESPONSABLEMANAGER_H
#define TIPORESPONSABLEMANAGER_H

#include "../main_classes/tipo_responsable.h"
#include "../controller/generic_array.h"
#include "../file_manager/file_system.h"

#include "../controller/modals.h"
#include "../controller/table/table.h"

using namespace std;

class TipoResponsableManager : public FileSystem<TipoResponsable> {
private:
    GenericArray<TipoResponsable> Listar();
    bool Existe(TipoResponsable& condicion_iva);

public:
    TipoResponsableManager(const string& condicion_ivaPath = "tipo_responsable.dat");
    ~TipoResponsableManager();
    unsigned int Cantidad();
    bool Modificar(unsigned int codigo, TipoResponsable* condicion_iva);
    void ListarPorDescripcion();
    void ListarPorPorcentaje();
    TipoResponsable* operator[](unsigned int codigo);
    GenericArray<TipoResponsable> PorcentajeMayorA(float minimo);

    static void ImprimirHeader();
    static void Imprimir(GenericArray<TipoResponsable>& condicion_ivas);
    static void Splitter(char Separator = '-');
};

#endif // TIPORESPONSABLEMANAGER_H
