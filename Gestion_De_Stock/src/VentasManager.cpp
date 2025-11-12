#include "VentasManager.h"

VentaManager::VentaManager(string _nombreArchivoFactura, string _nombreArchivoNotaDeCredito) {
    this->rutasArchivos[0] = _nombreArchivoFactura;
    this->rutasArchivos[1] = _nombreArchivoNotaDeCredito;;
}

VentaManager::~VentaManager() {

}

Factura *VentaManager::ListarFacturas() {
    const unsigned int cantidadFacturas = this->ContarFacturas();
    Factura* misFacturas = new Factura[cantidadFacturas];
    unsigned int contador = 0;
    FILE* archivo = fopen(this->rutasArchivos[0].c_str(), "rb");
    if (archivo == nullptr) {
        return nullptr;
    }
    unsigned int i = 0;
    while (fread(&misFacturas[i], sizeof(Factura), 1, archivo)) {
        i++;
    }
    fclose(archivo);
    return misFacturas;
}

NotaDeCredito *VentaManager::ListarNotasDeCredito() {
    const unsigned int cantidadNotasDeCredito = this->ContarNotasDeCreditos();
    NotaDeCredito* misNotasDeCredito = new NotaDeCredito[cantidadNotasDeCredito];
    unsigned int contador = 0;
    FILE* archivo = fopen(this->rutasArchivos[1].c_str(), "rb");
    if (archivo == nullptr) {
        return nullptr;
    }
    unsigned int i = 0;
    while (fread(&misNotasDeCredito[i], sizeof(Factura), 1, archivo)) {
        i++;
    }
    fclose(archivo);
    return misNotasDeCredito;
}

bool VentaManager::Existe(Factura &factura) {
    FILE* archivo = fopen(this->rutasArchivos[0].c_str(), "rb");
    if (archivo == nullptr) {
        return false;
    }
    Factura tempFactura;
    while (fread(&tempFactura, sizeof(Factura), 1, archivo)) {
        if (tempFactura.getNumero() == factura.getNumero()) {
            fclose(archivo);
            return true;
        }
    }
    fclose(archivo);
    return false;
}

bool VentaManager::Existe(NotaDeCredito &notaDeCredito) {
    FILE* archivo = fopen(this->rutasArchivos[1].c_str(), "rb");
    if (archivo == nullptr) {
        return false;
    }
    NotaDeCredito tempNotaDeCredito;
    while (fread(&tempNotaDeCredito, sizeof(NotaDeCredito), 1, archivo)) {
        if (tempNotaDeCredito.getNumero() == notaDeCredito.getNumero()) {
            fclose(archivo);
            return true;
        }
    }
    fclose(archivo);
    return false;
}

int VentaManager::PosicionFactura(unsigned int numero, unsigned int &posicion) {
    FILE* archivo = fopen(this->rutasArchivos[0].c_str(), "rb");
    if (archivo == nullptr) {
        return -1;
    }
    Factura factura;
    unsigned int index = 0;
    while (fread(&factura, sizeof(Factura), 1, archivo)) {
        if (factura.getNumero() == numero) {
            posicion = index;
            fclose(archivo);
            return 0;
        }
        index++;
    }
    fclose(archivo);
    return -1;
}

int VentaManager::PosicionNotaDeCredito(unsigned int numero, unsigned int &posicion) {
    FILE* archivo = fopen(this->rutasArchivos[1].c_str(), "rb");
    if (archivo == nullptr) {
        return -1;
    }
    NotaDeCredito notaDeCredito;
    unsigned int index = 0;
    while (fread(&notaDeCredito, sizeof(NotaDeCredito), 1, archivo)) {
        if (notaDeCredito.getNumero() == numero) {
            posicion = index;
            fclose(archivo);
            return 0;
        }
        index++;
    }
    fclose(archivo);
    return -1;
}

bool VentaManager::CrearFactura(Factura &f) {
    if (Existe(f)) {
        return false;
    }
    FILE* archivo = fopen(this->rutasArchivos[0].c_str(), "ab");
    if (archivo == nullptr) {
        return false;
    }
    fwrite(&f, sizeof(Factura), 1, archivo);
    fclose(archivo);
    return true;
}

bool VentaManager::CrearNotaDeCredito(NotaDeCredito &nc) {
    if (Existe(nc)) {
        return false;
    }
    FILE* archivo = fopen(this->rutasArchivos[1].c_str(), "ab");
    if (archivo == nullptr) {
        return false;
    }
    fwrite(&nc, sizeof(NotaDeCredito), 1, archivo);
    fclose(archivo);
    return true;
}

