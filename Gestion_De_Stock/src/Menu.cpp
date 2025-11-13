#include "Menu.h"
#include <iostream>
#include <rlutil.h>

using namespace std;

namespace {
    const int MARGIN_X = 8;
    const int HEADER_WIDTH = 64;

    int centeredOffset(const string &text, int width) {
        int w = width - 4;
        int pad = (w - static_cast<int>(text.size())) / 2;
        return max(0, pad);
    }

    void drawHeader(const string &title, int startY = 2) {
        using rlutil::locate; using std::cout; using std::string; using std::endl;
        locate(MARGIN_X, startY);
        cout << string(HEADER_WIDTH, '*');
        int leftPad = centeredOffset(title, HEADER_WIDTH);
        int innerWidth = HEADER_WIDTH - 4;
        int rightPad = max(0, innerWidth - leftPad - static_cast<int>(title.size()));
        locate(MARGIN_X, startY + 1);
        cout << "**" << string(leftPad, ' ') << title << string(rightPad, ' ') << "**";
        locate(MARGIN_X, startY + 2);
        cout << string(HEADER_WIDTH, '*') << endl;
    }

    void drawSectionTitle(const string &text, int y) {
        using rlutil::locate; using std::cout; using std::string; using std::endl;
        locate(MARGIN_X, y);
        cout << string(HEADER_WIDTH, '=') << endl;
        locate(MARGIN_X + 2, y + 1);
        cout << text << endl;
        locate(MARGIN_X, y + 2);
        cout << string(HEADER_WIDTH, '=') << endl;
    }

    void printOption(int y, int index, const string &label) {
        using rlutil::locate; using std::cout; using std::endl;
        rlutil::locate(MARGIN_X + 2, y);
        cout << "[" << index << "] " << label << endl;
    }

    int readIntAtPrompt(int y, const string &prompt = "Ingrese una opcion: ") {
        using rlutil::locate; using std::cout; using std::cin; using std::endl;
        rlutil::locate(MARGIN_X + 2, y);
        cout << prompt;
        int v; cin >> v;
        return v;
    }
}


void Menu::mostrar() {
    int opcion;

    do {
        rlutil::cls();
        rlutil::hidecursor();
        drawHeader("MENU PRINCIPAL");

        int y = 6;
        rlutil::locate(MARGIN_X + 2, y++); cout << "Seleccionar seccion:" << endl;
        y++;
        printOption(y++, 1, "Clientes");
        printOption(y++, 2, "Ventas");
        printOption(y++, 3, "Proveedores");
        printOption(y++, 4, "Productos");
        y++;
        rlutil::locate(MARGIN_X, y++); cout << string(HEADER_WIDTH, '=') << endl;
        printOption(y++, 0, "Salir");
        y += 2;
        rlutil::showcursor();
        opcion = readIntAtPrompt(y);

        rlutil::cls();
        switch (opcion) {
            case 1: menuSub("MENU CLIENTES"); rlutil::cls(); break;
            case 2: menuSub("MENU VENTAS"); rlutil::cls(); break;
            case 3: menuSub("MENU PROVEEDORES"); rlutil::cls(); break;
            case 4: menuSub("MENU PRODUCTOS"); rlutil::cls(); break;
            case 0: rlutil::cls(); break;
            default: cout << "Opcion invalida" << endl; break;
        }

    } while (opcion != 0);
}


void Menu::menuSub(const string &titulo) {
    int opcionSub;

    do {
        opcionSub = mostrarSubmenu(titulo);
        
        if(titulo == "MENU CLIENTES") {
            switch (opcionSub) {
            case 1:
                clientes.alta(); 
                break;
            case 2:
                clientes.baja(); 
                break;
            case 3:
                clientes.modificacion(); 
                break;
            case 4:
                clientes.consulta(); 
                break;
            case 0: 
                break;
            default: cout << "Opcion invalida" << endl; 
            break;
        }
        }
        if(titulo == "MENU VENTAS") {
            switch (opcionSub) {
            case 1:
                ventas.alta(); 
                break;
            case 2:
                ventas.baja(); 
                break;
            case 3:
                ventas.modificacion(); 
                break;
            case 4:
                ventas.consulta(); 
                break;
            case 0: 
                break;
            default: cout << "Opcion invalida" << endl; break;
        }
        }
        if(titulo == "MENU PROVEEDORES") {
            switch (opcionSub) {
            case 1:
                proveedores.alta(); 
                break;
            case 2:
                proveedores.baja(); 
                break;
            case 3:
                proveedores.modificacion(); 
                break;
            case 4:
                proveedores.consulta(); 
                break;
            case 0: 
                break;
            default: cout << "Opcion invalida" << endl; 
            break;
        }
        }
        if(titulo == "MENU PRODUCTOS") {
            switch (opcionSub) {
            case 1:
                productos.alta(); 
                break;
            case 2:
                productos.baja(); 
                break;
            case 3:
                productos.modificacion(); 
                break;
            case 4:
                productos.consulta(); 
                break;
            case 0: 
                break;
            default: cout << "Opcion invalida" << endl; 
            break;
        }
        }

    } while (opcionSub != 0);
}

int Menu::mostrarSubmenu(const string &titulo) {
    rlutil::cls();
    rlutil::hidecursor();
    drawHeader(titulo);

    int y = 6;
    rlutil::locate(MARGIN_X + 2, y++); cout << "Seleccionar accion:" << endl;
    y++;
    printOption(y++, 1, "Alta");
    printOption(y++, 2, "Baja");
    printOption(y++, 3, "Modificacion");
    printOption(y++, 4, "Consulta");
    y++;
    rlutil::locate(MARGIN_X, y++); cout << string(HEADER_WIDTH, '=') << endl;
    printOption(y++, 0, "Volver");
    y += 2;
    rlutil::showcursor();
    int op = readIntAtPrompt(y);
    rlutil::cls();
    return op;
}
