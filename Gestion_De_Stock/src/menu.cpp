#include "menu.h"
#include <iostream>

using namespace std;

int opcion;

void Menu::mostrar() {
    
    cout << "==========MENU==========" << endl;
    cout << "Seleccionar seccion:" << endl;
    cout << "1. Clientes" << endl;
    cout << "2. Ventas" << endl;
    cout << "3. Proveedores" << endl;
    cout << "4. Productos" << endl;
    cout << "========================" << endl;
    cout << "0. Salir" << endl;

    cout << "Ingrese una opcion: ";
    cin >> opcion;

    switch (opcion) {
        case 1:
            menuClientes();
            break;
        case 2:
            menuVentas();
            break;
        case 3:
            menuProveedores();
            break;
        case 4:
            menuProductos();
            break;
        case 0:
            break;
        default:
            cout << "Opcion invalida" << endl;
            break;
    }
}

void Menu::menuClientes() {
    
    opcion = mostrarSubmenu("MENU CLIENTES");

    switch (opcion) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 0:
            break;
        default:
            cout << "Opcion invalida" << endl;
            break;
    }
}

void Menu::menuVentas() {
    
    opcion = mostrarSubmenu("MENU VENTAS");

    switch (opcion) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 0:
            break;
        default:
            cout << "Opcion invalida" << endl;
            break;
    }
}

void Menu::menuProveedores() {
    
    opcion = mostrarSubmenu("MENU PROVEEDORES");

    switch (opcion) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 0:
            break;
        default:
            cout << "Opcion invalida" << endl;
            break;
    }
}

void Menu::menuProductos() {
    
    opcion = mostrarSubmenu("MENU PRODUCTOS");

    switch (opcion) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 0:
            break;
        default:
            cout << "Opcion invalida" << endl;
            break;
    }
}

int Menu::mostrarSubmenu(const string &titulo) {
    cout << "==========" << titulo << "==========" << endl;
    cout << "Seleccionar seccion:" << endl;
    cout << "1. Alta" << endl;
    cout << "2. Baja" << endl;
    cout << "3. Modificacion" << endl;
    cout << "4. Consulta" << endl;
    cout << "========================" << endl;
    cout << "0. Salir" << endl;
    cout << "Ingrese una opcion: ";
    int op;
    cin >> op;
    return op;
}
