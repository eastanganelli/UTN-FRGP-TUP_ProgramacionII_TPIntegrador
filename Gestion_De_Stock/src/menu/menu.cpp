#include "menu.h"
#include <iostream>
#include "../controller/modals.h"
#include "../rlutil.h"

using namespace std;

Menu::Menu(const std::string& title_, bool centered_)
    : title(title_), centered(centered_), selectedIndex(0) { }

Menu::~Menu() { }

void Menu::AddOption(const std::string& opt) {
    options.push_back(opt);
}

void Menu::DrawHeader() {
    // Simple header; subclasses can override drawing behavior if needed
    cout << "\n=== " << title << " ===\n";
}

void Menu::DrawOptions() {
    for (size_t i = 0; i < options.size(); ++i) {
        if ((int)i == selectedIndex) cout << "> "; else cout << "  ";
        cout << (i + 1) << ") " << options[i] << "\n";
    }
}

void Menu::Run() {
    OnEnter:
    DrawHeader();
    DrawOptions();

    // Simple numeric selection for portability
    cout << "Seleccione una opcion (numero) y presione Enter: ";
    int sel = 0;
    if (!(cin >> sel)) {
        cin.clear();
        string tmp; getline(cin, tmp);
        return;
    }
    if (sel < 1 || sel > (int)options.size()) return;
    selectedIndex = sel - 1;
    OnSelect(selectedIndex);
}
