#include "ClientesManager.h"

ClienteManager::ClienteManager(string ruta) {
    this->rutaArchivo = ruta;
    cargarDeArchivo();
}

void ClienteManager::agregar(Cliente& cli) {
    this->clientes.push_back(cli);
}

bool ClienteManager::eliminar(int id) {
    int indice = obtenerIndice(id);
    if (indice != -1) {
        this->clientes.erase(this->clientes.begin() + indice);
        return true;
    }
    return false;
}

Cliente* ClienteManager::buscar(int id) {
    for (size_t i = 0; i < this->clientes.size(); ++i) {
        if (this->clientes[i].getIDCliente() == id) {
            return &this->clientes[i];
        }
    }
    return nullptr;
}

int ClienteManager::obtenerIndice(int id) {
    for (size_t i = 0; i < this->clientes.size(); ++i) {
        if (this->clientes[i].getIDCliente() == id) {
            return i;
        }
    }
    return -1;
}

int ClienteManager::getCantidad() {
    return this->clientes.size();
}

Cliente ClienteManager::getPorIndice(int index) {
    return this->clientes[index];
}

void ClienteManager::listarTodos() {
    for (size_t i = 0; i < this->clientes.size(); ++i) {
        //this->clientes[i].mostrar();
        cout << "--------------------" << endl;
    }
}

bool ClienteManager::cargarDeArchivo() {
    // this->clientes.clear();
    // FILE* pFile = fopen(this->rutaArchivo.c_str(), "rb");
    // if (pFile == NULL) return false;

    // Cliente temp;
    // while (fread(&temp, sizeof(Cliente), 1, pFile) == 1) {
    //     this->clientes.push_back(temp);
    // }

    // fclose(pFile);
    return true;
}

bool ClienteManager::escribirArchivo() {
    // FILE* pFile = fopen(this->rutaArchivo.c_str(), "wb");
    // if (pFile == NULL) return false;

    // for (size_t i = 0; i < this->clientes.size(); ++i) {
    //     fwrite(&this->clientes[i], sizeof(Cliente), 1, pFile);
    // }

    // fclose(pFile);
    return true;
}
