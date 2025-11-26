#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <string>

#include "../../../rlutil.h"

using namespace std;

namespace Tabling {
    class Cell {
    private:
        string content;
        unsigned int width;
    public:
        Cell(const string& content = "", unsigned int width = 10);
        ~Cell();

        string getContent() const;
        unsigned int getWidth() const;
    };
}

#endif // CELL_H