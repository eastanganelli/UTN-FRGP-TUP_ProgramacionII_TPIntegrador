#ifndef CLIENTE_MENU_H
#define CLIENTE_MENU_H

#include "..\menu.h"
#include "..\menu_utils.h"
#include "..\..\manager\manager_cliente.h"
#include "..\..\manager\manager_tipo_responsables.h"

class ClienteMenu : public Menu {
private:
    ClienteManager clientes;
    TipoResponsableManager tiposResponsables;

    Cliente CrearCliente();
    void ModificarClienteInteractivo(Cliente& cliente);
    bool EliminarClienteInteractivo(Cliente& cliente);
    void VerDetalleCliente();
    std::string SeleccionarRazonSocial(bool obligatoria);
public:
    ClienteMenu();
    virtual bool OnSelect(int index) override;
};

#endif // CLIENTE_MENU_H
