#ifndef FACTURAMANAGER_H
#define FACTURAMANAGER_H

#include "../main_classes/por_pasar/Factura.h"
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

    unsigned int Cantidad();
    bool Modificar(unsigned int numero, Factura* factura);
    Factura* operator[](unsigned int numero);

    GenericArray<Factura> BuscarPorCliente(string clienteDNI);
    GenericArray<Factura> BuscarPorItemCodigo(string codigo);

    static void Imprimir(GenericArray<Factura>& facturas);
};

#endif // FACTURAMANAGER_H
