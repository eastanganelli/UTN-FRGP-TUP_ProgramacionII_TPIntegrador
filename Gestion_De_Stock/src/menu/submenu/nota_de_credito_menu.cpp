#include "nota_de_credito_menu.h"
#include <iostream>

using namespace std;

NotaDeCreditoMenu::NotaDeCreditoMenu() : Menu("Menu Notas de Credito", true) {
    AddOption("Listar todas las notas");
    AddOption("Buscar por cliente");
    AddOption("Volver");
}

void NotaDeCreditoMenu::OnSelect(int index) {
    switch(index) {
        case 0: {
            auto lista = notas.Listar();
            NotaDeCreditoManager::Imprimir(lista);
            PauseConsole();
            break;
        }
        case 1: {
            string dni = InputBox("DNI del cliente: ");
            auto res = notas.BuscarPorCliente(dni);
            NotaDeCreditoManager::Imprimir(res);
            PauseConsole();
            break;
        }
        default:
            break;
    }
}
