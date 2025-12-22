#ifndef PROVEEDOR_MENU_H
#define PROVEEDOR_MENU_H

#include <iostream>
#include <cstdlib>

using namespace std;

#include "../../controller/modals/error.h"

#include "..\menu.h"
#include "..\menu_utils.h"
#include "..\..\manager\manager_proveedor.h"

class ProveedorMenu : public Menu {
private:
    ProveedorManager proveedores;
    /** Construye un proveedor mediante ingreso interactivo. */
    Proveedor CrearProveedor(bool& ok);
    /** Permite modificar campos del proveedor indicado. */
    void ModificarProveedorInteractivo(Proveedor& proveedor);
    /** Marca como baja un proveedor tras confirmacion. */
    bool EliminarProveedorInteractivo(Proveedor& proveedor);
public:
    /** Inicializa el menu de proveedores. */
    ProveedorMenu();
    /** Ejecuta la opcion elegida del menu de proveedores. */
    virtual bool OnSelect(int index) override;
};

#endif // PROVEEDOR_MENU_H
