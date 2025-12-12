#include "Producto.h"
#include "../controller/modals.h"
#include "../menu/menu_utils.h"
#include <cstdio>

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

unsigned int Producto::GetCodigoSize() { return Producto::CODIGO_SIZE; }

unsigned int Producto::GetCodigoProveedorSize() { return Producto::CODIGOPROVEEDOR_SIZE; }

unsigned int Producto::GetDescripcionSize() { return Producto::DESCRIPCION_SIZE; }

unsigned int Producto::GetPrecioSize() { return Producto::PRECIO_SIZE; }

unsigned int Producto::GetStockSize() { return Producto::STOCK_SIZE; }

unsigned int Producto::ColCodigoSize() { return Producto::COL_Codigo; }

unsigned int Producto::ColCodigoProveedorSize() { return Producto::COL_CodigoProveedor; }

unsigned int Producto::ColDescripcionSize() { return Producto::COL_Descripcion; }

unsigned int Producto::ColPrecioSize() { return Producto::COL_Precio; }

unsigned int Producto::ColStockSize() { return Producto::COL_Stock; }

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

// Interactive methods moved to menu layer (producto_menu)

