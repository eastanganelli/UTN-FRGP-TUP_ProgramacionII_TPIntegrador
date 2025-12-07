#ifndef VENTA_MENU_H
#define VENTA_MENU_H

#include "../menu.h"
#include "../menu_utils.h"
#include "../../manager/ventas/manager_ventas.h"

class VentaMenu : public Menu {
private:
    VentaManager ventas;
public:
    VentaMenu();
    virtual bool OnSelect(int index) override;
};

#endif // VENTA_MENU_H
