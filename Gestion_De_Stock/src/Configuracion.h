#ifndef CONFIGURACION_H
#define CONFIGURACION_H

#include <string>
#include <cstring>
#include <fstream>

using namespace std;

class Configuracion {
private:
    string rutaOrigenCopiaSeguridadClientes,
        rutaOrigenCopiaSeguridadProveedores,
        rutaOrigenCopiaSeguridadProductos,
        rutaOrigenCopiaSeguridadFacturas,
        rutaOrigenCopiaSeguridadNotasDeCredito;

    string rutaDestinoCopiaSeguridadClientes,
        rutaDestinoCopiaSeguridadProveedores,
        rutaDestinoCopiaSeguridadProductos,
        rutaDestinoCopiaSeguridadFacturas,
        rutaDestinoCopiaSeguridadNotasDeCredito;

    bool copiarArchivo(string origen, string destino);

public:
    Configuracion(string _rutaDestinoCopiaSeguridadClientes = "", string _rutaDestinoCopiaSeguridadProveedores = "", string _rutaDestinoCopiaSeguridadProductos = "", string _rutaDestinoCopiaSeguridadFacturas = "", string _rutaDestinoCopiaSeguridadNotasDeCredito = "",
    string _rutaOrigenCopiaSeguridadClientes = "", string _rutaOrigenCopiaSeguridadProveedores = "", string _rutaOrigenCopiaSeguridadProductos = "", string _rutaOrigenCopiaSeguridadFacturas = "", string _rutaOrigenCopiaSeguridadNotasDeCredito = "");
    ~Configuracion();

    // Métodos
    bool guardarCopiaClientes();
    bool cargarCopiaClientes();
    bool guardarCopiaProveedores();
    bool cargarCopiaProveedores();
    bool guardarCopiaProductos();
    bool cargarCopiaProductos();
    bool guardarCopiaVentas();
    bool cargarCopiaVentas();
    bool guardarCopiaNotasDeCredito();
    bool cargarCopiaNotasDeCredito();
    bool guardarCopiaSeguridad();
    bool cargarCopiaSeguridad();

    bool exportarTodoCSV();
    bool exportarClientesCSV();
    bool exportarProveedoresCSV();
    bool exportarProductosCSV();
    bool exportarVentasCSV();
};

#endif // CONFIGURACION_H
