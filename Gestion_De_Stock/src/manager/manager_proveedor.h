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
    bool Existe(string codigo);
    bool Indice(string codigo, unsigned int& index);

public:
    ProveedorManager(const string& proveedorPath = "proveedores.dat");
    ~ProveedorManager();

    bool Agregar(Proveedor& proveedor);
    bool Modificar(string cuit, Proveedor* proveedor);
    bool Eliminar(string cuit);
    Proveedor* operator[](string cuit);
    GenericArray<Proveedor> ConsultarPorCUIT(string cuit);
    GenericArray<Proveedor> ConsultarPorNombre(string nombreRazon);
    GenericArray<Proveedor> ConsultarPorRubro(unsigned int rubro);
    GenericArray<Proveedor> ConsultarPorEstado(bool estado);

    unsigned int SeleccionarRubro();
    string getNombreRubro(unsigned int cr);

    void ListarPorNombre();
    void ListarPorRubro();
    void ListarPorCUIT();

    static void Imprimir(GenericArray<Proveedor>& proveedores);
};

#endif // PROVEEDORMANAGER_H
