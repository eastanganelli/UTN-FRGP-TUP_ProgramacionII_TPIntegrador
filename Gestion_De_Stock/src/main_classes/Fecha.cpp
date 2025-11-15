#include "Fecha.h"

Fecha::Fecha(int dia, int mes, int anio) {
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

int Fecha::getDia() { return this->dia; }
int Fecha::getMes() { return this->mes; }
int Fecha::getAnio() { return this->anio; }

void Fecha::setDia(int d) { this->dia = d; }
void Fecha::setMes(int m) { this->mes = m; }
void Fecha::setAnio(int a) { this->anio = a; }

void Fecha::CargarFecha() {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    this->dia = ltm->tm_mday;
    this->mes = ltm->tm_mon + 1;
    this->anio = ltm->tm_year + 1900;
}

string Fecha::toString() {
    return std::to_string(this->dia) + "/" + std::to_string(this->mes) + "/" + std::to_string(this->anio);
}

bool Fecha::operator>(Fecha fechaComparar) {
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

bool Fecha::operator>=(Fecha fechaComparar) {
    return (*this > fechaComparar) || (*this == fechaComparar);
}

bool Fecha::operator<(Fecha fechaComparar) {
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

bool Fecha::operator<=(Fecha fechaComparar) {
    return (*this < fechaComparar) || (*this == fechaComparar);
}

bool Fecha::operator==(Fecha fechaComparar) {
    return (this->anio == fechaComparar.anio &&
            this->mes == fechaComparar.mes &&
            this->dia == fechaComparar.dia);
}

bool Fecha::operator!=(Fecha fechaComparar) {
    return !(*this == fechaComparar);
}
