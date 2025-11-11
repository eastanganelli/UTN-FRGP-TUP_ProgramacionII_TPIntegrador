#include <iostream>
#include "menu.h"

#include "Cliente.h"
#include "ClientesManager.h"

using namespace std;

void TestingCliente() {
    Cliente testCliente(1, "Eze", "battousai", "39068857", "20390688572", "213412341234", "", "", "", 1, true);

    cout << testCliente.getApellido();

    ClienteManager clientes("clientes.bin");

    bool resultado = clientes.CrearCliente(testCliente);

    if(resultado)
        cout << "Ya existe" << endl;

    Cliente* aux = clientes[1];
}


int main() {

    // Menu menu;
    // menu.mostrar();

    TestingCliente();

    return 0;
}
