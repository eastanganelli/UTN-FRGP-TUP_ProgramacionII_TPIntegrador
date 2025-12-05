#ifndef PRODUCTOMANAGER_H
#define PRODUCTOMANAGER_H

#include "../../rlutil.h"
#include "../main_classes/producto.h"
#include "../controller/generic_array.h"
#include "../file_manager/file_system.h"

#include "../controller/modals.h"
#include "../controller/table/table.h"

using namespace std;

class ProductoManager : public FileSystem<Producto> {
private:
    GenericArray<Producto> Listar();

public:
    ProductoManager(const string& productoPath = "productos.dat");
    ~ProductoManager();

    bool Agregar(Producto& producto);
    bool Modificar(string codigo, Producto* producto);
    bool Eliminar(string codigo);
    Producto* operator[](string codigo);
    GenericArray<Producto> BuscarPorCodigo(string codigo);
    GenericArray<Producto> BuscarPorDescripcion(string descripcion);
    GenericArray<Producto> BuscarPorStockMinimo(unsigned int stockMinimo);
    
    void ListarPorCodigo();
    void ListarPorPrecio();
    void ListarPorStock();

    static void Imprimir(GenericArray<Producto>& productos);
};

#endif // PRODUCTOMANAGER_H
