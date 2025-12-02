#include "producto_menu.h"
#include <iostream>

using namespace std;

ProductoMenu::ProductoMenu() : Menu("Menu Productos", true) {
    AddOption("Listar por Codigo");
    AddOption("Listar por Precio");
    AddOption("Listar por Stock");
    AddOption("Buscar por codigo");
    AddOption("Buscar por descripcion");
    AddOption("Buscar por stock minimo");
    AddOption("Volver");
}

bool ProductoMenu::OnSelect(int index) {
    rlutil::cls();
    switch(index) {
        case 0: {
            productos.ListarPorCodigo();
            PauseConsole();
            return false;
        }
        case 1: {
            productos.ListarPorPrecio();
            PauseConsole();
            return false;
        }
        case 2: {
            productos.ListarPorStock();
            PauseConsole();
            return false;
        }
        case 3: {
            string codigo = InputBox("Codigo: ");
            auto res = productos.BuscarPorCodigo(codigo);
            ProductoManager::Imprimir(res);
            PauseConsole();
            return false;
        }
        case 4: {
            string descripcion = InputBox("Descripcion: ");
            auto res = productos.BuscarPorDescripcion(descripcion);
            ProductoManager::Imprimir(res);
            PauseConsole();
            return false;
        }
        case 5: {
            unsigned int stockMinimo = InputNumber("Stock Minimo: ");
            auto res = productos.BuscarPorStockMinimo(stockMinimo);
            ProductoManager::Imprimir(res);
            PauseConsole();
            return false;
        }
        case 6: {
            return true;
        }
        default:
            return false;
    }
}
