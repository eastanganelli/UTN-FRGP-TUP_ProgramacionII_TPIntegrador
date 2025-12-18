#ifndef FACTURAMANAGER_H
#define FACTURAMANAGER_H

#include "../../../rlutil.h"
#include "../../main_classes/ventas/factura.h"
#include "../../controller/generic_array.h"
#include "../../file_manager/file_system.h"

#include "../../controller/modals.h"
#include "../../controller/table/table.h"

using namespace std;

class FacturaManager : public FileSystem<Factura> {
private:
    GenericArray<Factura> Listar();
    bool Existe(unsigned int codigo);
    bool Indice(unsigned int codigo, unsigned int& index);

public:
    FacturaManager(const string& facturaPath = "facturas.dat");
    ~FacturaManager();

    bool ExportCSV(const string& comprobantesPath = "ventas.csv", const string& itemsPath = "ventas_items.csv", bool append = false, bool includeHeader = true);

    bool Agregar(Factura& factura);
    bool Modificar(unsigned int numero, Factura* factura);
    bool Eliminar(unsigned int numero);
    Factura* operator[](unsigned int numero);
    GenericArray<Factura> BuscarPorCliente(string clienteDNI);
    GenericArray<Factura> BuscarPorCAE(string cae);
    GenericArray<Factura> BuscarPorRangoFecha(Fecha fechaInicio, Fecha fechaFin);

    void ListarPorCliente();
    void ListarPorFecha();
    void ListarPorMonto();

    static void Imprimir(GenericArray<Factura>& facturas);
};

#endif // FACTURAMANAGER_H
