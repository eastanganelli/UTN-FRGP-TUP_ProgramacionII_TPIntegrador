#include "Configuracion.h"

Configuracion::Configuracion(string _rutaDestinoCopiaSeguridadClientes, string _rutaDestinoCopiaSeguridadProveedores, string _rutaDestinoCopiaSeguridadProductos, string _rutaDestinoCopiaSeguridadFacturas, string _rutaDestinoCopiaSeguridadNotasDeCredito,
    string _rutaOrigenCopiaSeguridadClientes, string _rutaOrigenCopiaSeguridadProveedores, string _rutaOrigenCopiaSeguridadProductos, string _rutaOrigenCopiaSeguridadFacturas, string _rutaOrigenCopiaSeguridadNotasDeCredito) {
    this->rutaDestinoCopiaSeguridadClientes = _rutaDestinoCopiaSeguridadClientes;
    this->rutaDestinoCopiaSeguridadProveedores = _rutaDestinoCopiaSeguridadProveedores;
    this->rutaDestinoCopiaSeguridadProductos = _rutaDestinoCopiaSeguridadProductos;
    this->rutaDestinoCopiaSeguridadFacturas = _rutaDestinoCopiaSeguridadFacturas;
    this->rutaDestinoCopiaSeguridadNotasDeCredito = _rutaDestinoCopiaSeguridadNotasDeCredito;

    this->rutaOrigenCopiaSeguridadClientes = _rutaOrigenCopiaSeguridadClientes;
    this->rutaOrigenCopiaSeguridadProveedores = _rutaOrigenCopiaSeguridadProveedores;
    this->rutaOrigenCopiaSeguridadProductos = _rutaOrigenCopiaSeguridadProductos;
    this->rutaOrigenCopiaSeguridadFacturas = _rutaOrigenCopiaSeguridadFacturas;
    this->rutaOrigenCopiaSeguridadNotasDeCredito = _rutaOrigenCopiaSeguridadNotasDeCredito;
}

Configuracion::~Configuracion() { }

bool Configuracion::copiarArchivo(string origen, string destino) {
    ifstream src(origen, ios::binary);
    ofstream dst(destino, ios::binary);

    if (!src || !dst) return false;
    dst << src.rdbuf();
    if (src.fail() || dst.fail()) return false;

    return true;
}

bool Configuracion::guardarCopiaClientes() {
    return this->copiarArchivo(this->rutaOrigenCopiaSeguridadClientes, this->rutaDestinoCopiaSeguridadClientes);
}

bool Configuracion::cargarCopiaClientes() {
    return this->copiarArchivo(this->rutaDestinoCopiaSeguridadClientes, this->rutaOrigenCopiaSeguridadClientes);
}

bool Configuracion::guardarCopiaProveedores() {
    return this->copiarArchivo(this->rutaOrigenCopiaSeguridadProveedores, this->rutaDestinoCopiaSeguridadProveedores);
}

bool Configuracion::cargarCopiaProveedores() {
    return this->copiarArchivo(this->rutaDestinoCopiaSeguridadProveedores, this->rutaOrigenCopiaSeguridadProveedores);
}

bool Configuracion::guardarCopiaProductos() {
    return this->copiarArchivo(this->rutaOrigenCopiaSeguridadProductos, this->rutaDestinoCopiaSeguridadProductos);
}

bool Configuracion::cargarCopiaProductos() {
    return this->copiarArchivo(this->rutaDestinoCopiaSeguridadProductos, this->rutaOrigenCopiaSeguridadProductos);
}

bool Configuracion::guardarCopiaVentas() {
    return this->copiarArchivo(this->rutaOrigenCopiaSeguridadFacturas, this->rutaDestinoCopiaSeguridadFacturas);
}

bool Configuracion::cargarCopiaVentas() {
    return this->copiarArchivo(this->rutaDestinoCopiaSeguridadFacturas, this->rutaOrigenCopiaSeguridadFacturas);
}

bool Configuracion::guardarCopiaNotasDeCredito() {
    return this->copiarArchivo(this->rutaOrigenCopiaSeguridadNotasDeCredito, this->rutaDestinoCopiaSeguridadNotasDeCredito);
}

bool Configuracion::cargarCopiaNotasDeCredito() {
    return this->copiarArchivo(this->rutaDestinoCopiaSeguridadNotasDeCredito, this->rutaOrigenCopiaSeguridadNotasDeCredito);
}

bool Configuracion::guardarCopiaSeguridad() {
    bool ok = true;
    ok &= guardarCopiaClientes();
    ok &= guardarCopiaProveedores();
    ok &= guardarCopiaProductos();
    ok &= guardarCopiaVentas();
    ok &= guardarCopiaNotasDeCredito();
    return ok;
}

bool Configuracion::cargarCopiaSeguridad() {
    bool ok = true;
    ok &= cargarCopiaClientes();
    ok &= cargarCopiaProveedores();
    ok &= cargarCopiaProductos();
    ok &= cargarCopiaVentas();
    ok &= cargarCopiaNotasDeCredito();
    return ok;
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
