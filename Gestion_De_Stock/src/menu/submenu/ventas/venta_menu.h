#ifndef VENTA_MENU_H
#define VENTA_MENU_H

#include "../../menu.h"
#include "../../menu_utils.h"
#include "../../../manager/manager_ventas.h"
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

    /** Agrega una factura nueva. */
    void AgregarFactura();
    /** Permite modificar una factura sin CAE. */
    void ModificarFactura();
    /** Anula una factura facturada. */
    void AnularFactura();
    /** Lista comprobantes agrupados por cliente. */
    void ListarComprobantesPorCliente();
    /** Lista facturas ordenadas por monto. */
    void ListarFacturasPorMonto();
    /** Busca comprobantes por cliente. */
    void BuscarComprobantePorCliente();
    /** Busca comprobantes por datos adicionales (CAE u otros). */
    void BuscarComprobantePorExtra();
    /** Busca comprobantes dentro de un rango de fechas. */
    void BuscarComprobantePorRangoFecha();
    /** Muestra el detalle de un comprobante. */
    void VerDetalleComprobante();
    /** Imprime comprobantes de un cliente especifico. */
    void ImprimirComprobantesCliente(const std::string& dni);
    /** Genera el orden intercalado para mostrar facturas y notas. */
    void ConstruirOrdenIntercalado(GenericArray<Factura>& fcs, GenericArray<NotaDeCredito>& nts, bool ordenarPorCliente, GenericArray<unsigned int>& mapTipo, GenericArray<unsigned int>& mapIdx);
    /** Construye intercalado por numero de comprobante. */
    void ConstruirIntercaladoPorNumero(GenericArray<Factura>& fcs, GenericArray<NotaDeCredito>& nts, GenericArray<unsigned int>& numeros, GenericArray<unsigned int>& tipos);
    /** Ordena comprobantes por cliente generando mapeos. */
    void OrdenarComprobantesPorCliente(GenericArray<Factura>& fcs, GenericArray<NotaDeCredito>& nts, GenericArray<unsigned int>& numeros, GenericArray<unsigned int>& tipos);
    /** Ordena comprobantes por monto generando mapeos. */
    void OrdenarComprobantesPorMonto(GenericArray<Factura>& fcs, GenericArray<NotaDeCredito>& nts, GenericArray<unsigned int>& numeros, GenericArray<unsigned int>& tipos);
    /** Imprime comprobantes segun orden intercalado. */
    void ImprimirIntercalado(GenericArray<unsigned int>& numeros, GenericArray<unsigned int>& tipos);
    /** Ordena un arreglo de facturas por numero. */
    void OrdenarPorNumero(GenericArray<Factura>& fcs);
    /** Ordena un arreglo de notas de credito por numero. */
    void OrdenarPorNumero(GenericArray<NotaDeCredito>& nts);
    /** Ordena facturas por cliente. */
    void OrdenarPorCliente(GenericArray<Factura>& fcs);
    /** Ordena notas de credito por cliente. */
    void OrdenarPorCliente(GenericArray<NotaDeCredito>& nts);

    /** Permite elegir un cliente activo. */
    std::string SeleccionarCliente();
    /** Permite elegir un producto activo. */
    std::string SeleccionarProductoCodigo();
    /** Agrega un item interactivo a una factura. */
    bool AgregarItemInteractivo(Factura& factura);
    /** Modifica un item existente de una factura. */
    bool ModificarItemInteractivo(Item& item);
    /** Elimina un item existente de una factura. */
    bool EliminarItemInteractivo(Item& item);
    /** Construye una factura con ingreso interactivo. */
    Factura CrearFactura(unsigned int numero, bool& ok);
    /** Menu de modificaciones sobre una factura en memoria. */
    void ModificarFacturaInteractiva(Factura& factura);
    /** Convierte una factura en nota de credito segun motivo. */
    bool ConvertirFacturaEnNota(unsigned int numero, const std::string& motivo);
public:
    /** Inicializa el menu de ventas. */
    VentaMenu();
    /** Ejecuta la opcion seleccionada del menu de ventas. */
    virtual bool OnSelect(int index) override;
};

#endif // VENTA_MENU_H
