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
#include "../../../../rlutil.h"

class VentaMenu : public Menu {
private:
    FacturaManager facturas;
    NotaDeCreditoManager notas;
    ProductoManager productos;
    ClienteManager clientes;

    void AgregarFactura();
    void ModificarFactura();
    void ListarFacturasPorMonto();
    void BuscarComprobantePorExtra();
    void BuscarComprobantePorRangoFecha();
    void ListarComprobantesPorCliente();
    void BuscarComprobantePorCliente();
    void AnularFactura();
    void ImprimirComprobantesCliente(const std::string& dni);
    void ImprimirIntercalado(GenericArray<Factura>& fcs, GenericArray<NotaDeCredito>& nts);
    void OrdenarPorNumero(GenericArray<Factura>& fcs);
    void OrdenarPorNumero(GenericArray<NotaDeCredito>& nts);
    void OrdenarPorCliente(GenericArray<Factura>& fcs);
    void OrdenarPorCliente(GenericArray<NotaDeCredito>& nts);
    void ImprimirIntercaladoOrdenCliente(GenericArray<Factura>& fcs, GenericArray<NotaDeCredito>& nts);

    std::string SeleccionarCliente();
    std::string SeleccionarProductoCodigo();
    bool AgregarItemInteractivo(Factura& factura);
    Factura CrearFactura(unsigned int numero, bool& ok);
    void ModificarFacturaInteractiva(Factura& factura);
    bool ConvertirFacturaEnNota(unsigned int numero, const std::string& motivo);
public:
    VentaMenu();
    virtual bool OnSelect(int index) override;
};

#endif // VENTA_MENU_H
