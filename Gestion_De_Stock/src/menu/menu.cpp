#include "menu.h"

using namespace std;

Menu::Menu(const std::string& title_, bool centered_)
    : title(title_), centered(centered_), selectedIndex(0) { }

Menu::~Menu() { }

void Menu::AddOption(const std::string& opt) {
    string aux = opt;
    options.Append(aux);
}

void Menu::DrawHeader() {
    cout << "\n=== " << title << " ===\n";
}

void Menu::DrawOptions() {
    for (size_t i = 0; i < options.Size(); ++i) {
        if ((int)i == selectedIndex) cout << "> "; else cout << "  ";
        cout << (i + 1) << ") " << *options[i] << "\n";
    }
}

bool Menu::Run() {
    rlutil::cls();
    DrawHeader();
    DrawOptions();

    cout << "Seleccione una opcion (numero) y presione Enter: ";
    int sel = 0;
    if (!(cin >> sel)) {
        cin.clear();
        string tmp; getline(cin, tmp);
        return false;
    }
    if (sel < 1 || sel > (int)options.Size()) return false;
    selectedIndex = sel - 1;
    return OnSelect(selectedIndex);
}
