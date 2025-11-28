#include "tipo_responsable_menu.h"
#include <iostream>

using namespace std;

TipoResponsableMenu::TipoResponsableMenu() : Menu("Menu Tipo Responsables", true) {
    AddOption("Listar tipos");
    AddOption("Volver");
}

void TipoResponsableMenu::OnSelect(int index) {
    switch(index) {
        case 0: {
            auto lista = tipos.Listar();
            TipoResponsableManager::Imprimir(lista);
            PauseConsole();
            break;
        }
        default:
            break;
    }
}
