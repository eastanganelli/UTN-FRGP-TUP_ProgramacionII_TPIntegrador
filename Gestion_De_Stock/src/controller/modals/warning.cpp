#include "warning.h"

Warning::Warning(const string& title, const string& message) : Modal(title, message) {}

Warning::~Warning() {}

void Warning::PrintHeader() {
    rlutil::saveDefaultColor();
    rlutil::setBackgroundColor(rlutil::YELLOW);
    rlutil::setColor(rlutil::BLACK);
    cout << "=== " << this->title << " ===" << endl;
    rlutil::resetColor();
}

void Warning::PrintFooter() {
    rlutil::saveDefaultColor();
    rlutil::setBackgroundColor(rlutil::YELLOW);
    rlutil::setColor(rlutil::BLACK);
    const int length = 8 + this->title.length();
    for(int i = 0; i < length; i++) {
        cout << "=";
    }
    cout << endl;
    rlutil::resetColor();
}

void Warning::Show() {
    this->ClearScreen();
    this->PrintHeader();
    cout << this->message << endl;
    this->PrintFooter();
}

bool Warning::ShowYesNo() {
    char key;
    do {
        this->PrintHeader();
        cout << this->message << endl
             << "\nSi (Y) || No (N)" << endl;
        this->PrintFooter();
        key = rlutil::getkey();
        key = toupper(key);
    } while(this->IsYes(key) || this->IsNo(key));
    return this->IsYes(key);
}