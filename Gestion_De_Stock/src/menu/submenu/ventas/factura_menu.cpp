#include "factura_menu.h"
#include <iostream>
#include <cstdlib>
#include "../../../controller/generic_array.h"
#include "../../../manager/manager_producto.h"
#include "../../../manager/manager_cliente.h"
#include "../../../manager/ventas/manager_nota_de_credito.h"

using namespace std;

FacturaMenu::FacturaMenu() : Menu("Menu Facturas", true) {
    AddOption("Agregar Factura");
    AddOption("Modificar Factura");
    AddOption("Listar por Cliente");
    AddOption("Listar por Fecha");
    AddOption("Listar por Monto");
    AddOption("Buscar por cliente");
    AddOption("Buscar por CAE");
    AddOption("Buscar por Rango de Fecha");
    AddOption("Volver");
}

bool FacturaMenu::OnSelect(int index) {
    rlutil::cls();
    switch(index) {
        case 0: {
            unsigned int maxNum = 0;
            unsigned int fc = facturas.Count();
            for (unsigned int i = 0; i < fc; ++i) {
                Factura* f = facturas.At(i);
                if (f != nullptr) { if (f->getNumero() > maxNum) maxNum = f->getNumero(); delete f; }
            }
            NotaDeCreditoManager nm;
            unsigned int nc = nm.Count();
            for (unsigned int i = 0; i < nc; ++i) {
                NotaDeCredito* n = nm.At(i);
                if (n != nullptr) { if (n->getNumero() > maxNum) maxNum = n->getNumero(); delete n; }
            }

            unsigned int nuevoId = maxNum + 1;
            bool ok = false;
            Factura f = CrearFactura(nuevoId, ok);
            if (!ok) {
                cout << "Operacion cancelada." << endl;
                PauseConsole();
                return false;
            }
            if (facturas.Agregar(f)) cout << "Factura agregada exitosamente." << endl;
            else cout << "Error al agregar la factura." << endl;
            PauseConsole();
            return false;
        }
        case 1: {
            unsigned int numero = InputNumber("Numero de la factura a modificar: ");
            Factura* f = facturas[numero];
            if (f == nullptr) {
                cout << "Factura no encontrada." << endl;
                PauseConsole();
                return false;
            }

            ModificarFacturaInteractiva(*f);

            if (facturas.Modificar(numero, f)) cout << "Factura modificada exitosamente." << endl;
            else cout << "Error al modificar la factura." << endl;
            PauseConsole();
            return false;
        }
        case 2: {
            facturas.ListarPorCliente();
            PauseConsole();
            return false;
        }
        case 3: {
            facturas.ListarPorFecha();
            PauseConsole();
            return false;
        }
        case 4: {
            facturas.ListarPorMonto();
            PauseConsole();
            return false;
        }
        case 5: {
            string dni = InputBox("DNI del cliente: ");
            auto res = facturas.BuscarPorCliente(dni);
            FacturaManager::Imprimir(res);
            PauseConsole();
            return false;
        }
        case 6: {
            string cae = InputBox("CAE: ");
            auto res = facturas.BuscarPorCAE(cae);
            FacturaManager::Imprimir(res);
            PauseConsole();
            return false;
        }
        case 7: {
            Fecha fechaInicio = InputDate("Fecha Inicio (DD/MM/AAAA): "),
                  fechaFin = InputDate("Fecha Fin (DD/MM/AAAA): ");

            auto res = facturas.BuscarPorRangoFecha(fechaInicio, fechaFin);
            FacturaManager::Imprimir(res);
            PauseConsole();
            return false;
        }
        case 8: {
            return true;
        }
        default:
            return false;
    }
}

string FacturaMenu::SeleccionarCliente() {
    rlutil::cls();
    const unsigned int total = clientes.Count();
    GenericArray<string> dnis;
    GenericArray<string> nombres;

    for (unsigned int i = 0; i < total; ++i) {
        Cliente* c = clientes.At(i);
        if (c != nullptr) {
            if (c->getAlta()) {
                string dni = c->getDNI();
                string nombre = c->getApellido() + string(", ") + c->getNombre();
                dnis.Append(dni);
                nombres.Append(nombre);
            }
            delete c;
        }
    }

    if (dnis.Size() == 0) {
        Warning w("Sin clientes activos", "No hay clientes dados de alta para seleccionar.");
        w.Show(); w.WaitForKey();
        return "";
    }

    while (true) {
        cout << "\nSeleccione cliente:\n";
        for (unsigned int i = 0; i < dnis.Size(); ++i) {
            cout << i << ") " << *dnis[i] << " - " << *nombres[i] << "\n";
        }

        string entrada = InputBox("Indice (vacio para cancelar): ");
        if (entrada.empty()) return "";
        char* endptr = nullptr;
        const char* raw = entrada.c_str();
        unsigned long idxLong = std::strtoul(raw, &endptr, 10);
        if (endptr == raw || *endptr != '\0') {
            Warning w("Indice invalido", "Ingrese un numero de la lista.");
            w.Show(); w.WaitForKey();
            rlutil::cls();
            continue;
        }
        unsigned int idx = static_cast<unsigned int>(idxLong);
        if (idx >= dnis.Size()) {
            Warning w("Fuera de rango", "Seleccione un indice existente.");
            w.Show(); w.WaitForKey();
            rlutil::cls();
            continue;
        }

        return *dnis[idx];
    }
}

