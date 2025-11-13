#include <ctime>

#include "Pruebas.h"
#include "src/Menu.h"

using namespace std;

int main() {
    srand(time(NULL));

    //TestingAll();

    Menu menu;
    menu.mostrar();

    return 0;
}
