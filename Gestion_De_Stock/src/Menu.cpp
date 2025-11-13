    #include "Menu.h"
    #include <iostream>
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

        int renderClientesLC() {
            rlutil::cls();
            rlutil::hidecursor();
            drawHeader("MENU CLIENTES");

            int y = 6;
            rlutil::locate(MARGIN_X + 2, y++); cout << "LISTADOS" << endl; y++;
            printOption(y++, 1, "Listado de clientes - Ordenado por apellido");
            printOption(y++, 2, "Listado de clientes - Ordenado por DNI");
            printOption(y++, 3, "Listado de clientes - Ordenado por CUIL/CUIT");

            y++; rlutil::locate(MARGIN_X, y++); cout << string(HEADER_WIDTH, '=') << endl;
            rlutil::locate(MARGIN_X + 2, y++); cout << "CONSULTAS" << endl; y++;
            printOption(y++, 4, "Consulta de clientes - Por DNI");
            printOption(y++, 5, "Consulta de clientes - Por CUIL/CUIT");
            printOption(y++, 6, "Consulta de clientes - Por nombre y apellido");
            printOption(y++, 7, "Consulta de clientes - Por correo");

            y++; rlutil::locate(MARGIN_X, y++); cout << string(HEADER_WIDTH, '=') << endl;
            printOption(y++, 0, "Volver");

            y += 2; rlutil::showcursor();
            int op = readIntAtPrompt(y);
            rlutil::cls();
            return op;
        }

        int renderVentasLC() {
            rlutil::cls(); rlutil::hidecursor(); drawHeader("MENU VENTAS");
            int y = 6;
            rlutil::locate(MARGIN_X + 2, y++); cout << "LISTADOS" << endl; y++;
            printOption(y++, 1, "Listado de ventas - Ordenado por fecha de venta");
            printOption(y++, 2, "Listado de ventas - Ordenado por CAE");
            printOption(y++, 3, "Listado de ventas - Ordenado por cliente");

            y++; rlutil::locate(MARGIN_X, y++); cout << string(HEADER_WIDTH, '=') << endl;
            rlutil::locate(MARGIN_X + 2, y++); cout << "CONSULTAS" << endl; y++;
            printOption(y++, 4, "Consulta de ventas - Por cliente");
            printOption(y++, 5, "Consulta de ventas - Por CAE");
            printOption(y++, 6, "Consulta de ventas - Por tipo de comprobante");
            printOption(y++, 7, "Consulta de ventas - Por rango de fechas");

            y++; rlutil::locate(MARGIN_X, y++); cout << string(HEADER_WIDTH, '=') << endl;
            printOption(y++, 0, "Volver");

            y += 2; rlutil::showcursor();
            int op = readIntAtPrompt(y);
            rlutil::cls();
            return op;
        }

        int renderProveedoresLC() {
            rlutil::cls(); rlutil::hidecursor(); drawHeader("MENU PROVEEDORES");
            int y = 6;
            rlutil::locate(MARGIN_X + 2, y++); cout << "LISTADOS" << endl; y++;
            printOption(y++, 1, "Listado de proveedores - Ordenado por Nombre");
            printOption(y++, 2, "Listado de proveedores - Ordenado por CUIL");
            printOption(y++, 3, "Listado de proveedores - Ordenado por Rubro");

            y++; rlutil::locate(MARGIN_X, y++); cout << string(HEADER_WIDTH, '=') << endl;
            rlutil::locate(MARGIN_X + 2, y++); cout << "CONSULTAS" << endl; y++;
            printOption(y++, 4, "Consulta de proveedores - Por CUIL");
            printOption(y++, 5, "Consulta de proveedores - Por Nombre");
            printOption(y++, 6, "Consulta de proveedores - Por Rubro");
            printOption(y++, 7, "Consulta de proveedores - Por Alta");
            printOption(y++, 8, "Consulta de Responsables Inscripto - Por Nombre");

            y++; rlutil::locate(MARGIN_X, y++); cout << string(HEADER_WIDTH, '=') << endl;
            printOption(y++, 0, "Volver");

            y += 2; rlutil::showcursor();
            int op = readIntAtPrompt(y);
            rlutil::cls();
            return op;
        }

        int renderProductosLC() {
            rlutil::cls(); rlutil::hidecursor(); drawHeader("MENU PRODUCTOS");
            int y = 6;
            rlutil::locate(MARGIN_X + 2, y++); cout << "LISTADOS" << endl; y++;
            printOption(y++, 1, "Listado de productos - Ordenado por Nombre");
            printOption(y++, 2, "Listado de productos - Ordenado por Precio");
            printOption(y++, 3, "Listado de productos - Ordenado por Stock");

            y++; rlutil::locate(MARGIN_X, y++); cout << string(HEADER_WIDTH, '=') << endl;
            rlutil::locate(MARGIN_X + 2, y++); cout << "CONSULTAS" << endl; y++;
            printOption(y++, 4, "Consulta de productos - Por Nombre");
            printOption(y++, 5, "Consulta de productos - Por Descripcion");
            printOption(y++, 6, "Consulta de productos - Por Stock");

            y++; rlutil::locate(MARGIN_X, y++); cout << string(HEADER_WIDTH, '=') << endl;
            printOption(y++, 0, "Volver");

            y += 2; rlutil::showcursor();
            int op = readIntAtPrompt(y);
            rlutil::cls();
            return op;
        }

        int renderExtrasLC() {
            rlutil::cls(); rlutil::hidecursor(); drawHeader("MENU EXTRAS");
            int y = 6;
            rlutil::locate(MARGIN_X + 2, y++); cout << "Informacion extra" << endl; y++;
            printOption(y++, 1, "Informe de recaudacion trimestral");
            printOption(y++, 2, "Informe de recaudacion anual");
            printOption(y++, 3, "Listado de los 10 productos mas vendidos y recaudacion");
            printOption(y++, 4, "Listado de las 5 fechas con mas ventas y cantidad vendida");
            printOption(y++, 5, "Consultar cliente que mas compras realizo en el año");

            y++; rlutil::locate(MARGIN_X, y++); cout << string(HEADER_WIDTH, '=') << endl;
            printOption(y++, 0, "Volver");

            y += 2; rlutil::showcursor();
            int op = readIntAtPrompt(y);
            rlutil::cls();
            return op;
        }

        int renderConfiguracionesLC() {
            rlutil::cls(); rlutil::hidecursor(); drawHeader("MENU CONFIGURACIONES");
            int y = 6;
            printOption(y++, 1, "Crear copia de seguridad");
            printOption(y++, 2, "Restaurar copia de seguridad");
            printOption(y++, 3, "Exportar datos a CSV");

            y++; rlutil::locate(MARGIN_X, y++); cout << string(HEADER_WIDTH, '=') << endl;
            printOption(y++, 0, "Volver");

            y += 2; rlutil::showcursor();
            int op = readIntAtPrompt(y);
            rlutil::cls();
            return op;
        }

        int renderModelosCopiaSeguridad(string ruta) {
            rlutil::cls(); rlutil::hidecursor(); drawHeader("MODELO DE RESTAURACION DE COPIAS DE SEGURIDAD");

            int y = 6;
            rlutil::locate(MARGIN_X + 2, y++); cout << "Que datos desea copiar?" << endl; y++;
            printOption(y++, 1, "Clientes");
            printOption(y++, 2, "Ventas");
            printOption(y++, 3, "Proveedores");
            printOption(y++, 4, "Productos");
            printOption(y++, 5, "Realizar copia completa de todo");

            y++; rlutil::locate(MARGIN_X, y++); cout << string(HEADER_WIDTH, '=') << endl;
            printOption(y++, 0, "Volver al menu de configuraciones");

            y += 2; rlutil::showcursor();
            int op = readIntAtPrompt(y);
            rlutil::cls();
            return op;
        }

        int renderModelosRestaurarCopiaSeguridad(string ruta) {
            rlutil::cls(); rlutil::hidecursor(); drawHeader("MODELO DE RESTAURACION DE COPIAS DE SEGURIDAD");

            int y = 6;
            rlutil::locate(MARGIN_X + 2, y++); cout << "Que datos desea restaurar?" << endl; y++;
            printOption(y++, 1, "Clientes");
            printOption(y++, 2, "Ventas");
            printOption(y++, 3, "Proveedores");
            printOption(y++, 4, "Productos");
            printOption(y++, 5, "Realizar copia completa de todo");

            y++; rlutil::locate(MARGIN_X, y++); cout << string(HEADER_WIDTH, '=') << endl;
            printOption(y++, 0, "Volver al menu de configuraciones");

            y += 2; rlutil::showcursor();
            int op = readIntAtPrompt(y);
            rlutil::cls();
            return op;
        }

        int renderModelosExportarCSV(string ruta) {
            rlutil::cls(); rlutil::hidecursor(); drawHeader("MODELO DE EXPORTACION A CSV");

            int y = 6;
            rlutil::locate(MARGIN_X + 2, y++); cout << "Seleccione los datos que desea exportar" << endl; y++;
            printOption(y++, 1, "Exportar Clientes");
            printOption(y++, 2, "Exportar Ventas");
            printOption(y++, 3, "Exportar Proveedores");
            printOption(y++, 4, "Exportar Productos");
            printOption(y++, 5, "Exportar todos los datos");

            y++; rlutil::locate(MARGIN_X, y++); cout << string(HEADER_WIDTH, '=') << endl;
            printOption(y++, 0, "Volver al menu de configuraciones");

            y += 2; rlutil::showcursor();
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
            printOption(y++, 5, "Extras");
            printOption(y++, 6, "Configuraciones");
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
                case 5: menuSub("EXTRAS"); rlutil::cls(); break;
                case 6: menuSub("CONFIGURACIONES"); rlutil::cls(); break;
                case 0: rlutil::cls(); break;
                default: cout << "Opcion invalida" << endl; break;
            }

        } while (opcion != 0);
    }


    void Menu::menuSub(const string &titulo) {
        int opcionSub;

        do {
            if (titulo == "MENU CLIENTES") {
                opcionSub = renderClientesLC();

            } else if (titulo == "MENU VENTAS") {
                opcionSub = renderVentasLC();

            } else if (titulo == "MENU PROVEEDORES") {
                opcionSub = renderProveedoresLC();

            } else if (titulo == "MENU PRODUCTOS") {
                opcionSub = renderProductosLC();

            } else if (titulo == "EXTRAS") {
                opcionSub = renderExtrasLC();

            } else if (titulo == "CONFIGURACIONES") {
                while (true) {
                    int cfg = renderConfiguracionesLC();
                    if (cfg == 0) {
                        opcionSub = 0;
                        break;
                    }
                    if (cfg == 1) {
                        int r = renderModelosCopiaSeguridad("./data");
                    } else if (cfg == 2) {
                        int r = renderModelosRestaurarCopiaSeguridad("./data");
                    } else if (cfg == 3) {
                        int r = renderModelosExportarCSV("./data");
                    }
                }

            } else {
                opcionSub = 0;
            }

            if (titulo != "CONFIGURACIONES") {
                if (opcionSub == 0) break;
                cout << "Seleccionaste opcion: " << opcionSub << endl;
                rlutil::anykey();
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
