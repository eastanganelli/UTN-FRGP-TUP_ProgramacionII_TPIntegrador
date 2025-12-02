#ifndef PRODUCTO_MENU_H
#define PRODUCTO_MENU_H

#include "..\menu.h"
#include "..\menu_utils.h"
#include "..\..\manager\manager_producto.h"

class ProductoMenu : public Menu {
private:
    ProductoManager productos;
public:
    ProductoMenu();
    virtual bool OnSelect(int index) override;
};

#endif // PRODUCTO_MENU_H
