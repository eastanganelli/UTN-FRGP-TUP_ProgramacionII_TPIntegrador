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
    /** Construye un producto mediante ingreso interactivo. */
    Producto CrearProducto(bool& ok);
    /** Permite modificar campos del producto indicado. */
    void ModificarProductoInteractivo(Producto& producto);
    /** Marca como baja un producto tras confirmacion. */
    bool EliminarProductoInteractivo(Producto& producto);
    /** Selecciona un proveedor vigente. */
    string SeleccionarProveedor();
    /** Selecciona un codigo de producto disponible. */
    string SeleccionarProductoCodigo();
public:
    /** Inicializa el menu de productos. */
    ProductoMenu();
    /** Ejecuta la opcion elegida del menu de productos. */
    virtual bool OnSelect(int index) override;
};

#endif // PRODUCTO_MENU_H
