#include <ctime>

#include "Pruebas.h"
//#include "src/Menu.h"

//https://pastebin.com/J4hm7rb5
//https://pastebin.com/MLT91vfM

using namespace std;

int main() {
    srand(time(NULL));

    //loadData();

//    Menu menu;
//    menu.mostrar();

//    Testing::TestingArray();
//    Testing::File();
    cout << "Iniciando pruebas de Cliente..." << endl;
    Testing::Cliente();

    return 0;
}
