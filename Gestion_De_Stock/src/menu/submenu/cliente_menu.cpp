#include "cliente_menu.h"
#include <iostream>

using namespace std;

ClienteMenu::ClienteMenu() : Menu("Menu Clientes", true) {
    AddOption("Listar todos los clientes");
    AddOption("Buscar por DNI");
    AddOption("Volver");
}

void ClienteMenu::OnSelect(int index) {
    switch(index) {
        case 0: {
            auto lista = clientes.Listar();
            ClienteManager::Imprimir(lista);
            PauseConsole();
            break;
        }
        case 1: {
            string dni = InputBox("DNI: ");
            auto res = clientes.BuscarPorDNI(dni);
            ClienteManager::Imprimir(res);
            PauseConsole();
            break;
        }
        default:
            break;
    }
}
