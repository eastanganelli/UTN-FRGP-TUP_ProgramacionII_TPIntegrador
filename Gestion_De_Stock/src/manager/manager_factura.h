#ifndef FACTURAMANAGER_H
#define FACTURAMANAGER_H

#include "../../rlutil.h"
#include "../main_classes/ventas/factura.h"
#include "../controller/generic_array.h"
#include "../file_manager/file_system.h"

#include "../controller/modals.h"
#include "../controller/table/table.h"

using namespace std;

class FacturaManager : public FileSystem<Factura> {
private:
    GenericArray<Factura> Listar();

public:
    FacturaManager(const string& facturaPath = "facturas.dat");
    ~FacturaManager();

    bool Modificar(unsigned int numero, Factura* factura);
    Factura* operator[](unsigned int numero);

    void ListarPorCliente();
    void ListarPorFecha();
    void ListarPorMonto();
    GenericArray<Factura> BuscarPorCliente(string clienteDNI);
    GenericArray<Factura> BuscarPorCAE(string cae);
    GenericArray<Factura> BuscarPorRangoFecha(Fecha fechaInicio, Fecha fechaFin);

    static void Imprimir(GenericArray<Factura>& facturas);
};

#endif // FACTURAMANAGER_H