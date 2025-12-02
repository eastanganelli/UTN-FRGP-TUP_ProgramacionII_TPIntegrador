#include "table.h"

Tabling::Table::Table(unsigned int _rows, unsigned int _cols, char _separator) : rows(_rows + 3), separator(_separator), used(0) {
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
    for(unsigned int i = 0, y = 1; i < this->rows; y++) {
        Tabling::Row* row = this->table_rows[i];
        if(y == 1) {
            rlutil::saveDefaultColor();
            rlutil::setBackgroundColor(rlutil::BLUE);
            rlutil::setColor(rlutil::WHITE);
            row->PrintAt(y);
            rlutil::resetColor();
            i++;
        }
        else if(y == 2) {
            this->PrintSeparator(y);
        } else if(y > 2 && y < this->rows) {
            row->PrintAt(y);
            i++;
        }
        else if(y == this->rows) {
            this->PrintSeparator(y);
            cout << endl;
            break;
        }
    }
}
