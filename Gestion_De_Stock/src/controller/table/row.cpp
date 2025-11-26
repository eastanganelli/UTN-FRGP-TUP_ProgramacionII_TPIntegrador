#include "row.h"

Tabling::Row::Row(const unsigned int _cols) : cols(_cols), used(0) {
    this->cells = new Tabling::Cell*[_cols];
}

Tabling::Row::~Row() {
    for(unsigned int i = 0; i < this->used; i++) {
        delete this->cells[i];
    }
    delete[] this->cells;
}

void Tabling::Row::AddCell(string content, unsigned int width) {
    if(this->used >= this->cols) {
        return;
    }
    this->cells[used] = new Tabling::Cell(content, width);
    used++;
}

unsigned int Tabling::Row::GetWidth() const {
    unsigned int totalWidth = 0;
    for(unsigned int i = 0; i < this->cols; i++) {
        totalWidth += this->cells[i]->getWidth();
    }
    return totalWidth;
}

void Tabling::Row::PrintAt(unsigned int y) {
    unsigned int currentX = 1;
    for(unsigned int i = 0; i < this->cols; i++) {
        Tabling::Cell* cell = this->cells[i];
        rlutil::locate(currentX, y);
        std::cout << cell->getContent();
        currentX += cell->getWidth();
    }
}
