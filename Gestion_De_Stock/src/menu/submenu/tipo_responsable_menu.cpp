#include "tipo_responsable_menu.h"
#include <iostream>

using namespace std;

TipoResponsableMenu::TipoResponsableMenu() : Menu("Menu Tipo Responsables", true) {
    AddOption("Agregar Tipo Responsable");
    AddOption("Modificar Tipo Responsable");
    AddOption("Eliminar Tipo Responsable");
    AddOption("Listar por Descripcion");
    AddOption("Listar por Porcentaje");
    AddOption("Buscar por Porcentaje Mayor a");
    AddOption("Volver");
}

bool TipoResponsableMenu::OnSelect(int index) {
    rlutil::cls();
    switch(index) {
        case 0: {
            TipoResponsable nuevo = TipoResponsable::NuevoTipoResponsable();
            if (tipos.Agregar(nuevo))
                cout << "Tipo responsable agregado exitosamente." << endl;
            else
                cout << "Error al agregar el tipo responsable." << endl;
            PauseConsole();
            return false;
        }
        case 1: {
            string codigo = InputBox("Codigo del tipo a modificar: ");
            TipoResponsable* t = tipos[codigo];
            if (t == nullptr) {
                cout << "Tipo responsable no encontrado." << endl;
                PauseConsole();
                return false;
            }

            TipoResponsable::ModificarTipoResponsable(*t);

            if (tipos.Modificar(codigo, t))
                cout << "Tipo responsable modificado exitosamente." << endl;
            else
                cout << "Error al modificar el tipo responsable." << endl;
            PauseConsole();
            return false;
        }
        case 2: {
            string codigo = InputBox("Codigo del tipo a eliminar: ");
            TipoResponsable* t = tipos[codigo];
            if (t == nullptr) {
                cout << "Tipo responsable no encontrado." << endl;
                PauseConsole();
                return false;
            }
            bool confirma = TipoResponsable::EliminarTipoResponsable(*t);
            delete t;
            if (confirma) {
                if (tipos.Eliminar(codigo))
                    cout << "Tipo responsable eliminado exitosamente." << endl;
                else
                    cout << "Error al eliminar el tipo responsable." << endl;
            } else
                cout << "Operacion cancelada." << endl;
            PauseConsole();
            return false;
        }
        case 3: {
            tipos.ListarPorDescripcion();
            PauseConsole();
            return false;
        }
        case 4: {
            tipos.ListarPorPorcentaje();
            PauseConsole();
            return false;
        }
        case 5: {
            float minimo = InputNumber("Porcentaje minimo: ");
            auto lista = tipos.PorcentajeMayorA(minimo);
            TipoResponsableManager::Imprimir(lista);
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
