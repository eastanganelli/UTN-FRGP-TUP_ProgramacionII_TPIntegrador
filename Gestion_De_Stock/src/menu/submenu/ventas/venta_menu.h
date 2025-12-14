#ifndef VENTA_MENU_H
#define VENTA_MENU_H

#include "../../menu.h"
#include "../../menu_utils.h"
#include "../../../manager/ventas/manager_factura.h"
#include "../../../manager/ventas/manager_nota_de_credito.h"
#include "../../../manager/manager_producto.h"
#include "../../../manager/manager_cliente.h"
#include "../../../controller/generic_array.h"
#include "../../../controller/validation.h"
#include "../../../rlutil.h"

class VentaMenu : public Menu {
private:
    FacturaManager facturas;
    NotaDeCreditoManager notas;
    ProductoManager productos;
    ClienteManager clientes;

    std::string SeleccionarCliente();
    std::string SeleccionarProductoCodigo();
    bool AgregarItemInteractivo(Factura& factura);
    Factura CrearFactura(unsigned int numero, bool& ok);
    void ModificarFacturaInteractiva(Factura& factura);
public:
    VentaMenu();
    virtual bool OnSelect(int index) override;
};

#endif // VENTA_MENU_H
