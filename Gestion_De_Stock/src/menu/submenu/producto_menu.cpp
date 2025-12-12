#include "producto_menu.h"
#include <iostream>
#include <algorithm>

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

Producto ProductoMenu::CrearProducto() {
    Producto producto;
    string v;

    // Descripcion (no vacio, longitud max)
    while (true) {
        v = InputBox("Descripcion: ");
        if (Validation::IsEmpty(v) || v.length() >= Producto::GetDescripcionSize()) {
            Warning w("Descripcion invalida", "Ingrese una descripcion valida y de longitud aceptable.");
            w.Show(); w.WaitForKey();
            continue;
        }
        producto.setDescripcion(v);
        break;
    }

    // Precio (numero float, > 0)
    while (true) {
        v = InputBox("Precio: ");
        float p = 0.0f;
        if (sscanf(v.c_str(), "%f", &p) != 1) { p = 0.0f; }
        if (!Validation::IsPositiveNumber(p) || p < 0.01f || p > 9999.99f) {
            Warning w("Precio invalido", "Ingrese un precio valido (numerico, mayor a 0).");
            w.Show(); w.WaitForKey();
            continue;
        }
        producto.setPrecio(p);
        break;
    }

    // Stock (numero entero >= 0)
    while (true) {
        unsigned int s = InputNumber("Stock inicial: ");
        if (!Validation::IsInRange<unsigned int>(s, 0u, 100000u)) {
            Warning w("Stock invalido", "Ingrese un stock valido (0 - 100000).");
            w.Show(); w.WaitForKey();
            continue;
        }
        producto.setStock(s);
        break;
    }

    return producto;
}

void ProductoMenu::ModificarProductoInteractivo(Producto& producto) {
    unsigned int opcion = 0;
    string entrada;
    do {
        rlutil::cls();
        cout << "-- Modificar Producto (codigo: " << producto.getCodigo() << ") --\n";
        cout << "1) Descripcion: " << producto.getDescripcion() << "\n";
        cout << "2) Precio: " << producto.getPrecio() << "\n";
        cout << "3) Stock: " << producto.getStock() << "\n";
        cout << "4) Terminar\n";

        opcion = InputNumber("Seleccione campo a modificar: ");

        switch(opcion) {
            case 1: {
                while (true) {
                    entrada = InputBox("Nueva Descripcion: ");
                    if (Validation::IsEmpty(entrada) || entrada.length() >= Producto::GetDescripcionSize()) {
                        Warning w("Descripcion invalida", "Ingrese una descripcion valida y de longitud aceptable.");
                        w.Show(); w.WaitForKey();
                        continue;
                    }
                    producto.setDescripcion(entrada);
                    Informational i("Descripcion modificada", "Descripcion actualizada correctamente.");
                    i.Show(); i.WaitForKey();
                    break;
                }
                break;
            }
            case 2: {
                while (true) {
                    entrada = InputNumber("Nuevo Precio: ");
                    float p = 0.0f;
                    if (sscanf(entrada.c_str(), "%f", &p) != 1) { p = 0.0f; }
                    if (!Validation::IsPositiveNumber(p) || p < 0.01f || p > 9999.99f) {
                        Warning w("Precio invalido", "Ingrese un precio valido (numerico, mayor a 0).");
                        w.Show(); w.WaitForKey();
                        continue;
                    }
                    producto.setPrecio(p);
                    Informational i("Precio modificado", "Precio actualizado correctamente.");
                    i.Show(); i.WaitForKey();
                    break;
                }
                break;
            }
            case 3: {
                while (true) {
                    unsigned int s = InputNumber("Nuevo Stock: ");
                    if (!Validation::IsInRange<unsigned int>(s, 0u, 100000u)) {
                        Warning w("Stock invalido", "Ingrese un stock valido (0 - 100000).");
                        w.Show(); w.WaitForKey();
                        continue;
                    }
                    producto.setStock(s);
                    Informational i("Stock modificado", "Stock actualizado correctamente.");
                    i.Show(); i.WaitForKey();
                    break;
                }
                break;
            }
            case 4: {
                break;
            }
            default: {
                Warning w("Opcion invalida", "Seleccione una opcion valida (1-4).");
                w.Show(); w.WaitForKey();
                break;
            }
        }
    } while (opcion != 4);
    rlutil::cls();
}

bool ProductoMenu::EliminarProductoInteractivo(Producto& producto) {
    Warning w("Eliminar Producto", "Esta seguro que desea eliminar este producto?");
    if (w.ShowYesNo()) {
        return true;
    }
    return false;
}

bool ProductoMenu::OnSelect(int index) {
    rlutil::cls();
    switch(index) {
        case 0: {
            Producto nuevo = CrearProducto();
            if (productos.Agregar(nuevo)) cout << "Producto agregado exitosamente." << endl;
            else cout << "Error al agregar el producto." << endl;
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

            ModificarProductoInteractivo(*prod);

            if (productos.Modificar(codigo, prod)) cout << "Producto modificado exitosamente." << endl;
            else cout << "Error al modificar el producto." << endl;
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
            bool confirma = EliminarProductoInteractivo(*prod);
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
