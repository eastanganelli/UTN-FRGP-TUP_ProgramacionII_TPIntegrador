#ifndef CLIENTE_MENU_H
#define CLIENTE_MENU_H

#include "..\menu.h"
#include "..\menu_utils.h"
#include "..\..\manager\manager_cliente.h"

class ClienteMenu : public Menu {
private:
    ClienteManager clientes;
public:
    ClienteMenu();
    virtual void OnSelect(int index) override;
};

#endif // CLIENTE_MENU_H
