#include "Pruebas.h"

void TestingCliente() {
    ClienteManager clientes("Clientes.dat");

    clientes.ListarXApellido();
    clientes.ListarXDNI();
    clientes.ListarXcuilcuit();
}

void TestingProveedores() {
    ProveedorManager proveedores("Proveedores.dat");
    //proveedores.SeleccionarRubro();

    cout << "----- Listados de Proveedores -----" << endl;

    proveedores.ListarXNombre();
}

void TestingProductos() {
    ProductoManager productos("Productos.dat");

    cout << "----- Listados de Productos -----" << endl;

    productos.ListarXCodigo();

    string descripcionBuscada = "Monitor";

    //loadData();
    /*
    Producto* listarxStock = productos.ListarXStock();
    for (unsigned int i = 0; i < productos.Contar(); i++) {
        std::cout << "Producto " << i + 1 << ": " << listarxStock[i].getCodigo()
                  << " | Stock: " << listarxStock[i].getStock() << std::endl;
    }

    string codigoBuscado = listarxStock[5].getCodigo();
    Producto* productosBuscado = productos.ConsultaXCodigo(codigoBuscado);
    if (productosBuscado != nullptr) {
            std::cout << "\nProducto buscado por codigo " << codigoBuscado << ": "
                      << productosBuscado->getCodigo() << " | Descripcion: " << productosBuscado->getDescripcion()
                      << " | Precio: " << productosBuscado->getPrecio() << " | Stock: " << productosBuscado->getStock() << std::endl;
    }

    delete[] listarxStock;
    delete[] productosBuscado;

    Producto* listarxDescripcion = productos.ListarXPrecio();
    for (unsigned int i = 0; i < productos.Contar(); i++) {
        std::cout << "Producto " << i + 1 << ": " << listarxDescripcion[i].getCodigo()
                  << " | Precio: " << listarxDescripcion[i].getPrecio() << std::endl;
    }

    string descripcionBuscada = listarxDescripcion[3].getDescripcion();
    Producto* productosBuscadoDesc = productos.ConsultaXDescripcion(descripcionBuscada);
    if (productosBuscadoDesc != nullptr) {
            std::cout << "\nProducto buscado por descripcion " << descripcionBuscada << ": "
                      << productosBuscadoDesc->getCodigo() << " | Descripcion: " << productosBuscadoDesc->getDescripcion()
                      << " | Precio: " << productosBuscadoDesc->getPrecio() << " | Stock: " << productosBuscadoDesc->getStock() << std::endl;
    }

    delete[] listarxDescripcion;
    delete[] productosBuscadoDesc;
    */
}

void TestingVentas() {
    VentaManager misComprobantes("Facturas.dat", "NotaDeCredito.dat");

    bool resultado = misComprobantes.NuevaFactura("39068857", 'A');
    std::cout << "Factura creada? >> " << (resultado ? "Si" : "No") << std::endl;

    Factura* factura = misComprobantes.ObtenerFactura(1);
    if(factura != nullptr) {
        cout << factura->toString() << endl;
    }

}

