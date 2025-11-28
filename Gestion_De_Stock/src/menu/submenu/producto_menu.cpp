#include "producto_menu.h"
#include <iostream>

using namespace std;

ProductoMenu::ProductoMenu() : Menu("Menu Productos", true) {
    AddOption("Listar todos los productos");
    AddOption("Buscar por codigo");
    AddOption("Volver");
}

void ProductoMenu::OnSelect(int index) {
    switch(index) {
        case 0: {
            auto lista = productos.Listar();
            ProductoManager::Imprimir(lista);
            PauseConsole();
            break;
        }
        case 1: {
            string codigo = InputBox("Codigo: ");
            auto res = productos.BuscarPorCodigo(codigo);
            ProductoManager::Imprimir(res);
            PauseConsole();
            break;
        }
        default:
            break;
    }
}
