#ifndef TABLE_H
#define TABLE_H

#include "../generic_array.h"
#include <iostream>

#include "row.h"

using namespace std;

namespace Tabling {
    class Table {
    private:
        const unsigned int rows;
        const char separator;
        unsigned int startY;
        unsigned int used;
        Tabling::Row** table_rows;

        void PrintSeparator(unsigned int y);

    public:
        Table(unsigned int _rows = 1, unsigned int _cols = 1, char _separator = '-', unsigned int _startY = 1);
        ~Table();

        void AddRow(Tabling::Row* row);
        void Print();
    };
}

#endif // TABLE_H
