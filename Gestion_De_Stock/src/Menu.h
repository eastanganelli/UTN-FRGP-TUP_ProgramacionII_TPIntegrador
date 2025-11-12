#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Menu {
public:
    //  Menu principal
    void mostrar();
    
    //  Menus
    void menuClientes();
    void menuVentas();
    void menuProveedores();
    void menuProductos();
private:
    int mostrarSubmenu(const string &titulo);
};

#endif // MENU_H
