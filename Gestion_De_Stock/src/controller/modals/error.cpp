#include "error.h"

Error::Error(const string& title, const string& message) : Modal(title, message) {}

Error::~Error() {}

void Error::PrintHeader() {
    rlutil::saveDefaultColor();
    rlutil::setBackgroundColor(rlutil::RED);
    rlutil::setColor(rlutil::WHITE);
    cout << "=== " << title << " ===" << endl;
    rlutil::resetColor();
}

void Error::PrintFooter() {
    rlutil::saveDefaultColor();
    rlutil::setBackgroundColor(rlutil::RED);
    rlutil::setColor(rlutil::WHITE);
    const int length = 8 + this->title.length();
    for(int i = 0; i < length; i++) {
        cout << "=";
    }
    cout << endl;
    rlutil::resetColor();
}

void Error::Show() {
    this->ClearScreen();
    this->PrintHeader();
    cout << this->message << endl;
    this->PrintFooter();
}

bool Error::ShowYesNo() {
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