#include "table.h"

Tabling::Table::Table(unsigned int _rows, unsigned int _cols, char _separator, unsigned int _startY)
    : rows(_rows + 3), separator(_separator), startY(_startY == 0 ? 1 : _startY), used(0), capacity(_rows + 1) {
    this->table_rows = new Tabling::Row*[this->capacity];
}

Tabling::Table::~Table() {
    for(unsigned int i = 0; i < this->used; i++) {
        delete this->table_rows[i];
    }
    delete[] this->table_rows;
}

void Tabling::Table::PrintSeparator(unsigned int y) {
    unsigned int totalWidth = this->table_rows[0]->GetWidth();
    string line(totalWidth, this->separator);
    rlutil::locate(1, y);
    cout << line;
}

void Tabling::Table::AddRow(Tabling::Row* row) {
    if (used >= capacity) {
        delete row; // avoid overflow and heap corruption
        return;
    }
    this->table_rows[used] = row;
    used++;
}

void Tabling::Table::Print() {
    if (this->used == 0) return;

    unsigned int y = this->startY == 0 ? 1 : this->startY;

    // header
    rlutil::saveDefaultColor();
    rlutil::setBackgroundColor(rlutil::BLUE);
    rlutil::setColor(rlutil::WHITE);
    this->table_rows[0]->PrintAt(y);
    rlutil::resetColor();
    y++;

    // separator
    this->PrintSeparator(y);
    y++;

    // body rows
    for (unsigned int i = 1; i < this->used; ++i, ++y) {
        Tabling::Row* row = this->table_rows[i];
        if (row != nullptr) {
            row->PrintAt(y);
        }
    }

    // bottom separator
    this->PrintSeparator(y);
    cout << endl;
}
