#include "clientes.h"

Clientes::Clientes(string ruta) : rutaArchivo(ruta) { }

Clientes::~Clientes() { }

int Clientes::Posicion(string dni, unsigned int& posicion) {
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

Cliente *Clientes::Redimensionar(Cliente *clientes, unsigned int capacidadActual, unsigned int nuevaCapacidad) {
    Cliente* nuevosClientes = new Cliente[nuevaCapacidad];
    unsigned int elementosACopiar = (capacidadActual < nuevaCapacidad) ? capacidadActual : nuevaCapacidad;
    for (unsigned int i = 0; i < elementosACopiar; i++) {
        nuevosClientes[i] = clientes[i];
    }
    delete[] clientes;
    return nuevosClientes;
}

void Clientes::Imprimir(Cliente* misClientes, unsigned int cantidadClientes) {
    for (unsigned int i = 0; i < cantidadClientes; i++) {
        // cout << misClientes[i].toString() << endl;
    }
    system ("pause");
}

bool Clientes::Existe(Cliente& cliente) {
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

bool Clientes::Crear(Cliente& cliente) {
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

Cliente* Clientes::Obtener(string dni) {
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

Cliente* Clientes::operator[](string dni) {
    return Obtener(dni);
}

bool Clientes::Modificar(string dni, Cliente* clienteActualizado) {
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

bool Clientes::Modificar(string dni, Cliente& clienteActualizado) {
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

bool Clientes::Eliminar(string dni) {
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

Cliente* Clientes::Listar() {
    const unsigned int cantidadClientes = this->Contar();
    Cliente* clientes = new Cliente[cantidadClientes];
    if(cantidadClientes > 0 && clientes != nullptr) {
        FILE* archivo = fopen(this->rutaArchivo.c_str(), "rb");
        if (archivo == nullptr) {
            delete[] clientes;
            return nullptr;
        }
        unsigned int i = 0;
        while (fread(&clientes[i], sizeof(Cliente), 1, archivo)) {
            i++;
        }
        fclose(archivo);
    }
    return clientes;
}

void Clientes::ListarXApellido() {
    Cliente* misClientes = this->Listar();

    if(misClientes != nullptr) {
        const unsigned int cantidadClientes = this->Contar();
        for (unsigned int i = 0; i < cantidadClientes - 1; i++) {
            for (unsigned int j = 0; j < cantidadClientes - i - 1; j++) {
                if (misClientes[j].getApellido() > misClientes[j + 1].getApellido()) {
                    Cliente temp = misClientes[j];
                    misClientes[j] = misClientes[j + 1];
                    misClientes[j + 1] = temp;
                }
            }
        }
        this->Imprimir(misClientes, cantidadClientes);
    }
}

void Clientes::ListarXDNI() {
    Cliente* misClientes = this->Listar();
    if(misClientes != nullptr) {
        const unsigned int cantidadClientes = this->Contar();
        for (unsigned int i = 0; i < cantidadClientes - 1; i++) {
            for (unsigned int j = 0; j < cantidadClientes - i - 1; j++) {
                if (misClientes[j].getDNI() > misClientes[j + 1].getDNI()) {
                    Cliente temp = misClientes[j];
                    misClientes[j] = misClientes[j + 1];
                    misClientes[j + 1] = temp;
                }
            }
        }
        this->Imprimir(misClientes, cantidadClientes);
    }
}

void Clientes::ListarXcuilcuit() {
    Cliente* misClientes = this->Listar();
    if(misClientes != nullptr) {
        const unsigned int cantidadClientes = this->Contar();
        for (unsigned int i = 0; i < cantidadClientes - 1; i++) {
            for (unsigned int j = 0; j < cantidadClientes - i - 1; j++) {
                if (misClientes[j].getCuilCuit() > misClientes[j + 1].getCuilCuit()) {
                    Cliente temp = misClientes[j];
                    misClientes[j] = misClientes[j + 1];
                    misClientes[j + 1] = temp;
                }
            }
        }
        this->Imprimir(misClientes, cantidadClientes);
    }
}

void Clientes::ConsultaXCUILCuit(string cuilcuit) {
    FILE* archivo = fopen(this->rutaArchivo.c_str(), "rb");
    if (archivo == nullptr) {
        return;
        return;
    }
    Cliente* resultados = new Cliente[0];
    unsigned int contador = 0;
    Cliente cliente;
    while (fread(&cliente, sizeof(Cliente), 1, archivo)) {
        string aux = cliente.getCuilCuit();
        if (aux.find(cuilcuit )!= string::npos){
            resultados = this->Redimensionar(resultados, contador, contador + 1);
            resultados[contador++] = cliente;
        }
    }
    fclose(archivo);
    this ->Imprimir(resultados,contador);
    delete [] resultados;

}

void Clientes::ConsultaXDNI(string dni) {
    FILE* archivo = fopen(this->rutaArchivo.c_str(), "rb");
    if (archivo == nullptr) {
        return;}
    Cliente* resultados = new Cliente[0];
    unsigned int contador = 0;
    Cliente cliente;
    while (fread(&cliente, sizeof(Cliente), 1, archivo)) {
        string aux = cliente.getDNI();
        if (aux.find(dni)!= string::npos) {
            resultados = this->Redimensionar(resultados, contador, contador + 1);
            resultados[contador++] = cliente;
        }
    }
    fclose(archivo);
     this ->Imprimir(resultados,contador);
    delete [] resultados;

}

void Clientes::ConsultaXNombreApellido(string nombre, string apellido) {
    FILE* archivo = fopen(this->rutaArchivo.c_str(), "rb");
    if (archivo == nullptr) {
        return;}
    Cliente* resultados = new Cliente[0];
    unsigned int contador = 0;
    Cliente cliente;
    while (fread(&cliente, sizeof(Cliente), 1, archivo)) {
        string aux = cliente.getNombre(), aux2 = cliente.getApellido();
        if ((aux.find(nombre)!= string::npos)  && (aux2.find(apellido)!= string::npos) ) {

            resultados = this->Redimensionar(resultados, contador, contador + 1);
            resultados[contador++] = cliente;
        }
    }
    fclose(archivo);
    this ->Imprimir(resultados,contador);
    delete [] resultados;

}

void Clientes::ConsultaXCorreo(string correo) {
    FILE* archivo = fopen(this->rutaArchivo.c_str(), "rb");
    if (archivo == nullptr) {
        return;
    }
    Cliente* resultados = new Cliente[0];
    unsigned int contador = 0;
    Cliente cliente;
    while (fread(&cliente, sizeof(Cliente), 1, archivo)) {
        string aux = cliente.getCorreo();
        if (aux.find(correo)!= string ::npos) {

            resultados = this->Redimensionar(resultados, contador, contador + 1);
            resultados[contador++] = cliente;
        }
    }
    fclose(archivo);
    this ->Imprimir(resultados,contador);
    delete [] resultados;
}

unsigned int Clientes::Contar() {
    FILE* archivo = fopen(this->rutaArchivo.c_str(), "rb");
    if (archivo == nullptr) {
        return 0;
    }
    fseek(archivo, 0, SEEK_END);
    unsigned int size = ftell(archivo);
    fclose(archivo);
    return size / sizeof(Cliente);
}
