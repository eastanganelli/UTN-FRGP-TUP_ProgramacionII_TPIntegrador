#include "factura_menu.h"
#include <iostream>
#include "../../../manager/manager_producto.h"
#include "../../../manager/manager_cliente.h"
#include "../../../manager/ventas/manager_nota_de_credito.h"

using namespace std;

FacturaMenu::FacturaMenu() : Menu("Menu Facturas", true) {
    AddOption("Agregar Factura");
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
            // Compute next invoice number (max of facturas and notas) and call NuevoFactura
            unsigned int maxNum = 0;
            // check existing facturas
            unsigned int fc = facturas.Count();
            for (unsigned int i = 0; i < fc; ++i) {
                Factura* f = facturas.At(i);
                if (f != nullptr) { if (f->getNumero() > maxNum) maxNum = f->getNumero(); delete f; }
            }
            // check notas
            NotaDeCreditoManager nm;
            unsigned int nc = nm.Count();
            for (unsigned int i = 0; i < nc; ++i) {
                NotaDeCredito* n = nm.At(i);
                if (n != nullptr) { if (n->getNumero() > maxNum) maxNum = n->getNumero(); delete n; }
            }

            unsigned int nuevoId = maxNum + 1;
            ProductoManager pm;
            ClienteManager cm;

            Factura f = Factura::NuevoFactura(nuevoId, pm, cm);
            if (facturas.Agregar(f)) cout << "Factura agregada exitosamente." << endl;
            else cout << "Error al agregar la factura." << endl;
            PauseConsole();
            return false;
        }
        case 1: {
            facturas.ListarPorCliente();
            PauseConsole();
            return false;
        }
        case 2: {
            facturas.ListarPorFecha();
            PauseConsole();
            return false;
        }
        case 3: {
            facturas.ListarPorMonto();
            PauseConsole();
            return false;
        }
        case 4: {
            string dni = InputBox("DNI del cliente: ");
            auto res = facturas.BuscarPorCliente(dni);
            FacturaManager::Imprimir(res);
            PauseConsole();
            return false;
        }
        case 5: {
            string cae = InputBox("CAE: ");
            auto res = facturas.BuscarPorCAE(cae);
            FacturaManager::Imprimir(res);
            PauseConsole();
            return false;
        }
        case 6: {
            Fecha fechaInicio = InputDate("Fecha Inicio (DD/MM/AAAA): "),
                  fechaFin = InputDate("Fecha Fin (DD/MM/AAAA): ");

            auto res = facturas.BuscarPorRangoFecha(fechaInicio, fechaFin);
            FacturaManager::Imprimir(res);
            PauseConsole();
            return false;
        }
        case 7: {
            return true;
        }
        default:
            return false;
    }
}
