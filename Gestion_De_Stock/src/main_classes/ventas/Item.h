#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <cstring>
#include <sstream>
#include <cstdio>

#include "../../controller/validation.h"
#include "../../menu/menu_utils.h"
#include "../../controller/modals.h"
#include "../../manager/manager_producto.h"

using namespace std;

class Item {
private:
    static const unsigned int CODIGO_SIZE = 9;

    static const unsigned int COL_Codigo = 12;
    static const unsigned int COL_Cantidad = 12;
    static const unsigned int COL_PrecioUnitario = 16;
    static const unsigned int COL_TotalItem = 16;

    char codigo[CODIGO_SIZE];
    unsigned int cantidad;
    float precioUnitario;

public:
    Item(const char* _codigo = "", unsigned int _cantidad = 0, float _precioUnitario = 0.0f);
    ~Item();

    // Getters
    std::string getCodigo() const;
    unsigned int getCantidad() const;
    float getPrecioUnitario() const;

    static const unsigned int CodigoSize() { return COL_Codigo; }
    static const unsigned int CantidadSize() { return COL_Cantidad; }
    static const unsigned int PrecioUnitarioSize() { return COL_PrecioUnitario; }
    static const unsigned int TotalItemSize() { return COL_TotalItem; }

    // Setters
    void setCodigo(const std::string& c);
    void setCantidad(unsigned int c);
    void setPrecioUnitario(float p);

    // Helpers
    static unsigned int ColCodigoSize();
    bool operator==(const Item& otro) const;
    bool IsEmpty() const;
    std::string toString() const;
};

#endif // ITEM_H
