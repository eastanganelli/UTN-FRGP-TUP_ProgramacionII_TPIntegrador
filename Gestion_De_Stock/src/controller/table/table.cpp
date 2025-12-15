#include "table.h"

Tabling::Table::Table(unsigned int _rows, unsigned int _cols, char _separator, unsigned int _startY)
    : rows(_rows + 3), separator(_separator), startY(_startY == 0 ? 1 : _startY), used(0) {
    this->table_rows = new Tabling::Row*[_rows + 1];
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
    this->table_rows[used] = row;
    used++;
}

void Tabling::Table::Print() {
    unsigned int yStart = this->startY == 0 ? 1 : this->startY;
    for(unsigned int i = 0, y = yStart; i < this->rows; y++) {
        Tabling::Row* row = this->table_rows[i];
        if(y == yStart) {
            rlutil::saveDefaultColor();
            rlutil::setBackgroundColor(rlutil::BLUE);
            rlutil::setColor(rlutil::WHITE);
            row->PrintAt(y);
            rlutil::resetColor();
            i++;
        }
        else if(y == yStart + 1) {
            this->PrintSeparator(y);
        } else if(y > yStart + 1 && y < yStart + this->rows - 1) {
            row->PrintAt(y);
            i++;
        }
        else if(y == yStart + this->rows - 1) {
            this->PrintSeparator(y);
            cout << endl;
            break;
        }
    }
}