string FacturaMenu::SeleccionarProductoCodigo() {
    rlutil::cls();
    const unsigned int total = productos.Count();
    if (total == 0) {
        Warning w("Sin productos", "No hay productos cargados. Agregue alguno antes de facturar.");
        w.Show(); w.WaitForKey();
        return "";
    }

    while (true) {
        cout << "\nSeleccione producto (vaciar para terminar):\n";
        for (unsigned int i = 0; i < total; ++i) {
            Producto* p = productos.At(i);
            if (p != nullptr) {
                cout << i << ") " << p->getCodigo() << " - " << p->getDescripcion() << " | Precio: " << p->getPrecio() << " | Stock: " << p->getStock() << "\n";
                delete p;
            }
        }

        string entrada = InputBox("Indice: ");
        if (entrada.empty()) return "";
        char* endptr = nullptr;
        const char* raw = entrada.c_str();
        unsigned long idxLong = std::strtoul(raw, &endptr, 10);
        if (endptr == raw || *endptr != '\0') {
            Warning w("Indice invalido", "Ingrese un numero de la lista.");
            w.Show(); w.WaitForKey();
            rlutil::cls();
            continue;
        }
        unsigned int idx = static_cast<unsigned int>(idxLong);
        if (idx >= total) {
            Warning w("Fuera de rango", "Seleccione un indice existente.");
            w.Show(); w.WaitForKey();
            rlutil::cls();
            continue;
        }

        Producto* elegido = productos.At(idx);
        string codigo = "";
        if (elegido != nullptr) {
            codigo = elegido->getCodigo();
            delete elegido;
        }
        return codigo;
    }
}

bool FacturaMenu::AgregarItemInteractivo(Factura& factura) {
    while (true) {
        string codigo = SeleccionarProductoCodigo();
        if (codigo.empty()) return false;

        Producto* p = productos[codigo];
        if (p == nullptr) {
            Warning w("Producto no encontrado", "Seleccione un producto valido.");
            w.Show(); w.WaitForKey();
            rlutil::cls();
            continue;
        }

        unsigned int stock = p->getStock();
        if (stock == 0) {
            Warning w("Sin stock", "El producto no tiene stock disponible.");
            w.Show(); w.WaitForKey();
            delete p;
            rlutil::cls();
            continue;
        }

        unsigned int cantidad = InputNumber("Cantidad: ");
        if (cantidad == 0 || cantidad > stock) {
            Warning w("Cantidad invalida", "Ingrese una cantidad mayor a 0 y menor o igual al stock.");
            w.Show(); w.WaitForKey();
            delete p;
            rlutil::cls();
            continue;
        }

        Item it(codigo.c_str(), cantidad, p->getPrecio());
        Producto actualizado = *p;
        delete p;

        if (!factura.AgregarItem(it)) {
            Warning w("Item duplicado", "Ya existe un item con ese producto en la factura.");
            w.Show(); w.WaitForKey();
            rlutil::cls();
            continue;
        }

        actualizado.setStock(stock - cantidad);
        productos.Modificar(actualizado.getCodigo(), &actualizado);
        return true;
    }
}

Factura FacturaMenu::CrearFactura(unsigned int numero, bool& ok) {
    ok = false;
    Factura f(numero, "");

    string dni = SeleccionarCliente();
    if (dni.empty()) return f;
    f.setClienteDNI(dni);

    f.getFechaEmision() = Fecha::Hoy();

    while (AgregarItemInteractivo(f)) { }

    if (f.CantidadItems() > 0) {
        if (!f.Facturar()) {
            Warning w("Facturacion", "No se pudo generar CAE para la factura.");
            w.Show(); w.WaitForKey();
        }
    } else {
        Informational i("Factura guardada", "Factura creada sin items. No puede ser facturada hasta agregar items.");
        i.Show(); i.WaitForKey();
    }

    ok = true;
    return f;
}

void FacturaMenu::ModificarFacturaInteractiva(Factura& factura) {
    unsigned int opcion = 0;
    do {
        rlutil::cls();
        cout << "-- Modificar Factura (ID: " << factura.getNumero() << ") --\n";
        cout << "1) Agregar Item\n";
        cout << "2) Modificar Item\n";
        cout << "3) Eliminar Item\n";
        cout << "4) Terminar\n";
        opcion = InputNumber("Seleccione accion: ");
        switch(opcion) {
            case 1: {
                AgregarItemInteractivo(factura);
                break;
            }
            case 2: {
                if (factura.CantidadItems() == 0) {
                    Warning w("Sin items", "La factura no tiene items para modificar.");
                    w.Show(); w.WaitForKey();
                    break;
                }
                unsigned int idx = InputNumber("Indice de item (0-based): ");
                const Item* pit = factura.ObtenerItem(idx);
                if (pit == nullptr) {
                    Warning w("Item no encontrado", "Indice invalido.");
                    w.Show(); w.WaitForKey();
                    break;
                }
                Item mutableItem = *pit;
                Item::ModificarItem(mutableItem, productos);
                factura.EliminarItem(mutableItem.getCodigo());
                factura.AgregarItem(mutableItem);
                break;
            }
            case 3: {
                if (factura.CantidadItems() == 0) {
                    Warning w("Sin items", "La factura no tiene items para eliminar.");
                    w.Show(); w.WaitForKey();
                    break;
                }
                unsigned int idx = InputNumber("Indice de item (0-based): ");
                const Item* pit = factura.ObtenerItem(idx);
                if (pit == nullptr) {
                    Warning w("Item no encontrado", "Indice invalido.");
                    w.Show(); w.WaitForKey();
                    break;
                }
                Item temp = *pit;
                if (Item::EliminarItem(temp, productos)) {
                    factura.EliminarItem(temp.getCodigo());
                }
                break;
            }
            case 4: break;
            default: {
                Warning w("Opcion invalida", "Seleccione una opcion valida.");
                w.Show(); w.WaitForKey();
                break;
            }
        }
    } while (opcion != 4);
    rlutil::cls();
}
