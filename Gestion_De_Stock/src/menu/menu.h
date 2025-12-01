#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>

#include "../controller/modals.h"
#include "../../rlutil.h"

class Menu {
protected:
    std::string title;
    std::vector<std::string> options;
    bool centered;
    int selectedIndex;

    virtual void DrawHeader();
    virtual void DrawOptions();

public:
    Menu(const std::string& title = "", bool centered = true);
    virtual ~Menu();

    void AddOption(const std::string& opt);
    void Run();

    // Subclases implementan la acción a realizar al seleccionar una opción
    virtual void OnSelect(int index) = 0;
};

#endif // MENU_H
