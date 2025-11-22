#include "error.h"

Error::Error(const string& title, const string& message) : Modal(title, message) {}

Error::~Error() {}

void Error::Show() {
    this->ClearScreen();
    rlutil::saveDefaultColor();
    rlutil::setBackgroundColor(rlutil::RED);
    rlutil::setColor(rlutil::LIGHTRED);
    cout << "=== " << this->title << " ===" << endl;
    rlutil::resetColor();
    cout << this->message << endl;
}

bool Error::ShowYesNo() {
    char key;
    do {
        this->Show();
        cout << "\nPresione 'Y' para Si o 'N' para No..." << endl;
        key = rlutil::getkey();
        key = toupper(key);
    } while(key != 'Y' && key != 'N');
    return key == 'Y';
}