Factura *VentaManager::ObtenerFactura(unsigned int numero) {
    FILE* archivo = fopen(this->rutasArchivos[0].c_str(), "rb");
    if (archivo == nullptr) {
        return nullptr;
    }
    Factura* factura = new Factura();
    while (fread(factura, sizeof(Factura), 1, archivo)) {
        if (factura->getNumero() == numero) {
            fclose(archivo);
            return factura;
        }
    }
    fclose(archivo);
    delete factura;
    return nullptr;
}

NotaDeCredito *VentaManager::ObtenerNotaDeCredito(unsigned int numero) {
    FILE* archivo = fopen(this->rutasArchivos[1].c_str(), "rb");
    if (archivo == nullptr) {
        return nullptr;
    }
    NotaDeCredito* notaDeCredito = new NotaDeCredito();
    while (fread(notaDeCredito, sizeof(NotaDeCredito), 1, archivo)) {
        if (notaDeCredito->getNumero() == numero) {
            fclose(archivo);
            return notaDeCredito;
        }
    }
    fclose(archivo);
    delete notaDeCredito;
    return nullptr;
}

bool VentaManager::Modificar(unsigned int numero, Factura &facturaActualizado) {
    FILE* archivo = fopen(this->rutasArchivos[0].c_str(), "r+b");
    bool resultado = false;
    unsigned int pos = 0;

    if (this->PosicionFactura(numero, pos) || archivo == nullptr) {
        return resultado;
    }
    fseek(archivo, sizeof(Factura) * pos, SEEK_SET);
    resultado = fwrite(&facturaActualizado, sizeof(Factura), 1, archivo);
    fclose(archivo);
    return resultado;
}

bool VentaManager::Modificar(unsigned int numero, NotaDeCredito &ndcActualizado) {
    FILE* archivo = fopen(this->rutasArchivos[1].c_str(), "r+b");
    bool resultado = false;
    unsigned int pos = 0;

    if (this->PosicionNotaDeCredito(numero, pos) || archivo == nullptr) {
        return resultado;
    }
    fseek(archivo, sizeof(NotaDeCredito) * pos, SEEK_SET);
    resultado = fwrite(&ndcActualizado, sizeof(NotaDeCredito), 1, archivo);
    fclose(archivo);
    return resultado;
}

bool VentaManager::EliminarFactura(unsigned int numero) {
    FILE* archivo = fopen(this->rutasArchivos[0].c_str(), "rb");
    if (archivo == nullptr) {
        return false;
    }
    FILE* tempArchivo = fopen("temp.dat", "wb");
    if (tempArchivo == nullptr) {
        fclose(archivo);
        return false;
    }
    Factura factura;
    bool encontrado = false;
    while (fread(&factura, sizeof(Factura), 1, archivo)) {
        if (factura.getNumero() != numero) {
            fwrite(&factura, sizeof(Factura), 1, tempArchivo);
        } else {
            encontrado = true;
        }
    }
    fclose(archivo);
    fclose(tempArchivo);
    remove(this->rutasArchivos[0].c_str());
    rename("temp.dat", this->rutasArchivos[0].c_str());
    return encontrado;
}

bool VentaManager::EliminarNotaDeCredito(unsigned int numero) {
    FILE* archivo = fopen(this->rutasArchivos[1].c_str(), "rb");
    if (archivo == nullptr) {
        return false;
    }
    FILE* tempArchivo = fopen("temp.dat", "wb");
    if (tempArchivo == nullptr) {
        fclose(archivo);
        return false;
    }
    NotaDeCredito notaDeCredito;
    bool encontrado = false;
    while (fread(&notaDeCredito, sizeof(NotaDeCredito), 1, archivo)) {
        if (notaDeCredito.getNumero() != numero) {
            fwrite(&notaDeCredito, sizeof(NotaDeCredito), 1, tempArchivo);
        } else {
            encontrado = true;
        }
    }
    fclose(archivo);
    fclose(tempArchivo);
    remove(this->rutasArchivos[1].c_str());
    rename("temp.dat", this->rutasArchivos[1].c_str());
    return encontrado;
}

unsigned int VentaManager::ContarFacturas() {
    FILE* archivo = fopen(this->rutasArchivos[0].c_str(), "rb");
    if (archivo == nullptr) {
        return 0;
    }
    fseek(archivo, 0, SEEK_END);
    unsigned int tamanioArchivo = ftell(archivo);
    fclose(archivo);
    return tamanioArchivo / sizeof(Factura);
}

unsigned int VentaManager::ContarNotasDeCreditos() {
    FILE* archivo = fopen(this->rutasArchivos[1].c_str(), "rb");
    if (archivo == nullptr) {
        return 0;
    }
    fseek(archivo, 0, SEEK_END);
    unsigned int tamanioArchivo = ftell(archivo);
    fclose(archivo);
    return tamanioArchivo / sizeof(NotaDeCredito);
}
