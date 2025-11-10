#include "ProductosManager.h"

ProductoManager::ProductoManager(string ruta) {
    this->rutaArchivo = ruta;
    cargarDeArchivo();
}

void ProductoManager::agregar(Producto& prod) {
    this->productos.push_back(prod);
}

bool ProductoManager::eliminar(int id) {
    int indice = obtenerIndice(id);
    if (indice != -1) {
        this->productos.erase(this->productos.begin() + indice);
        return true;
    }
    return false;
}

Producto* ProductoManager::buscar(int id) {
    for (size_t i = 0; i < this->productos.size(); ++i) {
        if (this->productos[i].getID() == id) {
            return &this->productos[i];
        }
    }
    return nullptr; // nullptr es el equivalente a NULL en C++ moderno
}

int ProductoManager::obtenerIndice(int id) {
    for (size_t i = 0; i < this->productos.size(); ++i) {
        if (this->productos[i].getID() == id) {
            return i;
        }
    }
    return -1; // -1 indica que no se encontró
}

int ProductoManager::getCantidad() {
    return this->productos.size();
}

Producto ProductoManager::getPorIndice(int index) {
    return this->productos[index];
}

void ProductoManager::listarTodos() {
    for (size_t i = 0; i < this->productos.size(); ++i) {
        // this->productos[i]->mostrar();
        cout << "--------------------" << endl;
    }
}

bool ProductoManager::cargarDeArchivo() {
    // this->productos.clear();
    // FILE* pFile = fopen(this->rutaArchivo.c_str(), "rb");
    // if (pFile == NULL) {
    //     return false; // Si no existe el archivo, no hay nada que cargar
    // }

    // Producto temp;
    // while (fread(&temp, sizeof(Producto), 1, pFile) == 1) {
    //     this->productos.push_back(temp);
    // }

    // fclose(pFile);
    return true;
}

bool ProductoManager::escribirArchivo() {
    // FILE* pFile = fopen(this->rutaArchivo.c_str(), "wb");
    // if (pFile == NULL) {
    //     return false;
    // }

    // for (size_t i = 0; i < this->productos.size(); ++i) {
    //     fwrite(&this->productos[i], sizeof(Producto), 1, pFile);
    // }

    // fclose(pFile);
    return true;
}

// Implementaciones Base
void ProductoManager::alta() {
    cout << "[Productos] Alta (pendiente de implementar)" << endl;
}

void ProductoManager::baja() {
    cout << "[Productos] Baja (pendiente de implementar)" << endl;
}

void ProductoManager::modificacion() {
    cout << "[Productos] Modificacion (pendiente de implementar)" << endl;
}

void ProductoManager::consulta() const {
    cout << "[Productos] Consulta (pendiente de implementar)" << endl;
}
