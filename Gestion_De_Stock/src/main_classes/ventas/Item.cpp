#include "Item.h"
#include "../../controller/validation.h"
#include <sstream>

Item::Item(const char* _codigo, unsigned int _cantidad, float _precioUnitario) {
    this->codigo[0] = '\0';
    this->cantidad = 0;
    this->precioUnitario = 0.0f;
    if (!Validation::IsEmpty(_codigo)) {
        setCodigo(std::string(_codigo));
    }
    this->cantidad = _cantidad;
    this->precioUnitario = _precioUnitario;
}

Item::~Item() { }

std::string Item::getCodigo() const {
    return std::string(this->codigo);
}

unsigned int Item::getCantidad() const {
    return this->cantidad;
}

float Item::getPrecioUnitario() const {
    return this->precioUnitario;
}

void Item::setCodigo(const std::string& c) {
    if (Validation::IsEmpty(c)) {
        this->codigo[0] = '\0';
        return;
    }
    // accept alphanumeric codes only
    if (!Validation::IsAlphanumeric(c)) {
        // store empty to indicate invalid
        this->codigo[0] = '\0';
        return;
    }
    strncpy(this->codigo, c.c_str(), CODIGO_SIZE - 1);
    this->codigo[CODIGO_SIZE - 1] = '\0';
}

void Item::setCantidad(unsigned int c) {
    if (c == 0) return; // do not accept zero
    this->cantidad = c;
}

void Item::setPrecioUnitario(float p) {
    if (p < 0.0f) return;
    this->precioUnitario = p;
}

unsigned int Item::ColCodigoSize() {
    return Item::COL_Codigo;
}

bool Item::operator==(const Item& otro) const {
    return Validation::IsEqual(this->codigo, otro.codigo);
}

bool Item::IsEmpty() const {
    return Validation::IsEmpty(this->codigo) && this->cantidad == 0 && this->precioUnitario == 0.0f;
}

std::string Item::toString() const {
    std::ostringstream oss;
    oss << "Codigo: " << this->codigo
        << " | Cantidad: " << this->cantidad
        << " | PrecioUnitario: " << this->precioUnitario;
    return oss.str();
}
