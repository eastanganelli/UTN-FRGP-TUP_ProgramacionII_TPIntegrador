#include <iostream>
// #include "include/menu.h"

#include "include/Cliente.h"
#include "include/ClientesManager.h"

using namespace std;

void TestingCliente() {
    Cliente testCliente("Eze", "battousai", "39068857", "20390688572", "213412341234", "", "", "", 1, true),
            testCliente2("Eze", "battousai", "39068858", "20390688572", "213412341234", "", "", "", 1, true);
    ClienteManager clientes("clientes.bin");
    bool resultado = clientes.CrearCliente(testCliente);
    if(!resultado)
        cout << "Ya existe" << endl;

    resultado = clientes.CrearCliente(testCliente2);
    if(!resultado)
        cout << "Ya existe" << endl;



    Cliente* aux = clientes["39068859"];
    if(aux != nullptr)
        cout<<aux->getApellido()<<endl;
}

int main() {

    // Menu menu;
    // menu.mostrar();

    TestingCliente();

    return 0;
}
