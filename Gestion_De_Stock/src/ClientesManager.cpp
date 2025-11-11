#include "ClientesManager.h"

ClienteManager::ClienteManager(string ruta) {
    this->rutaArchivo = ruta;
}

ClienteManager::~ClienteManager() {

}

bool ClienteManager::clienteExiste(Cliente& cliente) {
    FILE* archivo = fopen(this->rutaArchivo.c_str(), "rb");
    if (archivo == nullptr) {
        return false;
    }
    Cliente tempCliente;
    while (fread(&tempCliente, sizeof(Cliente), 1, archivo)) {
        if (tempCliente.getID() == cliente.getID()) {
            fclose(archivo);
            return true;
        }
    }
    fclose(archivo);
    return false;
}

bool ClienteManager::CrearCliente(Cliente& cliente) {
    if (clienteExiste(cliente)) {
        return false;
    }
    FILE* archivo = fopen(this->rutaArchivo.c_str(), "ab");
    if (archivo == nullptr) {
        return false;
    }
    fwrite(&cliente, sizeof(Cliente), 1, archivo);
    fclose(archivo);
    return true;
}

Cliente* ClienteManager::ObtenerCliente(unsigned int id) {
    FILE* archivo = fopen(this->rutaArchivo.c_str(), "rb");
    if (archivo == nullptr) {
        return nullptr;
    }
    Cliente* cliente = new Cliente();
    while (fread(cliente, sizeof(Cliente), 1, archivo)) {
        if (cliente->getID() == id) {
            fclose(archivo);
            return cliente;
        }
    }
    fclose(archivo);
    delete cliente;
    return nullptr;
}

Cliente* ClienteManager::operator[](unsigned int id) {
    return ObtenerCliente(id);
}

bool ClienteManager::ModificarCliente(unsigned int id, Cliente& clienteActualizado) {
    FILE* archivo = fopen(this->rutaArchivo.c_str(), "r+b");
    if (archivo == nullptr) {
        return false;
    }
    Cliente cliente;
    while (fread(&cliente, sizeof(Cliente), 1, archivo)) {
        if (cliente.getID() == id) {
            fseek(archivo, -static_cast<long>(sizeof(Cliente)), SEEK_CUR);
            fwrite(&clienteActualizado, sizeof(Cliente), 1, archivo);
            fclose(archivo);
            return true;
        }
    }
    fclose(archivo);
    return false;
}

bool ClienteManager::EliminarCliente(unsigned int id) {
    FILE* archivo = fopen(this->rutaArchivo.c_str(), "rb");
    if (archivo == nullptr) {
        return false;
    }
    FILE* tempArchivo = fopen("temp.dat", "wb");
    if (tempArchivo == nullptr) {
        fclose(archivo);
        return false;
    }
    Cliente cliente;
    bool encontrado = false;
    while (fread(&cliente, sizeof(Cliente), 1, archivo)) {
        if (cliente.getID() != id) {
            fwrite(&cliente, sizeof(Cliente), 1, tempArchivo);
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

vector<Cliente> ClienteManager::ListarClientes() {
    vector<Cliente> clientes;
    FILE* archivo = fopen(this->rutaArchivo.c_str(), "rb");
    if (archivo == nullptr) {
        return clientes;
    }
    Cliente cliente;
    while (fread(&cliente, sizeof(Cliente), 1, archivo)) {
        clientes.push_back(cliente);
    }
    fclose(archivo);
    return clientes;
}

unsigned int ClienteManager::ContarClientes() {
    FILE* archivo = fopen(this->rutaArchivo.c_str(), "rb");
    if (archivo == nullptr) {
        return 0;
    }
    fseek(archivo, 0, SEEK_END);
    unsigned int size = ftell(archivo);
    fclose(archivo);
    return size / sizeof(Cliente);
}