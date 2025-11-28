#include "proveedor_menu.h"
#include <iostream>

using namespace std;

ProveedorMenu::ProveedorMenu() : Menu("Menu Proveedores", true) {
    AddOption("Listar todos los proveedores");
    AddOption("Buscar por CUIT");
    AddOption("Volver");
}

void ProveedorMenu::OnSelect(int index) {
    switch(index) {
        case 0: {
            auto lista = proveedores.Listar();
            ProveedorManager::Imprimir(lista);
            PauseConsole();
            break;
        }
        case 1: {
            string cuit = InputBox("CUIT: ");
            auto res = proveedores.ConsultarPorCUIT(cuit);
            ProveedorManager::Imprimir(res);
            PauseConsole();
            break;
        }
        default:
            break;
    }
}
