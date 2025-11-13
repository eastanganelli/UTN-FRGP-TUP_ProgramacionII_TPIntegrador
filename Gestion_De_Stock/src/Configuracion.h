#ifndef CONFIGURACION_H
#define CONFIGURACION_H

#include <string>
#include <cstring>

using namespace std;

class Configuracion {
private:
    string rutaCopiaSeguridadClientes;
    string rutaCopiaSeguridadProveedores;
    string rutaCopiaSeguridadProductos;
    string rutaCopiaSeguridadFacturas;
    string rutaCopiaSeguridadNotasDeCredito;

public:
    Configuracion(string _rutaCopiaSeguridadClientes = "", string _rutaCopiaSeguridadProveedores = "", string _rutaCopiaSeguridadProductos = "", string _rutaCopiaSeguridadFacturas = "", string _rutaCopiaSeguridadNotasDeCredito = "");
    ~Configuracion();

    // Métodos
    bool cargarCopiaSeguridad();
    bool guardarCopiaSeguridad();
    bool cargarCopiaClientes();
    bool guardarCopiaClientes();
    bool cargarCopiaProveedores();
    bool guardarCopiaProveedores();
    bool cargarCopiaProductos();
    bool guardarCopiaProductos();
    bool cargarCopiaVentas();
    bool guardarCopiaVentas();

    bool exportarTodoCSV();
    bool exportarClientesCSV();
    bool exportarProveedoresCSV();
    bool exportarProductosCSV();
    bool exportarVentasCSV();
};

#endif // CONFIGURACION_H
