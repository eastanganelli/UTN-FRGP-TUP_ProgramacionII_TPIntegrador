#ifndef CLIENTEMANAGER_H
#define CLIENTEMANAGER_H

#include "Cliente.h"

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

class ClienteManager {
private:
    vector<Cliente*> clientes;
    string rutaArchivo;

public:
    ClienteManager(string ruta);

    void agregar(Cliente* cli);
    bool eliminar(int id);
    Cliente* buscar(int id);
    int obtenerIndice(int id);

    int getCantidad();
    Cliente* getPorIndice(int index);

    void listarTodos();

    bool cargarDeArchivo();
    bool escribirArchivo();
};

#endif // CLIENTEMANAGER_H
