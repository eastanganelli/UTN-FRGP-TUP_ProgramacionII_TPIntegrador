#include "Producto.h"

Producto::Producto(string _codigo, string _codigoProveedor, string _descripcion, float _precio, unsigned int _stock) {
    this->codigo[0] = '\0';
    this->codigoProveedor[0] = '\0';
    this->descripcion[0] = '\0';

    if (Validation::IsEmpty(_codigo)) {
        string generado = Producto::GenerarCodigo();
        strcpy(this->codigo, generado.c_str());
    } else {
        strcpy(this->codigo, _codigo.c_str());
    }

    setCodigoProveedor(_codigoProveedor);
    strcpy(this->descripcion, _descripcion.c_str());
    this->precio = _precio;
    this->stock = _stock;
}

Producto::~Producto() { }

string Producto::getCodigo() { return string(this->codigo, CODIGO_SIZE); }

string Producto::getCodigoProveedor() { return string(this->codigoProveedor, CODIGOPROVEEDOR_SIZE); }

string Producto::getDescripcion() { return string(this->descripcion); }

float Producto::getPrecio() { return this->precio; }

unsigned int Producto::getStock() { return this->stock; }

void Producto::setDescripcion(string d) { strcpy(this->descripcion, d.c_str()); }

void Producto::setPrecio(float p) { this->precio = p; }

void Producto::setStock(unsigned int s) { this->stock = s; }

void Producto::setCodigo(const string& c) {
    if (Validation::IsEmpty(c) || c.length() >= CODIGO_SIZE || !Validation::IsAlphanumeric(c)) {
        this->codigo[0] = '\0';
        return;
    }
    strcpy(this->codigo, c.c_str());
}

void Producto::setCodigoProveedor(const string& c) {
    if (Validation::IsEmpty(c) || c.length() >= CODIGOPROVEEDOR_SIZE || !Validation::IsAlphanumeric(c)) {
        this->codigoProveedor[0] = '\0';
        return;
    }
    strcpy(this->codigoProveedor, c.c_str());
}

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

string Producto::GenerarCodigo() {
    return DataGenerator::generarCodigoAlfaNumerico(CODIGO_SIZE);
}

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
