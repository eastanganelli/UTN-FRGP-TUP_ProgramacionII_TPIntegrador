#include "Pruebas.h"

void TestingCliente() {
    ClienteManager clientes("clientes.bin");


    Cliente testCliente("Martin", "Fano", "41099122", "20410991226", "Somewhere in Benavidez", "eltincho@capo.com", "15-5768-4547", "15-5768-4547", 4, true);

    bool resultado = clientes.Crear(testCliente);
    /*if(!resultado)
        cout << "Ya existe" << endl;

    Cliente testCliente2("Eze", "battousai", "39068858", "20390688572", "213412341234", "", "", "", 1, true);

    bool resultado_2 = clientes.Crear(testCliente2);
    if(!resultado_2)
        cout << "Ya existe" << endl;

    Cliente* aux_actualizar = clientes["39068857"];
    aux_actualizar->setApellido("Stanganelli Di Pasqua");

    clientes.Modificar("39068857", *aux_actualizar);

    Cliente* aux = clientes["39068857"];
    if(aux != nullptr)
        cout<<aux->getApellido()<<endl;

    cout<<clientes.Contar();*/
}

void TestingProveedores() {
    ProveedorManager proveedores("proveedores.bin");
    proveedores.SeleccionarRubro();
    /*
    Proveedor dipasqua("10390688572", "dipasqua", 2, "av dr honorio 1915", "-", "1131454150", "", 0, true);

    proveedores.Crear(dipasqua);

    Proveedor* aux_selec = proveedores["10390688572"];
    aux_selec->setNombreRazon("stanganelli SRL");

    proveedores.Modificar("10390688572", aux_selec);

    if(aux_selec != nullptr)
        cout << aux_selec->getNombreRazon();
    */
}

void TestingProductos() {
    ProductoManager productos("productos.bin");

    string codigo = productos.generarCodigo();
    Producto alfajor(codigo, "10390688572", "", 12.67, 20);
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
    ClienteManager clientes("clientes.bin");
    ProveedorManager proveedores("proveedores.bin");

    std::cout << "--- Datos de Clientes Generados ---" << std::endl;
    for (int i = 0; i < 10; ++i) {
        DatosCliente dc;
        dc.nombre = "Cliente" + std::to_string(i + 1);
        dc.apellido = "Apellido" + std::to_string(i + 1);
        dc.DNI = std::to_string(30000000 + i);
        dc.cuilCuit = "20" + std::to_string(30000000 + i) + "1";
        dc.direccion = "Calle Falsa " + std::to_string(100 + i);
        dc.correo = "cliente" + std::to_string(i + 1) + "@example.com";
        dc.telefono = "4" + std::to_string(rand() % 9000 + 1000) + "-" + std::to_string(rand() % 9000 + 1000);
        dc.celular = "11-" + std::to_string(rand() % 9000 + 1000) + "-" + std::to_string(rand() % 9000 + 1000);
        dc.codigoRazonSocial = 1000 + i;
        dc.alta = (i % 2 == 0);

        Cliente dataCliente(dc.nombre, dc.apellido, dc.DNI, dc.cuilCuit, dc.direccion, dc.correo, dc.telefono, dc.celular, dc.codigoRazonSocial, dc.alta);
        clientes.Crear(dataCliente);

        std::cout << "Cliente " << i + 1 << ": " << dc.nombre << " " << dc.apellido
                  << " | DNI: " << dc.DNI << " | CUIL/CUIT: " << dc.cuilCuit
                  << " | Dir: " << dc.direccion << " | Correo: " << dc.correo
                  << " | Tel: " << dc.telefono << " | Cel: " << dc.celular
                  << " | Cod Razon Soc: " << dc.codigoRazonSocial
                  << " | Alta: " << (dc.alta ? "Si" : "No") << std::endl;
    }
    std::cout << "\n-------------------------------------\n" << std::endl;

    std::cout << "--- Datos de Proveedores Generados ---" << std::endl;
    for (int i = 0; i < 5; ++i) {
        DatosProveedor dp;
        dp.cuit = "30" + std::to_string(70000000 + i) + "9";
        dp.nombreRazon = "Proveedor SA " + generarCodigoAlfaNumerico(3);
        dp.rubro = (i % 3) + 1;
        dp.direccion = "Avenida Siempreviva " + std::to_string(500 + i);
        dp.correo = "info@" + dp.nombreRazon.substr(0, dp.nombreRazon.find(" ")) + ".com";
        dp.telefono = "0810-" + std::to_string(rand() % 9000 + 1000);
        dp.celular = "15-" + std::to_string(rand() % 9000 + 1000) + "-" + std::to_string(rand() % 9000 + 1000);
        dp.codigoRazonSocial = rand() % 6 + 1;
        dp.alta = (i % 2 != 0);

        Proveedor dataProveedor(dp.cuit, dp.nombreRazon, dp.rubro, dp.direccion, dp.correo, dp.telefono, dp.celular, dp.codigoRazonSocial, dp.alta);
        proveedores.Crear(dataProveedor);

        std::cout << "Proveedor " << i + 1 << ": " << dp.nombreRazon
                  << " | CUIT: " << dp.cuit << " | Rubro: " << dp.rubro
                  << " | Dir: " << dp.direccion << " | Correo: " << dp.correo
                  << " | Tel: " << dp.telefono << " | Cel: " << dp.celular
                  << " | Cod Razon Soc: " << dp.codigoRazonSocial
                  << " | Alta: " << (dp.alta ? "Si" : "No") << std::endl;
    }
    std::cout << "\n-------------------------------------\n" << std::endl;
}
