#include "VentasManager.h"

VentaManager::VentaManager(string ruta) {
    this->rutaArchivo = ruta;
}

VentaManager::~VentaManager() {

}

Factura *VentaManager::ListarFacturas() {
    const unsigned int cantidadClientes = this->Contar();
    Factura* misFacturas = new Factura[cantidadClientes];
    unsigned int contador = 0;
    FILE* archivo = fopen(this->rutaArchivo.c_str(), "rb");
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

bool VentaManager::CrearFactura(Factura &f) {
    if (Existe(f)) {
        return false;
    }
    FILE* archivo = fopen(this->rutaArchivo.c_str(), "ab");
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
    FILE* archivo = fopen(this->rutaArchivo.c_str(), "ab");
    if (archivo == nullptr) {
        return false;
    }
    fwrite(&nc, sizeof(NotaDeCredito), 1, archivo);
    fclose(archivo);
    return true;
}

Factura *VentaManager::ObtenerFactura(unsigned int numero) {
    FILE* archivo = fopen(this->rutaArchivo.c_str(), "rb");
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
    FILE* archivo = fopen(this->rutaArchivo.c_str(), "rb");
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
    FILE* archivo = fopen(this->rutaArchivo.c_str(), "r+b");
    bool resultado = false;
    unsigned int pos = 0;

    if (this->Posicion(numero, pos) || archivo == nullptr) {
        return resultado;
    }
    fseek(archivo, sizeof(Factura) * pos, SEEK_SET);
    resultado = fwrite(&facturaActualizado, sizeof(Factura), 1, archivo);
    fclose(archivo);
    return resultado;
}

bool VentaManager::Modificar(unsigned int numero, NotaDeCredito &ndcActualizado) {

}
