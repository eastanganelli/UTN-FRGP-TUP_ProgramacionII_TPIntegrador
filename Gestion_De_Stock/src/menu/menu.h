#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>

#include "../controller/generic_array.h"
#include "../controller/modals.h"
#include "../../rlutil.h"

using namespace std;

class Menu {
protected:
    string title;
    GenericArray<string> options;
    bool centered;
    int selectedIndex;

    /** Dibuja el encabezado del menu. */
    virtual void DrawHeader();
    /** Dibuja la lista de opciones. */
    virtual void DrawOptions();

public:
    /** Crea un menu con titulo y alineacion opcional. */
    Menu(const std::string& title = "", bool centered = true);
    /** Destructor virtual de menu base. */
    virtual ~Menu();

    /** Agrega una opcion visible al menu. */
    void AddOption(const std::string& opt);
    /** Ejecuta el loop interactivo de seleccion. */
    bool Run();
    /** Maneja la accion de la opcion seleccionada. */
    virtual bool OnSelect(int index) = 0;
};

#endif // MENU_H
