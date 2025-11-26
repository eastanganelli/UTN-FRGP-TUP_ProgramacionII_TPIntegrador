#include "cell.h"

Tabling::Cell::Cell(const string& content, unsigned int width) : content(content), width(width) { }

Tabling::Cell::~Cell() { }

string Tabling::Cell::getContent() const { return this->content; }

unsigned int Tabling::Cell::getWidth() const { return this->width; }