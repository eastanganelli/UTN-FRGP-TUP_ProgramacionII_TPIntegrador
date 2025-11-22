#ifndef ERROR_H
#define ERROR_H

#include <string>
#include <iostream>

#include "modal.h"

using namespace std;

class Error : public Modal {

public:
    Error(const string& title, const string& message);
    ~Error();
    void Show();
    bool ShowYesNo();
};

#endif // ERROR_H
