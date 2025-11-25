#ifndef CONDICIONIVA_H
#define CONDICIONIVA_H

#include <string>
#include <cstring>

using namespace std;

class CondicionIVA {
private:
    static const unsigned int CODIGO_SIZE = 5;
    static const unsigned int DESCRIPCION_SIZE = 31;
    static const unsigned int PORCENTAJE_SIZE = 6;

    unsigned int codigo;
    char descripcion[DESCRIPCION_SIZE];
    float porcentaje;

public:
    // Constructor
    CondicionIVA(const unsigned int codigo = 0, const string descripcion = "", const float porcentaje = 0.0f);
    ~CondicionIVA();

    // Getters
    unsigned int getCodigo() const;
    string getDescripcion() const;
    float getPorcentaje() const;

    // Métodos
    bool operator==(const CondicionIVA& otra) const;
    bool IsEmpty() const;
    void Print();
};

#endif // CONDICIONIVA_Hd