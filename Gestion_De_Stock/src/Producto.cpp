#include "Producto.h"

int Producto::getID() {
    return this->id;
}

string Producto::getNombre() {
    return string(this->nombre);
}

string Producto::getDescripcion() {
    return string(this->descripcion);
}

float Producto::getPrecio() {
    return this->precio;
}

unsigned int Producto::getStock() {
    return this->stock;
}

void Producto::setID(int id) {
    this->id = id;
}

void Producto::setNombre(const string& n) {
    strcpy(this->nombre, n.c_str());
}

void Producto::setDescripcion(const string& d) {
    strcpy(this->descripcion, d.c_str());
}

void Producto::setPrecio(float p) {
    this->precio = p;
}

void Producto::setStock(unsigned int s) {
    this->stock = s;
}