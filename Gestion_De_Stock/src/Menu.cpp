    #include "Menu.h"
    #include "ClientesManager.h"
    #include "VentasManager.h"
    #include "ProveedoresManager.h"
    #include "ProductosManager.h"
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
            printOption(y++, 1, "Crear");
            printOption(y++, 2, "Eliminar");
            printOption(y++, 3, "Modificar");

            y++; rlutil::locate(MARGIN_X, y++); cout << string(HEADER_WIDTH, '=') << endl;

            printOption(y++, 4, "Listado de clientes - Ordenado por apellido");
            printOption(y++, 5, "Listado de clientes - Ordenado por DNI");
            printOption(y++, 6, "Listado de clientes - Ordenado por CUIL/CUIT");
            printOption(y++, 7, "Consulta de clientes - Por DNI");
            printOption(y++, 8, "Consulta de clientes - Por CUIL/CUIT");
            printOption(y++, 9, "Consulta de clientes - Por nombre y apellido");
            printOption(y++, 10, "Consulta de clientes - Por correo");

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
            printOption(y++, 1, "Crear");
            printOption(y++, 2, "Eliminar");
            printOption(y++, 3, "Modificar");

            y++; rlutil::locate(MARGIN_X, y++); cout << string(HEADER_WIDTH, '=') << endl;

            rlutil::locate(MARGIN_X + 2, y++); cout << "LISTADOS" << endl; y++;
            printOption(y++, 4, "Listado de ventas - Ordenado por fecha de venta");
            printOption(y++, 5, "Listado de ventas - Ordenado por CAE");
            printOption(y++, 6, "Listado de ventas - Ordenado por cliente");

            y++; rlutil::locate(MARGIN_X, y++); cout << string(HEADER_WIDTH, '=') << endl;
            rlutil::locate(MARGIN_X + 2, y++); cout << "CONSULTAS" << endl; y++;
            printOption(y++, 7, "Consulta de ventas - Por cliente");
            printOption(y++, 8, "Consulta de ventas - Por CAE");
            printOption(y++, 9, "Consulta de ventas - Por tipo de comprobante");
            printOption(y++, 10, "Consulta de ventas - Por rango de fechas");

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
            printOption(y++, 1, "Crear");
            printOption(y++, 2, "Eliminar");
            printOption(y++, 3, "Modificar");

            y++; rlutil::locate(MARGIN_X, y++); cout << string(HEADER_WIDTH, '=') << endl;

            rlutil::locate(MARGIN_X + 2, y++); cout << "LISTADOS" << endl; y++;
            printOption(y++, 4, "Listado de proveedores - Ordenado por Nombre");
            printOption(y++, 5, "Listado de proveedores - Ordenado por CUIL");
            printOption(y++, 6, "Listado de proveedores - Ordenado por Rubro");

            y++; rlutil::locate(MARGIN_X, y++); cout << string(HEADER_WIDTH, '=') << endl;
            rlutil::locate(MARGIN_X + 2, y++); cout << "CONSULTAS" << endl; y++;
            printOption(y++, 7, "Consulta de proveedores - Por CUIL");
            printOption(y++, 8, "Consulta de proveedores - Por Nombre");
            printOption(y++, 9, "Consulta de proveedores - Por Rubro");
            printOption(y++, 10, "Consulta de proveedores - Por Alta");
            printOption(y++, 11, "Consulta de Responsables Inscripto - Por Nombre");

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
            printOption(y++, 1, "Crear");
            printOption(y++, 2, "Eliminar");
            printOption(y++, 3, "Modificar");

            y++; rlutil::locate(MARGIN_X, y++); cout << string(HEADER_WIDTH, '=') << endl;

            rlutil::locate(MARGIN_X + 2, y++); cout << "LISTADOS" << endl; y++;
            printOption(y++, 4, "Listado de productos - Ordenado por Codigo");
            printOption(y++, 5, "Listado de productos - Ordenado por Precio");
            printOption(y++, 6, "Listado de productos - Ordenado por Stock");

            y++; rlutil::locate(MARGIN_X, y++); cout << string(HEADER_WIDTH, '=') << endl;
            rlutil::locate(MARGIN_X + 2, y++); cout << "CONSULTAS" << endl; y++;
            printOption(y++, 7, "Consulta de productos - Por Codigo");
            printOption(y++, 8, "Consulta de productos - Por Descripcion");
            printOption(y++, 9, "Consulta de productos - Por Stock");

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

        ClienteManager clientesManager("clientes.bin");
        VentaManager ventasManager("facturas.dat", "notascredito.dat");
        ProveedorManager proveedoresManager("proveedores.bin");
        ProductoManager productosManager("productos.bin");
    //agreegar si no encuentra archivo
    //revisar si existe registro en los delete, en el update y create
        do {
           if (titulo == "MENU CLIENTES") {
                opcionSub = renderClientesLC();
                if (opcionSub == 1) {
                  //  clientesManager.Crear();
                }
                if (opcionSub == 2) {
                  //  clientesManager.Eliminar();
                }
                if (opcionSub == 3) {
                  //  clientesManager.Modificar();
                }
                if (opcionSub == 4) {
                    clientesManager.ListarXApellido();
                }
                if (opcionSub == 5) {
                    clientesManager.ListarXDNI();
                }
                if (opcionSub == 6) {
                    clientesManager.ListarXcuilcuit();
                }
                if (opcionSub == 7) {
                    string dniCliente;
                    cout << "Ingrese el DNI del cliente: ";
                    cin >> dniCliente;
                    clientesManager.ConsultaXDNI(dniCliente);
                }
                if (opcionSub == 8) {
                    string cuilCuitCliente;
                    cout << "Ingrese el CUIL/CUIT del cliente: ";
                    cin >> cuilCuitCliente;
                    clientesManager.ConsultaXCUILCuit(cuilCuitCliente);
                }
                if (opcionSub == 9) {
                    string nombreCliente;
                    string apellidoCliente;
                    cout << "Ingrese el nombre del cliente: ";
                    cin >> nombreCliente;
                    cout << "Ingrese el apellido del cliente: ";
                    cin >> apellidoCliente;
                    clientesManager.ConsultaXNombreApellido(nombreCliente, apellidoCliente);
                }
                if (opcionSub == 10) {
                    string correoCliente;
                    cout << "Ingrese el correo del cliente: ";
                    cin >> correoCliente;
                    clientesManager.ConsultaXCorreo(correoCliente);
                }

                rlutil::cls();
            } else if (titulo == "MENU VENTAS") {
                opcionSub = renderVentasLC();
                if(opcionSub == 1) {
                  //  ventasManager.Crear();
                }
                if(opcionSub == 2) {
                  //  ventasManager.Eliminar();
                }
                if(opcionSub == 3) {
                  //  ventasManager.Modificar();
                }
                if(opcionSub == 4) {

                }
                if(opcionSub == 5) {

                }
                if(opcionSub == 6) {

                }
                if(opcionSub == 7) {

                }
                if(opcionSub == 8) {

                }
                if(opcionSub == 9) {

                }
                if(opcionSub == 10) {

                }

            } else if (titulo == "MENU PROVEEDORES") {
                opcionSub = renderProveedoresLC();
                if(opcionSub == 1) {
                  //  proveedoresManager.Crear();
                }
                if(opcionSub == 2) {
                  //  proveedoresManager.Eliminar();
                }
                if(opcionSub == 3) {
                  //  proveedoresManager.Modificar();
                }
                if(opcionSub == 4) {
                    proveedoresManager.ListarXNombre();
                }
                if(opcionSub == 5) {
                    proveedoresManager.ListarXCUIT();
                }
                if(opcionSub == 6) {
                    proveedoresManager.ListarXRubro();
                }
                if(opcionSub == 7) {
                    string cuitProveedor;
                    cout << "Ingrese el CUIT del proveedor: ";
                    cin >> cuitProveedor;
                    proveedoresManager.ConsultarXCUIT(cuitProveedor);
                }
                if(opcionSub == 8) {
                    string nombreProveedor;
                    cout << "Ingrese el nombre del proveedor: ";
                    cin >> nombreProveedor;
                    proveedoresManager.ConsultarXNombre(nombreProveedor);
                }
                if(opcionSub == 9) {
                    int rubroProveedor;
                    cout << "Ingrese el rubro del proveedor: ";
                    cin >> rubroProveedor;
                    proveedoresManager.ConsultarXRubro(rubroProveedor);
                }
                if(opcionSub == 10) {
                    bool estadoProveedor;
                    cout << "Ingrese el estado del proveedor: ";
                    cin >> estadoProveedor;
                    proveedoresManager.ConsultarXEstado(estadoProveedor);
                }
                if(opcionSub == 11) {
                    proveedoresManager.Contar();
                }

            } else if (titulo == "MENU PRODUCTOS") {
                opcionSub = renderProductosLC();
                if (opcionSub == 1) {
                  //  productosManager.Crear();
                }
                if (opcionSub == 2) {
                  //  productosManager.Eliminar();
                }
                if (opcionSub == 3) {
                  //  productosManager.Modificacion();
                }
                if (opcionSub == 4) {
                    productosManager.ListarXCodigo();
                }
                if (opcionSub == 5) {
                    productosManager.ListarXPrecio();
                }
                if (opcionSub == 6) {
                    productosManager.ListarXStock();
                }
                if (opcionSub == 7) {
                    string codigoProducto;
                    cout << "Ingrese el codigo del producto: ";
                    cin >> codigoProducto;
                    productosManager.ConsultaXCodigo(codigoProducto);
                }
                if (opcionSub == 8) {
                    string descripcionProducto;
                    cout << "Ingrese la descripcion del producto: ";
                    cin >> descripcionProducto;
                    productosManager.ConsultaXDescripcion(descripcionProducto);
                }
                if (opcionSub == 9) {
                    int stockMinimoProducto;
                    cout << "Ingrese el stock minimo del producto: ";
                    cin >> stockMinimoProducto;
                    productosManager.ConsultaXStockMinimo(stockMinimoProducto);
                }
            } else if (titulo == "EXTRAS") {
                opcionSub = renderExtrasLC();
                if(opcionSub == 1) {
                
                }
                if(opcionSub == 2) {

                }
                if(opcionSub == 3) {

                }
                if(opcionSub == 4) {

                }
                if(opcionSub == 5) {

                }
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
        y++;
        rlutil::locate(MARGIN_X, y++); cout << string(HEADER_WIDTH, '=') << endl;
        printOption(y++, 0, "Volver");
        y += 2;
        rlutil::showcursor();
        int op = readIntAtPrompt(y);
        rlutil::cls();
        return op;
    }
