#ifndef NOTADECREDITOMANAGER_H
#define NOTADECREDITOMANAGER_H

#include "../../rlutil.h"
#include "../main_classes/ventas/nota_de_credito.h"
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

    void ListarPorCliente();
    void ListarPorFecha();
    GenericArray<NotaDeCredito> BuscarPorCliente(string clienteDNI);
    GenericArray<NotaDeCredito> BuscarPorMotivo(string motivo);
    GenericArray<NotaDeCredito> BuscarPorRangoFecha(Fecha fechaInicio, Fecha fechaFin);

    static void Imprimir(GenericArray<NotaDeCredito>& notas);
};

#endif // NOTADECREDITOMANAGER_H
