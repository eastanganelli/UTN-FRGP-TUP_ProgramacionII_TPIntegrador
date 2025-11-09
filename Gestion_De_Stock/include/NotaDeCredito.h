#ifndef NOTADECREDITO_H
#define NOTADECREDITO_H

#include "Comprobante.h"
#include "Producto.h"

#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

class NotaDeCredito : public Comprobante {
private:
    int idFacturaOriginal;
    string motivoAnulacion;
    vector<Producto> items;

public:
    // Getters
    int getIDFacturaOriginal();
    const string& getMotivoAnulacion();

    // Setters
    void setIDFacturaOriginal(int id);
    void setMotivoAnulacion(const char* m);
    void setMotivoAnulacion(const string& m);

    // Metodos
    void agregarItem(const Producto&* item);
    void operator++(const Producto&* item);
    void eliminarItem(const Producto&* item);
    void operator--(const Producto&* item);
};

std::ostream& operator<<(std::ostream& os, const NotaDeCredito& obj);

#endif // NOTADECREDITO_H
