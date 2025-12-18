#include "reports_menu.h"

#include <iostream>

ReportsMenu::ReportsMenu() : Menu("Menu de Informes", true) {
    AddOption("Recaudacion Anual");
    AddOption("Recaudacion Trimestral");
    AddOption("Top 10 Productos");
    AddOption("Top 5 Fechas");
    AddOption("Top Cliente");
    AddOption("Volver");
}

bool ReportsMenu::OnSelect(int index) {
    switch(index) {
        case 0: {
            RecaudacionAnualReport r;
            r.Run();
            PauseConsole();
            return false;
        }
        case 1: {
            RecaudacionTrimestralReport r;
            r.Run();
            PauseConsole();
            return false;
        }
        case 2: {
            Top10ProductosReport r;
            r.Run();
            PauseConsole();
            return false;
        }
        case 3: {
            Top5FechasReport r;
            r.Run();
            PauseConsole();
            return false;
        }
        case 4: {
            TopClienteReport r;
            r.Run();
            PauseConsole();
            return false;
        }
        case 5: {
            return true; // Volver
        }
        default:
            return false;
    }
}
