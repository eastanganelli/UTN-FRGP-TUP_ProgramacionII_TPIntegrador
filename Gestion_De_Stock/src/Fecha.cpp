#include "Fecha.h"

Fecha::Fecha(unsigned int dia, unsigned int mes, unsigned int anio) {
    _dia = dia;
    _mes = mes;
    _anio = anio;
}

unsigned int Fecha::getDia() { return _dia; }
unsigned int Fecha::getMes() { return _mes; }
unsigned int Fecha::getAnio() { return _anio; }

void Fecha::setDia(unsigned int d) { _dia = d; }
void Fecha::setMes(unsigned int m) { _mes = m; }
void Fecha::setAnio(unsigned int a) { _anio = a; }

void Fecha::mostrar() {
    std::cout << _dia << "/" << _mes << "/" << _anio;
}

std::ostream& operator<<(std::ostream& os, const Fecha& obj) {
    os << obj.getDia() << "/" << obj.getMes() << "/" << obj.getAnio(); 
    return os;
}