std::string generarCodigoAlfaNumerico(int longitud) {
    const char caracteresPosibles[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    const int numCaracteresPosibles = sizeof(caracteresPosibles) - 1;
    std::string codigoGenerado = "";
    for (int i = 0; i < longitud; ++i) {
        codigoGenerado += caracteresPosibles[rand() % numCaracteresPosibles];
    }
    return codigoGenerado;
}

void loadData() {
    srand(static_cast<unsigned int>(time(NULL)));
    ClienteManager clientes("Clientes.dat");
    ProveedorManager proveedores("Proveedores.dat");
    ProductoManager productos("Productos.bin");

    string nombres[]   = {"Juan", "Maria", "Carlos", "Ana", "Luis", "Sofia", "Miguel", "Laura", "Diego", "Elena",
                          "Jorge", "Carmen", "Pedro", "Lucia", "Andres", "Marta", "Fernando", "Isabel", "Ricardo", "Patricia", "Alberto", "Gabriela"},
           apellidos[] = {"Perez", "Gomez", "Rodriguez", "Lopez", "Garcia", "Martinez", "Sanchez", "Ramirez", "Torres", "Flores",
                          "Diaz", "Vargas", "Castro", "Rojas", "Silva", "Molina", "Suarez", "Ortega", "Gutierrez", "Jimenez", "Morales", "Alvarez"},
           calles[]    = {"Calle Falsa", "Avenida Siempreviva", "Boulevard Central", "Pasaje del Sol", "Camino Real",
                          "Paseo de las Flores", "Calle del Lago", "Avenida de la Libertad", "Callejón del Beso", "Paseo del Parque",
                          "Calle de la Amistad", "Avenida del Mar", "Boulevard de los Sueños", "Pasaje de la Luna", "Camino del Viento"},
            // la descripcion de los productos deberia tener el tipo de producto
            descripcionProducto[] = {"Laptop", "Smartphone", "Tablet", "Monitor", "Teclado",
                                     "Ratón", "Impresora", "Cámara", "Auriculares", "Altavoces",
                                     "Disco Duro", "Memoria USB", "Router", "Smartwatch", "Proyector"};

    if(clientes.Contar() == 0) {
        std::cout << "--- Datos de Clientes Generados ---" << std::endl;
        for (int i = 0; i < 10; ++i) {
            DatosCliente dc;
            dc.nombre = nombres[rand() % nombres->length()];
            dc.apellido = apellidos[rand() % apellidos->length()];
            dc.DNI = std::to_string(rand() % 40000000 + i) + "\0";
            dc.cuilCuit = "20" + dc.DNI + "1" + "\0";
            dc.direccion = calles[rand() % calles->length()] + std::to_string(rand() % 9999 + 1);
            dc.correo = dc.apellido + "." + dc.nombre + "@example.com";
            dc.telefono = "4" + std::to_string(rand() % 9000 + 1000) + "-" + std::to_string(rand() % 9000 + 1000) + "\0";
            dc.celular = "11-" + std::to_string(rand() % 9000 + 1000) + "-" + std::to_string(rand() % 9000 + 1000) + "\0";
            dc.codigoRazonSocial = rand() % 3 + 1;
            dc.alta = (i % 2 == 0);

            Cliente dataCliente(dc.nombre, dc.apellido, dc.DNI, dc.cuilCuit, dc.direccion, dc.correo, dc.telefono, dc.celular, dc.codigoRazonSocial, dc.alta);
            cout << "Proveedor agregado? >> " << (clientes.Crear(dataCliente) ? "Si" : "No") << endl;

            std::cout << "Cliente " << i + 1 << ": " << dc.nombre << " " << dc.apellido
                      << " | DNI: " << dc.DNI << " | CUIL/CUIT: " << dc.cuilCuit
                      << " | Dir: " << dc.direccion << " | Correo: " << dc.correo
                      << " | Tel: " << dc.telefono << " | Cel: " << dc.celular
                      << " | Cod Razon Soc: " << dc.codigoRazonSocial
                      << " | Alta: " << (dc.alta ? "Si" : "No") << std::endl;
        }
        std::cout << "\n-------------------------------------\n" << std::endl;
    }

    if(proveedores.Contar() == 0) {
        std::cout << "--- Datos de Proveedores Generados ---" << std::endl;
        for (int i = 0; i < 5; ++i) {
            DatosProveedor dp;
            dp.cuit = "30" + std::to_string(rand() % 40000000 + i) + "9" + "\0";
            dp.nombreRazon = "Proveedor SA " + generarCodigoAlfaNumerico(6) + "\0";
            dp.rubro = (i % 6) + 1;
            dp.direccion = calles[rand() % calles->length()] + std::to_string(rand() % 9999 + 1) + "\0";
            dp.correo = "info@" + dp.nombreRazon.substr(0, dp.nombreRazon.find(" ")) + ".com" + "\0";
            dp.telefono = "0810-" + std::to_string(rand() % 9000 + 1000) + "\0";
            dp.celular = "15-" + std::to_string(rand() % 9000 + 1000) + "-" + std::to_string(rand() % 9000 + 1000) + "\0";
            dp.codigoRazonSocial = rand() % 6 + 1;
            dp.alta = (i % 2 != 0);

            Proveedor dataProveedor(dp.cuit, dp.nombreRazon, dp.rubro, dp.direccion, dp.correo, dp.telefono, dp.celular, dp.codigoRazonSocial, dp.alta);
            cout << "Proveedor agregado? >> " << (proveedores.Crear(dataProveedor) ? "Si" : "No") << endl;

            std::cout << "Proveedor " << i + 1 << ": " << dp.nombreRazon
                      << " | CUIT: " << dp.cuit << " | Rubro: " << dp.rubro
                      << " | Dir: " << dp.direccion << " | Correo: " << dp.correo
                      << " | Tel: " << dp.telefono << " | Cel: " << dp.celular
                      << " | Cod Razon Soc: " << dp.codigoRazonSocial
                      << " | Alta: " << (dp.alta ? "Si" : "No") << std::endl;
        }
        std::cout << "\n-------------------------------------\n" << std::endl;
    }

    if(productos.Contar() == 0) {
        std::cout << "--- Datos de Productos Generados ---" << std::endl;
        for (int i = 0; i < 30; ++i) {
            DatosProducto dp;
            dp.codigo = productos.generarCodigo() + "\0";
            dp.codigoProveedor = proveedores.SeleccionarRandom()->getCuit() + "\0";
            dp.descripcion = "Producto " + dp.codigo + "\0";
            dp.precio = static_cast<float>((rand() % 10000) / 100.0 + 1.0);
            dp.stock = rand() % 100 + 1;

            Producto dataProducto(dp.codigo, dp.codigoProveedor, dp.descripcion, dp.precio, dp.stock);
            cout << "Producto agregado? >> " << (productos.Crear(dataProducto) ? "Si" : "No") << endl;

            std::cout << "Producto " << i + 1 << ": " << dp.codigo
                      << " | Codigo Proveedor: " << dp.codigoProveedor << " | Descripcion: " << dp.descripcion
                      << " | Precio: " << dp.precio << " | Stock: " << dp.stock << std::endl;
        }
        std::cout << "\n-------------------------------------\n" << std::endl;
    }
}

void TestingAll() {
    //loadData();

    //TestingCliente();
    //TestingProveedores();
    //TestingProductos();
    TestingVentas();
}
