#ifndef PROVEEDORMANAGER_H
#define PROVEEDORMANAGER_H

#include "Proveedor.h"

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

class ProveedorManager {
private:
    const string rubros[6] = { "Textil", "Calzado", "Gastronomia", "Automotor", "Libreria", "Indumentaria" };
    string rutaArchivo;

    int Posicion(string cuit, unsigned int& posicion);
    bool Existe(Proveedor& proveedor);
    Proveedor* Listar();
    Proveedor* Redimensionar(Proveedor* proveedores, unsigned int capacidadActual, unsigned int nuevaCapacidad);

public:
    ProveedorManager(string ruta);
    ~ProveedorManager();

    bool Crear(Proveedor& proveedor);
    Proveedor* Obtener(string cuit);
    Proveedor* operator[](string cuit);
    bool Modificar(string cuit, Proveedor* proveedorActualizado);
    bool Modificar(string cuit, Proveedor& proveedorActualizado);
    bool Eliminar(string cuit);

    Proveedor* ListarXNombre();
    Proveedor* ListarXRubro();
    Proveedor* ListarXCUIT();
    Proveedor* ConsultarXCUIT(string cuit);
    Proveedor* ConsultarXNombre(string nombreRazon);
    Proveedor* ConsultarXRubro(unsigned int rubro);
    Proveedor* ConsultarXEstado(bool estado);
    unsigned int Contar();
    unsigned int SeleccionarRubro();
    string getNombreRubro(unsigned int cr);
};

#endif // PROVEEDORMANAGER_H
