#include "nota_de_credito_menu.h"
#include <iostream>

using namespace std;

NotaDeCreditoMenu::NotaDeCreditoMenu() : Menu("Menu Notas de Credito", true) {
    AddOption("Listar por Cliente");
    AddOption("Buscar por Cliente");
    AddOption("Listar por Motivo");
    AddOption("Buscar por Rango de Fecha");
    AddOption("Volver");
}

void NotaDeCreditoMenu::OnSelect(int index) {
    rlutil::cls();
    switch(index) {
        case 0: {
            notas.ListarPorCliente();
            PauseConsole();
            break;
        }
        case 1: {
            string dni = InputBox("DNI del cliente: ");
            auto res = notas.BuscarPorCliente(dni);
            NotaDeCreditoManager::Imprimir(res);
            PauseConsole();
            break;
        }
        case 2: {
            string dni = InputBox("DNI del cliente: ");
            auto res = notas.BuscarPorCliente(dni);
            NotaDeCreditoManager::Imprimir(res);
            PauseConsole();
            break;
        }
        case 3: {
            string motivo = InputBox("Motivo de la nota de credito: ");
            auto res = notas.BuscarPorMotivo(motivo);
            NotaDeCreditoManager::Imprimir(res);
            PauseConsole();
            break;
        }
        case 4: {
            Fecha fechaInicio = InputDate("Fecha Inicio (DD/MM/AAAA): ");
            Fecha fechaFin = InputDate("Fecha Fin (DD/MM/AAAA): ");
            auto res = notas.BuscarPorRangoFecha(fechaInicio, fechaFin);
            NotaDeCreditoManager::Imprimir(res);
            PauseConsole();
            break;
        }
        case 5: {
            return;
        }
        default:
            break;
    }
}
