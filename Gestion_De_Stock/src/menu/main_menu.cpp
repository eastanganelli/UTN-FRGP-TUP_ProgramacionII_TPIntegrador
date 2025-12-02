#include "main_menu.h"
#include <iostream>

using namespace std;

MainMenu::MainMenu() : Menu("Menu Principal", true) {
    AddOption("Clientes");
    AddOption("Productos");
    AddOption("Proveedores");
    AddOption("Tipo Responsables");
    AddOption("Facturas");
    AddOption("Notas de Credito");
    AddOption("Ventas");
    AddOption("Salir");
}

void MainMenu::OnSelect(int index) {
    rlutil::cls();
    switch(index) {
        case 0: {
            ClienteMenu m; m.Run();
            break;
        }
        case 1: {
            ProductoMenu m; m.Run();
            break;
        }
        case 2: {
            ProveedorMenu m; m.Run();
            break;
        }
        case 3: {
            TipoResponsableMenu m; m.Run();
            break;
        }
        case 4: {
            FacturaMenu m; m.Run();
            break;
        }
        case 5: {
            NotaDeCreditoMenu m; m.Run();
            break;
        }
        case 6: {
            VentaMenu m; m.Run();
            break;
        }
        default:
            exit(0);
    }
}
