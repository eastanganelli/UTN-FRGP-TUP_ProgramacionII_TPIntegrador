#include "backup_menu.h"

#include <iostream>

BackupMenu::BackupMenu() : Menu("Copias de Seguridad", true) {
    AddOption("Crear backup");
    AddOption("Restaurar backup");
    AddOption("Volver");
}

bool BackupMenu::OnSelect(int index) {
    switch(index) {
        case 0: {
            std::cout << "[Backup] Crear backup no implementado aun." << std::endl;
            PauseConsole();
            return false;
        }
        case 1: {
            std::cout << "[Backup] Restaurar backup no implementado aun." << std::endl;
            PauseConsole();
            return false;
        }
        case 2: {
            return true; // Volver
        }
        default:
            return false;
    }
}
