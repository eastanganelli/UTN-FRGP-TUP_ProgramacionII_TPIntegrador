#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Base {
protected:
public:
    virtual ~Base() {}

    // Operaciones CRUD genéricas
    virtual void alta() {}
    virtual void baja() {}
    virtual void modificacion() {}
    virtual void consulta() const {}
};

#endif // BASE_H
