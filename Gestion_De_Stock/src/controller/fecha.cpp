#include "fecha.h"

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

string Fecha::toString() { return to_string(this->dia) + "/" + to_string(this->mes) + "/" + to_string(this->anio); }

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

Fecha Fecha::CrearFecha() {
    int d = 0, m = 0, a = 0;

    if (!cin.good()) {
        cin.clear();
    }
    Validation::ClearInputLine();

    do {
        cout << "Mes: " << std::flush;
        if (!(cin >> m)) {
            cin.clear();
            Validation::ClearInputLine();
            Warning w("Entrada invalida", "Ingrese solo digitos.");
            w.Show();
            continue;
        }
        Validation::ClearInputLine();

        if (!Validation::IsInRange<int>(m, 1, 12)) {
            Warning w("Mes invalido", "El mes debe estar entre 1 y 12.");
            w.Show();
            continue;
        }

        break;
    } while (true);

    do {
        cout << "Anio: " << std::flush;
        if (!(cin >> a)) {
            cin.clear();
            Validation::ClearInputLine();
            Warning w("Entrada invalida", "Ingrese solo digitos.");
            w.Show();
            continue;
        }
        Validation::ClearInputLine();

        if (!Validation::IsInRange<int>(a, 1900, 9999)) {
            Warning w("Anio invalido", "El anio debe ser mayor o igual a 1900.");
            w.Show();
            continue;
        }

        break;
    } while (true);

    bool isLeap = (a % 4 == 0 && a % 100 != 0) || (a % 400 == 0);
    int maxDay = 31;
    if (m == 2) maxDay = isLeap ? 29 : 28;
    else if (m == 4 || m == 6 || m == 9 || m == 11) maxDay = 30;

    do {
        cout << "Dia: " << std::flush;
        if (!(cin >> d)) {
            cin.clear();
            Validation::ClearInputLine();
            Warning w("Entrada invalida", "Ingrese solo digitos.");
            w.Show();
            continue;
        }
        Validation::ClearInputLine();

        if (!Validation::IsInRange<int>(d, 1, maxDay)) {
            Warning w("Dia invalido", "El dia ingresado no es valido para el mes y anio seleccionados.");
            w.Show();
            continue;
        }

        break;
    } while (true);

    Fecha fecha(d, m, a);
    return fecha;
}

Fecha Fecha::Hoy() {
    Fecha f;
    f.CargarFecha();
    return f;
}
