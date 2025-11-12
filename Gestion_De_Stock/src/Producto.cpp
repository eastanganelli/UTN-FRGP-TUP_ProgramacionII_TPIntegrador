#include "Producto.h"

Producto::Producto(string _codigo, string _codigoProveedor, string _descripcion, float _precio, unsigned int _stock) {
    strcpy(this->codigo, _codigo.c_str());
    strcpy(this->codigoProveedor, _codigoProveedor.c_str());
    strcpy(this->descripcion, _descripcion.c_str());
    this->precio = _precio;
    this->stock = _stock;
}

Producto::~Producto() {

}

string Producto::getCodigo() {
    return string(this->codigo, 8);
}

string Producto::getCodigoProveedor() {
    return string(this->codigoProveedor, 11);
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

void Producto::setPrecio(float p) {
    this->precio = p;
}

void Producto::setStock(unsigned int s) {
    this->stock = s;
}
