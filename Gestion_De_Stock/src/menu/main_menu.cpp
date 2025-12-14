#include "main_menu.h"
#include <iostream>

using namespace std;

MainMenu::MainMenu() : Menu("Menu Principal", true) {
    AddOption("Clientes");
    AddOption("Proveedores");
    AddOption("Productos");
    AddOption("Tipo Responsables");
    AddOption("Ventas");
    AddOption("Data Generator");
    AddOption("Salir");
}

bool MainMenu::OnSelect(int index) {
    switch(index) {
        case 0: {
            ClienteMenu m;
            while (!m.Run());
            return false;
        }
        case 1: {
            ProveedorMenu m;
            while (!m.Run());
            return false;
        }
        case 2: {
            ProductoMenu m;
            while (!m.Run());
            return false;
        }
        case 3: {
            TipoResponsableMenu m;
            while (!m.Run());
            return false;
        }
        case 4: {
            VentaMenu m;
            while (!m.Run());
            return false;
        }
        case 5: {
            cout << "--- Generando datos de prueba... ---" << endl << endl;
            DataGenerator::GenerateTipoResponsable();
            DataGenerator::GenerateClients();
            DataGenerator::GenerateProviders();
            DataGenerator::GenerateProduct();
            DataGenerator::GenerateInvoices();
            cout << endl << "--- Datos de prueba generados. ---" << endl;
            PauseConsole();
            return false;
        }
        case 6: { // Salir
            return true;
        }
        default:
            return true;
    }
}
