#ifndef PRUEBAS_H
#define PRUEBAS_H

#include <ctime>
#include <iostream>

#include "src/ClientesManager.h"
#include "src/ProveedoresManager.h"
#include "src/ProductosManager.h"
#include "src/VentasManager.h"

using namespace std;

void TestingCliente();

void TestingProveedores();

void TestingProductos();

void TestingVentas();

void TestingAll();

struct DatosCliente {
    std::string nombre;
    std::string apellido;
    std::string DNI;
    std::string cuilCuit;
    std::string direccion;
    std::string correo;
    std::string telefono;
    std::string celular;
    unsigned int codigoRazonSocial;
    bool alta;
};

struct DatosProveedor {
    std::string cuit;
    std::string nombreRazon;
    unsigned int rubro;
    std::string direccion;
    std::string correo;
    std::string telefono;
    std::string celular;
    unsigned int codigoRazonSocial;
    bool alta;
};

struct DatosProducto {
    std::string codigo;
    std::string codigoProveedor;
    std::string descripcion;
    float precio;
    unsigned int stock;
};

std::string generarCodigoAlfaNumerico(int longitud);

void loadData();

#endif // PRUEBAS_H
