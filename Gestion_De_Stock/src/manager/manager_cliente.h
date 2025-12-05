#ifndef CLIENTEMANAGER_H
#define CLIENTEMANAGER_H

#include "../../rlutil.h"
#include "../main_classes/cliente.h"
#include "../controller/generic_array.h"
#include "../file_manager/file_system.h"

#include "../controller/modals.h"
#include "../controller/table/table.h"

using namespace std;

class ClienteManager : public FileSystem<Cliente> {
private:
    GenericArray<Cliente> Listar();

    bool Existe(string dni);
    bool Indice(string dni, unsigned int& index);

public:
    ClienteManager(const string& clientePath = "clientes.dat");
    ~ClienteManager();

    bool Agregar(Cliente& cliente);
    bool Modificar(string dni, Cliente* cliente);
    bool Eliminar(string dni);
    Cliente* operator[](string dni);
    GenericArray<Cliente> BuscarPorDNI(string dni);
    GenericArray<Cliente> BuscarPorCUIL_CUIT(string cuil_cuit);
    GenericArray<Cliente> BuscarPorNombreApellido(string nombre, string Apellido);
    GenericArray<Cliente> BuscarPorCorreo(string correo);
    unsigned int Cantidad();

    void ListarPorCuil_Cuit();
    void ListarPorDNI();
    void ListarPorApellido();

    static void Imprimir(GenericArray<Cliente>& clientes);
};

#endif // CLIENTEMANAGER_H
