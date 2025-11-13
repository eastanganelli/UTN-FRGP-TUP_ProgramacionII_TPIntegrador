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
    string nombreCSV = "clientes_exportados.csv";
    FILE* archivoBinario = fopen(this->rutaOrigenCopiaSeguridadClientes.c_str(), "rb"),
        * archivoCSV = fopen(nombreCSV.c_str(), "w+");
    if (archivoBinario == nullptr && archivoCSV == nullptr) {
        cout << "Error al abrir los archivos para exportacion." << endl;
        return;
    }
    Cliente cliente;
    fprintf(archivoCSV, "DNI,Nombre,Apellido,CUIL/CUIT,Direccion,Telefono,Email\n");
    while (fread(&cliente, sizeof(Cliente), 1, archivoBinario)) {
        fprintf(archivoCSV, "%s,%s,%s,%s,%s,%s,%s\n", cliente.getDNI().c_str(), cliente.getNombre().c_str(), cliente.getApellido().c_str(), cliente.getCuilCuit().c_str(),
        cliente.getDireccion().c_str(), cliente.getTelefono().c_str(), cliente.getCorreo().c_str());
    }
    fclose(archivoBinario);
    fclose(archivoCSV);
    cout << "Exportacion de clientes a CSV realizada con exito." << endl;
}

void Configuracion::exportarProveedoresCSV() {
    bool existe = this->VerificarSiArchivoExiste(this->rutaOrigenCopiaSeguridadProveedores);
    if (!existe) {
        cout << "El archivo de proveedores no existe. No se puede exportar a CSV." << endl;
        return;
    }
    string nombreCSV = "proveedores_exportados.csv";
    FILE* archivoBinario = fopen(this->rutaOrigenCopiaSeguridadClientes.c_str(), "rb"),
        * archivoCSV = fopen(nombreCSV.c_str(), "w+");
    if (archivoBinario == nullptr && archivoCSV == nullptr) {
        cout << "Error al abrir los archivos para exportacion." << endl;
        return;
    }
    Proveedor proveedor;
    fprintf(archivoCSV, "NombreRazon,CUIT,Direccion,Telefono,Email,Rubro\n");
    while (fread(&proveedor, sizeof(Proveedor), 1, archivoBinario)) {
        fprintf(archivoCSV, "%s,%s,%s,%s,%s,%s\n", proveedor.getNombreRazon().c_str(), proveedor.getCuit().c_str(), proveedor.getDireccion().c_str(),
        proveedor.getTelefono().c_str(), proveedor.getCorreo().c_str(), proveedor.getRubroNombre().c_str());
    }
    fclose(archivoBinario);
    fclose(archivoCSV);
    cout << "Exportacion de clientes a CSV realizada con exito." << endl;
}

void Configuracion::exportarProductosCSV() {
    bool existe = this->VerificarSiArchivoExiste(this->rutaOrigenCopiaSeguridadProductos);
    if (!existe) {
        cout << "El archivo de productos no existe. No se puede exportar a CSV." << endl;
        return;
    }
    string nombreCSV = "productos_exportados.csv";
    FILE* archivoBinario = fopen(this->rutaOrigenCopiaSeguridadProductos.c_str(), "rb"),
        * archivoCSV = fopen(nombreCSV.c_str(), "w+");
    if (archivoBinario == nullptr && archivoCSV == nullptr) {
        cout << "Error al abrir los archivos para exportacion." << endl;
        return;
    }
    Producto prod;
    fprintf(archivoCSV, "Codigo,Descripcion,ProveedorCodigo,Precio,CantidadStock\n");
    while (fread(&prod, sizeof(Producto), 1, archivoBinario)) {
        fprintf(archivoCSV, "%s,%s,%s,%.2f,%d\n", prod.getCodigo().c_str(), prod.getCodigoProveedor().c_str(), prod.getDescripcion().c_str(),
        prod.getPrecio(), prod.getStock());
    }
    fclose(archivoBinario);
    fclose(archivoCSV);
    cout << "Exportacion de productos a CSV realizada con exito." << endl;
}

void Configuracion::exportarVentasCSV() {
    bool existe = this->VerificarSiArchivoExiste(this->rutaOrigenCopiaSeguridadFacturas);
    if (!existe) {
        cout << "El archivo de ventas no existe. No se puede exportar a CSV." << endl;
        return;
    }
    string nombreCSV = "ventas_exportadas.csv";
    FILE* archivoBinario = fopen(this->rutaOrigenCopiaSeguridadFacturas.c_str(), "rb"),
        * archivoCSV = fopen(nombreCSV.c_str(), "w+");
    if (archivoBinario == nullptr && archivoCSV == nullptr) {
        cout << "Error al abrir los archivos para exportacion." << endl;
        return;
    }
    Factura fact;
    fprintf(archivoCSV, "Numero_Factura,Tipo,Fecha_Emision,CAE,Vencimiento_CAE,DNI_Cliente,Cantidad_Items,Total,Total_Con_IVA\n");
    while (fread(&fact, sizeof(Factura), 1, archivoBinario)) {
        fprintf(archivoCSV, "%d,%c,%s,%s,%s,%s,%d,%.2f,%.2f\n", fact.getNumero(),fact.getTipoFactura(), fact.getFechaEmision().toString().c_str(), fact.getCAE().c_str(),
                fact.getVencimientoCAE().toString().c_str(), fact.getClienteDNI().c_str(), fact.getCantidadItems(),fact.TotalSinIVA(),fact.TotalConIVA());
    }
    fclose(archivoBinario);
    fclose(archivoCSV);
    cout << "Exportacion de ventas a CSV realizada con exito." << endl;
}

void Configuracion::exportarNotasDeCreditoCSV() {
    bool existe = this->VerificarSiArchivoExiste(this->rutaOrigenCopiaSeguridadNotasDeCredito);
    if (!existe) {
        cout << "El archivo de notas de credito no existe. No se puede exportar a CSV." << endl;
        return;
    }
    string nombreCSV = "notas_de_credito_exportadas.csv";
    FILE* archivoBinario = fopen(this->rutaOrigenCopiaSeguridadNotasDeCredito.c_str(), "rb"),
        * archivoCSV = fopen(nombreCSV.c_str(), "w+");
    if (archivoBinario == nullptr && archivoCSV == nullptr) {
        cout << "Error al abrir los archivos para exportacion." << endl;
        return;
    }
    NotaDeCredito nota;
    fprintf(archivoCSV, "Numero_Nota,Fecha_Emision,Monto,DNI_Cliente\n");
    while (fread(&nota, sizeof(NotaDeCredito), 1, archivoBinario)) {
        fprintf(archivoCSV, "%d,%s,%.2f,%s\n", nota.getNumero(), nota.getFechaEmision().toString().c_str(),
        nota.getMonto(), nota.getClienteDNI().c_str());
    }
    fclose(archivoBinario);
    fclose(archivoCSV);
    cout << "Exportacion de notas de credito a CSV realizada con exito." << endl;
}

void Configuracion::exportarTodo() {
    this->exportarClientesCSV();
    this->exportarProveedoresCSV();
    this->exportarProductosCSV();
    this->exportarVentasCSV();
    this->exportarNotasDeCreditoCSV();
}
