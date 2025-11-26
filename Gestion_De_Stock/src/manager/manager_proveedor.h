#ifndef PROVEEDORMANAGER_H
#define PROVEEDORMANAGER_H

#include "../../rlutil.h"
#include "../main_classes/proveedor.h"
#include "../controller/generic_array.h"
#include "../file_manager/file_system.h"

#include "../controller/modals.h"
#include "../controller/table/table.h"

using namespace std;

class ProveedorManager : public FileSystem<Proveedor> {
private:
    GenericArray<Proveedor> Listar();

public:
    ProveedorManager(const string& proveedorPath = "proveedores.dat");
    ~ProveedorManager();

    bool Modificar(string cuit, Proveedor* proveedor);

    Proveedor* SeleccionarRandom();
    Proveedor* operator[](string cuit);

    void ListarPorNombre();
    void ListarPorRubro();
    void ListarPorCUIT();

    GenericArray<Proveedor> ConsultarPorCUIT(string cuit);
    GenericArray<Proveedor> ConsultarPorNombre(string nombreRazon);
    GenericArray<Proveedor> ConsultarPorRubro(unsigned int rubro);
    GenericArray<Proveedor> ConsultarPorEstado(bool estado);

    unsigned int SeleccionarRubro();
    string getNombreRubro(unsigned int cr);

    static void Imprimir(GenericArray<Proveedor>& proveedores);
};

#endif // PROVEEDORMANAGER_H
