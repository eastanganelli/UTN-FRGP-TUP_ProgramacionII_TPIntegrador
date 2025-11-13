#ifndef FECHA_H
#define FECHA_H

#include <iostream>

using namespace std;

class Fecha {
private:
    unsigned int dia, mes, anio;

public:
    // Constructor
    Fecha(unsigned int dia = 1, unsigned int mes = 1, unsigned int anio = 1900);

    // Getters
    unsigned int getDia();
    unsigned int getMes();
    unsigned int getAnio();

    // Setters
    void setDia(unsigned int d);
    void setMes(unsigned int m);
    void setAnio(unsigned int a);

    // Métodos
    string toString();
    bool operator>(Fecha fechaComparar);
    bool operator>=(Fecha fechaComparar);
    bool operator<(Fecha fechaComparar);
    bool operator<=(Fecha fechaComparar);
    bool operator==(Fecha fechaComparar);
    bool operator!=(Fecha fechaComparar);
};

#endif // FECHA_H
