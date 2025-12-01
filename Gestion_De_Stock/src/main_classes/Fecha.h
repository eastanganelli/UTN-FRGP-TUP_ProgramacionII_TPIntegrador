#ifndef FECHA_H
#define FECHA_H

#include <ctime>
#include <iostream>

#include "../controller/validation.h"
#include "../controller/modals.h"

using namespace std;

class Fecha {
private:
    int dia, mes, anio;

public:
    // Constructor
    Fecha(int dia = 1, int mes = 1, int anio = 2024);

    // Getters
    int getDia();
    int getMes();
    int getAnio();

    // Setters
    void setDia(int d);
    void setMes(int m);
    void setAnio(int a);

    void CargarFecha();

    // Métodos
    string toString();
    bool operator>(Fecha fechaComparar);
    bool operator>=(Fecha fechaComparar);
    bool operator<(Fecha fechaComparar);
    bool operator<=(Fecha fechaComparar);
    bool operator==(Fecha fechaComparar);
    bool operator!=(Fecha fechaComparar);

    static Fecha CrearFecha();
};

#endif // FECHA_H
