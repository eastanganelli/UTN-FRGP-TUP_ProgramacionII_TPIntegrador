#include "producto_menu.h"
#include <iostream>

using namespace std;

ProductoMenu::ProductoMenu() : Menu("Menu Productos", true) {
    AddOption("Agregar Producto");
    AddOption("Modificar Producto");
    AddOption("Eliminar Producto");
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
            Producto nuevo = Producto::NuevoProducto();
            if (productos.Agregar(nuevo))
                cout << "Producto agregado exitosamente." << endl;
            else
                cout << "Error al agregar el producto." << endl;
            PauseConsole();
            return false;
        }
        case 1: {
            string codigo = InputBox("Codigo del producto a modificar: ");
            Producto* prod = productos[codigo];
            if (prod == nullptr) {
                cout << "Producto no encontrado." << endl;
                PauseConsole();
                return false;
            }

            Producto::ModificarProducto(*prod);

            if (productos.Modificar(codigo, prod))
                cout << "Producto modificado exitosamente." << endl;
            else
                cout << "Error al modificar el producto." << endl;
            PauseConsole();
            return false;
        }
        case 2: {
            string codigo = InputBox("Codigo del producto a eliminar: ");
            Producto* prod = productos[codigo];
            if (prod == nullptr) {
                cout << "Producto no encontrado." << endl;
                PauseConsole();
                return false;
            }
            bool confirma = Producto::EliminarProducto(*prod);
            delete prod;
            if (confirma) {
                if (productos.Eliminar(codigo))
                    cout << "Producto eliminado exitosamente." << endl;
                else
                    cout << "Error al eliminar el producto." << endl;
            } else
                cout << "Operacion cancelada." << endl;
            PauseConsole();
            return false;
        }
        case 3: {
            productos.ListarPorCodigo();
            PauseConsole();
            return false;
        }
        case 4: {
            productos.ListarPorPrecio();
            PauseConsole();
            return false;
        }
        case 5: {
            productos.ListarPorStock();
            PauseConsole();
            return false;
        }
        case 6: {
            string codigo = InputBox("Codigo: ");
            auto res = productos.BuscarPorCodigo(codigo);
            ProductoManager::Imprimir(res);
            PauseConsole();
            return false;
        }
        case 7: {
            string descripcion = InputBox("Descripcion: ");
            auto res = productos.BuscarPorDescripcion(descripcion);
            ProductoManager::Imprimir(res);
            PauseConsole();
            return false;
        }
        case 8: {
            unsigned int stockMinimo = InputNumber("Stock Minimo: ");
            auto res = productos.BuscarPorStockMinimo(stockMinimo);
            ProductoManager::Imprimir(res);
            PauseConsole();
            return false;
        }
        case 9: {
            return true;
        }
        default:
            return false;
    }
}
