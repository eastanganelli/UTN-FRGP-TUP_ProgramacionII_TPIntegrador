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
    /** Crea un item con codigo, cantidad y precio unitario. */
    Item(const char* _codigo = "", unsigned int _cantidad = 0, float _precioUnitario = 0.0f);
    /** Destructor de item. */
    ~Item();

    /** Obtiene el codigo del item. */
    std::string getCodigo() const;
    /** Obtiene la cantidad. */
    unsigned int getCantidad() const;
    /** Obtiene el precio unitario. */
    float getPrecioUnitario() const;

    static const unsigned int CodigoSize() { return COL_Codigo; }
    static const unsigned int CantidadSize() { return COL_Cantidad; }
    static const unsigned int PrecioUnitarioSize() { return COL_PrecioUnitario; }
    static const unsigned int TotalItemSize() { return COL_TotalItem; }

    /** Actualiza el codigo del item. */
    void setCodigo(const std::string& c);
    /** Actualiza la cantidad. */
    void setCantidad(unsigned int c);
    /** Actualiza el precio unitario. */
    void setPrecioUnitario(float p);

    /** Ancho de columna para codigo. */
    static unsigned int ColCodigoSize();
    /** Compara igualdad de items. */
    bool operator==(const Item& otro) const;
    /** Indica si el item esta vacio. */
    bool IsEmpty() const;
    /** Devuelve representacion en texto. */
    std::string toString() const;
};

#endif // ITEM_H
