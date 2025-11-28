#ifndef NOTADECREDITOMANAGER_H
#define NOTADECREDITOMANAGER_H

#include "../../rlutil.h"
#include "../main_classes/por_pasar/NotaDeCredito.h"
#include "../controller/generic_array.h"
#include "../file_manager/file_system.h"

#include "../controller/modals.h"
#include "../controller/table/table.h"

using namespace std;

class NotaDeCreditoManager : public FileSystem<NotaDeCredito> {
private:
    GenericArray<NotaDeCredito> Listar();

public:
    NotaDeCreditoManager(const string& notasPath = "notas_de_credito.dat");
    ~NotaDeCreditoManager();

    unsigned int Cantidad();
    bool Modificar(unsigned int numero, NotaDeCredito* nota);
    NotaDeCredito* operator[](unsigned int numero);

    GenericArray<NotaDeCredito> BuscarPorCliente(string clienteDNI);
    GenericArray<NotaDeCredito> BuscarPorItemCodigo(string codigo);

    static void Imprimir(GenericArray<NotaDeCredito>& notas);
};

#endif // NOTADECREDITOMANAGER_H
