#ifndef CLIENTEMANAGER_H
#define CLIENTEMANAGER_H

#include "../main_classes/condicion_iva.h"
#include "../controller/generic_array.h"
#include "../file_manager/file_system.h"

#include "../controller/modals.h"

using namespace std;

class CondicionIVAManager : public FileSystem<CondicionIVA> {
private:
    GenericArray<CondicionIVA> Listar();
    bool Existe(CondicionIVA& condicion_iva);

public:
    CondicionIVAManager(const string& condicion_ivaPath = "condicion_ivas.dat");
    ~CondicionIVAManager();
    unsigned int Cantidad();
    bool Modificar(unsigned int codigo, CondicionIVA* condicion_iva);
    void ListarPorDescripcion();
    void ListarPorPorcentaje();
    CondicionIVA* operator[](unsigned int codigo);
    GenericArray<CondicionIVA> PorcentajeMayorA(float minimo);

    static void Imprimir(GenericArray<CondicionIVA>& condicion_ivas);
};

#endif // CLIENTEMANAGER_H
