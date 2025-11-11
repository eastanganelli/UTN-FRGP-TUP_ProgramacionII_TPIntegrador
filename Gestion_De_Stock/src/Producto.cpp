#include "../include/Producto.h"

string Producto::getCodigo() {
    return string(this->codigo);
}

string Producto::getCodigoProveedor() {
    return string(this->codigoProveedor);
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

void Producto::setCodigo(string c) {
    strcpy(this->codigo, c.c_str());
}

void Producto::setPrecio(float p) {
    this->precio = p;
}

void Producto::setStock(unsigned int s) {
    this->stock = s;
}
