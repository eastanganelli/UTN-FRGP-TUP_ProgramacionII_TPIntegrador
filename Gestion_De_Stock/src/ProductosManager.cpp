#include "ProductosManager.h"

ProductoManager::ProductoManager(string ruta) {
    this->rutaArchivo = ruta;
}

ProductoManager::~ProductoManager() {

}

int ProductoManager::Posicion(string codigo, unsigned int& posicion) {
    FILE* archivo = fopen(this->rutaArchivo.c_str(), "rb");
    if (archivo == nullptr) {
        return -1;
    }
    Producto producto;
    unsigned int index = 0;
    while (fread(&producto, sizeof(Producto), 1, archivo)) {
        if (producto.getCodigo() == codigo) {
            posicion = index;
            fclose(archivo);
            return 0;
        }
        index++;
    }
    fclose(archivo);
    return -1;
}

bool ProductoManager::Existe(string codigo) {
    FILE* archivo = fopen(this->rutaArchivo.c_str(), "rb");
    if (archivo == nullptr) {
        return false;
    }
    Producto tempProducto;
    while (fread(&tempProducto, sizeof(Producto), 1, archivo)) {
        if (tempProducto.getCodigo() == codigo) {
            fclose(archivo);
            return true;
        }
    }
    fclose(archivo);
    return false;
}

bool ProductoManager::Existe(Producto& producto) {
    FILE* archivo = fopen(this->rutaArchivo.c_str(), "rb");
    if (archivo == nullptr) {
        return false;
    }
    Producto tempProducto;
    while (fread(&tempProducto, sizeof(Producto), 1, archivo)) {
        if (tempProducto.getCodigo() == producto.getCodigo()) {
            fclose(archivo);
            return true;
        }
    }
    fclose(archivo);
    return false;
}

bool ProductoManager::Crear(Producto& producto) {
    if (Existe(producto)) {
        return false;
    }
    FILE* archivo = fopen(this->rutaArchivo.c_str(), "ab");
    if (archivo == nullptr) {
        return false;
    }
    fwrite(&producto, sizeof(Producto), 1, archivo);
    fclose(archivo);
    return true;
}

Producto* ProductoManager::Obtener(string codigo) {
    FILE* archivo = fopen(this->rutaArchivo.c_str(), "rb");
    if (archivo == nullptr) {
        return nullptr;
    }
    Producto* producto = new Producto();
    while (fread(producto, sizeof(Producto), 1, archivo)) {
        if (producto->getCodigo() == codigo) {
            fclose(archivo);
            return producto;
        }
    }
    fclose(archivo);
    delete producto;
    return nullptr;
}

Producto* ProductoManager::operator[](string codigo) {
    return Obtener(codigo);
}

bool ProductoManager::Modificar(string codigo, Producto* productoActualizado) {
    FILE* archivo = fopen(this->rutaArchivo.c_str(), "r+b");
    bool resultado = false;
    unsigned int pos = 0;

    if (this->Posicion(codigo, pos) || archivo == nullptr) {
        return resultado;
    }
    fseek(archivo, sizeof(Producto) * pos, SEEK_SET);
    resultado = fwrite(productoActualizado, sizeof(Producto), 1, archivo);
    fclose(archivo);
    return resultado;
}

bool ProductoManager::Modificar(string codigo, Producto& productoActualizado) {
    FILE* archivo = fopen(this->rutaArchivo.c_str(), "r+b");
    bool resultado = false;
    unsigned int pos = 0;

    if (this->Posicion(codigo, pos) || archivo == nullptr) {
        return resultado;
    }
    fseek(archivo, sizeof(Producto) * pos, SEEK_SET);
    resultado = fwrite(&productoActualizado, sizeof(Producto), 1, archivo);
    fclose(archivo);
    return resultado;
}

bool ProductoManager::Eliminar(string codigo) {
    FILE* archivo = fopen(this->rutaArchivo.c_str(), "rb");
    if (archivo == nullptr) {
        return false;
    }
    FILE* tempArchivo = fopen("temp.dat", "wb");
    if (tempArchivo == nullptr) {
        fclose(archivo);
        return false;
    }
    Producto producto;
    bool encontrado = false;
    while (fread(&producto, sizeof(Producto), 1, archivo)) {
        if (producto.getCodigo() != codigo) {
            fwrite(&producto, sizeof(Producto), 1, tempArchivo);
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

vector<Producto> ProductoManager::Listar() {
    vector<Producto> productos;
    FILE* archivo = fopen(this->rutaArchivo.c_str(), "rb");
    if (archivo == nullptr) {
        return productos;
    }
    Producto producto;
    while (fread(&producto, sizeof(Producto), 1, archivo)) {
        productos.push_back(producto);
    }
    fclose(archivo);
    return productos;
}

unsigned int ProductoManager::Contar() {
    FILE* archivo = fopen(this->rutaArchivo.c_str(), "rb");
    if (archivo == nullptr) {
        return 0;
    }
    fseek(archivo, 0, SEEK_END);
    unsigned int size = ftell(archivo);
    fclose(archivo);
    return size / sizeof(Producto);
}

string ProductoManager::generarCodigo() {
    const char caracteresPosibles[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    const int numCaracteresPosibles = sizeof(caracteresPosibles) - 1;

    string codigo;

    while(true) {
        for (int i = 0; i < 9; ++i) {
            int indiceAleatorio = rand() % numCaracteresPosibles;
            codigo += caracteresPosibles[indiceAleatorio];
        }
        codigo += '\0';
        if(!this->Existe(codigo)) {
            break;
        }
        codigo.clear();
    }

    return codigo;
}
