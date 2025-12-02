#include <ctime>

//https://pastebin.com/J4hm7rb5
//https://pastebin.com/MLT91vfM

#include "src/menu/main_menu.h"

using namespace std;

int main() {
//    srand(time(NULL));

//    DataGenerator::GenerateTipoResponsable();
//    DataGenerator::GenerateProviders();
//    DataGenerator::GenerateProduct();
//    DataGenerator::GenerateInvoices();

    MainMenu menuPrincipal;
    while (!menuPrincipal.Run());

    Informational exitMsg("Salir", "Gracias por usar el sistema de gestion de stock. Hasta luego!");
    exitMsg.Show();
    PauseConsole();

    return 0;
}
