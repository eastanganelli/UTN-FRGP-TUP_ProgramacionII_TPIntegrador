#include "producto_menu.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>
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

Producto ProductoMenu::CrearProducto() {
    rlutil::cls();
    Producto producto;
    string v;

    // Seleccionar proveedor mostrando lista con indice
    string cuitProveedor = SeleccionarProveedor();
    if (Validation::IsEmpty(cuitProveedor)) {
        Warning w("Proveedor requerido", "No se selecciono proveedor. Operacion cancelada.");
        w.Show(); w.WaitForKey();
        return producto;
    }
    producto.setCodigoProveedor(cuitProveedor);

    // Codigo generado automaticamente (se puede mostrar al usuario si se desea)
    producto.setCodigo(Producto::GenerarCodigo());

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
        cout << "4) Proveedor (CUIT actual: " << producto.getCodigoProveedor() << ")\n";
        cout << "5) Terminar\n";

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
            Producto nuevo = CrearProducto();
            if (Validation::IsEmpty(nuevo.getCodigoProveedor())) {
                return false;
            }
            if (productos.Agregar(nuevo)) cout << "Producto agregado exitosamente." << endl;
            else cout << "Error al agregar el producto." << endl;
            PauseConsole();
            return false;
        }
        case 1: {
            string codigo = SeleccionarProductoCodigo();
            if (codigo.empty()) return false;
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
            string codigo = SeleccionarProductoCodigo();
            if (codigo.empty()) return false;
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

string ProductoMenu::SeleccionarProveedor() {
    rlutil::cls();
    const unsigned int total = proveedores.Count();
    GenericArray<string> cuits;
    GenericArray<string> descripciones;

    for (unsigned int i = 0; i < total; ++i) {
        Proveedor* p = proveedores.At(i);
        if (p != nullptr) {
            if (p->getAlta()) {
                string cuit = p->getCuit();
                string desc = p->getNombreRazon() + string(" ( ") + p->getRubroNombre() + string(" )");
                cuits.Append(cuit);
                descripciones.Append(desc);
            }
            delete p;
        }
    }

    if (cuits.Size() == 0) {
        Warning w("Sin proveedores activos", "No hay proveedores dados de alta para seleccionar.");
        w.Show(); w.WaitForKey();
        return "";
    }

    ImprimirProveedoresActivos(cuits, descripciones);

    unsigned int idx = cuits.Size(); // valor invalido inicial
    do {
        idx = InputNumber("Ingrese indice: ");
        if (idx < cuits.Size()) break;
        Warning w("Indice invalido", "Seleccione un indice existente.");
        w.Show(); w.WaitForKey();
        ImprimirProveedoresActivos(cuits, descripciones);
    } while (true);

    return *cuits[idx];
}

void ProductoMenu::ImprimirProveedoresActivos(GenericArray<string>& cuits, GenericArray<string>& descripciones) {
    rlutil::cls();
    cout << "\nSeleccione proveedor:\n";
    for (unsigned int i = 0; i < cuits.Size(); ++i) {
        cout << i << ") " << *cuits[i] << " - " << *descripciones[i] << "\n";
    }
}

string ProductoMenu::SeleccionarProductoCodigo() {
    rlutil::cls();
    const unsigned int total = productos.Count();
    GenericArray<string> codigos;
    GenericArray<string> filas;

    for (unsigned int i = 0; i < total; ++i) {
        Producto* p = productos.At(i);
        if (p != nullptr) {
            string codigo = p->getCodigo();
            string fila = codigo + " - " + p->getDescripcion() + " | Precio: " + to_string(p->getPrecio()) + " | Stock: " + to_string(p->getStock());
            codigos.Append(codigo);
            filas.Append(fila);
            delete p;
        }
    }

    if (codigos.Size() == 0) {
        Warning w("Sin productos", "No hay productos cargados para seleccionar.");
        w.Show(); w.WaitForKey();
        return "";
    }

    ImprimirProductosListado(codigos, filas);

    while (true) {
        string entrada = InputBox("Indice (vacio para cancelar): ");
        if (entrada.empty()) return "";

        char* endptr = nullptr;
        const char* raw = entrada.c_str();
        unsigned long idxLong = std::strtoul(raw, &endptr, 10);
        if (endptr == raw || *endptr != '\0') {
            Warning w("Indice invalido", "Ingrese un numero de la lista.");
            w.Show(); w.WaitForKey();
            ImprimirProductosListado(codigos, filas);
            continue;
        }
        if (idxLong >= codigos.Size()) {
            Warning w("Fuera de rango", "Seleccione un indice existente.");
            w.Show(); w.WaitForKey();
            ImprimirProductosListado(codigos, filas);
            continue;
        }
        return *codigos[static_cast<unsigned int>(idxLong)];
    }
}

void ProductoMenu::ImprimirProductosListado(GenericArray<string>& codigos, GenericArray<string>& filas) {
    rlutil::cls();
    cout << "\nSeleccione producto:\n";
    for (unsigned int i = 0; i < codigos.Size(); ++i) {
        cout << i << ") " << *filas[i] << "\n";
    }
}
