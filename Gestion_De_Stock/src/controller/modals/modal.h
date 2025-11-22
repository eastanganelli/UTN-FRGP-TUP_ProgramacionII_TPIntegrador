#ifndef MODAL_H
#define MODAL_H

#include <string>
#include <iostream>

#include "../../../rlutil.h"

using namespace std;

class Modal {
protected:
    const string title,
                 message;

    void ClearScreen();
    bool IsYes(char key);
    bool IsNo(char key);

public:
    Modal(const string& title, const string& message);
    virtual ~Modal();
    virtual void Show() = 0;
    virtual bool ShowYesNo() = 0;
    void WaitForKey();
};

#endif // MODAL_H
