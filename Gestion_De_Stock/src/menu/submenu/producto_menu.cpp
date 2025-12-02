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

void ProductoMenu::OnSelect(int index) {
    rlutil::cls();
    switch(index) {
        case 0: {
            productos.ListarPorCodigo();
            PauseConsole();
            break;
        }
        case 1: {
            productos.ListarPorPrecio();
            PauseConsole();
            break;
        }
        case 2: {
            productos.ListarPorStock();
            PauseConsole();
            break;
        }
        case 3: {
            string codigo = InputBox("Codigo: ");
            auto res = productos.BuscarPorCodigo(codigo);
            ProductoManager::Imprimir(res);
            PauseConsole();
            break;
        }
        case 4: {
            string descripcion = InputBox("Descripcion: ");
            auto res = productos.BuscarPorDescripcion(descripcion);
            ProductoManager::Imprimir(res);
            PauseConsole();
            break;
        }
        case 5: {
            unsigned int stockMinimo = InputNumber("Stock Minimo: ");
            auto res = productos.BuscarPorStockMinimo(stockMinimo);
            ProductoManager::Imprimir(res);
            PauseConsole();
            break;
        }
        default:
            break;
    }
}
