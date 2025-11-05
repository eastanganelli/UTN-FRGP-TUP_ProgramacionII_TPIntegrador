
NotaDeCreditoManager::NotaDeCreditoManager(string ruta) {
    this->rutaArchivo = ruta;
    cargarDeArchivo();
}

void NotaDeCreditoManager::agregar(NotaDeCredito& nota) {
    this->_notasDeCredito.push_back(nota);
}

bool NotaDeCreditoManager::eliminar(int idVenta) {
    int indice = obtenerIndice(idVenta);
    if (indice != -1) {
        this->_notasDeCredito.erase(this->_notasDeCredito.begin() + indice);
        return true;
    }
    return false;
}

NotaDeCredito* NotaDeCreditoManager::buscar(int idVenta) {
    for (size_t i = 0; i < this->_notasDeCredito.size(); ++i) {
        if (this->_notasDeCredito[i].getIDVenta() == idVenta) {
            return &this->_notasDeCredito[i];
        }
    }
    return nullptr;
}

int NotaDeCreditoManager::obtenerIndice(int idVenta) {
    for (size_t i = 0; i < this->_notasDeCredito.size(); ++i) {
        if (this->_notasDeCredito[i].getIDVenta() == idVenta) {
            return i;
        }
    }
    return -1;
}

int NotaDeCreditoManager::getCantidad() {
    return this->_notasDeCredito.size();
}

NotaDeCredito NotaDeCreditoManager::getPorIndice(int index) {
    return this->_notasDeCredito[index];
}

void NotaDeCreditoManager::listarTodos() {
    for (size_t i = 0; i < this->_notasDeCredito.size(); ++i) {
        this->_notasDeCredito[i].mostrar();
        cout << "--------------------" << endl;
    }
}

bool NotaDeCreditoManager::cargarDeArchivo() {
    // this->_notasDeCredito.clear();
    // FILE* pFile = fopen(this->_rutaArchivo.c_str(), "rb");
    // if (pFile == NULL) return false;

    // NotaDeCredito temp;
    // while (fread(&temp, sizeof(NotaDeCredito), 1, pFile) == 1) {
    //     this->_notasDeCredito.push_back(temp);
    // }
    
    // fclose(pFile);
    return true;
}

bool NotaDeCreditoManager::escribirArchivo() {
    // FILE* pFile = fopen(this->_rutaArchivo.c_str(), "wb");
    // if (pFile == NULL) return false;

    // for (size_t i = 0; i < this->_notasDeCredito.size(); ++i) {
    //     fwrite(&this->_notasDeCredito[i], sizeof(NotaDeCredito), 1, pFile);
    // }
    
    // fclose(pFile);
    return true;
}