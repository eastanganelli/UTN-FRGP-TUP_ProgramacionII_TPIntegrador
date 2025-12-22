#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "menu.h"
#include "../controller/data_generator.h"
#include "submenu.h"

class MainMenu : public Menu {
public:
    /** Construye el menu principal de la aplicacion. */
    MainMenu();
    /** Despacha la opcion seleccionada del menu principal. */
    virtual bool OnSelect(int index) override;
};

#endif // MAIN_MENU_H
