#include "../include/ProveedoresManager.h"

ProveedorManager::ProveedorManager(string ruta) {
    this->rutaArchivo = ruta;
}

ProveedorManager::~ProveedorManager() {

}

int ProveedorManager::Posicion(string cuit, unsigned int& posicion) {
    FILE* archivo = fopen(this->rutaArchivo.c_str(), "rb");
    if (archivo == nullptr) {
        return -1;
    }
    Proveedor proveedor;
    unsigned int index = 0;
    while (fread(&proveedor, sizeof(Proveedor), 1, archivo)) {
        if (proveedor.getCuit() == cuit) {
            posicion = index;
            fclose(archivo);
            return 0;
        }
        index++;
    }
    fclose(archivo);
    return -1;
}

bool ProveedorManager::Existe(Proveedor& proveedor) {
    FILE* archivo = fopen(this->rutaArchivo.c_str(), "rb");
    if (archivo == nullptr) {
        return false;
    }
    Proveedor tempProveedor;
    while (fread(&tempProveedor, sizeof(Proveedor), 1, archivo)) {
        if (tempProveedor.getCuit() == proveedor.getCuit()) {
            fclose(archivo);
            return true;
        }
    }
    fclose(archivo);
    return false;
}

bool ProveedorManager::Crear(Proveedor& proveedor) {
    if (Existe(proveedor)) {
        return false;
    }
    FILE* archivo = fopen(this->rutaArchivo.c_str(), "ab");
    if (archivo == nullptr) {
        return false;
    }
    fwrite(&proveedor, sizeof(Proveedor), 1, archivo);
    fclose(archivo);
    return true;
}

Proveedor* ProveedorManager::Obtener(string cuit) {
    FILE* archivo = fopen(this->rutaArchivo.c_str(), "rb");
    if (archivo == nullptr) {
        return nullptr;
    }
    Proveedor* proveedor = new Proveedor();
    while (fread(proveedor, sizeof(Proveedor), 1, archivo)) {
        if (proveedor->getCuit() == cuit) {
            fclose(archivo);
            return proveedor;
        }
    }
    fclose(archivo);
    delete proveedor;
    return nullptr;
}

Proveedor* ProveedorManager::operator[](string cuit) {
    return Obtener(cuit);
}

bool ProveedorManager::Modificar(string cuit, Proveedor* proveedorActualizado) {
    FILE* archivo = fopen(this->rutaArchivo.c_str(), "r+b");
    bool resultado = false;
    unsigned int pos = 0;

    if (this->Posicion(cuit, pos) || archivo == nullptr) {
        return resultado;
    }
    fseek(archivo, sizeof(Proveedor) * pos, SEEK_SET);
    resultado = fwrite(proveedorActualizado, sizeof(Proveedor), 1, archivo);
    fclose(archivo);
    return resultado;
}

bool ProveedorManager::Modificar(string cuit, Proveedor& proveedorActualizado) {
    FILE* archivo = fopen(this->rutaArchivo.c_str(), "r+b");
    bool resultado = false;
    unsigned int pos = 0;

    if (this->Posicion(cuit, pos) || archivo == nullptr) {
        return resultado;
    }
    fseek(archivo, sizeof(Proveedor) * pos, SEEK_SET);
    resultado = fwrite(&proveedorActualizado, sizeof(Proveedor), 1, archivo);
    fclose(archivo);
    return resultado;
}

bool ProveedorManager::Eliminar(string cuit) {
    FILE* archivo = fopen(this->rutaArchivo.c_str(), "rb");
    if (archivo == nullptr) {
        return false;
    }
    FILE* tempArchivo = fopen("temp.dat", "wb");
    if (tempArchivo == nullptr) {
        fclose(archivo);
        return false;
    }
    Proveedor proveedor;
    bool encontrado = false;
    while (fread(&proveedor, sizeof(Proveedor), 1, archivo)) {
        if (proveedor.getCuit() != cuit) {
            fwrite(&proveedor, sizeof(Proveedor), 1, tempArchivo);
        } else {
            encontrado = true;
        }
    }
    fclose(archivo);
    fclose(tempArchivo);
    remove(this->rutaArchivo.c_str());
    rename("temp.dat", this->rutaArchivo.c_str());
    return encontrado;
}

vector<Proveedor> ProveedorManager::Listar() {
    vector<Proveedor> proveedors;
    FILE* archivo = fopen(this->rutaArchivo.c_str(), "rb");
    if (archivo == nullptr) {
        return proveedors;
    }
    Proveedor proveedor;
    while (fread(&proveedor, sizeof(Proveedor), 1, archivo)) {
        proveedors.push_back(proveedor);
    }
    fclose(archivo);
    return proveedors;
}

unsigned int ProveedorManager::Contar() {
    FILE* archivo = fopen(this->rutaArchivo.c_str(), "rb");
    if (archivo == nullptr) {
        return 0;
    }
    fseek(archivo, 0, SEEK_END);
    unsigned int size = ftell(archivo);
    fclose(archivo);
    return size / sizeof(Proveedor);
}
