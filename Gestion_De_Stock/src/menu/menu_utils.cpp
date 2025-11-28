#include "menu_utils.h"
#include <iostream>
#include <string>

using namespace std;

std::string InputBox(const std::string& prompt) {
    cout << prompt;
    string s;
    // consume newline from previous input if present
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
    // consume rest of line
    string tmp; getline(cin, tmp);
    return n;
}

bool Confirm(const std::string& prompt) {
    cout << prompt << " (s/N): ";
    string r;
    getline(cin, r);
    if (r.size() == 0) { getline(cin, r); }
    return (r.size() > 0 && (r[0] == 's' || r[0] == 'S' || r[0] == 'y' || r[0] == 'Y'));
}

void PauseConsole() {
    cout << "Presione Enter para continuar...";
    string tmp; getline(cin, tmp);
    if (tmp.size() == 0) getline(cin, tmp);
}
