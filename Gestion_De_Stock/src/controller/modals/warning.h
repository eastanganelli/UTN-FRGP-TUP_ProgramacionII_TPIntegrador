#ifndef WARNING_H
#define WARNING_H

#include <string>
#include <iostream>

#include "modal.h"

using namespace std;

class Warning : public Modal {

public:
    Warning(const string& title, const string& message);
    ~Warning();
    void Show();
    bool ShowYesNo();
};

#endif // WARNING_H
