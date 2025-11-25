#ifndef INFORMATIONAL_H
#define INFORMATIONAL_H

#include <string>
#include <iostream>

#include "modal.h"

using namespace std;

class Informational : public Modal {
private:
    void PrintHeader();
    void PrintFooter();

public:
    Informational(const string& title, const string& message);
    ~Informational();
    void Show();
    bool ShowYesNo();
};

#endif // INFORMATIONAL_H
