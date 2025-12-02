#include "main_menu.h"
#include <iostream>

using namespace std;

MainMenu::MainMenu() : Menu("Menu Principal", true) {
    AddOption("Clientes");
    AddOption("Proveedores");
    AddOption("Productos");
    AddOption("Tipo Responsables");
    AddOption("Facturas");
    AddOption("Notas de Credito");
    AddOption("Ventas");
    AddOption("Data Generator");
    AddOption("Salir");
}

void MainMenu::OnSelect(int index) {
    switch(index) {
        case 0: {
            ClienteMenu m;
            do {
                m.Run();
            } while (true);
            break;
        }
        case 1: {
            ProveedorMenu m;
            do {
                m.Run();
            } while (true);
            break;
        }
        case 2: {
            ProductoMenu m;
            do {
                m.Run();
            } while (true);
            break;
        }
        case 3: {
            TipoResponsableMenu m;
            do {
                m.Run();
            } while (true);
            break;
        }
        case 4: {
            FacturaMenu m;
            do {
                m.Run();
            } while (true);
            break;
        }
        case 5: {
            NotaDeCreditoMenu m;
            do {
                m.Run();
            } while (true);
            break;
        }
        case 6: {
            VentaMenu m;
            do {
                m.Run();
            } while (true);
            break;
        }
        case 7: {
            cout << "--- Generando datos de prueba... ---" << endl << endl;
            DataGenerator::GenerateTipoResponsable();
            DataGenerator::GenerateClients();
            DataGenerator::GenerateProviders();
            DataGenerator::GenerateProduct();
            DataGenerator::GenerateInvoices();
            cout << endl << "--- Datos de prueba generados. ---" << endl;
            PauseConsole();
            break;
        }
        default:
            exit(0);
    }
}
