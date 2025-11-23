#include "condicion_iva.h"

CondicionIVA::CondicionIVA(const unsigned int codigo, const string descripcion, const float porcentaje) {
    this->codigo = codigo;
    strcpy(this->descripcion, descripcion.c_str());
    this->descripcion[sizeof(this->descripcion) - 1] = '\0';
    this->porcentaje = porcentaje;
}

CondicionIVA::~CondicionIVA() { }

unsigned int CondicionIVA::getCodigo() const {
    return this->codigo;
}

string CondicionIVA::getDescripcion() const {
    return string(this->descripcion);
}

float CondicionIVA::getPorcentaje() const {
    return this->porcentaje;
}

bool CondicionIVA::operator==(const CondicionIVA& otra) const {
    return this->codigo == otra.codigo &&
           strcmp(this->descripcion, otra.descripcion) == 0 &&
           this->porcentaje == otra.porcentaje;
}

bool CondicionIVA::IsEmpty() const {
    return this->codigo == 0 &&
           strlen(this->descripcion) == 0 &&
           this->porcentaje == 0.0f;
}