#include "proveedor_menu.h"
#include <iostream>

using namespace std;

ProveedorMenu::ProveedorMenu() : Menu("Menu Proveedores", true) {
    AddOption("Agregar Proveedor");
    AddOption("Modificar Proveedor");
    AddOption("Eliminar Proveedor");
    AddOption("Listar por Rubro");
    AddOption("Listar por CUIT");
    AddOption("Listar por Nombre o Razon Social");
    AddOption("Buscar por Rubro");
    AddOption("Buscar por CUIT");
    AddOption("Buscar por Nombre o Razon Social");
    AddOption("Buscar por Estado");
    AddOption("Volver");
}

bool ProveedorMenu::OnSelect(int index) {
    rlutil::cls();
    switch(index) {
        case 0: {
            Proveedor nuevo = Proveedor::NuevoProveedor();
            if (proveedores.Agregar(nuevo))
                cout << "Proveedor agregado exitosamente." << endl;
            else
                cout << "Error al agregar el proveedor." << endl;
            PauseConsole();
            return false;
        }
        case 1: {
            string cuit = InputBox("CUIT del proveedor a modificar: ");
            Proveedor* pv = proveedores[cuit];
            if (pv == nullptr) {
                cout << "Proveedor no encontrado." << endl;
                PauseConsole();
                return false;
            }

            Proveedor::ModificarProveedor(*pv);

            if (proveedores.Modificar(cuit, pv))
                cout << "Proveedor modificado exitosamente." << endl;
            else
                cout << "Error al modificar el proveedor." << endl;
            PauseConsole();
            return false;
        }
        case 2: {
            string cuit = InputBox("CUIT del proveedor a eliminar: ");
            Proveedor* pv = proveedores[cuit];
            if (pv == nullptr) {
                cout << "Proveedor no encontrado." << endl;
                PauseConsole();
                return false;
            }
            bool confirma = Proveedor::EliminarProveedor(*pv);
            delete pv;
            if (confirma) {
                if (proveedores.Eliminar(cuit))
                    cout << "Proveedor eliminado exitosamente." << endl;
                else
                    cout << "Error al eliminar el proveedor." << endl;
            } else
                cout << "Operacion cancelada." << endl;
            PauseConsole();
            return false;
        }
        case 3: {
            proveedores.ListarPorRubro();
            PauseConsole();
            return false;
        }
        case 4: {
            proveedores.ListarPorCUIT();
            PauseConsole();
            return false;
        }
        case 5: {
            proveedores.ListarPorNombre();
            PauseConsole();
            return false;
        }
        case 6: {
            unsigned int rubro = proveedores.SeleccionarRubro();
            auto res = proveedores.ConsultarPorRubro(rubro);
            ProveedorManager::Imprimir(res);
            PauseConsole();
            return false;
        }
        case 7: {
            string cuit = InputBox("CUIT: ");
            auto res = proveedores.ConsultarPorCUIT(cuit);
            ProveedorManager::Imprimir(res);
            PauseConsole();
            return false;
        }
        case 8: {
            string nombre = InputBox("Nombre o Razon Social: ");
            auto res = proveedores.ConsultarPorNombre(nombre);
            ProveedorManager::Imprimir(res);
            PauseConsole();
            return false;
        }
        case 9: {
            bool estado = Confirm("¿Desea buscar proveedores activos?");
            auto res = proveedores.ConsultarPorEstado(estado);
            ProveedorManager::Imprimir(res);
            PauseConsole();
            return false;
        }
        case 10: {
            return true;
        }
        default:
            return false;
    }
}
