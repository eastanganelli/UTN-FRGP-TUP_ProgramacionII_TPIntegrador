#include "Menu.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include "rlutil.h"

using namespace std;

namespace {
    const int MARGIN_X = 8;
    const int HEADER_WIDTH = 64;

    int centeredOffset(const string &text, int width) {
        int w = width - 4;
        int pad = (w - static_cast<int>(text.size())) / 2;
       return std::max(0, pad);
    }

    void drawHeader(const string &title, int startY = 2) {
        using rlutil::locate; using std::cout; using std::string; using std::endl;
        locate(MARGIN_X, startY);
        cout << string(HEADER_WIDTH, '*');
        int leftPad = centeredOffset(title, HEADER_WIDTH);
        int innerWidth = HEADER_WIDTH - 4;
        int rightPad = std::max(0, innerWidth - leftPad - static_cast<int>(title.size()));
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

    int renderListadosConsultas(const string& titulo,
                            const vector<string>& listados,
                            const vector<string>& consultas) {
    rlutil::cls();
    rlutil::hidecursor();
    drawHeader(titulo);

    int y = 6;
    rlutil::locate(MARGIN_X + 2, y++); cout << "LISTADOS" << endl;
    y++;

    int idx = 1;
    for (const auto& item : listados) {
        printOption(y++, idx++, item);
    }

    y++;
    rlutil::locate(MARGIN_X, y++); cout << string(HEADER_WIDTH, '=') << endl;
    rlutil::locate(MARGIN_X + 2, y++); cout << "CONSULTAS" << endl;
    y++;

    for (const auto& item : consultas) {
        printOption(y++, idx++, item);
    }

    y++;
    rlutil::locate(MARGIN_X, y++); cout << string(HEADER_WIDTH, '=') << endl;
    printOption(y++, 0, "Volver");

    y += 2;
    rlutil::showcursor();
    int op = readIntAtPrompt(y);
    rlutil::cls();
    return op;
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
        if (titulo == "MENU CLIENTES") {
            vector<string> listados = {
                "Listado de clientes - Ordenado por apellido",
                "Listado de clientes - Ordenado por DNI",
                "Listado de clientes - Ordenado por CUIL/CUIT"
            };
            vector<string> consultas = {
                "Consulta de clientes - Por DNI",
                "Consulta de clientes - Por CUIL/CUIT",
                "Consulta de clientes - Por nombre y apellido",
                "Consulta de clientes - Por correo"
            };
            opcionSub = renderListadosConsultas("MENU CLIENTES", listados, consultas);

        } else if (titulo == "MENU VENTAS") {
            vector<string> listados = {
                "Listado de ventas - Ordenado por fecha de venta",
                "Listado de ventas - Ordenado por CAE",
                "Listado de ventas - Ordenado por cliente"
            };
            vector<string> consultas = {
                "Consulta de ventas - Por cliente",
                "Consulta de ventas - Por CAE",
                "Consulta de ventas - Por tipo de comprobante",
                "Consulta de ventas - Por rango de fechas"
            };
            opcionSub = renderListadosConsultas("MENU VENTAS", listados, consultas);

        } else if (titulo == "MENU PROVEEDORES") {
            vector<string> listados = {
                "Listado de proveedores - Ordenado por nombre",
                "Listado de proveedores - Ordenado por CUIL",
                "Listado de proveedores - Ordenado por rubro"
            };
            vector<string> consultas = {
                "Consulta de proveedores - Por CUIL",
                "Consulta de proveedores - Por nombre",
                "Consulta de proveedores - Por rubro",
                "Consulta de proveedores - Por alta",
                "Consulta de Responsables Inscripto - Por nombre"
            };
            opcionSub = renderListadosConsultas("MENU PROVEEDORES", listados, consultas);

        } else if (titulo == "MENU PRODUCTOS") {
            vector<string> listados = {
                "Listado de productos - Ordenado por nombre",
                "Listado de productos - Ordenado por precio",
                "Listado de productos - Ordenado por stock"
            };
            vector<string> consultas = {
                "Consulta de productos - Por nombre",
                "Consulta de productos - Por descripcion",
                "Consulta de productos - Por stock"
            };
            opcionSub = renderListadosConsultas("MENU PRODUCTOS", listados, consultas);

        } else {
            opcionSub = 0;
        }

        if (opcionSub == 0) break;

        cout << "Seleccionaste opcion: " << opcionSub << endl;
        rlutil::anykey();

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
