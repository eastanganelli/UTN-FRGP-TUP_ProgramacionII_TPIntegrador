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

public:
    ClienteManager(const string& clientePath = "clientes.dat");
    ~ClienteManager();
    
    void ListarPorCuil_Cuit();
    void ListarPorDNI();
    void ListarPorApellido();
    GenericArray<Cliente> BuscarPorDNI(string dni);
    GenericArray<Cliente> BuscarPorCUIL_CUIT(string cuil_cuit);
    GenericArray<Cliente> BuscarPorNombreApellido(string nombre, string Apellido);
    GenericArray<Cliente> BuscarPorCorreo(string correo);

    unsigned int Cantidad();
    bool Modificar(string dni, Cliente* cliente);
    Cliente* operator[](string dni);

    static void Imprimir(GenericArray<Cliente>& clientes);
};

#endif // CLIENTEMANAGER_H
