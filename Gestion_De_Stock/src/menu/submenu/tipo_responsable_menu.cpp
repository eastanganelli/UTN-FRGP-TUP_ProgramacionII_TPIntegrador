#include "tipo_responsable_menu.h"
#include <iostream>

using namespace std;

TipoResponsableMenu::TipoResponsableMenu() : Menu("Menu Tipo Responsables", true) {
    AddOption("Listar por Descripcion");
    AddOption("Listar por Porcentaje");
    AddOption("Buscar por Porcentaje Mayor a");
    AddOption("Volver");
}

void TipoResponsableMenu::OnSelect(int index) {
    switch(index) {
        case 0: {
            tipos.ListarPorDescripcion();
            PauseConsole();
            break;
        }
        case 1: {
            tipos.ListarPorPorcentaje();
            PauseConsole();
            break;
        }
        case 2: {
            float minimo = InputNumber("Porcentaje minimo: ");
            auto lista = tipos.PorcentajeMayorA(minimo);
            TipoResponsableManager::Imprimir(lista);
            PauseConsole();
            break;
        }
        default:
            break;
    }
}
