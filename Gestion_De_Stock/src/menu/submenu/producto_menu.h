#ifndef PRODUCTO_MENU_H
#define PRODUCTO_MENU_H

#include "..\menu.h"
#include "..\menu_utils.h"
#include "..\..\manager\manager_producto.h"
#include "..\..\manager\manager_proveedor.h"

class ProductoMenu : public Menu {
private:
    ProductoManager productos;
    ProveedorManager proveedores;
    Producto CrearProducto();
    void ModificarProductoInteractivo(Producto& producto);
    bool EliminarProductoInteractivo(Producto& producto);
    string SeleccionarProveedor();
public:
    ProductoMenu();
    virtual bool OnSelect(int index) override;
};

#endif // PRODUCTO_MENU_H
