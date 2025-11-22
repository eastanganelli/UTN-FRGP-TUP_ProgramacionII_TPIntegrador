#include "modal.h"

Modal::Modal(const string& title, const string& message) : title(title), message(message) {}

Modal::~Modal() {
    this->ClearScreen();
}

void Modal::ClearScreen() {
    rlutil::cls();
}

bool Modal::IsYes(char key) {
    return key == 'Y' || key == 'y';
}

bool Modal::IsNo(char key) {
    return key == 'N' || key == 'n';
}

void Modal::WaitForKey() {
    cout << "\nPresione cualquier tecla para continuar..." << endl;
    rlutil::anykey();
}