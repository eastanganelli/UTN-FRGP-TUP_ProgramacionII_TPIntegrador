#ifndef PRODUCTOMANAGER_H
#define PRODUCTOMANAGER_H

#include "Producto.h"

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

class ProductoManager {
private:
    vector<Producto> productos;
    string rutaArchivo;

public:
    ProductoManager(string ruta);

    void agregar(Producto& prod);
    bool eliminar(int id);
    Producto* buscar(int id);
    int obtenerIndice(int id);

    int getCantidad();
    Producto getPorIndice(int index);
    
    void listarTodos();

    bool cargarDeArchivo();
    bool escribirArchivo();
};

#endif // PRODUCTOMANAGER_H