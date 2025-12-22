#include "producto_menu.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include "../../controller/modals/error.h"
#include "../../controller/generic_array.h"

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

Producto ProductoMenu::CrearProducto(bool& ok) {
    ok = false;
    rlutil::cls();
    Producto producto;
    string v;

    string cuitProveedor = SeleccionarProveedor();
    if (Validation::IsEmpty(cuitProveedor)) {
        Warning w("Proveedor requerido", "No se selecciono proveedor. Operacion cancelada.");
        w.Show(); w.WaitForKey();
        return producto;
    }
    producto.setCodigoProveedor(cuitProveedor);

    producto.setCodigo(Producto::GenerarCodigo());

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

    ok = true;
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
        cout << "4) Proveedor (CUIT actual: " << producto.getCodigoProveedor() << ")\n";
        cout << "5) Terminar\n";

        opcion = InputNumber("Seleccione campo a modificar: ");

        switch(opcion) {
            case 1: {
                while (true) {
                    entrada = InputBox("Nueva Descripcion: ");
                    if (entrada.empty()) { // mantener valor actual si no se ingresa nada
                        break;
                    }
                    if (Validation::IsEmpty(entrada) || entrada.length() >= Producto::GetDescripcionSize()) {
                        Warning w("Descripcion invalida", "Ingrese una descripcion valida y de longitud aceptable.");
                        w.Show(); w.WaitForKey();
                        continue;
                    }
                    producto.setDescripcion(entrada);
                    Informational i("Descripcion modificada", "Descripcion " + producto.getDescripcion() + " actualizada correctamente.");
                    i.Show(); i.WaitForKey();
                    break;
                }
                break;
            }
            case 2: {
                while (true) {
                    entrada = InputBox("Nuevo Precio (vacio para mantener): ");
                    if (entrada.empty()) { // mantener valor actual
                        break;
                    }
                    float p = 0.0f;
                    if (sscanf(entrada.c_str(), "%f", &p) != 1) { p = 0.0f; }
                    if (!Validation::IsPositiveNumber(p) || p < 0.01f || p > 9999.99f) {
                        Warning w("Precio invalido", "Ingrese un precio valido (numerico, mayor a 0).");
                        w.Show(); w.WaitForKey();
                        continue;
                    }
                    producto.setPrecio(p);
                    Informational i("Precio modificado", "Precio " + producto.getDescripcion() + " actualizado correctamente.");
                    i.Show(); i.WaitForKey();
                    break;
                }
                break;
            }
            case 3: {
                while (true) {
                    entrada = InputBox("Nuevo Stock (vacio para mantener): ");
                    if (entrada.empty()) { // mantener valor actual
                        break;
                    }
                    unsigned int s = 0;
                    if (!Validation::IsNumeric(entrada)) {
                        Warning w("Stock invalido", "Ingrese un stock valido (numero).");
                        w.Show(); w.WaitForKey();
                        continue;
                    }
                    s = static_cast<unsigned int>(std::strtoul(entrada.c_str(), nullptr, 10));
                    if (!Validation::IsInRange<unsigned int>(s, 0u, 100000u)) {
                        Warning w("Stock invalido", "Ingrese un stock valido (0 - 100000).");
                        w.Show(); w.WaitForKey();
                        continue;
                    }
                    producto.setStock(s);
                    Informational i("Stock modificado", "Stock " + producto.getDescripcion() + " actualizado correctamente.");
                    i.Show(); i.WaitForKey();
                    break;
                }
                break;
            }
            case 4: {
                string nuevo = SeleccionarProveedor();
                if (!Validation::IsEmpty(nuevo)) {
                    producto.setCodigoProveedor(nuevo);
                    Informational i("Proveedor actualizado", "Se actualizo el proveedor del producto.");
                    i.Show(); i.WaitForKey();
                }
                break;
            }
            case 5: {
                break;
            }
            default: {
                Warning w("Opcion invalida", "Seleccione una opcion valida (1-5).");
                w.Show(); w.WaitForKey();
                break;
            }
        }
    } while (opcion != 5);
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
            bool ok = false;
            Producto nuevo = CrearProducto(ok);
            if (!ok || Validation::IsEmpty(nuevo.getCodigoProveedor())) {
                return false;
            }
            if (productos.Agregar(nuevo)) {
                Informational i("Producto agregado", "Producto " + nuevo.getCodigo() + " agregado exitosamente.");
                i.Show(); i.WaitForKey();
                PauseConsole();
            } else {
                Error e("Error", "Error al agregar el producto.");
                e.Show(); e.WaitForKey();
            }
            return false;
        }
        case 1: {
            string codigo = SeleccionarProductoCodigo();
            if (codigo.empty()) return false;
            Producto* prod = productos[codigo];
            if (prod == nullptr) {
                Warning w("Producto no encontrado", "No se encontro producto con codigo " + codigo + ".");
                w.Show(); w.WaitForKey();
                return false;
            }

            ModificarProductoInteractivo(*prod);

            if (productos.Modificar(codigo, prod)) {
                Informational i("Producto modificado", "Producto " + codigo + " modificado exitosamente.");
                i.Show(); i.WaitForKey();
                PauseConsole();
            } else {
                Error e("Error", "Error al modificar el producto.");
                e.Show(); e.WaitForKey();
            }
            return false;
        }
        case 2: {
            string codigo = SeleccionarProductoCodigo();
            if (codigo.empty()) return false;
            Producto* prod = productos[codigo];
            if (prod == nullptr) {
                Warning w("Producto no encontrado", "No se encontro producto con codigo " + codigo + ".");
                w.Show(); w.WaitForKey();
                return false;
            }
            bool confirma = EliminarProductoInteractivo(*prod);
            delete prod;
            if (confirma) {
                if (productos.Eliminar(codigo)) {
                    Informational i("Producto eliminado", "Producto " + codigo + " eliminado exitosamente.");
                    i.Show(); i.WaitForKey();
                } else {
                    Error e("Error", "Error al eliminar el producto.");
                    e.Show(); e.WaitForKey();
                }
            } else {
                Informational i("Operacion cancelada", "Operacion de eliminacion cancelada.");
                i.Show(); i.WaitForKey();
            }
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

string ProductoMenu::SeleccionarProveedor() {
    rlutil::cls();
    const unsigned int total = proveedores.Count();
    GenericArray<Proveedor> lista;

    for (unsigned int i = 0; i < total; ++i) {
        Proveedor* p = proveedores.At(i);
        if (p != nullptr) {
            if (p->getAlta()) {
                lista.Append(*p);
            }
            delete p;
        }
    }

    if (lista.Size() == 0) {
        Warning w("Sin proveedores activos", "No hay proveedores dados de alta para seleccionar.");
        w.Show(); w.WaitForKey();
        return "";
    }

    const unsigned int columnas = 4;
    Tabling::Table tabla(lista.Size(), columnas);
    Tabling::Row* header = new Tabling::Row(columnas);
    header->AddCell("Idx", 4);
    header->AddCell("CUIT", Proveedor::ColCuitSize());
    header->AddCell("Nombre/Razon", Proveedor::ColNombreRazonSize());
    header->AddCell("Rubro", 12);
    tabla.AddRow(header);

    for (unsigned int i = 0; i < lista.Size(); ++i) {
        Proveedor* p = lista[i];
        Tabling::Row* fila = new Tabling::Row(columnas);
        fila->AddCell(std::to_string(i), 4);
        fila->AddCell(p->getCuit(), Proveedor::ColCuitSize());
        fila->AddCell(p->getNombreRazon(), Proveedor::ColNombreRazonSize());
        fila->AddCell(p->getRubroNombre(), 12);
        tabla.AddRow(fila);
    }

    int idx = -1;
    while (true) {
        rlutil::cls();
        tabla.Print();
        idx = SelectorIndex(tabla, "Indice de proveedor (vacio para cancelar): ", lista.Size());
        if (idx == -1) return "";
        if (idx < 0) continue;
        return lista[static_cast<unsigned int>(idx)]->getCuit();
    }
}

string ProductoMenu::SeleccionarProductoCodigo() {
    rlutil::cls();
    const unsigned int total = productos.Count();
    GenericArray<Producto> lista;

    for (unsigned int i = 0; i < total; ++i) {
        Producto* p = productos.At(i);
        if (p != nullptr) {
            lista.Append(*p);
            delete p;
        }
    }

    if (lista.Size() == 0) {
        Warning w("Sin productos", "No hay productos cargados para seleccionar.");
        w.Show(); w.WaitForKey();
        return "";
    }

    const unsigned int columnas = 5;
    Tabling::Table tabla(lista.Size(), columnas);
    Tabling::Row* header = new Tabling::Row(columnas);
    header->AddCell("Idx", 4);
    header->AddCell("Codigo", Producto::ColCodigoSize());
    header->AddCell("Descripcion", Producto::ColDescripcionSize());
    header->AddCell("Precio", Producto::ColPrecioSize());
    header->AddCell("Stock", Producto::ColStockSize());
    tabla.AddRow(header);

    for (unsigned int i = 0; i < lista.Size(); ++i) {
        Producto* p = lista[i];
        Tabling::Row* fila = new Tabling::Row(columnas);
        fila->AddCell(std::to_string(i), 4);
        fila->AddCell(p->getCodigo(), Producto::ColCodigoSize());
        fila->AddCell(p->getDescripcion(), Producto::ColDescripcionSize());
        fila->AddCell(Validation::ToFixedDecimal(p->getPrecio(), 2), Producto::ColPrecioSize());
        fila->AddCell(std::to_string(p->getStock()), Producto::ColStockSize());
        tabla.AddRow(fila);
    }

    int idx = -1;
    while (true) {
        rlutil::cls();
        tabla.Print();
        idx = SelectorIndex(tabla, "Indice (vacio para cancelar): ", lista.Size());
        if (idx == -1) return "";
        if (idx < 0) continue;
        return lista[static_cast<unsigned int>(idx)]->getCodigo();
    }
}
