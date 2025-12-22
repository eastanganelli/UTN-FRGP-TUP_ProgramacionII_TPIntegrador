#ifndef CLIENTE_MENU_H
#define CLIENTE_MENU_H

#include <cctype>
#include <cstdlib>
#include <iostream>

using namespace std;

#include "../../controller/modals/warning.h"
#include "../../controller/modals/error.h"
#include "../../controller/table/table.h"

#include "..\menu.h"
#include "..\menu_utils.h"
#include "..\..\manager\manager_cliente.h"
#include "..\..\manager\manager_tipo_responsables.h"

class ClienteMenu : public Menu {
private:
    ClienteManager clientes;
    TipoResponsableManager tiposResponsables;

    /** Construye un cliente mediante ingreso interactivo. */
    Cliente CrearCliente(bool& ok);
    /** Permite modificar campos del cliente indicado. */
    void ModificarClienteInteractivo(Cliente& cliente);
    /** Marca como baja un cliente tras confirmacion. */
    bool EliminarClienteInteractivo(Cliente& cliente);
    /** Muestra el detalle del cliente seleccionado. */
    void VerDetalleCliente();
    /** Selecciona codigo de razon social, obligatorio o no. */
    std::string SeleccionarRazonSocial(bool obligatoria);
public:
    /** Inicializa el menu de clientes. */
    ClienteMenu();
    /** Ejecuta la opcion seleccionada del menu de clientes. */
    virtual bool OnSelect(int index) override;
};

#endif // CLIENTE_MENU_H
