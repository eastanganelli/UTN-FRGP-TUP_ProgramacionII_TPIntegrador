#include "informational.h"

Informational::Informational(const string& title, const string& message) : Modal(title, message) {}

Informational::~Informational() {}

void Informational::Show() {
    this->ClearScreen();
    rlutil::saveDefaultColor();
    rlutil::setBackgroundColor(rlutil::BLUE);
    rlutil::setColor(rlutil::LIGHTBLUE);
    cout << "=== " << this->title << " ===" << endl;
    rlutil::resetColor();
    cout << this->message << endl;
}

bool Informational::ShowYesNo() {
    char key;
    do {
        this->Show();
        cout << "\nPresione 'Y' para Si o 'N' para No..." << endl;
        key = rlutil::getkey();
        key = toupper(key);
    } while(key != 'Y' && key != 'N');
    return key == 'Y';
}