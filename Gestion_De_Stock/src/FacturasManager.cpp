#include "FacturasManager.h"

FacturaManager::FacturaManager(string ruta) {
    this->rutaArchivo = ruta;
    cargarDeArchivo();
}

void FacturaManager::agregar(Factura& fact) {
    this->facturas.push_back(fact);
}

bool FacturaManager::eliminar(int idVenta) {
    int indice = obtenerIndice(idVenta);
    if (indice != -1) {
        this->facturas.erase(this->facturas.begin() + indice);
        return true;
    }
    return false;
}

Factura* FacturaManager::buscar(int idVenta) {
    for (size_t i = 0; i < this->facturas.size(); ++i) {
        if (this->facturas[i].getID() == idVenta) {
            return &this->facturas[i];
        }
    }
    return nullptr;
}

int FacturaManager::obtenerIndice(int idVenta) {
    for (size_t i = 0; i < this->facturas.size(); ++i) {
        if (this->facturas[i].getID() == idVenta) {
            return i;
        }
    }
    return -1;
}

int FacturaManager::getCantidad() {
    return this->facturas.size();
}

Factura FacturaManager::getPorIndice(int index) {
    return this->facturas[index];
}

void FacturaManager::listarTodos() {
    for (size_t i = 0; i < this->facturas.size(); ++i) {
        this->facturas[i].mostrar();
        cout << "--------------------" << endl;
    }
}

bool FacturaManager::cargarDeArchivo() {
    // this->facturas.clear();
    // FILE* pFile = fopen(this->rutaArchivo.c_str(), "rb");
    // if (pFile == NULL) return false;

    // Factura temp;
    // while (fread(&temp, sizeof(Factura), 1, pFile) == 1) {
    //     this->facturas.push_back(temp);
    // }

    // fclose(pFile);
    return true;
}

bool FacturaManager::escribirArchivo() {
    // FILE* pFile = fopen(this->rutaArchivo.c_str(), "wb");
    // if (pFile == NULL) return false;

    // for (size_t i = 0; i < this->facturas.size(); ++i) {
    //     fwrite(&this->facturas[i], sizeof(Factura), 1, pFile);
    // }

    // fclose(pFile);
    return true;
}
