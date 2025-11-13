#include "Menu.h"

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

void Menu::menuSub(string titulo) {
    int opcionSub;
   const string archivoCliente = "Clientes.dat",
   archivoFactura  = "Facturas.dat",
   archivoNotasDeCredito = "NotasDeCreditos.dat",
   archivoProveedor = "Proveedores.dat",
   archivoProducto = "Productos.dat";

        ClienteManager clientesManager(archivoCliente);
        VentaManager ventasManager(archivoFactura, archivoNotasDeCredito);
        ProveedorManager proveedoresManager(archivoProveedor);
        ProductoManager productosManager(archivoProducto);

        do {
           if (titulo == "MENU CLIENTES") {
                opcionSub = renderClientesLC();
                if (opcionSub == 1) {
                  string nombreClienteCrear, apellidoClienteCrear, DNIClienteCrear, cuilCuitClienteCrear, direccionClienteCrear, correoClienteCrear, telefonoClienteCrear, celularClienteCrear;
                  unsigned int codigoRazonSocial;
                  bool alta;
                  cout << "Ingrese el nombre del cliente: "; cin >> nombreClienteCrear;
                  cout << "Ingrese el apellido del cliente: "; cin >> apellidoClienteCrear;
                  cout << "Ingrese el DNI del cliente: "; cin >> DNIClienteCrear;
                  cout << "Ingrese el CUIL/CUIT del cliente: "; cin >> cuilCuitClienteCrear;
                  cout << "Ingrese la direccion del cliente: "; cin >> direccionClienteCrear;
                  cout << "Ingrese el correo del cliente: "; cin >> correoClienteCrear;
                  cout << "Ingrese el telefono del cliente: "; cin >> telefonoClienteCrear;
                  cout << "Ingrese el celular del cliente: "; cin >> celularClienteCrear;
                  cout << "Ingrese el codigo razon social: "; cin >> codigoRazonSocial;
                  cout << "¿Alta? (1=Si, 0=No): "; cin >> alta;
                  Cliente nuevo(nombreClienteCrear, apellidoClienteCrear, DNIClienteCrear, cuilCuitClienteCrear, direccionClienteCrear, correoClienteCrear, telefonoClienteCrear, celularClienteCrear, codigoRazonSocial, alta);
                  if(clientesManager.Crear(nuevo)) cout << "Cliente creado exitosamente." << endl;
                  else cout << "Error: El cliente ya existe o hubo un problema." << endl;
                  system("pause");
                }
                if (opcionSub == 2) {
                 string dniEliminar;
                 cout << "Ingrese el DNI del cliente a eliminar: ";
                 cin >> dniEliminar;
                 if (clientesManager.Eliminar(dniEliminar)) cout << "Cliente eliminado exitosamente." << endl;
                 else cout << "Error: Cliente no encontrado o no se pudo eliminar." << endl;
                 system("pause");
                }
                if (opcionSub == 3) {
                 string dniModificar;
                 cout << "Ingrese el DNI del cliente a modificar: ";
                 cin >> dniModificar;
                 Cliente* actual = clientesManager.Obtener(dniModificar);
                 if (actual == nullptr) {
                     cout << "Error: Cliente no encontrado." << endl;
                     system("pause");
                 } else {
                     string nombre, apellido, cuilCuit, direccion, correo, telefono, celular;
                     unsigned int codigoRazonSocial;
                     bool alta;
                     cout << "Ingrese nuevo nombre: "; cin >> nombre;
                     cout << "Ingrese nuevo apellido: "; cin >> apellido;
                     cout << "Ingrese nuevo CUIL/CUIT: "; cin >> cuilCuit;
                     cout << "Ingrese nueva direccion: "; cin >> direccion;
                     cout << "Ingrese nuevo correo: "; cin >> correo;
                     cout << "Ingrese nuevo telefono: "; cin >> telefono;
                     cout << "Ingrese nuevo celular: "; cin >> celular;
                     cout << "Ingrese nuevo codigo razon social: "; cin >> codigoRazonSocial;
                     cout << "¿Alta? (1=Si, 0=No): "; cin >> alta;
                     Cliente modificado(nombre, apellido, dniModificar, cuilCuit, direccion, correo, telefono, celular, codigoRazonSocial, alta);
                     if (clientesManager.Modificar(dniModificar, modificado)) cout << "Cliente modificado exitosamente." << endl;
                     else cout << "Error al modificar el cliente." << endl;
                     system("pause");
                 }
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
                ventasManager.ListarXFecha();
            }
            if(opcionSub == 5) {
                ventasManager.ListarXCAE();
            }
            if(opcionSub == 6) {
                ventasManager.ListarXCliente();
            }
            if(opcionSub == 7) {
                string dniClienteVenta;
                cout << "Ingrese el DNI del cliente: ";
                cin >> dniClienteVenta;
                ventasManager.ConsultaXCliente(dniClienteVenta);
            }
            if(opcionSub == 8) {
                string caeVenta;
                cout << "Ingrese el CAE: ";
                cin >> caeVenta;
                ventasManager.ConsultaXCAE(caeVenta);
            }
            if(opcionSub == 9) {
                char tipoComprobanteVenta;
                cout << "Ingrese el tipo de comprobante: ";
                cin >> tipoComprobanteVenta;
                ventasManager.ConsultaXTipoDeComprobante(tipoComprobanteVenta);
            }
            if(opcionSub == 10) {
                //Fecha fechaInicioVenta;
                //Fecha fechaFinVenta;
                //cout << "Ingrese la fecha de inicio: ";
                //cin >> fechaInicioVenta;
                //cout << "Ingrese la fecha de fin: ";
                //cin >> fechaFinVenta;
                //ventasManager.ConsultaXRangoDeFechas(fechaInicioVenta, fechaFinVenta);
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
                    string codigoProductoCrear, codigoProveedorCrear, descripcionProductoCrear;
                    float precioProductoCrear;
                    unsigned int stockProductoCrear;
                    cout << "Ingrese código: "; cin >> codigoProductoCrear;
                    cout << "Ingrese código proveedor: "; cin >> codigoProveedorCrear;
                    cout << "Ingrese descripción: "; cin >> descripcionProductoCrear;
                    cout << "Ingrese precio: "; cin >> precioProductoCrear;
                    cout << "Ingrese stock: "; cin >> stockProductoCrear;
                    Producto nuevo(codigoProductoCrear, codigoProveedorCrear, descripcionProductoCrear, precioProductoCrear, stockProductoCrear);
                    if(productosManager.Crear(nuevo)) cout << "Producto creado exitosamente." << endl;
                    else cout << "Error al crear producto." << endl;
                    system("pause");
                }
                if (opcionSub == 2) {
                    string codigoProductoEliminar;
                    cout << "Ingrese código del producto a eliminar: "; cin >> codigoProductoEliminar;
                    if(productosManager.Eliminar(codigoProductoEliminar)) cout << "Producto eliminado exitosamente." << endl;
                    else cout << "Error al eliminar producto." << endl;
                    system("pause");
                }
                if (opcionSub == 3) {
                    string codigoProductoModificar;
                    cout << "Ingrese código del producto a modificar: "; cin >> codigoProductoModificar;
                    Producto* actual = productosManager.Obtener(codigoProductoModificar);
                    if(actual == nullptr) {
                        cout << "Producto no encontrado." << endl;
                        system("pause");
                    } else {
                        string codigoProveedorModificar, descripcionProductoModificar;
                        float precioProductoModificar;
                        unsigned int stockProductoModificar;
                        cout << "Ingrese nuevo código proveedor: "; cin >> codigoProveedorModificar;
                        cout << "Ingrese nueva descripción: "; cin >> descripcionProductoModificar;
                        cout << "Ingrese nuevo precio: "; cin >> precioProductoModificar;
                        cout << "Ingrese nuevo stock: "; cin >> stockProductoModificar;
                        Producto modificado(codigoProductoModificar, codigoProveedorModificar, descripcionProductoModificar, precioProductoModificar, stockProductoModificar);
                        if(productosManager.Modificar(codigoProductoModificar, modificado)) cout << "Producto modificado exitosamente." << endl;
                        else cout << "Error al modificar producto." << endl;
                        system("pause");
                    }
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

int Menu::mostrarSubmenu(string titulo) {
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

int Menu::centeredOffset(string text, int width) {
    int w = width - 4;
    int pad = (w - static_cast<int>(text.size())) / 2;
    return std::max(0, pad);
}

void Menu::drawHeader(string title, int startY) {
    using rlutil::locate;
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

void Menu::drawSectionTitle(string text, int y) {
    using rlutil::locate;
    locate(MARGIN_X, y);
    cout << string(HEADER_WIDTH, '=') << endl;
    locate(MARGIN_X + 2, y + 1);
    cout << text << endl;
    locate(MARGIN_X, y + 2);
    cout << string(HEADER_WIDTH, '=') << endl;
}

void Menu::printOption(int y, int index, string label) {
    using rlutil::locate; using std::cout; using std::endl;
    rlutil::locate(MARGIN_X + 2, y);
    cout << "[" << index << "] " << label << endl;
}

int Menu::readIntAtPrompt(int y, string prompt) {
    using rlutil::locate; using std::cout; using std::cin; using std::endl;
    rlutil::locate(MARGIN_X + 2, y);
    cout << prompt;
    int v; cin >> v;
    return v;
}

int Menu::renderClientesLC() {
    rlutil::cls();
    rlutil::hidecursor();
    drawHeader("MENU CLIENTES");

    int y = 6;
    printOption(y++, 1, "Crear");
    printOption(y++, 2, "Eliminar");
    printOption(y++, 3, "Modificar");

    y++; rlutil::locate(MARGIN_X, y++); cout << string(HEADER_WIDTH, '=') << endl;
    rlutil::locate(MARGIN_X + 2, y++); cout << "LISTADOS" << endl; y++;
    printOption(y++, 4, "Listado de clientes - Ordenado por apellido");
    printOption(y++, 5, "Listado de clientes - Ordenado por DNI");
    printOption(y++, 6, "Listado de clientes - Ordenado por CUIL/CUIT");

    y++; rlutil::locate(MARGIN_X, y++); cout << string(HEADER_WIDTH, '=') << endl;
    rlutil::locate(MARGIN_X + 2, y++); cout << "CONSULTAS" << endl; y++;
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

int Menu::renderVentasLC() {
    rlutil::cls(); rlutil::hidecursor(); drawHeader("MENU VENTAS");
    int y = 6;
    printOption(y++, 1, "Crear");
    printOption(y++, 2, "Eliminar");
    printOption(y++, 3, "Modificar");

    y++;
    rlutil::locate(MARGIN_X, y++);
    cout << string(HEADER_WIDTH, '=') << endl;

    rlutil::locate(MARGIN_X + 2, y++); cout << "LISTADOS" << endl; y++;
    printOption(y++, 4, "Listado de ventas - Ordenado por fecha de venta");
    printOption(y++, 5, "Listado de ventas - Ordenado por CAE");
    printOption(y++, 6, "Listado de ventas - Ordenado por cliente");

    y++;
    rlutil::locate(MARGIN_X, y++);
    cout << string(HEADER_WIDTH, '=') << endl;
    rlutil::locate(MARGIN_X + 2, y++);
    cout << "CONSULTAS" << endl; y++;
    printOption(y++, 7, "Consulta de ventas - Por cliente");
    printOption(y++, 8, "Consulta de ventas - Por CAE");
    printOption(y++, 9, "Consulta de ventas - Por tipo de comprobante");
    printOption(y++, 10, "Consulta de ventas - Por rango de fechas");

    y++;
    rlutil::locate(MARGIN_X, y++);
    cout << string(HEADER_WIDTH, '=') << endl;
    printOption(y++, 0, "Volver");

    y += 2; rlutil::showcursor();
    int op = readIntAtPrompt(y);
    rlutil::cls();
    return op;
}

int Menu::renderProveedoresLC() {
    rlutil::cls();
    rlutil::hidecursor();
    drawHeader("MENU PROVEEDORES");
    int y = 6;
    printOption(y++, 1, "Crear");
    printOption(y++, 2, "Eliminar");
    printOption(y++, 3, "Modificar");

    y++; rlutil::locate(MARGIN_X, y++);
    cout << string(HEADER_WIDTH, '=') << endl;

    rlutil::locate(MARGIN_X + 2, y++);
    cout << "LISTADOS" << endl; y++;
    printOption(y++, 4, "Listado de proveedores - Ordenado por Nombre");
    printOption(y++, 5, "Listado de proveedores - Ordenado por CUIL");
    printOption(y++, 6, "Listado de proveedores - Ordenado por Rubro");

    y++; rlutil::locate(MARGIN_X, y++);
    cout << string(HEADER_WIDTH, '=') << endl;
    rlutil::locate(MARGIN_X + 2, y++);
    cout << "CONSULTAS" << endl; y++;
    printOption(y++, 7, "Consulta de proveedores - Por CUIL");
    printOption(y++, 8, "Consulta de proveedores - Por Nombre");
    printOption(y++, 9, "Consulta de proveedores - Por Rubro");
    printOption(y++, 10, "Consulta de proveedores - Por Alta");
    printOption(y++, 11, "Consulta de Responsables Inscripto - Por Nombre");

    y++; rlutil::locate(MARGIN_X, y++);
    cout << string(HEADER_WIDTH, '=') << endl;
    printOption(y++, 0, "Volver");

    y += 2; rlutil::showcursor();
    int op = readIntAtPrompt(y);
    rlutil::cls();
    return op;
}

int Menu::renderProductosLC() {
    rlutil::cls();
    rlutil::hidecursor();
    drawHeader("MENU PRODUCTOS");
    int y = 6;
    printOption(y++, 1, "Crear");
    printOption(y++, 2, "Eliminar");
    printOption(y++, 3, "Modificar");

    y++; rlutil::locate(MARGIN_X, y++);
    cout << string(HEADER_WIDTH, '=') << endl;

    rlutil::locate(MARGIN_X + 2, y++);
    cout << "LISTADOS" << endl; y++;
    printOption(y++, 4, "Listado de productos - Ordenado por Codigo");
    printOption(y++, 5, "Listado de productos - Ordenado por Precio");
    printOption(y++, 6, "Listado de productos - Ordenado por Stock");

    y++; rlutil::locate(MARGIN_X, y++);
    cout << string(HEADER_WIDTH, '=') << endl;
    rlutil::locate(MARGIN_X + 2, y++);
    cout << "CONSULTAS" << endl; y++;
    printOption(y++, 7, "Consulta de productos - Por Codigo");
    printOption(y++, 8, "Consulta de productos - Por Descripcion");
    printOption(y++, 9, "Consulta de productos - Por Stock");

    y++; rlutil::locate(MARGIN_X, y++);
    cout << string(HEADER_WIDTH, '=') << endl;
    printOption(y++, 0, "Volver");

    y += 2; rlutil::showcursor();
    int op = readIntAtPrompt(y);
    rlutil::cls();
    return op;
}

int Menu::renderExtrasLC() {
    rlutil::cls();
    rlutil::hidecursor();
    drawHeader("MENU EXTRAS");

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

int Menu::renderConfiguracionesLC() {
    rlutil::cls();
    rlutil::hidecursor();
    drawHeader("MENU CONFIGURACIONES");
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

int Menu::renderModelosCopiaSeguridad(string ruta) {
    rlutil::cls();
    rlutil::hidecursor();
    drawHeader("MODELO DE RESTAURACION DE COPIAS DE SEGURIDAD");

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

int Menu::renderModelosRestaurarCopiaSeguridad(string ruta) {
    rlutil::cls();
    rlutil::hidecursor();
    drawHeader("MODELO DE RESTAURACION DE COPIAS DE SEGURIDAD");

    int y = 6;
    rlutil::locate(MARGIN_X + 2, y++);
    cout << "Que datos desea restaurar?" << endl; y++;
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

int Menu::renderModelosExportarCSV(string ruta) {
    rlutil::cls();
    rlutil::hidecursor();
    drawHeader("MODELO DE EXPORTACION A CSV");

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
