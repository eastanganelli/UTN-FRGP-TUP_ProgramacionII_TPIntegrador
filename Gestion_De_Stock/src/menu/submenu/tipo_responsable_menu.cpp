#include "tipo_responsable_menu.h"
#include <iostream>
#include "../../controller/modals/warning.h"
#include "../../controller/modals/error.h"

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
            if (tipos.Agregar(nuevo)) {
                cout << "Tipo responsable agregado exitosamente." << endl;
                PauseConsole();
            } else {
                Error e("Error", "Error al agregar el tipo responsable.");
                e.Show(); e.WaitForKey();
            }
            return false;
        }
        case 1: {
            string codigo = InputBox("Codigo del tipo a modificar: ");
            TipoResponsable* t = tipos[codigo];
            if (t == nullptr) {
                Warning w("Tipo responsable no encontrado", "No se encontro tipo con codigo " + codigo + ".");
                w.Show(); w.WaitForKey();
                return false;
            }

            TipoResponsable::ModificarTipoResponsable(*t);

            if (tipos.Modificar(codigo, t)) {
                Informational i("Tipo responsable modificado", "Tipo responsable " + codigo + " modificado exitosamente.");
                i.Show(); i.WaitForKey();
                PauseConsole();
            }
            else {
                Error e("Error", "Error al modificar el tipo responsable.");
                e.Show(); e.WaitForKey();
            }
            return false;
        }
        case 2: {
            string codigo = InputBox("Codigo del tipo a eliminar: ");
            TipoResponsable* t = tipos[codigo];
            if (t == nullptr) {
                Warning w("Tipo responsable no encontrado", "No se encontro tipo con codigo " + codigo + ".");
                w.Show(); w.WaitForKey();
                return false;
            }
            bool confirma = TipoResponsable::EliminarTipoResponsable(*t);
            delete t;
            if (confirma) {
                if (tipos.Eliminar(codigo)) {
                    Informational i("Tipo responsable eliminado", "Tipo responsable " + codigo + " eliminado exitosamente.");
                    i.Show(); i.WaitForKey();
                } else {
                    Error e("Error", "Error al eliminar el tipo responsable.");
                    e.Show(); e.WaitForKey();
                }
            } else {
                Informational i("Operacion cancelada", "Operacion cancelada por el usuario.");
                i.Show(); i.WaitForKey();
            }
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
