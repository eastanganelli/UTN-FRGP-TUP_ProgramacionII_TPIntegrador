#ifndef CLIENTEMANAGER_H
#define CLIENTEMANAGER_H

#include "Cliente.h"
#include "Base.h"

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

class ClienteManager : public Base {
private:
    string rutaArchivo;

    bool clienteExiste(Cliente& cliente);

public:
    ClienteManager(string ruta);
    ~ClienteManager();

    bool CrearCliente(Cliente& cliente);
    Cliente* ObtenerCliente(unsigned int id);
    Cliente* operator[](unsigned int id);
    bool ModificarCliente(unsigned int id, Cliente& clienteActualizado);
    bool EliminarCliente(unsigned int id);
    vector<Cliente> ListarClientes();

    unsigned int ContarClientes();
};

#endif // CLIENTEMANAGER_H
