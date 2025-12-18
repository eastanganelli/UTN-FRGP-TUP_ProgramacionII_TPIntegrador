#ifndef NOTADECREDITOMANAGER_H
#define NOTADECREDITOMANAGER_H

#include "../../../rlutil.h"
#include "../../main_classes/ventas/nota_de_credito.h"
#include "../../controller/generic_array.h"
#include "../../file_manager/file_system.h"

#include "../../controller/modals.h"
#include "../../controller/table/table.h"

using namespace std;

class NotaDeCreditoManager : public FileSystem<NotaDeCredito> {
private:
    GenericArray<NotaDeCredito> Listar();
    bool Existe(unsigned int codigo);
    bool Indice(unsigned int codigo, unsigned int& index);

public:
    NotaDeCreditoManager(const string& notasPath = "notas_de_credito.dat");
    ~NotaDeCreditoManager();

    bool ExportCSV(const string& comprobantesPath = "ventas.csv", const string& itemsPath = "ventas_items.csv", bool append = true, bool includeHeader = false);

    bool Agregar(NotaDeCredito& nota);
    bool Modificar(unsigned int numero, NotaDeCredito* nota);
    bool Eliminar(unsigned int numero);
    NotaDeCredito* operator[](unsigned int numero);
    GenericArray<NotaDeCredito> BuscarPorCliente(string clienteDNI);
    GenericArray<NotaDeCredito> BuscarPorMotivo(string motivo);
    GenericArray<NotaDeCredito> BuscarPorRangoFecha(Fecha fechaInicio, Fecha fechaFin);
    unsigned int Cantidad();

    void ListarPorCliente();
    void ListarPorFecha();

    static void Imprimir(GenericArray<NotaDeCredito>& notas);
};

#endif // NOTADECREDITOMANAGER_H
