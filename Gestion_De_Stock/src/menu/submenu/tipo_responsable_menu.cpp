#include "tipo_responsable_menu.h"
#include <iostream>

using namespace std;

TipoResponsableMenu::TipoResponsableMenu() : Menu("Menu Tipo Responsables", true) {
    AddOption("Listar por Descripcion");
    AddOption("Listar por Porcentaje");
    AddOption("Buscar por Porcentaje Mayor a");
    AddOption("Volver");
}

bool TipoResponsableMenu::OnSelect(int index) {
    rlutil::cls();
    switch(index) {
        case 0: {
            tipos.ListarPorDescripcion();
            PauseConsole();
            return false;
        }
        case 1: {
            tipos.ListarPorPorcentaje();
            PauseConsole();
            return false;
        }
        case 2: {
            float minimo = InputNumber("Porcentaje minimo: ");
            auto lista = tipos.PorcentajeMayorA(minimo);
            TipoResponsableManager::Imprimir(lista);
            PauseConsole();
            return false;
        }
        case 3: {
            return true;
        }
        default:
            return false;
    }
}
