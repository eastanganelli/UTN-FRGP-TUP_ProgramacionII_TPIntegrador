#ifndef CLIENTES_H
#define CLIENTES_H

#include "Cliente.h"

#include <cstdio>
#include <string>

using namespace std;

class Clientes {
private:
    string rutaArchivo;

    Cliente* Listar();
    Cliente* Redimensionar(Cliente* clientes, unsigned int capacidadActual, unsigned int nuevaCapacidad);
    void Imprimir(Cliente* misClientes, unsigned int cantidadClientes);
    bool Existe(Cliente& cliente);
    int Posicion(string dni, unsigned int& posicion);

public:
    Clientes(string ruta);
    ~Clientes();

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
    void ConsultaXDNI(string dni);
    void ConsultaXNombreApellido(string nombre, string apellido);
    void ConsultaXCorreo(string correo);

    unsigned int Contar();
};

#endif // CLIENTES_H
