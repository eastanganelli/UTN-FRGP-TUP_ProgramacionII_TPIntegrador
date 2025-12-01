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

void FacturaMenu::OnSelect(int index) {
    switch(index) {
        case 0: {
            facturas.ListarPorCliente();
            PauseConsole();
            break;
        }
        case 1: {
            facturas.ListarPorFecha();
            PauseConsole();
            break;
        }
        case 2: {
            facturas.ListarPorMonto();
            PauseConsole();
            break;
        }
        case 3: {
            string dni = InputBox("DNI del cliente: ");
            auto res = facturas.BuscarPorCliente(dni);
            FacturaManager::Imprimir(res);
            PauseConsole();
            break;
        }
        case 4: {
            string cae = InputBox("CAE: ");
            auto res = facturas.BuscarPorCAE(cae);
            FacturaManager::Imprimir(res);
            PauseConsole();
            break;
        }
        case 5: {
            Fecha fechaInicio = InputDate("Fecha Inicio (DD/MM/AAAA): "),
                  fechaFin = InputDate("Fecha Fin (DD/MM/AAAA): ");

            Fecha fechaInicio, fechaFin;
            if (!fechaInicio.IsValid() || !fechaFin.()) {
                cout << "Formato de fecha invalido." << endl;
                PauseConsole();
                break;
            }

            auto res = facturas.BuscarPorRangoFecha(fechaInicio, fechaFin);
            FacturaManager::Imprimir(res);
            PauseConsole();
            break;
        }
        default:
            break;
    }
}
