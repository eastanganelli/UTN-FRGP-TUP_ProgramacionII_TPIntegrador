#include "Producto.h"

unsigned int Producto::getID() {
    return this->id;
}

unsigned int Producto::getCodigoProveedor() {
    return this->codigoProveedor;
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

void Producto::setID(unsigned int id) {
    this->id = id;
}

void Producto::setPrecio(float p) {
    this->precio = p;
}

void Producto::setStock(unsigned int s) {
    this->stock = s;
}
