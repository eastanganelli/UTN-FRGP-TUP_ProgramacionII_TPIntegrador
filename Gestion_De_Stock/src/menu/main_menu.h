#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "menu.h"
#include "../controller/data_generator.h"
#include "submenu/factura_menu.h"
#include "submenu/cliente_menu.h"
#include "submenu/producto_menu.h"
#include "submenu/proveedor_menu.h"
#include "submenu/tipo_responsable_menu.h"
#include "submenu/nota_de_credito_menu.h"
#include "submenu/venta_menu.h"

class MainMenu : public Menu {
public:
    MainMenu();
    virtual void OnSelect(int index) override;
};

#endif // MAIN_MENU_H
