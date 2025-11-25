#include "condicioniva_manager.h"

CondicionIVAManager::CondicionIVAManager(const string& condicion_ivaPath)
    : FileSystem<CondicionIVA>(condicion_ivaPath) { }

CondicionIVAManager::~CondicionIVAManager() { }

unsigned int CondicionIVAManager::Cantidad() {
    return this->Count();
}

bool CondicionIVAManager::Existe(CondicionIVA& condicion_iva) {
    unsigned int index;
    return this->IndexOf(condicion_iva, index);
}

