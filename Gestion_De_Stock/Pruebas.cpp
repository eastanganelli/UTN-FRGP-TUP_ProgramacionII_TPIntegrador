#include "Pruebas.h"

void Testing::Modals() {
//    Informational information("Hola Mundo", "mensaje");
//    information.Show();
//    cout << endl;
//    information.ShowYesNo();

//    Warning alerta("Hola Mundo", "mensaje");
//    alerta.Show();
//    cout << endl;
//    alerta.ShowYesNo();

//    Error error("Hola Mundo", "mensaje");
//    error.Show();
//    cout << endl;
//    error.ShowYesNo();
}

void Testing::Array() {
    GenericArray<int> misNumeros;
    int num1 = 1, num2 = 2, num3 = 3, num4 = 4;
    bool resultado = misNumeros+num1;
    resultado = misNumeros+num2;
    resultado = misNumeros+num3;
    resultado = misNumeros+num4;
    cout << resultado << endl;
    int cantidad = misNumeros.Size();
    for(int i = 0; i < cantidad; i++) {
        cout << "Pos: " << i << " -  Valor: " << *misNumeros[i] << endl;
    }

    cout << "---------------------" << endl;

    int* valor_remover = misNumeros[2];
    misNumeros-*valor_remover;
    cantidad = misNumeros.Size();
    for(int i = 0; i < cantidad; i++) {
        cout << "Pos: " << i << " -  Valor: " << *misNumeros[i] << endl;
    }

    cout << "---------------------" << endl;

    int nuevoVal=15;
    misNumeros.InsertAt(1,nuevoVal);
    cantidad = misNumeros.Size();
    for(int i = 0; i < cantidad; i++) {
        cout << "Pos: " << i << " -  Valor: " << *misNumeros[i] << endl;
    }
    misNumeros.RemoveAt(20);
    misNumeros.InsertAt(-1,nuevoVal);
    misNumeros.InsertAt(7,nuevoVal);
    misNumeros[-99];
    misNumeros[99];
}

void Testing::File() {
    FileSystem<int> miArchivo("mi_archivo_prueba.dat");

//    int aux_value = -99;
//    bool resultado = miArchivo.New(aux_value);

    cout << "Pre Update/Delete" << endl;
    for(unsigned int i; i < miArchivo.Count(); i++) {
        cout << "[" << i << "] : " << *miArchivo.At(i) << endl;
    }

    cout << "Post Update/" << endl;
    int aux = 235;
    miArchivo.Update(1, aux);
//    int newValue = 23;
//    miArchivo.New(newValue);
//    newValue = 1995;
//    miArchivo.New(newValue);
    for(unsigned int i; i < miArchivo.Count(); i++) {
        cout << "[" << i << "] : " << *miArchivo.At(i) << endl;
    }

    cout << "Post Delete" << endl;
    miArchivo.Delete(2);
    for(unsigned int i; i < miArchivo.Count(); i++) {
        cout << "[" << i << "] : " << *miArchivo.At(i) << endl;
    }

    miArchivo.Backup("archivo_backup.dat");
}

void Testing::ClientePrueba() {
    ClienteManager misClientes("clientes.dat");

//    misClientes.ListarPorCuil_Cuit();
//    misClientes.ListarPorDNI();
//    misClientes.ListarPorApellido();

    Cliente* miCliente = misClientes["34"];

    if(miCliente != nullptr) {
        ClienteManager::ImprimirHeader();
        ClienteManager::Splitter('=');
        miCliente->Print();
        ClienteManager::Splitter('=');
    }
}

//
//void TestingProveedores() {
//    ProveedorManager proveedores("Proveedores.dat");
//    proveedores.SeleccionarRubro();
//
//    cout << "----- Listados de Proveedores -----" << endl;
//
//    proveedores.ListarXNombre();
//}
//
//void TestingProductos() {
//    ProductoManager productos("Productos.dat");
//
//    cout << "----- Listados de Productos -----" << endl;
//
//    productos.ListarXCodigo();
//
//    string descripcionBuscada = "Monitor";
//
//    loadData();
//    /*
//    Producto* listarxStock = productos.ListarXStock();
//    for (unsigned int i = 0; i < productos.Contar(); i++) {
//        std::cout << "Producto " << i + 1 << ": " << listarxStock[i].getCodigo()
//                  << " | Stock: " << listarxStock[i].getStock() << std::endl;
//    }
//
//    string codigoBuscado = listarxStock[5].getCodigo();
//    Producto* productosBuscado = productos.ConsultaXCodigo(codigoBuscado);
//    if (productosBuscado != nullptr) {
//            std::cout << "\nProducto buscado por codigo " << codigoBuscado << ": "
//                      << productosBuscado->getCodigo() << " | Descripcion: " << productosBuscado->getDescripcion()
//                      << " | Precio: " << productosBuscado->getPrecio() << " | Stock: " << productosBuscado->getStock() << std::endl;
//    }
//
//    delete[] listarxStock;
//    delete[] productosBuscado;
//
//    Producto* listarxDescripcion = productos.ListarXPrecio();
//    for (unsigned int i = 0; i < productos.Contar(); i++) {
//        std::cout << "Producto " << i + 1 << ": " << listarxDescripcion[i].getCodigo()
//                  << " | Precio: " << listarxDescripcion[i].getPrecio() << std::endl;
//    }
//
//    string descripcionBuscada = listarxDescripcion[3].getDescripcion();
//    Producto* productosBuscadoDesc = productos.ConsultaXDescripcion(descripcionBuscada);
//    if (productosBuscadoDesc != nullptr) {
//            std::cout << "\nProducto buscado por descripcion " << descripcionBuscada << ": "
//                      << productosBuscadoDesc->getCodigo() << " | Descripcion: " << productosBuscadoDesc->getDescripcion()
//                      << " | Precio: " << productosBuscadoDesc->getPrecio() << " | Stock: " << productosBuscadoDesc->getStock() << std::endl;
//    }
//
//    delete[] listarxDescripcion;
//    delete[] productosBuscadoDesc;
//    */
//}
//
//void TestingVentas() {
//    VentaManager misComprobantes("Facturas.dat", "NotaDeCreditos.dat");
//
//    bool resultado_1 = misComprobantes.NuevaFactura("39068857", 345.7, 5, 'A'),
//         resultado_2 = misComprobantes.NuevaFactura("39068857", 23045, 20, 'B');
//    std::cout << "Factura 1 creada? >> " << (resultado_1 ? "Si" : "No") << std::endl;
//    std::cout << "Factura 2 creada? >> " << (resultado_2 ? "Si" : "No") << std::endl;
//
//    Factura* factura = misComprobantes.ObtenerFactura(2);
//    if(factura != nullptr) {
//        cout << factura->toString() << endl;
//    }
//
//    bool result_nota = misComprobantes.NuevaNotaDeCredito(*factura);
//    std::cout << "Nota creada? >> " << (result_nota ? "Si" : "No") << std::endl;
//    NotaDeCredito* miNota = misComprobantes.ObtenerNotaDeCredito(1);
//    if(miNota != nullptr) {
//        cout << miNota->toString();
//    }
//
//    misComprobantes.ListarXCliente();
//    misComprobantes.ListarXFecha();
//    misComprobantes.ConsultaXTipoDeComprobante('A');
//    misComprobantes.ConsultaXRangoDeFechas(Fecha(22, 6, 2024), Fecha(31,12,2025));
//}
//
//
//void TestingAll() {
//    TestingCliente();
//    TestingProveedores();
//    TestingProductos();
//    TestingVentas();
//}
