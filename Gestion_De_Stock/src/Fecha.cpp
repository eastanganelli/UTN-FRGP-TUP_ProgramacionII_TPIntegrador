#include "Fecha.h"

Fecha::Fecha(unsigned int dia, unsigned int mes, unsigned int anio) {
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

unsigned int Fecha::getDia() { return this->dia; }
unsigned int Fecha::getMes() { return this->mes; }
unsigned int Fecha::getAnio() { return this->anio; }

void Fecha::setDia(unsigned int d) { this->dia = d; }
void Fecha::setMes(unsigned int m) { this->mes = m; }
void Fecha::setAnio(unsigned int a) { this->anio = a; }

std::ostream& operator<<(std::ostream& os, Fecha* obj) {
    os << obj->getDia() << "/" << obj->getMes() << "/" << obj->getAnio();
    return os;
}
