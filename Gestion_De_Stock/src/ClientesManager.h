#ifndef CLIENTEMANAGER_H
#define CLIENTEMANAGER_H

#include "Cliente.h"

#include <cstdio>
#include <vector>
#include <string>

using namespace std;

class ClienteManager {
private:
    string rutaArchivo;

    Cliente* Listar();
    bool Existe(Cliente& cliente);
    int Posicion(string dni, unsigned int& posicion);

public:
    ClienteManager(string ruta);
    ~ClienteManager();

    bool Crear(Cliente& cliente);
    Cliente* Obtener(string dni);
    Cliente* operator[](string dni);
    bool Modificar(string dni, Cliente* clienteActualizado);
    bool Modificar(string dni, Cliente& clienteActualizado);
    bool Eliminar(string dni);
    Cliente* ListarXApellido();
    Cliente* ListarXDNI();
    Cliente* ListarXcuilcuit();

    unsigned int Contar();
};

#endif // CLIENTEMANAGER_H
