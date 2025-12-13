#ifndef CLIENTE_MENU_H
#define CLIENTE_MENU_H

#include "..\menu.h"
#include "..\menu_utils.h"
#include "..\..\manager\manager_cliente.h"

class ClienteMenu : public Menu {
private:
    ClienteManager clientes;
    // UI moved from model
    Cliente CrearCliente();
    void ModificarClienteInteractivo(Cliente& cliente);
    bool EliminarClienteInteractivo(Cliente& cliente);
public:
    ClienteMenu();
    virtual bool OnSelect(int index) override;
};

#endif // CLIENTE_MENU_H
