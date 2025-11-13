#ifndef VENTASMANAGER_H
#define VENTASMANAGER_H

#include "Factura.h"
#include "NotaDeCredito.h"

class VentaManager {
private:
    string rutasArchivos[2];

    Factura* ListarFacturas();
    NotaDeCredito* ListarNotasDeCredito();
    bool Existe(Factura& factura);
    bool Existe(NotaDeCredito& notaDeCredito);
    int PosicionFactura(unsigned int numero, unsigned int& posicion);
    int PosicionNotaDeCredito(unsigned int numero, unsigned int& posicion);
    Factura* Redimensionar(Factura* facturas, unsigned int capacidadActual, unsigned int nuevaCapacidad);
    bool CrearFactura(Factura& f);
    bool CrearNotaDeCredito(NotaDeCredito& nc);

    void ListarFacturasXFecha();
    void ListarNotasDeCreditoXFecha();
    void ListarFacturasXCAE();
    void ListarNotasDeCreditoXCAE();
    void ListarFacturasXCliente();
    void ListarNotasDeCreditoXCliente();

public:
    VentaManager(string _nombreArchivoFactura = "facturas.bin", string _nombreArchivoNotaDeCredito = "notasdecredito.bin");
    ~VentaManager();

    bool Crear(Factura& factura);
    Factura* ObtenerFactura(unsigned int numero);
    NotaDeCredito* ObtenerNotaDeCredito(unsigned int numero);
    bool Modificar(unsigned int numero, Factura& facturaActualizado);
    bool Modificar(unsigned int numero, NotaDeCredito& ndcActualizado);
    bool EliminarFactura(unsigned int numero);
    bool EliminarNotaDeCredito(unsigned int numero);
    void ListarXFecha();
    void ListarXCAE();
    void ListarXCliente();
    void ConsultaXCliente(string dniCliente);
    void ConsultaXCAE(string cae);
    void ConsultaXTipoDeComprobante(char tipoComprobante);
    void ConsultaXRangoDeFechas(Fecha fechaInicio, Fecha fechaFin);

    unsigned int ContarFacturas();
    unsigned int ContarNotasDeCreditos();
};

#endif // VENTASMANAGER_H
