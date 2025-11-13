#ifndef MENU_H
#define MENU_H

#include <string>

class Menu {
public:
    // Muestra el menu principal
    void mostrar();

private:
    // Funcion generica para mostrar un submenu de cualquier seccion
    void menuSub(const std::string &titulo);

    // Muestra el submenu genérico y devuelve la opción elegida
    int mostrarSubmenu(const std::string &titulo);
};

#endif // MENU_H
