#include "Menu.h"
#include <iostream>

using namespace std;

const int SEC_CLIENTES = 1;
const int SEC_VENTAS = 2;
const int SEC_PROVEEDORES = 3;
const int SEC_PRODUCTOS = 4;

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
            case SEC_CLIENTES:    menuSub(SEC_CLIENTES,    "MENU CLIENTES");    break;
            case SEC_VENTAS:      menuSub(SEC_VENTAS,      "MENU VENTAS");      break;
            case SEC_PROVEEDORES: menuSub(SEC_PROVEEDORES, "MENU PROVEEDORES"); break;
            case SEC_PRODUCTOS:   menuSub(SEC_PRODUCTOS,   "MENU PRODUCTOS");   break;
            case 0: cout << "Saliendo del programa..." << endl; break;
            default: cout << "Opcion invalida" << endl; break;
        }
        system("cls");
    } while (opcion != 0);
}

void Menu::menuSub(int seccion, const string &titulo) {
    int opcionSub;

    do {
        opcionSub = mostrarSubmenu(titulo);

        switch (opcionSub) {
            case 1: // Alta
                switch (seccion) {
                    case SEC_CLIENTES: {
                        Cliente c; /* leer datos */ clientes.Crear(c);
                        break;
                    }
                    case SEC_PROVEEDORES: {
                        Proveedor p; /* leer datos */ proveedores.Crear(p);
                        break;
                    }
                    case SEC_PRODUCTOS: {
                        Producto pr; /* leer datos */ productos.Crear(pr);
                        break;
                    }
                    case SEC_VENTAS: {
                        // emitir factura/nota
                        // ventas.CrearFactura(...);
                        break;
                    }
                }
                break;

            case 2: // Baja
                switch (seccion) {
                    case SEC_CLIENTES: {
                        string dni; /* leer */ clientes.Eliminar(dni);
                        break;
                    }
                    case SEC_PROVEEDORES: {
                        string cuit; /* leer */ proveedores.Eliminar(cuit);
                        break;
                    }
                    case SEC_PRODUCTOS: {
                        string codigo; /* leer */ productos.Eliminar(codigo);
                        break;
                    }
                    case SEC_VENTAS: {
                        // anular/nota de crédito
                        break;
                    }
                }
                break;

            case 3: // Modificacion
                switch (seccion) {
                    case SEC_CLIENTES: {
                        string dni; /* leer */
                        Cliente actualizado; /* leer */
                        clientes.Modificar(dni, actualizado);
                        break;
                    }
                    case SEC_PROVEEDORES: {
                        string cuit; Proveedor actualizado;
                        proveedores.Modificar(cuit, actualizado);
                        break;
                    }
                    case SEC_PRODUCTOS: {
                        string codigo; Producto actualizado;
                        productos.Modificar(codigo, actualizado);
                        break;
                    }
                    case SEC_VENTAS: {

                        break;
                    }
                }
                break;

            case 4: // Consulta/Listado
                switch (seccion) {
                    case SEC_CLIENTES:
                        clientes.ListarXApellido(); // o Listar()
                        break;
                    case SEC_PROVEEDORES:
                        proveedores.ListarXRazonSocial(); // o Listar()
                        break;
                    case SEC_PRODUCTOS:
                        productos.ListarXCodigo(); // o Listar()
                        break;
                    case SEC_VENTAS:
                        ventas.Listar(); // o filtros por fecha/cliente
                        break;
                }
                break;

            case 0: break;

            default:
                cout << "Opcion invalida" << endl;
                break;
        }

        if (opcionSub != 0) {
            cout << "Presione Enter para volver al submenu...";
            cin.ignore();
            cin.get();
            system("cls");
        }

    } while (opcionSub != 0);
}

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