#include "Producto.h"

Producto::Producto(string _codigo, string _codigoProveedor, string _descripcion, float _precio, unsigned int _stock) {
    this->codigo[0] = '\0';
    this->codigoProveedor[0] = '\0';
    this->descripcion[0] = '\0';
    strcpy(this->codigo, _codigo.c_str());
    strcpy(this->codigoProveedor, _codigoProveedor.c_str());
    strcpy(this->descripcion, _descripcion.c_str());
    this->precio = _precio;
    this->stock = _stock;
}

Producto::~Producto() { }

string Producto::getCodigo() { return string(this->codigo); }

string Producto::getCodigoProveedor() { return string(this->codigoProveedor); }

string Producto::getDescripcion() { return string(this->descripcion); }

float Producto::getPrecio() { return this->precio; }

unsigned int Producto::getStock() { return this->stock; }

void Producto::setDescripcion(string d) { strcpy(this->descripcion, d.c_str()); }

void Producto::setPrecio(float p) { this->precio = p; }

void Producto::setStock(unsigned int s) { this->stock = s; }

unsigned int Producto::GetCodigoLength() { return Producto::CODIGO_SIZE; }

unsigned int Producto::GetCodigoProveedorLength() { return Producto::CODIGOPROVEEDOR_SIZE; }

unsigned int Producto::GetDescripcionLength() { return Producto::DESCRIPCION_SIZE; }

unsigned int Producto::GetPrecioLength() { return Producto::PRECIO_SIZE; }

unsigned int Producto::GetStockLength() { return Producto::STOCK_SIZE; }

bool Producto::operator==(const Producto& otro) {
    return Validation::IsEqual(this->codigo, otro.codigo);
}

bool Producto::IsEmpty() {
    return Validation::IsEmpty(this->codigo) && Validation::IsEmpty(this->codigoProveedor)
        && Validation::IsEmpty(this->descripcion) && this->precio == 0.0f && this->stock == 0;
}

void Producto::Print() {
    cout << "Codigo: " + this->getCodigo() +
           " | Codigo Proveedor: " + this->getCodigoProveedor() +
           " | Descripcion: " + this->getDescripcion() +
           " | Precio: " + to_string(this->getPrecio()) +
           " | Stock: " + to_string(this->getStock());
}
