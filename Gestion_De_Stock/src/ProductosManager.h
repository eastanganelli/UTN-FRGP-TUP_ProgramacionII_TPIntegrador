#ifndef PRODUCTOMANAGER_H
#define PRODUCTOMANAGER_H

#include "Producto.h"

#include <cstdio>
#include <string>
#include <ctime>

using namespace std;

class ProductoManager {
private:
    string rutaArchivo;

    Producto* Listar();
    Producto* Redimensionar(Producto* productos, unsigned int capacidadActual, unsigned int nuevaCapacidad);
    void Imprimir(Producto* misProductos, unsigned int cantidadProductos);
    bool Existe(string codigo);
    bool Existe(Producto& producto);
    int Posicion(string codigo, unsigned int& posicion);

public:
    ProductoManager(string ruta);
    ~ProductoManager();

    bool Crear(Producto& producto);
    Producto* Obtener(string codigo);
    Producto* operator[](string codigo);
    bool Modificar(string codigo, Producto* productoActualizado);
    bool Modificar(string codigo, Producto& productoActualizado);
    bool Eliminar(string codigo);

    void ListarXCodigo();
    void ListarXPrecio();
    void ListarXStock();
    void ConsultaXCodigo(string codigo);
    void ConsultaXDescripcion(string descripcion);
    void ConsultaXStockMinimo(unsigned int stockMinimo);

    unsigned int Contar();
    string generarCodigo();
};

#endif // PRODUCTOMANAGER_H
