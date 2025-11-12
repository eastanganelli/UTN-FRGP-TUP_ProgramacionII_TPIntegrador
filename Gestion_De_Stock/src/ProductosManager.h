#ifndef PRODUCTOMANAGER_H
#define PRODUCTOMANAGER_H

#include "Producto.h"

#include <cstdio>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

class ProductoManager {
private:
    string rutaArchivo;

    int Posicion(string codigo, unsigned int& posicion);
    bool Existe(string codigo);
    bool Existe(Producto& producto);
    Producto* Listar();

public:
    ProductoManager(string ruta);
    ~ProductoManager();

    bool Crear(Producto& producto);
    Producto* Obtener(string codigo);
    Producto* operator[](string codigo);
    bool Modificar(string codigo, Producto* productoActualizado);
    bool Modificar(string codigo, Producto& productoActualizado);
    bool Eliminar(string codigo);

    unsigned int Contar();
    string generarCodigo();
};

#endif // PRODUCTOMANAGER_H
