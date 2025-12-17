#include "Item.h"

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

std::string Item::getCodigo() const { return std::string(this->codigo, CODIGO_SIZE); }

unsigned int Item::getCantidad() const { return this->cantidad; }

float Item::getPrecioUnitario() const { return this->precioUnitario; }

void Item::setCodigo(const std::string& c) {
    if (Validation::IsEmpty(c)) {
        this->codigo[0] = '\0';
        return;
    }
    if (!Validation::IsAlphanumeric(c)) {
        this->codigo[0] = '\0';
        return;
    }
    strncpy(this->codigo, c.c_str(), CODIGO_SIZE);
}

void Item::setCantidad(unsigned int c) {
    if (c == 0) return;
    this->cantidad = c;
}

void Item::setPrecioUnitario(float p) {
    if (p < 0.0f) return;
    this->precioUnitario = p;
}

unsigned int Item::ColCodigoSize() { return Item::COL_Codigo; }

bool Item::operator==(const Item& otro) const { return Validation::IsEqual(this->codigo, otro.codigo); }

bool Item::IsEmpty() const { return Validation::IsEmpty(this->codigo) && this->cantidad == 0 && this->precioUnitario == 0.0f; }

std::string Item::toString() const {
    std::ostringstream oss;
    oss << "Codigo: " << this->codigo
        << " | Cantidad: " << this->cantidad
        << " | PrecioUnitario: " << this->precioUnitario;
    return oss.str();
}

Item Item::NuevoItem(ProductoManager& pm) {
    string codigo;
    while (true) {
        codigo = InputBox("Codigo producto: ");
        if (Validation::IsEmpty(codigo)) {
            Warning w("Codigo invalido", "Ingrese codigo de producto.");
            w.Show(); w.WaitForKey();
            continue;
        }
        Producto* p = pm[codigo];
        if (p == nullptr) {
            Warning w("Producto no encontrado", "No existe producto con ese codigo.");
            w.Show(); w.WaitForKey();
            continue;
        }
        unsigned int stock = p->getStock();
        unsigned int cantidad = InputNumber("Cantidad: ");
        if (cantidad == 0 || cantidad > stock) {
            Warning w("Cantidad invalida", "Cantidad debe ser >0 y menor o igual al stock disponible.");
            w.Show(); w.WaitForKey();
            continue;
        }
        float precio = p->getPrecio();
        Producto aux = *p;
        aux.setStock(stock - cantidad);
        pm.Modificar(aux.getCodigo(), &aux);
        return Item(codigo.c_str(), cantidad, precio);
    }
}

void Item::ModificarItem(Item& item, ProductoManager& pm) {
    Producto* p = pm[item.getCodigo()];
    if (p == nullptr) {
        Warning w("Producto no encontrado", "No existe producto asociado al item.");
        w.Show(); w.WaitForKey();
        return;
    }
    unsigned int stock = p->getStock();
    unsigned int old = item.getCantidad();
    unsigned int nueva = InputNumber("Nueva cantidad: ");
    if (nueva == 0) { Warning w("Cantidad invalida", "Cantidad debe ser mayor a 0.");
    w.Show(); w.WaitForKey(); return; }
    if (nueva > old) {
        unsigned int delta = nueva - old;
        if (delta > stock) { Warning w("Stock insuficiente", "No hay suficiente stock para aumentar la cantidad.");
        w.Show(); w.WaitForKey(); return; }
        Producto aux = *p; aux.setStock(stock - delta);
        pm.Modificar(aux.getCodigo(), &aux);
        item.setCantidad(nueva);
    } else if (nueva < old) {
        unsigned int delta = old - nueva;
        Producto aux = *p; aux.setStock(stock + delta);
        pm.Modificar(aux.getCodigo(), &aux);
        item.setCantidad(nueva);
    }
}

unsigned int Item::EliminarItem(Item& item, ProductoManager& pm) {
    Warning w("Eliminar Item", "Esta seguro que desea eliminar este item?");
    if (!w.ShowYesNo()) return 0;
    Producto* p = pm[item.getCodigo()];
    if (p != nullptr) {
        Producto aux = *p;
        aux.setStock(p->getStock() + item.getCantidad());
        pm.Modificar(aux.getCodigo(), &aux);
    }
    return 1;
}
