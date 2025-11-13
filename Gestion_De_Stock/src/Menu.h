#ifndef MENU_H
#define MENU_H

#include <string>

class Menu {
public:
    // Muestra el menú principal
    void mostrar();

private:
    // Función genérica para mostrar un submenú de cualquier sección
    void menuSub(const std::string &titulo);

    // Muestra el submenú genérico y devuelve la opción elegida
    int mostrarSubmenu(const std::string &titulo);
};

#endif // MENU_H
