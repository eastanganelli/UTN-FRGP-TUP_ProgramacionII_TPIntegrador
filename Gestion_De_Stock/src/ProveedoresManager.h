#ifndef PROVEEDORMANAGER_H
#define PROVEEDORMANAGER_H

#include "Proveedor.h"

#include <cstdio>
#include <string>

using namespace std;

class ProveedorManager {
private:
    const string rubros[6] = { "Textil", "Calzado", "Gastronomia", "Automotor", "Libreria", "Indumentaria" };
    string rutaArchivo;

    Proveedor* Listar();
    Proveedor* Redimensionar(Proveedor* proveedores, unsigned int capacidadActual, unsigned int nuevaCapacidad);
    void Imprimir(Proveedor* misProveedores, unsigned int cantidadProveedores);
    bool Existe(Proveedor& proveedor);
    int Posicion(string cuit, unsigned int& posicion);


public:
    ProveedorManager(string ruta);
    ~ProveedorManager();

    bool Crear(Proveedor& proveedor);
    Proveedor* SeleccionarRandom();
    Proveedor* Obtener(string cuit);
    Proveedor* operator[](string cuit);
    bool Modificar(string cuit, Proveedor* proveedorActualizado);
    bool Modificar(string cuit, Proveedor& proveedorActualizado);
    bool Eliminar(string cuit);

    void ListarXNombre();
    void ListarXRubro();
    void ListarXCUIT();
    void ConsultarXCUIT(string cuit);
    void ConsultarXNombre(string nombreRazon);
    void ConsultarXRubro(unsigned int rubro);
    void ConsultarXEstado(bool estado);
    unsigned int Contar();
    unsigned int SeleccionarRubro();
    string getNombreRubro(unsigned int cr);
};

#endif // PROVEEDORMANAGER_H
