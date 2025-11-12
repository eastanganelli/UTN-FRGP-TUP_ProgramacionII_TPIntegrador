#include <iostream>
// #include "menu.h"

#include <ctime>

#include "src/ClientesManager.h"
#include "src/ProveedoresManager.h"
#include "src/ProductosManager.h"

using namespace std;

void TestingCliente() {
    ClienteManager clientes("clientes.bin");
    Cliente testCliente("Eze", "battousai", "39068857", "20390688572", "213412341234", "", "", "", 1, true);

    bool resultado = clientes.Crear(testCliente);
    if(!resultado)
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

    cout<<clientes.Contar();
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

int main() {
    srand(time(NULL));
    // Menu menu;
    // menu.mostrar();

    //TestingCliente();
    TestingProveedores();
    TestingProductos();

    return 0;
}
