#ifndef CONFIGURACION_H
#define CONFIGURACION_H

#include <string>
#include <cstring>
#include <fstream>
#include <iostream>

#include "Cliente.h"
#include "Proveedor.h"
#include "Producto.h"
#include "Factura.h"
#include "NotaDeCredito.h"

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
    void ImprimirResultado(bool estado, string nombreArchivo);
    bool VerificarSiArchivoExiste(string rutaArchivo);

public:
    Configuracion(string _rutaDestinoCopiaSeguridadClientes = "", string _rutaDestinoCopiaSeguridadProveedores = "", string _rutaDestinoCopiaSeguridadProductos = "", string _rutaDestinoCopiaSeguridadFacturas = "", string _rutaDestinoCopiaSeguridadNotasDeCredito = "",
    string _rutaOrigenCopiaSeguridadClientes = "", string _rutaOrigenCopiaSeguridadProveedores = "", string _rutaOrigenCopiaSeguridadProductos = "", string _rutaOrigenCopiaSeguridadFacturas = "", string _rutaOrigenCopiaSeguridadNotasDeCredito = "");
    ~Configuracion();

    // Métodos
    void guardarCopiaClientes();
    void cargarCopiaClientes();
    void guardarCopiaProveedores();
    void cargarCopiaProveedores();
    void guardarCopiaProductos();
    void cargarCopiaProductos();
    void guardarCopiaVentas();
    void cargarCopiaVentas();
    void guardarCopiaNotasDeCredito();
    void cargarCopiaNotasDeCredito();
    void guardarCopiaSeguridad();
    void cargarCopiaSeguridad();

    void exportarTodoCSV();
    void exportarClientesCSV();
    void exportarProveedoresCSV();
    void exportarProductosCSV();
    void exportarVentasCSV();
    void exportarNotasDeCreditoCSV();
    void exportarTodo();
};

#endif // CONFIGURACION_H
