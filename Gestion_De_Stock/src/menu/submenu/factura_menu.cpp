#include "factura_menu.h"
#include <iostream>

using namespace std;

FacturaMenu::FacturaMenu() : Menu("Menu Facturas", true) {
    AddOption("Listar todas las facturas");
    AddOption("Buscar por cliente");
    AddOption("Volver");
}

void FacturaMenu::OnSelect(int index) {
    switch(index) {
        case 0: {
            auto lista = facturas.Listar();
            FacturaManager::Imprimir(lista);
            PauseConsole();
            break;
        }
        case 1: {
            string dni = InputBox("DNI del cliente: ");
            auto res = facturas.BuscarPorCliente(dni);
            FacturaManager::Imprimir(res);
            PauseConsole();
            break;
        }
        default:
            break;
    }
}
