#ifndef WARNING_H
#define WARNING_H

#include <string>
#include <iostream>

#include "modal.h"

using namespace std;

class Warning : public Modal {
private:
    void PrintHeader();
    void PrintFooter();

public:
    Warning(const string& title, const string& message);
    ~Warning();
    void Show();
    bool ShowYesNo();
};

#endif // WARNING_H
