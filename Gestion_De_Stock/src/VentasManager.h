#ifndef VENTASMANAGER_H
#define VENTASMANAGER_H

#include "Factura.h"
#include "NotaDeCredito.h"

class VentaManager {
private:
    string rutaArchivo;

    Factura* ListarFacturas();
    NotaDeCredito* ListarNotasDeCredito();
    bool Existe(Factura& factura);
    bool Existe(NotaDeCredito& notaDeCredito);
    int Posicion(string dni, unsigned int& posicion);
    Factura* Redimensionar(Factura* facturas, unsigned int capacidadActual, unsigned int nuevaCapacidad);

public:
    VentaManager(string ruta);
    ~VentaManager();

    bool CrearFactura(Factura& f);
    bool CrearNotaDeCredito(NotaDeCredito& nc);
    Factura* ObtenerFactura(string numero);
    NotaDeCredito* ObtenerNotaDeCredito(string numero);
    bool Modificar(string numero, Factura& facturaActualizado);
    bool Modificar(string numero, NotaDeCredito& ndcActualizado);
    bool Eliminar(string dni);

    unsigned int Contar();
};

#endif // VENTASMANAGER_H
