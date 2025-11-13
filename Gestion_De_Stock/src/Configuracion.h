#ifndef CONFIGURACION_H
#define CONFIGURACION_H

#include <cstring>

using namespace std;

class Configuracion {
private:


public:
    Configuracion();
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
