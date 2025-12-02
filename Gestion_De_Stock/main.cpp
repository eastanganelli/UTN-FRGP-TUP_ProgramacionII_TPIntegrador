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
    do {
        menuPrincipal.Run();
    } while(true);

    return 0;
}
