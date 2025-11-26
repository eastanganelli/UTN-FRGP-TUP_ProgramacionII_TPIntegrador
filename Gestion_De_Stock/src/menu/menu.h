#ifndef MENU_H
#define MENU_H

#include <string>
using namespace std;

#include "../../rlutil.h"

class Menu {

public:
    Menu();
    ~Menu();

    virtual void Crear();
    virtual void Mostrar();
    virtual void Modificar();
    virtual void Eliminar();
    virtual void Listar();
};

#endif // MENU_H