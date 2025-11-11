#include "../include/Item.h"

Item::Item() : codigoProducto(0), cantidad(0), precioUnitario(0.0f) {
    strcpy(this->descripcion, "");
}

Item::Item(unsigned int id, unsigned int codigoProducto, string descripcion, unsigned int cantidad, float precioUnitario) {
    this->codigoProducto = codigoProducto;
    strcpy(this->descripcion, descripcion.c_str());
    this->cantidad = cantidad;
    this->precioUnitario = precioUnitario;
}

Item::~Item() {
    // Destructor
}
unsigned int Item::getCodigoProducto() {
    return this->codigoProducto;
}

unsigned int Item::getCantidad() {
    return this->cantidad;
}

float Item::getPrecioUnitario() {
    return this->precioUnitario;
}

float Item::getPrecioTotal() {
    return this->cantidad * this->precioUnitario;
}

void Item::setCodigoProducto(unsigned int id) {
    this->codigoProducto = id;
}

void Item::setCantidad(unsigned int cant) {
    this->cantidad = cant;
}

void Item::setPrecioUnitario(float precio) {
    this->precioUnitario = precio;
}

void Item::operator=(Item& item) {
    this->codigoProducto = item.codigoProducto;
    strcpy(this->descripcion, item.descripcion);
    this->precioUnitario = item.precioUnitario;
}

std::ostream& operator<<(std::ostream& os, Item* obj) {
    os << "ID: " << ", Codigo Producto: " << obj->getCodigoProducto()
       << ", Descripcion: " << ", Cantidad: " << obj->getCantidad()
       << ", Precio Unitario: " << obj->getPrecioUnitario()
       << ", Precio Total: " << obj->getPrecioTotal();
    return os;
}
