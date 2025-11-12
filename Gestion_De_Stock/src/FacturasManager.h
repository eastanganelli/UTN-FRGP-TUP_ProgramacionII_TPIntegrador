#ifndef FACTURAMANAGER_H
#define FACTURAMANAGER_H

#include "Factura.h"

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

class FacturaManager {
private:
    vector<Factura*> facturas;
    string rutaArchivo;

public:
    FacturaManager(string ruta);

    void agregar(Factura* fact);
    bool eliminar(int idVenta);
    Factura* buscar(int idVenta);
    int obtenerIndice(int idVenta);

    int getCantidad();
    Factura* getPorIndice(int index);

    void listarTodos();

    bool cargarDeArchivo();
    bool escribirArchivo();
};

#endif // FACTURAMANAGER_H
