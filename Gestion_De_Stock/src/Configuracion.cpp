#include "Configuracion.h"

Configuracion::Configuracion(string _rutaCopiaSeguridadClientes, string _rutaCopiaSeguridadProveedores, string _rutaCopiaSeguridadProductos, string _rutaCopiaSeguridadFacturas, string _rutaCopiaSeguridadNotasDeCredito) {
    this->rutaCopiaSeguridadClientes = _rutaCopiaSeguridadClientes;
    this->rutaCopiaSeguridadProveedores = _rutaCopiaSeguridadProveedores;
    this->rutaCopiaSeguridadProductos = _rutaCopiaSeguridadProductos;
    this->rutaCopiaSeguridadFacturas = _rutaCopiaSeguridadFacturas;
    this->rutaCopiaSeguridadNotasDeCredito = _rutaCopiaSeguridadNotasDeCredito;
}

Configuracion::~Configuracion() { }

bool Configuracion::cargarCopiaSeguridad() {
    return true;
}

bool Configuracion::guardarCopiaSeguridad() {
    return true;
}

bool Configuracion::cargarCopiaClientes() {
    
    return true;
}

bool Configuracion::guardarCopiaClientes() {
    return true;
}

bool Configuracion::cargarCopiaProveedores() {
    return true;
}

bool Configuracion::guardarCopiaProveedores() {
    return true;
}

bool Configuracion::cargarCopiaProductos() {
    return true;
}

bool Configuracion::guardarCopiaProductos() {
    return true;
}

bool Configuracion::cargarCopiaVentas() {
    return true;
}

bool Configuracion::guardarCopiaVentas() {
    return true;
}

bool Configuracion::exportarClientesCSV() {
    return true;
}

bool Configuracion::exportarProveedoresCSV() {
    return true;
}

bool Configuracion::exportarProductosCSV() {
    return true;
}

bool Configuracion::exportarVentasCSV() {
    return true;
}
