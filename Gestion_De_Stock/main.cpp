#include <iostream>
#include <ctime>

#include "Pruebas.h"

// #include "menu.h"

using namespace std;

int main() {
    srand(time(NULL));
    // Menu menu;
    // menu.mostrar();

    ClienteManager clientes("clientes.bin");

    Cliente* misClientes = clientes.ListarXDNI();

    if (misClientes != nullptr) {
        const unsigned int cantidadClientes = clientes.Contar();
        for (unsigned int i = 0; i < cantidadClientes; i++) {
            cout << &misClientes[i] << endl;
            cout << "------------------------" << endl;
        }
        delete[] misClientes;
    } else {
        cout << "No hay clientes registrados." << endl;
    }

    //TestingCliente();
    //TestingProveedores();
    //TestingProductos();

    return 0;
}
