#include "Producto.h"

int Producto::getIDProducto() { return this->idProducto; }
const char* Producto::getNombre() { return this->nombre; }
const char* Producto::getDescripcion() { return this->descripcion; }
float Producto::getPrecio() { return this->precio; }
int Producto::getStock() { return this->stock; }

void Producto::setIDProducto(int id) { this->idProducto = id; }
void Producto::setNombre(const char* n) { strcpy(this->nombre, n); }
void Producto::setNombre(const string& n) { this->nombre = n; }
void Producto::setDescripcion(const char* d) { strcpy(this->descripcion, d); }
void Producto::setDescripcion(const string& d) { this->descripcion = d; }
void Producto::setPrecio(float p) { this->precio = p; }
void Producto::setStock(int s) { this->stock = s; }

void Producto::cargar() {
    cout << "ID Producto: ";
    cin >> this->idProducto;
    cout << "Nombre: ";
    cin.ignore(); // Limpiar buffer
    cin.getline(this->nombre, 100);
    cout << "Descripcion: ";
    cin.getline(this->descripcion, 150);
    cout << "Precio: ";
    cin >> this->precio;
    cout << "Stock: ";
    cin >> this->stock;
}

void Producto::mostrar() {
    cout << "ID Producto: " << this->idProducto << endl;
    cout << "Nombre: " << this->nombre << endl;
    cout << "Descripcion: " << this->descripcion << endl;
    cout << "Precio: $" << this->precio << endl;
    cout << "Stock: " << this->stock << " unidades" << endl;
}

bool Producto::escribirDisco(int pos) {
    cout << "Simulando escritura de Producto en disco..." << endl;
    return true;
}

bool Producto::leerDisco(int pos) {
    cout << "Simulando lectura de Producto desde disco..." << endl;
    return true;
}