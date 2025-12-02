#include "factura_menu.h"
#include <iostream>

using namespace std;

FacturaMenu::FacturaMenu() : Menu("Menu Facturas", true) {
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
            facturas.ListarPorCliente();
            PauseConsole();
            return false;
        }
        case 1: {
            facturas.ListarPorFecha();
            PauseConsole();
            return false;
        }
        case 2: {
            facturas.ListarPorMonto();
            PauseConsole();
            return false;
        }
        case 3: {
            string dni = InputBox("DNI del cliente: ");
            auto res = facturas.BuscarPorCliente(dni);
            FacturaManager::Imprimir(res);
            PauseConsole();
            return false;
        }
        case 4: {
            string cae = InputBox("CAE: ");
            auto res = facturas.BuscarPorCAE(cae);
            FacturaManager::Imprimir(res);
            PauseConsole();
            return false;
        }
        case 5: {
            Fecha fechaInicio = InputDate("Fecha Inicio (DD/MM/AAAA): "),
                  fechaFin = InputDate("Fecha Fin (DD/MM/AAAA): ");

            auto res = facturas.BuscarPorRangoFecha(fechaInicio, fechaFin);
            FacturaManager::Imprimir(res);
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
