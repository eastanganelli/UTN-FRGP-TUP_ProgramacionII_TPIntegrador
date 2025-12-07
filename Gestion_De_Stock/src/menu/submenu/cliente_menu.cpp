#include "cliente_menu.h"
#include <iostream>

using namespace std;

ClienteMenu::ClienteMenu() : Menu("Menu Clientes", true) {
    AddOption("Agregar Cliente");
    AddOption("Modificar Cliente");
    AddOption("Eliminar Cliente");
    AddOption("Listar Por DNI");
    AddOption("Listar Por CUIL/CUIT");
    AddOption("Listar Por Apellido");
    AddOption("Buscar por DNI");
    AddOption("Buscar por CUIL/CUIT");
    AddOption("Buscar por Nombre y Apellido");
    AddOption("Buscar por Correo");
    AddOption("Volver");
}

bool ClienteMenu::OnSelect(int index) {
    rlutil::cls();
    switch(index) {
        case 0: {
            Cliente nuevoCliente = Cliente::NuevoCliente();
            if(clientes.Agregar(nuevoCliente)) {
                cout << "Cliente agregado exitosamente." << endl;
            } else {
                cout << "Error al agregar el cliente." << endl;
            }
            return false;
        }
        case 1: {
            string dni = InputBox("DNI del cliente a modificar: ");
            Cliente* cliente = clientes[dni];
            if (cliente == nullptr) {
                cout << "Cliente no encontrado." << endl;
                PauseConsole();
                return false;
            }

            Cliente::ModificarCliente(*cliente);

            if (clientes.Modificar(dni, cliente))
                cout << "Cliente modificado exitosamente." << endl;
            else
                cout << "Error al modificar el cliente." << endl;
            PauseConsole();
            return false;
        }
        case 2: {
            string dni = InputBox("DNI del cliente a eliminar: ");
            Cliente* cliente = clientes[dni];
            if (cliente == nullptr) {
                cout << "Cliente no encontrado." << endl;
                PauseConsole();
                return false;
            }
            bool confirma = Cliente::EliminarCliente(*cliente);
            delete cliente;
            if (confirma) {
                if (clientes.Eliminar(dni)) {
                    cout << "Cliente eliminado exitosamente." << endl;
                } else {
                    cout << "Error al eliminar el cliente." << endl;
                }
            } else
                cout << "Error al buscar el cliente para eliminar." << endl;
            PauseConsole();
            return false;
        }
        case 3: {
            clientes.ListarPorDNI();
            PauseConsole();
            return false;
        }
        case 4: {
            clientes.ListarPorCuil_Cuit();
            PauseConsole();
            return false;
        }
        case 5: {
            clientes.ListarPorApellido();
            PauseConsole();
            return false;
        }
        case 6: {
            string dni = InputBox("DNI: ");
            auto res = clientes.BuscarPorDNI(dni);
            ClienteManager::Imprimir(res);
            PauseConsole();
            return false;
        }
        case 7: {
            string cuilCuit = InputBox("CUIL/CUIT: ");
            auto res = clientes.BuscarPorCUIL_CUIT(cuilCuit);
            ClienteManager::Imprimir(res);
            PauseConsole();
            return false;
        }
        case 8: {
            string nombre = InputBox("Nombre: ");
            string apellido = InputBox("Apellido: ");
            auto res = clientes.BuscarPorNombreApellido(nombre, apellido);
            ClienteManager::Imprimir(res);
            PauseConsole();
            return false;
        }
        case 9: {
            string correo = InputBox("Correo: ");
            auto res = clientes.BuscarPorCorreo(correo);
            ClienteManager::Imprimir(res);
            PauseConsole();
            return false;
        }
        case 10: {
            return true; // Volver
        }
        default:
            return false;
    }
}
