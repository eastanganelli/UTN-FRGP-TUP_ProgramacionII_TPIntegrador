#ifndef VENTA_MENU_H
#define VENTA_MENU_H

#include "../../menu.h"
#include "../../menu_utils.h"
#include "../../../manager/ventas/manager_factura.h"
#include "../../../manager/ventas/manager_nota_de_credito.h"
#include "../../../manager/manager_producto.h"
#include "../../../manager/manager_cliente.h"
#include "../../../manager/manager_tipo_responsables.h"
#include "../../../controller/generic_array.h"
#include "../../../controller/validation.h"
#include "../../../../rlutil.h"

class VentaMenu : public Menu {
private:
    FacturaManager facturas;
    NotaDeCreditoManager notas;
    ProductoManager productos;
    ClienteManager clientes;
    TipoResponsableManager tiposResponsables;

    void AgregarFactura();
    void ModificarFactura();
    void AnularFactura();
    void ListarComprobantesPorCliente();
    void ListarFacturasPorMonto();
    void BuscarComprobantePorCliente();
    void BuscarComprobantePorExtra();
    void BuscarComprobantePorRangoFecha();
    void VerDetalleComprobante();
    void ImprimirComprobantesCliente(const std::string& dni);
    void ConstruirOrdenIntercalado(GenericArray<Factura>& fcs, GenericArray<NotaDeCredito>& nts, bool ordenarPorCliente, GenericArray<unsigned int>& mapTipo, GenericArray<unsigned int>& mapIdx);
    void ConstruirIntercaladoPorNumero(GenericArray<Factura>& fcs, GenericArray<NotaDeCredito>& nts, GenericArray<unsigned int>& numeros, GenericArray<unsigned int>& tipos);
    void OrdenarComprobantesPorCliente(GenericArray<Factura>& fcs, GenericArray<NotaDeCredito>& nts, GenericArray<unsigned int>& numeros, GenericArray<unsigned int>& tipos);
    void OrdenarComprobantesPorMonto(GenericArray<Factura>& fcs, GenericArray<NotaDeCredito>& nts, GenericArray<unsigned int>& numeros, GenericArray<unsigned int>& tipos);
    void ImprimirIntercalado(GenericArray<unsigned int>& numeros, GenericArray<unsigned int>& tipos);
    void OrdenarPorNumero(GenericArray<Factura>& fcs);
    void OrdenarPorNumero(GenericArray<NotaDeCredito>& nts);
    void OrdenarPorCliente(GenericArray<Factura>& fcs);
    void OrdenarPorCliente(GenericArray<NotaDeCredito>& nts);

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
