#include "VentasManager.h"

VentaManager::VentaManager(string _nombreArchivoFactura, string _nombreArchivoNotaDeCredito) {
    this->rutasArchivoFactura = _nombreArchivoFactura;
    this->rutasArchivosNotaDeCredito = _nombreArchivoNotaDeCredito;
}

VentaManager::~VentaManager() {

}

void VentaManager::iniciarArchivoFactura() {
    FILE* archivo = fopen(this->rutasArchivoFactura.c_str(), "wb");
    if (archivo == nullptr) {
        return;
    }
    fclose(archivo);
}

void VentaManager::iniciarArchivoNotaDeCredito() {
    FILE* archivo = fopen(this->rutasArchivosNotaDeCredito.c_str(), "wb");
    if (archivo == nullptr) {
        return;
    }
    fclose(archivo);
}

Factura *VentaManager::ListarFacturas() {
    const unsigned int cantidadFacturas = this->ContarFacturas();
    if(cantidadFacturas == 0) {
        return nullptr;
    }
    Factura* misFacturas = new Factura[cantidadFacturas];
    unsigned int contador = 0;
    FILE* archivo = fopen(this->rutasArchivoFactura.c_str(), "rb");
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
    FILE* archivo = fopen(this->rutasArchivosNotaDeCredito.c_str(), "rb");
    if (archivo == nullptr) {
        return nullptr;
    }
    unsigned int i = 0;
    while (fread(&misNotasDeCredito[i], sizeof(NotaDeCredito), 1, archivo)) {
        i++;
    }
    fclose(archivo);
    return misNotasDeCredito;
}

