#include "manager_producto.h"

ProductoManager::ProductoManager(const string& productoPath)
    : FileSystem<Producto>(productoPath) { }

ProductoManager::~ProductoManager() { }

GenericArray<Producto> ProductoManager::Listar() {
    GenericArray<Producto> productos;
    const unsigned int cantidad = this->Count();
    for(unsigned int i = 0; i < cantidad; i++) {
        Producto* aux = this->At(i);
        productos + (*aux);
        delete aux;
    }
    return productos;
}

bool ProductoManager::Agregar(Producto& producto) {
    if(this->Exist(producto)) {
        Warning mi_warning("Alta de Producto", "El producto con codigo " + producto.getCodigo() + " ya existe.");
        mi_warning.Show();
        return false;
    }
    return this->New(producto);
}

bool ProductoManager::Modificar(string codigo, Producto* producto) {
    const unsigned int cantidad = this->Count();
    unsigned int index = 0;
    for(unsigned int i = 0; i < cantidad; i++) {
        Producto* aux = this->At(i);
        if(aux != nullptr && aux->getCodigo() == codigo) {
            index = i;
            delete aux;
            return this->Update(index, *producto);
        }
        delete aux;
    }
    Error mi_error("Modificacion de Producto", "Producto con codigo " + codigo + " no encontrado.");
    mi_error.Show();
    return false;
}

bool ProductoManager::Eliminar(string codigo) {
    const unsigned int cantidad = this->Count();
    unsigned int index = 0;
    for(unsigned int i = 0; i < cantidad; i++) {
        Producto* aux = this->At(i);
        if(aux != nullptr && aux->getCodigo() == codigo) {
            index = i;
            delete aux;
            return this->Delete(index);
        }
        delete aux;
    }
    Error mi_error("Eliminacion de Producto", "Producto con codigo " + codigo + " no encontrado.");
    mi_error.Show();
    return false;
}

Producto* ProductoManager::operator[](string codigo) {
    const unsigned int cantidad = this->Count();
    Producto* aux = nullptr;
    for(unsigned int i = 0; i < cantidad; i++) {
        aux = this->At(i);
        if(aux != nullptr && aux->getCodigo() == codigo) {
            break;
        }
        delete aux;
        aux = nullptr;
    }
    if(aux == nullptr) {
        Warning mi_warning("Busqueda de Producto", "No se encontro producto con codigo " + codigo + ".");
        mi_warning.Show();
    }
    return aux;
}

GenericArray<Producto> ProductoManager::BuscarPorCodigo(string codigo) {
    GenericArray<Producto> resultados;
    const unsigned int cantidad = this->Count();
    if(cantidad == 0) {
        Warning mi_warning("Busqueda de Producto", "No hay productos registrados.");
        mi_warning.Show();
        return resultados;
    }
    for(unsigned int i = 0; i < cantidad; i++) {
        Producto* aux = this->At(i);
        if(aux->getCodigo().find(codigo) != string::npos) {
            resultados + (*aux);
        }
        delete aux;
    }
    if(resultados.Size() == 0) {
        Warning mi_warning("Busqueda de Producto", "No se encontraron productos con codigo/parte de codigo " + codigo + ".");
        mi_warning.Show();
    }
    return resultados;
}

GenericArray<Producto> ProductoManager::BuscarPorDescripcion(string descripcion) {
    GenericArray<Producto> resultados;
    const unsigned int cantidad = this->Count();
    if(cantidad == 0) {
        Warning mi_warning("Busqueda de Producto", "No hay productos registrados.");
        mi_warning.Show();
        return resultados;
    }
    for(unsigned int i = 0; i < cantidad; i++) {
        Producto* aux = this->At(i);
        if(aux->getDescripcion().find(descripcion) != string::npos) {
            resultados + (*aux);
        }
        delete aux;
    }
    if(resultados.Size() == 0) {
        Warning mi_warning("Busqueda de Producto", "No se encontraron productos con descripcion que contenga " + descripcion + ".");
        mi_warning.Show();
    }
    return resultados;
}

