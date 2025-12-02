#include "proveedor_menu.h"
#include <iostream>

using namespace std;

ProveedorMenu::ProveedorMenu() : Menu("Menu Proveedores", true) {
    AddOption("Listar por Nombre o Razon Social");
    AddOption("Buscar por Rubro");
    AddOption("Listar por CUIT");
    AddOption("Buscar por CUIT");
    AddOption("Buscar por Nombre o Razon Social");
    AddOption("Buscar por Rubro");
    AddOption("Buscar por Estado");
    AddOption("Volver");
}

bool ProveedorMenu::OnSelect(int index) {
    rlutil::cls();
    switch(index) {
        case 0: {
            proveedores.ListarPorNombre();
            PauseConsole();
            return false;
        }
        case 1: {
            proveedores.ListarPorRubro();
            PauseConsole();
            return false;
        }
        case 2: {
            proveedores.ListarPorCUIT();
            PauseConsole();
            return false;
        }
        case 3: {
            string cuit = InputBox("CUIT: ");
            auto res = proveedores.ConsultarPorCUIT(cuit);
            ProveedorManager::Imprimir(res);
            PauseConsole();
            return false;
        }
        case 4: {
            string nombre = InputBox("Nombre o Razon Social: ");
            auto res = proveedores.ConsultarPorNombre(nombre);
            ProveedorManager::Imprimir(res);
            PauseConsole();
            return false;
        }
        case 5: {
            unsigned int rubro = proveedores.SeleccionarRubro();
            auto res = proveedores.ConsultarPorRubro(rubro);
            ProveedorManager::Imprimir(res);
            PauseConsole();
            return false;
        }
        case 6: {
            bool estado = Confirm("¿Desea buscar proveedores activos?");
            auto res = proveedores.ConsultarPorEstado(estado);
            ProveedorManager::Imprimir(res);
            PauseConsole();
            return false;
        }
        case 7: {
            return true;
        }
        default:
            return false;
    }
}
