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

    int Posicion(string dni, unsigned int& posicion);
    bool Existe(Cliente& cliente);

public:
    ClienteManager(string ruta);
    ~ClienteManager();

    bool Crear(Cliente& cliente);
    Cliente* Obtener(string dni);
    Cliente* operator[](string dni);
    bool Modificar(string dni, Cliente* clienteActualizado);
    bool Modificar(string dni, Cliente& clienteActualizado);
    bool Eliminar(string dni);
    vector<Cliente> Listar();

    unsigned int Contar();
};

#endif // CLIENTEMANAGER_H
