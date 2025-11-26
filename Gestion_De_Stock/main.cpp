#include <ctime>

#include "Pruebas.h"
#include "src/controller/data_generator/tiporesponsables_generator.h"
#include "src/controller/data_generator/client_generator.h"
//#include "src/Menu.h"

//https://pastebin.com/J4hm7rb5
//https://pastebin.com/MLT91vfM

using namespace std;

int main() {
    srand(time(NULL));

//    Menu menu;
//    menu.mostrar();

//    Testing::TestingArray();
//    Testing::File();
//    Testing::Modals();
//    DataGenerator::GenerateClients(15);
//    rlutil::anykey();
//    rlutil::cls();
    Testing::ClientePrueba();
//    Testing::TipoResponsablePrueba();

//    DataGenerator::GenerateTipoResponsable();

    return 0;
}
