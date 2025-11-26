#ifndef ROW_H
#define ROW_H

#include "../generic_array.h"
#include "cell.h"

using namespace std;

namespace Tabling {
    class Row {
    private:
        const unsigned int cols;
        unsigned int used;
        Tabling::Cell** cells;

    public:
        Row(const unsigned int _cols = 1);
        ~Row();

        void AddCell(string content, unsigned int width = 10);
        unsigned int GetWidth() const;
        void PrintAt(unsigned int y);
    };
}

#endif // ROW_H
