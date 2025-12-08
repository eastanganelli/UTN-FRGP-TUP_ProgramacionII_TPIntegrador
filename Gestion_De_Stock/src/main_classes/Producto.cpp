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

Producto Producto::NuevoProducto() {
    Producto producto;
    string v;

    // Descripcion (no vacio, longitud max)
    while (true) {
        v = InputBox("Descripcion: ");
        if (Validation::IsEmpty(v) || v.length() >= DESCRIPCION_SIZE) {
            Warning w("Descripcion invalida", "Ingrese una descripcion valida y de longitud aceptable.");
            w.Show(); w.WaitForKey();
            continue;
        }
        producto.setDescripcion(v);
        break;
    }

    // Precio (numero float, > 0)
    while (true) {
        v = InputBox("Precio: ");
        float p = 0.0f;
        if (sscanf(v.c_str(), "%f", &p) != 1) { p = 0.0f; }
        if (!Validation::IsPositiveNumber(p) || p < 0.01f || p > 9999.99f) {
            Warning w("Precio invalido", "Ingrese un precio valido (numerico, mayor a 0).");
            w.Show(); w.WaitForKey();
            continue;
        }
        producto.setPrecio(p);
        break;
    }

    // Stock (numero entero >= 0)
    while (true) {
        unsigned int s = InputNumber("Stock inicial: ");
        if (!Validation::IsInRange<unsigned int>(s, 0u, 100000u)) {
            Warning w("Stock invalido", "Ingrese un stock valido (0 - 100000).");
            w.Show(); w.WaitForKey();
            continue;
        }
        producto.setStock(s);
        break;
    }

    return producto;
}

void Producto::ModificarProducto(Producto& producto) {
    unsigned int opcion = 0;
    string entrada;
    do {
        rlutil::cls();
        cout << "-- Modificar Producto (codigo: " << producto.getCodigo() << ") --\n";
        cout << "1) Descripcion: " << producto.getDescripcion() << "\n";
        cout << "2) Precio: " << producto.getPrecio() << "\n";
        cout << "3) Stock: " << producto.getStock() << "\n";
        cout << "4) Terminar\n";

        opcion = InputNumber("Seleccione campo a modificar: ");

        switch(opcion) {
            case 1: {
                while (true) {
                    entrada = InputBox("Nueva Descripcion: ");
                    if (Validation::IsEmpty(entrada) || entrada.length() >= DESCRIPCION_SIZE) {
                        Warning w("Descripcion invalida", "Ingrese una descripcion valida y de longitud aceptable.");
                        w.Show(); w.WaitForKey();
                        continue;
                    }
                    producto.setDescripcion(entrada);
                    Informational i("Descripcion modificada", "Descripcion actualizada correctamente.");
                    i.Show(); i.WaitForKey();
                    break;
                }
                break;
            }
            case 2: {
                while (true) {
                    entrada = InputNumber("Nuevo Precio: ");
                    float p = 0.0f;
                    if (sscanf(entrada.c_str(), "%f", &p) != 1) { p = 0.0f; }
                    if (!Validation::IsPositiveNumber(p) || p < 0.01f || p > 9999.99f) {
                        Warning w("Precio invalido", "Ingrese un precio valido (numerico, mayor a 0).");
                        w.Show(); w.WaitForKey();
                        continue;
                    }
                    producto.setPrecio(p);
                    Informational i("Precio modificado", "Precio actualizado correctamente.");
                    i.Show(); i.WaitForKey();
                    break;
                }
                break;
            }
            case 3: {
                while (true) {
                    unsigned int s = InputNumber("Nuevo Stock: ");
                    if (!Validation::IsInRange<unsigned int>(s, 0u, 100000u)) {
                        Warning w("Stock invalido", "Ingrese un stock valido (0 - 100000).");
                        w.Show(); w.WaitForKey();
                        continue;
                    }
                    producto.setStock(s);
                    Informational i("Stock modificado", "Stock actualizado correctamente.");
                    i.Show(); i.WaitForKey();
                    break;
                }
                break;
            }
            case 4: {
                break;
            }
            default: {
                Warning w("Opcion invalida", "Seleccione una opcion valida (1-4).");
                w.Show(); w.WaitForKey();
                break;
            }
        }
    } while (opcion != 4);
    rlutil::cls();
}

unsigned int Producto::EliminarProducto(Producto& producto) {
    Warning w("Eliminar Producto", "Esta seguro que desea eliminar este producto?");
    if (w.ShowYesNo()) {
        return 1;
    }
    return 0;
}

