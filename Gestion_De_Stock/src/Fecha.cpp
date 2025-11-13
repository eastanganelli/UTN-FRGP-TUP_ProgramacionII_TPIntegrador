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

bool Fecha::operator>(const Fecha &fechaComparar) {
    if (this->anio > fechaComparar.anio) {
        return true;
    } else if (this->anio == fechaComparar.anio) {
        if (this->mes > fechaComparar.mes) {
            return true;
        } else if (this->mes == fechaComparar.mes) {
            return this->dia > fechaComparar.dia;
        }
    }
    return false;
}

bool Fecha::operator<(const Fecha &fechaComparar) {
    if (this->anio < fechaComparar.anio) {
        return true;
    } else if (this->anio == fechaComparar.anio) {
        if (this->mes < fechaComparar.mes) {
            return true;
        } else if (this->mes == fechaComparar.mes) {
            return this->dia < fechaComparar.dia;
        }
    }
    return false;
}

bool Fecha::operator==(const Fecha &fechaComparar) {
    return (this->anio == fechaComparar.anio &&
            this->mes == fechaComparar.mes &&
            this->dia == fechaComparar.dia);
}

bool Fecha::operator!=(const Fecha &fechaComparar) {
    return !(*this == fechaComparar);
}

std::ostream& operator<<(std::ostream& os, Fecha* obj) {
    os << obj->getDia() << "/" << obj->getMes() << "/" << obj->getAnio();
    return os;
}
