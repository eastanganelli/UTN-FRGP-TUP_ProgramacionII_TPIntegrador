#ifndef PRODUCTOMANAGER_H
#define PRODUCTOMANAGER_H

#include "Producto.h"

#include <cstdio>
#include <vector>
#include <string>

using namespace std;

class ProductoManager {
private:
    string rutaArchivo;

    int Posicion(string codigo, unsigned int& posicion);
    bool Existe(Producto& producto);

public:
    ProductoManager(string ruta);
    ~ProductoManager();

    bool Crear(Producto& producto);
    Producto* Obtener(string codigo);
    Producto* operator[](string codigo);
    bool Modificar(string codigo, Producto* productoActualizado);
    bool Modificar(string codigo, Producto& productoActualizado);
    bool Eliminar(string codigo);
    vector<Producto> Listar();

    unsigned int Contar();
};

#endif // PRODUCTOMANAGER_H
