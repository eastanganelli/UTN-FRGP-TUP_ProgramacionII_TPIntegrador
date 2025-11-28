#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <cstring>

using namespace std;

class Item {
private:
    static const unsigned int CODIGO_SIZE = 9;

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

    // Setters
    void setCodigo(const std::string& c);
    void setCantidad(unsigned int c);
    void setPrecioUnitario(float p);

    // Helpers
    static unsigned int GetCodigoLength();
    bool operator==(const Item& otro) const;
    bool IsEmpty() const;
    std::string toString() const;
};

#endif // ITEM_H
