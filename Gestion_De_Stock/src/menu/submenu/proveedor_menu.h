#ifndef PROVEEDOR_MENU_H
#define PROVEEDOR_MENU_H

#include "..\menu.h"
#include "..\menu_utils.h"
#include "..\..\manager\manager_proveedor.h"

class ProveedorMenu : public Menu {
private:
    ProveedorManager proveedores;
public:
    ProveedorMenu();
    virtual bool OnSelect(int index) override;
};

#endif // PROVEEDOR_MENU_H
