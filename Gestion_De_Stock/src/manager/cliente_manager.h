#ifndef CLIENTEMANAGER_H
#define CLIENTEMANAGER_H

#include "../main_classes/Cliente.h"
#include "../controller/generic_array.h"
#include "../file_manager/file_system.h"

#include "../controller/modals.h"

using namespace std;

class ClienteManager : public FileSystem<Cliente> {
private:
    // const CondicionIVAManager* condicionesIVA;
    GenericArray<Cliente> Listar();
    bool Existe(Cliente& cliente);

public:
    ClienteManager(const string& clientePath = "clientes.dat");
    ~ClienteManager();
    unsigned int Cantidad();
    bool Modificar(string dni, Cliente* cliente);
    void ListarPorCuil_Cuit();
    void ListarPorDNI();
    void ListarPorApellido();
    Cliente* operator[](string dni);
    GenericArray<Cliente> BuscarPorCUIL_CUIT(string cuil_cuit);
    GenericArray<Cliente> BuscarPorDNI(string dni);
    GenericArray<Cliente> BuscarPorNombreApellido(string nombre, string Apellido);
    GenericArray<Cliente> BuscarPorCorreo(string correo);

    static void ImprimirHeader();
    static void Imprimir(GenericArray<Cliente>& clientes);
    static void SplitterLength(char Separator = '-');
};

#endif // CLIENTEMANAGER_H
