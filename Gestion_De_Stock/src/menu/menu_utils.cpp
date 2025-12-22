#include "menu_utils.h"

using namespace std;

std::string InputBox(const std::string& prompt) {
    cout << prompt;
    string s;
    if (!std::getline(cin, s) || s.size() == 0) {
        std::getline(cin, s);
    }
    return s;
}

unsigned int InputNumber(const std::string& prompt) {
    cout << prompt;
    unsigned int n;
    if (!(cin >> n)) {
        cin.clear();
        string tmp; getline(cin, tmp);
        return 0;
    }
    string tmp; getline(cin, tmp);
    return n;
}

Fecha InputDate(const std::string& prompt) {
    cout << prompt;
    Fecha f = Fecha::CrearFecha();
    return f;
}

bool Confirm(const std::string& prompt) {
    cout << prompt << " (s/N): ";
    string r;
    getline(cin, r);
    if (r.size() == 0) { getline(cin, r); }
    r = Validation::ToUpper(r);
    return (r.size() > 0 && (Validation::IsEqual(r, "N") || Validation::IsEqual(r, "Y")));
}

void PauseConsole() {
    cout << "Presione Enter para continuar...";
    string tmp; getline(cin, tmp);
    if (tmp.size() == 0) getline(cin, tmp);
}

int SelectorIndex(Tabling::Table& table, const std::string& prompt, unsigned int maxExclusive) {
    while (true) {
        rlutil::cls();
        table.Print();

        string entrada = InputBox(prompt);
        if (entrada.empty()) return -1;
        if (!Validation::IsNumeric(entrada)) continue;

        unsigned long idxLong = std::strtoul(entrada.c_str(), nullptr, 10);
        if (idxLong >= maxExclusive) continue;

        return static_cast<int>(idxLong);
    }
}
