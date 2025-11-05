#ifndef FECHA_H
#define FECHA_H

#include <iostream>

using namespace std;

class Fecha {
private:
    unsigned int _dia, _mes, _anio;

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
};

// Imprisión de fecha
std::ostream& operator<<(std::ostream& os, const Fecha& obj);

#endif // FECHA_H
