#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "menu.h"
#include "../controller/data_generator.h"
#include "submenu.h"

class MainMenu : public Menu {
public:
    MainMenu();
    virtual bool OnSelect(int index) override;
};

#endif // MAIN_MENU_H
