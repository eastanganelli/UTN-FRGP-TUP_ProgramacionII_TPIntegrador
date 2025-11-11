#include <iostream>
// #include "include/menu.h"

#include "include/Cliente.h"
#include "include/ClientesManager.h"

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

int main() {

    // Menu menu;
    // menu.mostrar();

    TestingCliente();

    return 0;
}
