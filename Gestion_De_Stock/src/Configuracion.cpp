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

void Configuracion::ImprimirResultado(bool estado, string nombreArchivo) {
    if (estado) {
        cout << "Copia de seguridad de " << nombreArchivo << " realizada con exito." << endl;
    } else {
        cout << "Error al realizar la copia de seguridad de " << nombreArchivo << "." << endl;
    }
}

bool Configuracion::VerificarSiArchivoExiste(string rutaArchivo) {
    ifstream src(rutaArchivo, ios::binary);
    if (!src) return false;
}

void Configuracion::guardarCopiaClientes() {
    bool resultado = this->copiarArchivo(this->rutaOrigenCopiaSeguridadClientes, this->rutaDestinoCopiaSeguridadClientes);
    this->ImprimirResultado(resultado, this->rutaOrigenCopiaSeguridadClientes);
}

void Configuracion::cargarCopiaClientes() {
    bool resultado = this->copiarArchivo(this->rutaDestinoCopiaSeguridadClientes, this->rutaOrigenCopiaSeguridadClientes);
    this->ImprimirResultado(resultado, this->rutaDestinoCopiaSeguridadClientes);
}

void Configuracion::guardarCopiaProveedores() {
    bool resultado = this->copiarArchivo(this->rutaOrigenCopiaSeguridadProveedores, this->rutaDestinoCopiaSeguridadProveedores);
    this->ImprimirResultado(resultado, this->rutaOrigenCopiaSeguridadProveedores);
}

void Configuracion::cargarCopiaProveedores() {
    bool resultado = this->copiarArchivo(this->rutaDestinoCopiaSeguridadProveedores, this->rutaOrigenCopiaSeguridadProveedores);
    this->ImprimirResultado(resultado, this->rutaDestinoCopiaSeguridadProveedores);
}

void Configuracion::guardarCopiaProductos() {
    bool resultado = this->copiarArchivo(this->rutaOrigenCopiaSeguridadProductos, this->rutaDestinoCopiaSeguridadProductos);
    this->ImprimirResultado(resultado, this->rutaOrigenCopiaSeguridadProductos);
}

void Configuracion::cargarCopiaProductos() {
    bool resultado = this->copiarArchivo(this->rutaDestinoCopiaSeguridadProductos, this->rutaOrigenCopiaSeguridadProductos);
    this->ImprimirResultado(resultado, this->rutaDestinoCopiaSeguridadProductos);
}

void Configuracion::guardarCopiaVentas() {
    bool resultado = this->copiarArchivo(this->rutaOrigenCopiaSeguridadFacturas, this->rutaDestinoCopiaSeguridadFacturas);
    this->ImprimirResultado(resultado, this->rutaOrigenCopiaSeguridadFacturas);
}

void Configuracion::cargarCopiaVentas() {
    bool resultado = this->copiarArchivo(this->rutaDestinoCopiaSeguridadFacturas, this->rutaOrigenCopiaSeguridadFacturas);
    this->ImprimirResultado(resultado, this->rutaDestinoCopiaSeguridadFacturas);
}

void Configuracion::guardarCopiaNotasDeCredito() {
    bool resultado = this->copiarArchivo(this->rutaOrigenCopiaSeguridadNotasDeCredito, this->rutaDestinoCopiaSeguridadNotasDeCredito);
    this->ImprimirResultado(resultado, this->rutaOrigenCopiaSeguridadNotasDeCredito);
}

void Configuracion::cargarCopiaNotasDeCredito() {
    bool resultado = this->copiarArchivo(this->rutaDestinoCopiaSeguridadNotasDeCredito, this->rutaOrigenCopiaSeguridadNotasDeCredito);
    this->ImprimirResultado(resultado, this->rutaDestinoCopiaSeguridadNotasDeCredito);
}

void Configuracion::guardarCopiaSeguridad() {
    guardarCopiaClientes();
    guardarCopiaProveedores();
    guardarCopiaProductos();
    guardarCopiaVentas();
    guardarCopiaNotasDeCredito();
}

void Configuracion::cargarCopiaSeguridad() {
    cargarCopiaClientes();
    cargarCopiaProveedores();
    cargarCopiaProductos();
    cargarCopiaVentas();
    cargarCopiaNotasDeCredito();
}

void Configuracion::exportarClientesCSV() {
    bool existe = this->VerificarSiArchivoExiste(this->rutaOrigenCopiaSeguridadClientes);
    if (!existe) {
        cout << "El archivo de clientes no existe. No se puede exportar a CSV." << endl;
        return;
    }

}

void Configuracion::exportarProveedoresCSV() {
    bool existe = this->VerificarSiArchivoExiste(this->rutaOrigenCopiaSeguridadProveedores);
    if (!existe) {
        cout << "El archivo de proveedores no existe. No se puede exportar a CSV." << endl;
        return;
    }
}

void Configuracion::exportarProductosCSV() {
    bool existe = this->VerificarSiArchivoExiste(this->rutaOrigenCopiaSeguridadProductos);
    if (!existe) {
        cout << "El archivo de productos no existe. No se puede exportar a CSV." << endl;
        return;
    }
}

void Configuracion::exportarVentasCSV() {
    bool existe = this->VerificarSiArchivoExiste(this->rutaOrigenCopiaSeguridadFacturas);
    if (!existe) {
        cout << "El archivo de ventas no existe. No se puede exportar a CSV." << endl;
        return;
    }
}

void Configuracion::exportarNotasDeCreditoCSV() {
    bool existe = this->VerificarSiArchivoExiste(this->rutaOrigenCopiaSeguridadNotasDeCredito);
    if (!existe) {
        cout << "El archivo de notas de credito no existe. No se puede exportar a CSV." << endl;
        return;
    }
}

void Configuracion::exportarTodo() {
    this->exportarClientesCSV();
    this->exportarProveedoresCSV();
    this->exportarProductosCSV();
    this->exportarVentasCSV();
    this->exportarNotasDeCreditoCSV();
}