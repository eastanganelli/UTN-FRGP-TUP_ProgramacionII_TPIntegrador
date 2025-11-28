#ifndef FACTURA_MENU_H
#define FACTURA_MENU_H

#include "..\menu.h"
#include "..\menu_utils.h"
#include "..\..\manager\manager_factura.h"

class FacturaMenu : public Menu {
private:
    FacturaManager facturas;
public:
    FacturaMenu();
    virtual void OnSelect(int index) override;
};

#endif // FACTURA_MENU_H
