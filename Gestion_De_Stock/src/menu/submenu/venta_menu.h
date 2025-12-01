#ifndef VENTA_MENU_H
#define VENTA_MENU_H

#include "..\menu.h"
#include "..\menu_utils.h"
#include "..\..\manager\manager_ventas.h"

class VentaMenu : public Menu {
private:
    VentaManager ventas;
public:
    VentaMenu();
    virtual void OnSelect(int index) override;
};

#endif // VENTA_MENU_H
