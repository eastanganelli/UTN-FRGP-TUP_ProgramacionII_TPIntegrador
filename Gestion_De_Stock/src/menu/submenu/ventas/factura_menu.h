#ifndef FACTURA_MENU_H
#define FACTURA_MENU_H

#include "../../menu.h"
#include "../../menu_utils.h"
#include "../../../manager/ventas/manager_factura.h"
#include "../../../manager/manager_producto.h"
#include "../../../manager/manager_cliente.h"

#include <string>

class FacturaMenu : public Menu {
private:
    FacturaManager facturas;
    ProductoManager productos;
    ClienteManager clientes;

    std::string SeleccionarCliente();
    std::string SeleccionarProductoCodigo();
    bool AgregarItemInteractivo(Factura& factura);
    Factura CrearFactura(unsigned int numero, bool& ok);
    void ModificarFacturaInteractiva(Factura& factura);
public:
    FacturaMenu();
    virtual bool OnSelect(int index) override;
};

#endif // FACTURA_MENU_H
