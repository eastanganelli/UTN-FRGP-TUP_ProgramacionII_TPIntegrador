#include "ProveedoresManager.h"

#include <iostream>

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

Proveedor *ProveedorManager::SeleccionarRandom() {
    FILE* archivo = fopen(this->rutaArchivo.c_str(), "rb");
    if (archivo == nullptr) {
        return nullptr;
    }
    unsigned int cantidadProveedores = this->Contar();
    if (cantidadProveedores == 0) {
        fclose(archivo);
        return nullptr;
    }
    unsigned int indiceAleatorio = rand() % cantidadProveedores;
    fseek(archivo, sizeof(Proveedor) * indiceAleatorio, SEEK_SET);
    Proveedor* proveedorSeleccionado = new Proveedor();
    fread(proveedorSeleccionado, sizeof(Proveedor), 1, archivo);
    fclose(archivo);
    return proveedorSeleccionado;
}

Proveedor* ProveedorManager::Obtener(string cuit) {
    FILE* archivo = fopen(this->rutaArchivo.c_str(), "rb");
    if (archivo == nullptr) {
        return nullptr;
    }
    Proveedor* proveedor = new Proveedor();
    while (fread(proveedor, sizeof(Proveedor), 1, archivo)) {
        string cuitProveedor = proveedor->getCuit();
        if (cuitProveedor == cuit) {
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

Proveedor* ProveedorManager::Listar() {
    const unsigned int cantidadProveedores = this->Contar();
    Proveedor* proveedores = new Proveedor[cantidadProveedores];;
    if(cantidadProveedores == 0 && proveedores != nullptr) {
        FILE* archivo = fopen(this->rutaArchivo.c_str(), "rb");
        if (archivo == nullptr) {
            delete[] proveedores;
            return nullptr;
        }
        unsigned int i = 0;
        while (fread(&proveedores[i], sizeof(Proveedor), 1, archivo)) {
            i++;
        }
        fclose(archivo);
    }
    return proveedores;
}

void ProveedorManager::ListarXNombre() {
    Proveedor* misProveedores = this->Listar();

    if(misProveedores == nullptr) {
        const unsigned int cantidadProveedores = this->Contar();
        for (unsigned int i = 0; i < cantidadProveedores - 1; i++) {
            for (unsigned int j = 0; j < cantidadProveedores - i - 1; j++) {
                if (misProveedores[j].getNombreRazon() > misProveedores[j + 1].getNombreRazon()) {
                    Proveedor temp = misProveedores[j];
                    misProveedores[j] = misProveedores[j + 1];
                    misProveedores[j + 1] = temp;
                }
            }
        }
        this->Imprimir(misProveedores, cantidadProveedores);
        delete[] misProveedores;
    }
}

void ProveedorManager::ListarXRubro() {
    Proveedor* misProveedores = this->Listar();

    if(misProveedores != nullptr) {
        const unsigned int cantidadProveedores = this->Contar();
        for (unsigned int i = 0; i < cantidadProveedores - 1; i++) {
            for (unsigned int j = 0; j < cantidadProveedores - i - 1; j++) {
                if (misProveedores[j].getRubro() > misProveedores[j + 1].getRubro()) {
                    Proveedor temp = misProveedores[j];
                    misProveedores[j] = misProveedores[j + 1];
                    misProveedores[j + 1] = temp;
                }
            }
        }
        this->Imprimir(misProveedores, cantidadProveedores);
        delete[] misProveedores;
    }
}

void ProveedorManager::ListarXCUIT() {
    Proveedor* misProveedores = this->Listar();

    if(misProveedores != nullptr) {
        const unsigned int cantidadProveedores = this->Contar();
        for (unsigned int i = 0; i < cantidadProveedores - 1; i++) {
            for (unsigned int j = 0; j < cantidadProveedores - i - 1; j++) {
                if (misProveedores[j].getCuit() > misProveedores[j + 1].getCuit()) {
                    Proveedor temp = misProveedores[j];
                    misProveedores[j] = misProveedores[j + 1];
                    misProveedores[j + 1] = temp;
                }
            }
        }
        this->Imprimir(misProveedores, cantidadProveedores);
        delete[] misProveedores;
    }
}

void ProveedorManager::ConsultarXCUIT(string cuit) {
    FILE* archivo = fopen(this->rutaArchivo.c_str(), "rb");
    if (archivo == nullptr) {
        return;
    }
    Proveedor* resultados = new Proveedor[0];
    unsigned int contador = 0;
    Proveedor proveedor;
    while (fread(&proveedor, sizeof(Proveedor), 1, archivo)) {
        if (proveedor.getCuit() == cuit) {
            resultados = this->Redimensionar(resultados, contador, contador + 1);
            resultados[contador++] = proveedor;
        }
    }
    fclose(archivo);
    this->Imprimir(resultados, contador);
    delete[] resultados;
}

void ProveedorManager::ConsultarXNombre(string nombreRazon) {
    FILE* archivo = fopen(this->rutaArchivo.c_str(), "rb");
    if (archivo == nullptr) {
        return;
    }
    Proveedor* resultados = new Proveedor[0];
    unsigned int contador = 0;
    Proveedor proveedor;
    while (fread(&proveedor, sizeof(Proveedor), 1, archivo)) {
        if (proveedor.getNombreRazon() == nombreRazon) {
            resultados = this->Redimensionar(resultados, contador, contador + 1);
            resultados[contador++] = proveedor;
        }
    }
    fclose(archivo);
    this->Imprimir(resultados, contador);
    delete[] resultados;
}

void ProveedorManager::ConsultarXRubro(unsigned int rubro) {
    FILE* archivo = fopen(this->rutaArchivo.c_str(), "rb");
    if (archivo == nullptr) {
        return;
    }
    Proveedor* resultados = new Proveedor[0];
    unsigned int contador = 0;
    Proveedor proveedor;
    while (fread(&proveedor, sizeof(Proveedor), 1, archivo)) {
        if (proveedor.getRubro() == rubro) {
            resultados = this->Redimensionar(resultados, contador, contador + 1);
            resultados[contador++] = proveedor;
        }
    }
    fclose(archivo);
    this->Imprimir(resultados, contador);
    delete[] resultados;
}

void ProveedorManager::ConsultarXEstado(bool estado) {
    FILE* archivo = fopen(this->rutaArchivo.c_str(), "rb");
    if (archivo == nullptr) {
        return;
    }
    Proveedor* resultados = new Proveedor[0];
    unsigned int contador = 0;
    Proveedor proveedor;
    while (fread(&proveedor, sizeof(Proveedor), 1, archivo)) {
        if (proveedor.getAlta() == estado) {
            resultados = this->Redimensionar(resultados, contador, contador + 1);
            resultados[contador++] = proveedor;
        }
    }
    fclose(archivo);
    this->Imprimir(resultados, contador);
    delete[] resultados;
}

Proveedor* ProveedorManager::Redimensionar(Proveedor *proveedores, unsigned int capacidadActual, unsigned int nuevaCapacidad) {
    Proveedor* nuevosProveedores = new Proveedor[nuevaCapacidad];
    unsigned int elementosACopiar = (capacidadActual < nuevaCapacidad) ? capacidadActual : nuevaCapacidad;
    for (unsigned int i = 0; i < elementosACopiar; i++) {
        nuevosProveedores[i] = proveedores[i];
    }
    delete[] proveedores;
    return nuevosProveedores;
}

void ProveedorManager::Imprimir(Proveedor *misProveedores, unsigned int cantidadProveedores) {
    for (unsigned int i = 0; i < cantidadProveedores; i++) {
        cout << misProveedores[i].toString() << endl;
    }
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

unsigned int ProveedorManager::SeleccionarRubro() {
    int seleccion = -1;
    do {
        unsigned int i = 0;
        cout << "ID | Rubro" << endl << "===========" << endl;
        for(string rubro: this->rubros) {
            i++;
            cout << i << " | " << rubro << endl;
        }

        cout << "Seleccionar: ";
        cin >> seleccion;

        if(seleccion > 0 && seleccion < this->rubros->length()) {
            break;
        } else {
            cout << "Valor incorrecto.";
            system("pause");
            system("cls");
        }
    } while (true);

    return seleccion;
}

string ProveedorManager::getNombreRubro(unsigned int cr) {
    for(unsigned int i = 0; i < this->rubros->length(); i++) {
        if(i == cr - 1) {
            return this->rubros[i];
        }
    }
    return "Otros";
}
