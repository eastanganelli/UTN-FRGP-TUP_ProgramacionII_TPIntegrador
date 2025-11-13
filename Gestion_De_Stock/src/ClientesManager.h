#ifndef CLIENTEMANAGER_H
#define CLIENTEMANAGER_H

#include "Cliente.h"

#include <cstdio>
#include <string>

using namespace std;

class ClienteManager {
private:
    string rutaArchivo;

    Cliente* Listar();
    Cliente* Redimensionar(Cliente* clientes, unsigned int capacidadActual, unsigned int nuevaCapacidad);
    void Imprimir(Cliente* misClientes, unsigned int cantidadClientes);
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
    void ListarXApellido();
    void ListarXDNI();
    void ListarXcuilcuit();
    void ConsultaXCUILCuit(string cuilcuit);
    Cliente* ConsultaXDNI(string dni);
    Cliente* ConsultaXNombreApellido(string nombre, string apellido);
    Cliente* ConsultaXCorreo(string correo);

    unsigned int Contar();
};

#endif // CLIENTEMANAGER_H
