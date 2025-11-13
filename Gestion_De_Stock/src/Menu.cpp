#include "Menu.h"
#include <iostream>

using namespace std;

void Menu::mostrar() {
    int opcion;
system("color 1F");

    do {
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
        system("cls");

        switch (opcion) {
            case 1: menuSub("MENU CLIENTES"); break;
            case 2: menuSub("MENU VENTAS"); break;
            case 3: menuSub("MENU PROVEEDORES"); break;
            case 4: menuSub("MENU PRODUCTOS"); break;
            case 0: cout << "Saliendo del programa..." << endl; break;
            default: cout << "Opcion invalida" << endl; break;
        }

        if (opcion != 0) {
            cout << "Presione Enter para volver al menu principal...";
            cin.ignore();
            cin.get();
            system("cls");
        }

    } while (opcion != 0);
}

// Función genérica para todos los submenús
void Menu::menuSub(const string &titulo) {
    int opcionSub;

    do {
        opcionSub = mostrarSubmenu(titulo);

        switch (opcionSub) {
            case 1: /* Alta */ break;
            case 2: /* Baja */ break;
            case 3: /* Modificación */ break;
            case 4: /* Consulta */ break;
            case 0: break; // volver al menú principal
            default: cout << "Opcion invalida" << endl; break;
        }

        if (opcionSub != 0) {
            cout << "Presione Enter para volver al submenu...";
            cin.ignore();
            cin.get();
            system("cls");
        }

    } while (opcionSub != 0);
}

// Muestra el submenú genérico
int Menu::mostrarSubmenu(const string &titulo) {
    int op;
    cout << "==========" << titulo << "==========" << endl;
    cout << "Seleccionar accion:" << endl;
    cout << "1. Alta" << endl;
    cout << "2. Baja" << endl;
    cout << "3. Modificacion" << endl;
    cout << "4. Consulta" << endl;
    cout << "========================" << endl;
    cout << "0. Volver" << endl;
    cout << "Ingrese una opcion: ";
    cin >> op;
    system("cls");
    return op;
}
