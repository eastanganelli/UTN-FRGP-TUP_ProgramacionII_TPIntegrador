#ifndef VENTASMANAGER_H
#define VENTASMANAGER_H

#include "Factura.h"
#include "NotaDeCredito.h"

using namespace std;

class VentaManager {
private:
    string rutasArchivoFactura;
    string rutasArchivosNotaDeCredito;

    void iniciarArchivoFactura();
    void iniciarArchivoNotaDeCredito();

    Factura* ListarFacturas();
    NotaDeCredito* ListarNotasDeCredito();
    bool Existe(Factura& factura);
    bool Existe(NotaDeCredito& notaDeCredito);
    int PosicionFactura(unsigned int numero, unsigned int& posicion);
    int PosicionNotaDeCredito(unsigned int numero, unsigned int& posicion);
    void Imprimir(Factura* misFacturas, unsigned int cantidad);
    void Imprimir(NotaDeCredito* misNotaDeCreditos, unsigned int cantidad);
    Factura* Redimensionar(Factura* facturas, unsigned int capacidadActual, unsigned int nuevaCapacidad);
    Factura* Redimensionar(NotaDeCredito* notaDeCreditos, unsigned int capacidadActual, unsigned int nuevaCapacidad);
    bool CrearFactura(Factura& f);
    bool CrearNotaDeCredito(NotaDeCredito& nc);
    int ultimaFacturaID();
    int ultimaNotaDeCreditoID();

public:
    VentaManager(string _nombreArchivoFactura = "Facturas.dat", string _nombreArchivoNotaDeCredito = "NotasDeCredito.dat");
    ~VentaManager();

    bool NuevaFactura(string _clienteDNI, float _monto, unsigned int _cantidadItems, char _tipoFactura);
    bool NuevaNotaDeCredito(unsigned int _nroFactura, string _motivoAnulacion);
    bool NuevaNotaDeCredito(Factura& factura);
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

    void RecaudacionTrimestralPorAnio(int anio, float* trimestres);
    float RecaudacionAnualPorAnio(int anio);
    unsigned int ContarFacturas();
    unsigned int ContarNotasDeCreditos();
};

#endif // VENTASMANAGER_H
