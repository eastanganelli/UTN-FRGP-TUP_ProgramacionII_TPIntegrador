#include "cliente_menu.h"
#include <iostream>

using namespace std;

ClienteMenu::ClienteMenu() : Menu("Menu Clientes", true) {
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
            clientes.ListarPorDNI();
            PauseConsole();
            return false;
        }
        case 1: {
            clientes.ListarPorCuil_Cuit();
            PauseConsole();
            return false;
        }
        case 2: {
            clientes.ListarPorApellido();
            PauseConsole();
            return false;
        }
        case 3: {
            string dni = InputBox("DNI: ");
            auto res = clientes.BuscarPorDNI(dni);
            ClienteManager::Imprimir(res);
            PauseConsole();
            return false;
        }
        case 4: {
            string cuilCuit = InputBox("CUIL/CUIT: ");
            auto res = clientes.BuscarPorCUIL_CUIT(cuilCuit);
            ClienteManager::Imprimir(res);
            PauseConsole();
            return false;
        }
        case 5: {
            string nombre = InputBox("Nombre: ");
            string apellido = InputBox("Apellido: ");
            auto res = clientes.BuscarPorNombreApellido(nombre, apellido);
            ClienteManager::Imprimir(res);
            PauseConsole();
            return false;
        }
        case 6: {
            string correo = InputBox("Correo: ");
            auto res = clientes.BuscarPorCorreo(correo);
            ClienteManager::Imprimir(res);
            PauseConsole();
            return false;
        }
        case 7: {
            return true; // Volver
        }
        default:
            return false;
    }
}
