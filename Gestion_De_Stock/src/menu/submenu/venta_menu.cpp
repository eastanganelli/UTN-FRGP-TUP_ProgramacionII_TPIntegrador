#include "venta_menu.h"
#include <iostream>

using namespace std;

VentaMenu::VentaMenu() : Menu("Menu Ventas", true) {
    AddOption("Listar comprobantes por cliente");
    AddOption("Anular factura -> crear nota");
    AddOption("Volver");
}

void VentaMenu::OnSelect(int index) {
    rlutil::cls();
    switch(index) {
        case 0: {
            string dni = InputBox("DNI del cliente: ");
            ventas.ImprimirComprobantesPorCliente(dni);
            PauseConsole();
            break;
        }
        case 1: {
            unsigned int nro = InputNumber("Numero factura: ");
            string motivo = InputBox("Motivo de anulación: ");
            if (Confirm("Confirmar anular factura?")) {
                bool ok = ventas.ConvertirFacturaANota(nro, motivo);
                if (ok) cout << "Factura convertida en Nota de Credito." << endl;
                else cout << "Error: no se pudo convertir la factura." << endl;
            }
            PauseConsole();
            break;
        }
        case 2: {
            return;
        }
        default:
            break;
    }
}