bool VentaManager::Existe(Factura &factura) {
    FILE* archivo = fopen(this->rutasArchivoFactura.c_str(), "rb");
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
    FILE* archivo = fopen(this->rutasArchivosNotaDeCredito.c_str(), "rb");
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
    FILE* archivo = fopen(this->rutasArchivoFactura.c_str(), "rb");
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
    FILE* archivo = fopen(this->rutasArchivosNotaDeCredito.c_str(), "rb");
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

void VentaManager::Imprimir(Factura *misFacturas, unsigned int cantidad) {
    for (unsigned int i = 0; i < cantidad; i++) {
        cout << misFacturas[i].toString() << endl;
    }

}

void VentaManager::Imprimir(NotaDeCredito *misNotaDeCreditos, unsigned int cantidad) {
    for (unsigned int i = 0; i < cantidad; i++) {
        cout << misNotaDeCreditos[i].toString() << endl;
    }

}

bool VentaManager::CrearFactura(Factura &f) {
    if (Existe(f)) {
        return false;
    }
    FILE* archivo = fopen(this->rutasArchivoFactura.c_str(), "ab");
    if (archivo == nullptr) {
        return false;
    }
    fwrite(&f, sizeof(Factura), 1, archivo);
    fclose(archivo);
    return true;
}

bool VentaManager::NuevaFactura(string _clienteDNI, float _monto, unsigned int _cantidadItems, char _tipoFactura) {
    const unsigned int ultimoID = this->ultimaFacturaID();
    if (ultimoID == -1) {
        return false;
    }
    unsigned int nuevoID = ultimoID + 1;
    Factura auxFactura(nuevoID, _clienteDNI, _monto, _cantidadItems, _tipoFactura);
    bool resultado = this->CrearFactura(auxFactura);
    if (resultado) {
        cout << "Factura creada con exito. Nro: " << nuevoID << endl;
    } else {
        cout << "Error al crear la factura." << endl;
    }
    return resultado;
}

bool VentaManager::CrearNotaDeCredito(NotaDeCredito &nc) {
    if (Existe(nc)) {
        return false;
    }
    FILE* archivo = fopen(this->rutasArchivosNotaDeCredito.c_str(), "ab");
    if (archivo == nullptr) {
        return false;
    }
    fwrite(&nc, sizeof(NotaDeCredito), 1, archivo);
    fclose(archivo);
    return true;
}

bool VentaManager::NuevaNotaDeCredito(unsigned int _nroFactura, string _motivoAnulacion) {
    Factura* miFactura = this->ObtenerFactura(_nroFactura);
    if(miFactura == nullptr) {
        cout << "Numero de factura indicado, no se encuentra" << endl;
    }
    const unsigned int ultimoID = this->ultimaNotaDeCreditoID();
    if (ultimoID == -1) {
        return false;
    }
    unsigned int nuevoID = ultimoID + 1;
    NotaDeCredito auxNotaDeCredito(nuevoID, miFactura->getClienteDNI(), miFactura->TotalSinIVA(), miFactura->getCantidadItems(), _motivoAnulacion);
    bool creado = this->CrearNotaDeCredito(auxNotaDeCredito),
        eliminado = this->EliminarFactura(_nroFactura);
    if (creado && eliminado) {
        cout << "Nota de credito creada con exito. Nro: " << nuevoID << endl;
    } else {
        cout << "Error al crear la nota de credito." << endl;
    }
    delete miFactura;
    return creado && eliminado;
}

bool VentaManager::NuevaNotaDeCredito(Factura &factura) {
    const unsigned int ultimoID = this->ultimaNotaDeCreditoID();
    if (ultimoID == -1) {
        return false;
    }
    unsigned int nuevoID = ultimoID + 1;
    string motivo = "Anulacion de factura nro " + to_string(factura.getNumero());
    NotaDeCredito auxNotaDeCredito(nuevoID, factura.getClienteDNI(), factura.TotalSinIVA(), factura.getCantidadItems(), motivo);
    bool creado = this->CrearNotaDeCredito(auxNotaDeCredito),
        eliminado = this->EliminarFactura(factura.getNumero());
    if (creado && eliminado) {
        cout << "Nota de credito creada con exito. Nro: " << nuevoID << endl;
    } else {
        cout << "Error al crear la nota de credito." << endl;
    }
    return creado && eliminado;
}

int VentaManager::ultimaFacturaID() {
    Factura* facturas = this->ListarFacturas();
    if (facturas == nullptr) {
        return 0;
    }
    unsigned int ultimaID = 0;
    const unsigned int cantidad = this->ContarFacturas();
    if (cantidad > 0) {
        ultimaID = facturas[cantidad - 1].getNumero();
    }
    delete[] facturas;
    return ultimaID;
}

int VentaManager::ultimaNotaDeCreditoID() {
    NotaDeCredito* notasDeCredito = this->ListarNotasDeCredito();
    if (notasDeCredito == nullptr) {
        return -1;
    }
    unsigned int ultimaID = 0;
    for (unsigned int i = 0; i < this->ContarNotasDeCreditos(); i++) {
        if (notasDeCredito[i].getNumero() > ultimaID) {
            ultimaID = notasDeCredito[i].getNumero();
        }
    }
    delete[] notasDeCredito;
    return ultimaID;
}

Factura *VentaManager::ObtenerFactura(unsigned int numero) {
    FILE* archivo = fopen(this->rutasArchivoFactura.c_str(), "rb");
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
    FILE* archivo = fopen(this->rutasArchivosNotaDeCredito.c_str(), "rb");
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
    FILE* archivo = fopen(this->rutasArchivoFactura.c_str(), "r+b");
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
    FILE* archivo = fopen(this->rutasArchivosNotaDeCredito.c_str(), "r+b");
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
    FILE* archivo = fopen(this->rutasArchivoFactura.c_str(), "rb");
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
    remove(this->rutasArchivoFactura.c_str());
    rename("temp.dat", this->rutasArchivoFactura.c_str());
    return encontrado;
}

bool VentaManager::EliminarNotaDeCredito(unsigned int numero) {
    FILE* archivo = fopen(this->rutasArchivosNotaDeCredito.c_str(), "rb");
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
    remove(this->rutasArchivosNotaDeCredito.c_str());
    rename("temp.dat", this->rutasArchivosNotaDeCredito.c_str());
    return encontrado;
}

void VentaManager::ListarXFecha() {
    Factura* misFacturas = this->ListarFacturas();

    if(misFacturas != nullptr) {
        const unsigned int cantidad = this->ContarFacturas();
        if(cantidad > 0) {
            for (unsigned int i = 0; i < cantidad - 1; i++) {
                for (unsigned int j = 0; j < cantidad - i - 1; j++) {
                    if (misFacturas[j].getFechaEmision() > misFacturas[j + 1].getFechaEmision()) {
                        Factura temp = misFacturas[j];
                        misFacturas[j] = misFacturas[j + 1];
                        misFacturas[j + 1] = temp;
                    }
                }
            }
            cout << "----- Facturas -----" << endl;
            this->Imprimir(misFacturas, cantidad);
        } else {
            cout << "No hay facturas.";
        }
    }

    NotaDeCredito* misNotaDeCreditos = this->ListarNotasDeCredito();

    if(misNotaDeCreditos != nullptr) {
        const unsigned int cantidad = this->ContarNotasDeCreditos();
        if(cantidad > 0) {
            for (unsigned int i = 0; i < cantidad - 1; i++) {
                for (unsigned int j = 0; j < cantidad - i - 1; j++) {
                    if (misNotaDeCreditos[j].getFechaEmision() > misNotaDeCreditos[j + 1].getFechaEmision()) {
                        NotaDeCredito temp = misNotaDeCreditos[j];
                        misNotaDeCreditos[j] = misNotaDeCreditos[j + 1];
                        misNotaDeCreditos[j + 1] = temp;
                    }
                }
            }
            cout << "----- Notas de Credito -----" << endl;
            this->Imprimir(misNotaDeCreditos, cantidad);
        } else {
            cout << "No hay facturas.";
        }
    }
}

void VentaManager::ListarXCAE() {
    Factura* misFacturas = this->ListarFacturas();

    if(misFacturas != nullptr) {
        const unsigned int cantidad = this->ContarFacturas();
        if(cantidad > 0) {
            for (unsigned int i = 0; i < cantidad - 1; i++) {
                for (unsigned int j = 0; j < cantidad - i - 1; j++) {
                    if (misFacturas[j].getCAE() > misFacturas[j + 1].getCAE()) {
                        Factura temp = misFacturas[j];
                        misFacturas[j] = misFacturas[j + 1];
                        misFacturas[j + 1] = temp;
                    }
                }
            }
            cout << "----- Facturas -----" << endl;
            this->Imprimir(misFacturas, cantidad);
        } else {
            cout << "No hay facturas.";
        }
    }
}

void VentaManager::ListarXCliente() {
    Factura* misFacturas = this->ListarFacturas();

    if(misFacturas != nullptr) {
        const unsigned int cantidad = this->ContarFacturas();
        if(cantidad > 0) {
            for (unsigned int i = 0; i < cantidad - 1; i++) {
                for (unsigned int j = 0; j < cantidad - i - 1; j++) {
                    if (misFacturas[j].getClienteDNI() > misFacturas[j + 1].getClienteDNI()) {
                        Factura temp = misFacturas[j];
                        misFacturas[j] = misFacturas[j + 1];
                        misFacturas[j + 1] = temp;
                    }
                }
            }
            cout << "----- Facturas -----" << endl;
            this->Imprimir(misFacturas, cantidad);
        } else {
            cout << "No hay facturas.";
        }
    }

    NotaDeCredito* misNotaDeCreditos = this->ListarNotasDeCredito();

    if(misNotaDeCreditos != nullptr) {
        const unsigned int cantidad = this->ContarNotasDeCreditos();
        if(cantidad > 0) {
            for (unsigned int i = 0; i < cantidad - 1; i++) {
                for (unsigned int j = 0; j < cantidad - i - 1; j++) {
                    if (misNotaDeCreditos[j].getClienteDNI() > misNotaDeCreditos[j + 1].getClienteDNI()) {
                        NotaDeCredito temp = misNotaDeCreditos[j];
                        misNotaDeCreditos[j] = misNotaDeCreditos[j + 1];
                        misNotaDeCreditos[j + 1] = temp;
                    }
                }
            }
            cout << "----- Notas de Credito -----" << endl;
            this->Imprimir(misNotaDeCreditos, cantidad);
        } else {
            cout << "No hay notas de creditos.";
        }
    }
}

void VentaManager::ConsultaXCliente(string dniCliente) {
    FILE* archivo = fopen(this->rutasArchivoFactura.c_str(), "rb");
    if (archivo == nullptr) {
        cout << "No se pudieron abrir las facturas." << endl;
        return;
    }
    Factura factura;
    cout << "----- Facturas del cliente " << dniCliente << " -----" << endl;
    bool encontrado = false;
    while (fread(&factura, sizeof(Factura), 1, archivo)) {
        string aux = factura.getClienteDNI();
        if (aux.find(dniCliente) != string::npos) {
            cout << factura.toString() << endl;
            encontrado = true;
        }
    }
    fclose(archivo);
    if (!encontrado) {
        cout << "No se encontraron facturas para el cliente " << dniCliente << "." << endl;
    }

    archivo = fopen(this->rutasArchivosNotaDeCredito.c_str(), "rb");
    if (archivo == nullptr) {
        cout << "No se pudieron abrir las notas de credito." << endl;
        return;
    }
    NotaDeCredito notaDeCredito;
    cout << "----- Notas de Credito del cliente " << dniCliente << " -----" << endl;
    encontrado = false;
    while (fread(&notaDeCredito, sizeof(NotaDeCredito), 1, archivo)) {
        string aux = factura.getClienteDNI();
        if (aux.find(dniCliente) != string::npos) {
            cout << notaDeCredito.toString() << endl;
            encontrado = true;
        }
    }
}

void VentaManager::ConsultaXCAE(string cae) {
    FILE* archivo = fopen(this->rutasArchivoFactura.c_str(), "rb");
    if (archivo == nullptr) {
        cout << "No se pudieron abrir las facturas." << endl;
        return;
    }
    Factura factura;
    cout << "----- Facturas con CAE " << cae << " -----" << endl;
    bool encontrado = false;
    while (fread(&factura, sizeof(Factura), 1, archivo)) {
        string aux = factura.getCAE();
        if (aux.find(cae) != string::npos) {
            cout << factura.toString() << endl;
            encontrado = true;
        }
    }
    fclose(archivo);
    if (!encontrado) {
        cout << "No se encontraron facturas con CAE " << cae << "." << endl;
    }
}

void VentaManager::ConsultaXTipoDeComprobante(char tipoComprobante) {
    FILE* archivo = fopen(this->rutasArchivoFactura.c_str(), "rb");
    if (archivo == nullptr) {
        cout << "No se pudieron abrir las facturas." << endl;
        return;
    }
    Factura factura;
    cout << "----- Facturas del tipo " << tipoComprobante << " -----" << endl;
    bool encontrado = false;
    while (fread(&factura, sizeof(Factura), 1, archivo)) {
        if (factura.getTipoFactura() == tipoComprobante) {
            cout << factura.toString() << endl;
            encontrado = true;
        }
    }
    fclose(archivo);
    if (!encontrado) {
        cout << "No se encontraron facturas del tipo " << tipoComprobante << "." << endl;
    }
}

void VentaManager::ConsultaXRangoDeFechas(Fecha fechaInicio, Fecha fechaFin) {
    FILE* archivo = fopen(this->rutasArchivoFactura.c_str(), "rb");
    if (archivo == nullptr) {
        cout << "No se pudieron abrir las facturas." << endl;
        return;
    }
    Factura factura;
    cout << "----- Facturas entre " << fechaInicio.toString() << " y " << fechaFin.toString() << " -----" << endl;
    bool encontrado = false;
    while (fread(&factura, sizeof(Factura), 1, archivo)) {
        if (factura.getFechaEmision() >= fechaInicio && factura.getFechaEmision() <= fechaFin) {
            cout << factura.toString() << endl;
            encontrado = true;
        }
    }
    fclose(archivo);
    if (!encontrado) {
        cout << "No se encontraron facturas en el rango de fechas especificado." << endl;
    }

    archivo = fopen(this->rutasArchivosNotaDeCredito.c_str(), "rb");
    if (archivo == nullptr) {
        cout << "No se pudieron abrir las notas de credito." << endl;
        return;
    }
    NotaDeCredito notaDeCredito;
    cout << "----- Notas de Credito entre " << fechaInicio.toString() << " y " << fechaFin.toString() << " -----" << endl;
    encontrado = false;
    while (fread(&notaDeCredito, sizeof(NotaDeCredito), 1, archivo)) {
        if (notaDeCredito.getFechaEmision() >= fechaInicio && notaDeCredito.getFechaEmision() <= fechaFin) {
            cout << notaDeCredito.toString() << endl;
            encontrado = true;
        }
    }
    fclose(archivo);
    if (!encontrado) {
        cout << "No se encontraron notas de credito en el rango de fechas especificado." << endl;
    }
}

void VentaManager::FacturasDeCliente(string dni, unsigned int* cantidad, float* monto) {
    FILE* archivo = fopen(this->rutasArchivoFactura.c_str(), "rb");
    if (archivo == nullptr) {
        cout << "No se pudieron abrir las facturas." << endl;
        return;
    }
    Factura factura;
    *cantidad = 0;
    *monto = 0.0f;
    while (fread(&factura, sizeof(Factura), 1, archivo)) {
        string aux = factura.getClienteDNI();
        if (aux.find(dni) != string::npos) {
            (*cantidad)++;
            *monto += factura.TotalSinIVA();
        }
    }
}

unsigned int VentaManager::ContarFacturas() {
    FILE* archivo = fopen(this->rutasArchivoFactura.c_str(), "rb");
    if (archivo == nullptr) {
            this->iniciarArchivoFactura();
        return 0;
    }
    fseek(archivo, 0, SEEK_END);
    unsigned int tamanioArchivo = ftell(archivo);
    fclose(archivo);
    return tamanioArchivo / sizeof(Factura);
}

unsigned int VentaManager::ContarNotasDeCreditos() {
    FILE* archivo = fopen(this->rutasArchivosNotaDeCredito.c_str(), "rb");
    if (archivo == nullptr) {
            this->iniciarArchivoNotaDeCredito();
        return 0;
    }
    fseek(archivo, 0, SEEK_END);
    unsigned int tamanioArchivo = ftell(archivo);
    fclose(archivo);
    return tamanioArchivo / sizeof(NotaDeCredito);
}

void VentaManager::RecaudacionTrimestralPorAnio(int anio, float* trimestres) {
    for (int i = 0; i < 4; ++i) trimestres[i] = 0.0f;
    unsigned int cantidad = this->ContarFacturas();
    Factura* facturas = this->ListarFacturas();
    if (!facturas) return;
    for (unsigned int i = 0; i < cantidad; ++i) {
        Fecha f = facturas[i].getFechaEmision();
        int y = f.getAnio();
        if (y == anio) {
            int mes = f.getMes();
            int trimestre = (mes - 1) / 3;
            if (trimestre >= 0 && trimestre < 4) {
                trimestres[trimestre] += facturas[i].TotalSinIVA();
            }
        }
    }
    delete[] facturas;
}

float VentaManager::RecaudacionAnualPorAnio(int anio) {
    float recaudacion = 0.0f;
    unsigned int cantidad = this->ContarFacturas();
    Factura* facturas = this->ListarFacturas();
    if (!facturas) return recaudacion;
    for (unsigned int i = 0; i < cantidad; ++i) {
        Fecha f = facturas[i].getFechaEmision();
        int y = f.getAnio();
        if (y == anio) {
            recaudacion += facturas[i].TotalSinIVA();
        }
    }
    delete[] facturas;
    return recaudacion;
}
