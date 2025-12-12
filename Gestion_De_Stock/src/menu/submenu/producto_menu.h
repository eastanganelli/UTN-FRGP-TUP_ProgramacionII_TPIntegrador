#ifndef PRODUCTO_MENU_H
#define PRODUCTO_MENU_H

#include "..\menu.h"
#include "..\menu_utils.h"
#include "..\..\manager\manager_producto.h"

class ProductoMenu : public Menu {
private:
    ProductoManager productos;
    Producto CrearProducto();
    void ModificarProductoInteractivo(Producto& producto);
    bool EliminarProductoInteractivo(Producto& producto);
public:
    ProductoMenu();
    virtual bool OnSelect(int index) override;
};

#endif // PRODUCTO_MENU_H
