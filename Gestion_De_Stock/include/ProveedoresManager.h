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
    const string rubros[6] = { "Textil", "Calzado", "Gastronomia", "Automotor", "Libreria", "Indumentaria" };
    string rutaArchivo;

    int Posicion(string cuit, unsigned int& posicion);
    bool Existe(Proveedor& proveedor);

public:
    ProveedorManager(string ruta);
    ~ProveedorManager();

    bool Crear(Proveedor& proveedor);
    Proveedor* Obtener(string cuit);
    Proveedor* operator[](string cuit);
    bool Modificar(string cuit, Proveedor* proveedorActualizado);
    bool Modificar(string cuit, Proveedor& proveedorActualizado);
    bool Eliminar(string cuit);
    vector<Proveedor> Listar();

    unsigned int Contar();
    void ImprimirRubros();
    string getNombreRubro(unsigned int cr);
};

#endif // PROVEEDORMANAGER_H
