#ifndef PROVEEDORMANAGER_H
#define PROVEEDORMANAGER_H

#include "Proveedor.h"

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

class ProveedorManager {
private:
    string rutaArchivo;

    int Posicion(string dni, unsigned int& posicion);
    bool Existe(Proveedor& proveedor);

public:
    ProveedorManager(string ruta);
    ~ProveedorManager();

    bool Crear(Proveedor& proveedor);
    Proveedor* Obtener(string dni);
    Proveedor* operator[](string dni);
    bool Modificar(string dni, Proveedor* proveedorActualizado);
    bool Modificar(string dni, Proveedor& proveedorActualizado);
    bool Eliminar(string dni);
    vector<Proveedor> Listar();

    unsigned int Contar();
};

#endif // PROVEEDORMANAGER_H