GenericArray<Producto> ProductoManager::BuscarPorStockMinimo(unsigned int stockMinimo) {
    GenericArray<Producto> resultados;
    const unsigned int cantidad = this->Count();
    if(cantidad == 0) {
        Warning mi_warning("Busqueda de Producto", "No hay productos registrados.");
        mi_warning.Show();
        return resultados;
    }
    for(unsigned int i = 0; i < cantidad; i++) {
        Producto* aux = this->At(i);
        if(aux->getStock() >= stockMinimo) {
            resultados + (*aux);
        }
        delete aux;
    }
    if(resultados.Size() == 0) {
        Warning mi_warning("Busqueda de Producto", "No se encontraron productos con stock mayor o igual a " + to_string(stockMinimo) + ".");
        mi_warning.Show();
    }
    return resultados;
}

void ProductoManager::ListarPorCodigo() {
    GenericArray<Producto> productos = this->Listar();
    if(productos.Size() == 0) {
        Warning mi_warning("Listado de Productos", "No se encontraron productos para mostrar.");
        mi_warning.Show();
        return;
    }
    for(unsigned int i = 0; i < productos.Size(); i++) {
        for(unsigned int j = i + 1; j < productos.Size(); j++) {
            if(productos[i]->getCodigo() > productos[j]->getCodigo()) {
                productos.Swap(productos[i], productos[j]);
            }
        }
    }
    ProductoManager::Imprimir(productos);
}

void ProductoManager::ListarPorPrecio() {
    GenericArray<Producto> productos = this->Listar();
    if(productos.Size() == 0) {
        Warning mi_warning("Listado de Productos", "No se encontraron productos para mostrar.");
        mi_warning.Show();
        return;
    }
    for(unsigned int i = 0; i < productos.Size(); i++) {
        for(unsigned int j = i + 1; j < productos.Size(); j++) {
            if(productos[i]->getPrecio() > productos[j]->getPrecio()) {
                productos.Swap(productos[i], productos[j]);
            }
        }
    }
    ProductoManager::Imprimir(productos);
}

void ProductoManager::ListarPorStock() {
    GenericArray<Producto> productos = this->Listar();
    if(productos.Size() == 0) {
        Warning mi_warning("Listado de Productos", "No se encontraron productos para mostrar.");
        mi_warning.Show();
        return;
    }
    for(unsigned int i = 0; i < productos.Size(); i++) {
        for(unsigned int j = i + 1; j < productos.Size(); j++) {
            if(productos[i]->getStock() > productos[j]->getStock()) {
                productos.Swap(productos[i], productos[j]);
            }
        }
    }
    ProductoManager::Imprimir(productos);
}

void ProductoManager::Imprimir(GenericArray<Producto>& productos) {
    if(productos.Size() == 0) {
        Warning mi_warning("Listado de Productos", "No se encontraron productos para mostrar.");
        mi_warning.Show();
        return;
    }

    const unsigned int altura = productos.Size(),
                        columnas = 5;
    Tabling::Table mi_tabla(altura, columnas);

    Tabling::Row* header = new Tabling::Row(columnas);
    header->AddCell("Codigo", Producto::ColCodigoSize());
    header->AddCell("Proveedor", Producto::ColCodigoProveedorSize());
    header->AddCell("Descripcion", Producto::ColDescripcionSize());
    header->AddCell("Precio", Producto::ColPrecioSize());
    header->AddCell("Stock", Producto::ColStockSize());
    mi_tabla.AddRow(header);

    for(unsigned int i = 0; i < altura; i++) {
        Tabling::Row* row = new Tabling::Row(columnas);
        Producto* aux = productos[i];
        row->AddCell(aux->getCodigo(), Producto::ColCodigoSize());
        row->AddCell(aux->getCodigoProveedor(), Producto::ColCodigoProveedorSize());
        row->AddCell(aux->getDescripcion(), Producto::ColDescripcionSize());
        row->AddCell(to_string(aux->getPrecio()), Producto::ColPrecioSize());
        row->AddCell(to_string(aux->getStock()), Producto::ColStockSize());
        mi_tabla.AddRow(row);
    }
    mi_tabla.Print();
}
