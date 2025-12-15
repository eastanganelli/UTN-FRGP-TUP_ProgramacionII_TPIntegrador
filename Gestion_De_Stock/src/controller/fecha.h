#ifndef FECHA_H
#define FECHA_H

#include <ctime>
#include <iostream>

#include "validation.h"
#include "modals.h"

using namespace std;

class Fecha {
private:
    int dia, mes, anio;

public:
    Fecha(int dia = 1, int mes = 1, int anio = 2024);

    int getDia();
    int getMes();
    int getAnio();

    void setDia(int d);
    void setMes(int m);
    void setAnio(int a);

    void CargarFecha();

    string toString();
    bool operator>(Fecha fechaComparar);
    bool operator>=(Fecha fechaComparar);
    bool operator<(Fecha fechaComparar);
    bool operator<=(Fecha fechaComparar);
    bool operator==(Fecha fechaComparar);
    bool operator!=(Fecha fechaComparar);

    static Fecha CrearFecha();
    static Fecha Hoy();
};

#endif // FECHA_H
