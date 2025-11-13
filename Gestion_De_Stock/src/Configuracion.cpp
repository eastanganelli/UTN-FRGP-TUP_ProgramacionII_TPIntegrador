#include "Configuracion.h"

Configuracion::Configuracion() { }

Configuracion::~Configuracion() { }

// Métodos
bool Configuracion::cargarCopiaSeguridad() { return true; }
bool Configuracion::guardarCopiaSeguridad() { return true; }
bool Configuracion::cargarCopiaClientes() { return true; }
bool Configuracion::guardarCopiaClientes() { return true; }
bool Configuracion::cargarCopiaProveedores() { return true; }
bool Configuracion::guardarCopiaProveedores() { return true; }
bool Configuracion::cargarCopiaProductos() { return true; }
bool Configuracion::guardarCopiaProductos() { return true; }
bool Configuracion::cargarCopiaVentas() { return true; }
bool Configuracion::guardarCopiaVentas() { return true; }
bool Configuracion::exportarClientesCSV() { return true; }
bool Configuracion::exportarProveedoresCSV() { return true; }
bool Configuracion::exportarProductosCSV() { return true; }
bool Configuracion::exportarVentasCSV() { return true; }
