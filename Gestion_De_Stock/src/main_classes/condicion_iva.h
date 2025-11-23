#ifndef CONDICIONIVA_H
#define CONDICIONIVA_H

#include <string>
#include <cstring>

using namespace std;

class CondicionIVA {
private:
    unsigned int codigo;
    char descripcion[31];
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
};

#endif // CONDICIONIVA_Hd