#include "../include/ClientesManager.h"

ClienteManager::ClienteManager(string ruta) {
    this->rutaArchivo = ruta;
}

ClienteManager::~ClienteManager() {

}

int ClienteManager::Posicion(string dni, unsigned int& posicion) {
    FILE* archivo = fopen(this->rutaArchivo.c_str(), "rb");
    if (archivo == nullptr) {
        return -1;
    }
    Cliente cliente;
    unsigned int index = 0;
    while (fread(&cliente, sizeof(Cliente), 1, archivo)) {
        if (cliente.getDNI() == dni) {
            posicion = index;
            fclose(archivo);
            return 0;
        }
        index++;
    }
    fclose(archivo);
    return -1;
}

bool ClienteManager::Existe(Cliente& cliente) {
    FILE* archivo = fopen(this->rutaArchivo.c_str(), "rb");
    if (archivo == nullptr) {
        return false;
    }
    Cliente tempCliente;
    while (fread(&tempCliente, sizeof(Cliente), 1, archivo)) {
        if (tempCliente.getDNI() == cliente.getDNI()) {
            fclose(archivo);
            return true;
        }
    }
    fclose(archivo);
    return false;
}

bool ClienteManager::Crear(Cliente& cliente) {
    if (Existe(cliente)) {
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

Cliente* ClienteManager::Obtener(string dni) {
    FILE* archivo = fopen(this->rutaArchivo.c_str(), "rb");
    if (archivo == nullptr) {
        return nullptr;
    }
    Cliente* cliente = new Cliente();
    while (fread(cliente, sizeof(Cliente), 1, archivo)) {
        if (cliente->getDNI() == dni) {
            fclose(archivo);
            return cliente;
        }
    }
    fclose(archivo);
    delete cliente;
    return nullptr;
}

Cliente* ClienteManager::operator[](string dni) {
    return Obtener(dni);
}

bool ClienteManager::Modificar(string dni, Cliente* clienteActualizado) {
    FILE* archivo = fopen(this->rutaArchivo.c_str(), "r+b");
    bool resultado = false;
    unsigned int pos = 0;

    if (this->Posicion(dni, pos) || archivo == nullptr) {
        return resultado;
    }
    fseek(archivo, sizeof(Cliente) * pos, SEEK_SET);
    resultado = fwrite(clienteActualizado, sizeof(Cliente), 1, archivo);
    fclose(archivo);
    return resultado;
}

bool ClienteManager::Modificar(string dni, Cliente& clienteActualizado) {
    FILE* archivo = fopen(this->rutaArchivo.c_str(), "r+b");
    bool resultado = false;
    unsigned int pos = 0;

    if (this->Posicion(dni, pos) || archivo == nullptr) {
        return resultado;
    }
    fseek(archivo, sizeof(Cliente) * pos, SEEK_SET);
    resultado = fwrite(&clienteActualizado, sizeof(Cliente), 1, archivo);
    fclose(archivo);
    return resultado;
}

bool ClienteManager::Eliminar(string dni) {
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
        if (cliente.getDNI() != dni) {
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

vector<Cliente> ClienteManager::Listar() {
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

unsigned int ClienteManager::Contar() {
    FILE* archivo = fopen(this->rutaArchivo.c_str(), "rb");
    if (archivo == nullptr) {
        return 0;
    }
    fseek(archivo, 0, SEEK_END);
    unsigned int size = ftell(archivo);
    fclose(archivo);
    return size / sizeof(Cliente);
}
