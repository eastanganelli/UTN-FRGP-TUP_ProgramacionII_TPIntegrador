#include "manager_proveedor.h"

static const string RUBROS[] = { "Textil", "Calzado", "Gastronomia", "Automotor", "Libreria", "Indumentaria" };

ProveedorManager::ProveedorManager(const string& proveedorPath)
    : FileSystem<Proveedor>(proveedorPath) { }

ProveedorManager::~ProveedorManager() { }

GenericArray<Proveedor> ProveedorManager::Listar() {
    GenericArray<Proveedor> proveedores;
    const unsigned int cantidad = this->Count();
    for(unsigned int i = 0; i < cantidad; i++) {
        Proveedor* aux = this->At(i);
        proveedores + (*aux);
        delete aux;
    }
    return proveedores;
}

bool ProveedorManager::Existe(string codigo) {
    unsigned int index;
    return this->Indice(codigo, index);
}

bool ProveedorManager::Indice(string codigo, unsigned int& index) {
    GenericArray<Proveedor> proveedores = this->Listar();
    for(unsigned int i = 0; i < proveedores.Size(); i++) {
        if(Validation::IsEqual(proveedores[i]->getCuit(), codigo)) {
            index = i;
            return true;
        }
    }
    return false;
}

bool ProveedorManager::Agregar(Proveedor& proveedor) {
    if(this->Existe(proveedor.getCuit())) {
        Warning mi_warning("Creacion de Proveedor", "El proveedor con CUIT " + proveedor.getCuit() + " ya existe.");
        mi_warning.Show();
        return false;
    }
    return this->New(proveedor);
}

bool ProveedorManager::Modificar(string cuit, Proveedor* proveedor) {
    unsigned int index;
    if(!this->Indice(cuit, index)) {
        Error mi_error("Modificacion de Proveedor", "Proveedor con CUIT " + cuit + " no encontrado.");
        mi_error.Show();
        return false;
    }
    return this->Update(index, *proveedor);
}

bool ProveedorManager::Eliminar(string cuit) {
    unsigned int index;
    if(!this->Indice(cuit, index)) {
        Error mi_error("Eliminacion de Proveedor", "Proveedor con CUIT " + cuit + " no encontrado.");
        mi_error.Show();
        return false;
    }
    return this->Delete(index);
}

Proveedor* ProveedorManager::operator[](string cuit) {
    unsigned int index;
    if(!this->Indice(cuit, index)) {
        Warning mi_warning("Busqueda de Proveedor", "Proveedor con CUIT " + cuit + " no encontrado.");
        mi_warning.Show();
        return nullptr;
    }
    return this->At(index);
}

GenericArray<Proveedor> ProveedorManager::ConsultarPorCUIT(string cuit) {
    GenericArray<Proveedor> resultados;
    const unsigned int cantidad = this->Count();
    if(cantidad == 0) {
        Warning mi_warning("Busqueda de Proveedor", "No hay proveedores registrados.");
        mi_warning.Show();
        return resultados;
    }
    for(unsigned int i = 0; i < cantidad; i++) {
        Proveedor* aux = this->At(i);
        if(aux->getCuit().find(cuit) != string::npos) {
            resultados + (*aux);
        }
        delete aux;
    }
    if(resultados.Size() == 0) {
        Warning mi_warning("Busqueda de Proveedor", "No se encontraron proveedores con CUIT que contenga " + cuit + ".");
        mi_warning.Show();
    }
    return resultados;
}

GenericArray<Proveedor> ProveedorManager::ConsultarPorNombre(string nombreRazon) {
    GenericArray<Proveedor> resultados;
    const unsigned int cantidad = this->Count();
    if(cantidad == 0) {
        Warning mi_warning("Busqueda de Proveedor", "No hay proveedores registrados.");
        mi_warning.Show();
        return resultados;
    }
    // Convertir a minusculas la cadena de busqueda
    for(size_t k = 0; k < nombreRazon.size(); k++) nombreRazon[k] = tolower(nombreRazon[k]);

    for(unsigned int i = 0; i < cantidad; i++) {
        Proveedor* aux = this->At(i);
        string nombreArchivo = aux->getNombreRazon();
        for(size_t k = 0; k < nombreArchivo.size(); k++) nombreArchivo[k] = tolower(nombreArchivo[k]);
        if(nombreArchivo.find(nombreRazon) != string::npos) {
            resultados + (*aux);
        }
        delete aux;
    }
    if(resultados.Size() == 0) {
        Warning mi_warning("Busqueda de Proveedor", "No se encontraron proveedores con nombre que contenga " + nombreRazon + ".");
        mi_warning.Show();
    }
    return resultados;
}

GenericArray<Proveedor> ProveedorManager::ConsultarPorRubro(unsigned int rubro) {
    GenericArray<Proveedor> resultados;
    const unsigned int cantidad = this->Count();
    if(cantidad == 0) {
        Warning mi_warning("Busqueda de Proveedor", "No hay proveedores registrados.");
        mi_warning.Show();
        return resultados;
    }
    for(unsigned int i = 0; i < cantidad; i++) {
        Proveedor* aux = this->At(i);
        if(aux->getRubro() == rubro) {
            resultados + (*aux);
        }
        delete aux;
    }
    if(resultados.Size() == 0) {
        Warning mi_warning("Busqueda de Proveedor", "No se encontraron proveedores para el rubro indicado.");
        mi_warning.Show();
    }
    return resultados;
}

GenericArray<Proveedor> ProveedorManager::ConsultarPorEstado(bool estado) {
    GenericArray<Proveedor> resultados;
    const unsigned int cantidad = this->Count();
    if(cantidad == 0) {
        Warning mi_warning("Busqueda de Proveedor", "No hay proveedores registrados.");
        mi_warning.Show();
        return resultados;
    }
    for(unsigned int i = 0; i < cantidad; i++) {
        Proveedor* aux = this->At(i);
        if(aux->getAlta() == estado) {
            resultados + (*aux);
        }
        delete aux;
    }
    if(resultados.Size() == 0) {
        Warning mi_warning("Busqueda de Proveedor", "No se encontraron proveedores con el estado solicitado.");
        mi_warning.Show();
    }
    return resultados;
}

unsigned int ProveedorManager::SeleccionarRubro() {
    int seleccion = -1;
    do {
        unsigned int i = 0;
        cout << "ID | Rubro" << endl << "===========" << endl;
        for(string rubro: RUBROS) {
            i++;
            cout << i << " | " << rubro << endl;
        }

        cout << "Seleccionar: ";
        cin >> seleccion;

        if(seleccion > 0 && seleccion <= (int)(sizeof(RUBROS) / sizeof(RUBROS[0]))) {
            break;
        } else {
            cout << "Valor incorrecto." << endl;
            system("pause");
            system("cls");
        }
    } while (true);

    return (unsigned int)seleccion;
}

string ProveedorManager::getNombreRubro(unsigned int cr) {
    if(cr == 0 || cr > (unsigned int)(sizeof(RUBROS) / sizeof(RUBROS[0]))) return string("Otros");
    return RUBROS[cr - 1];
}

void ProveedorManager::ListarPorNombre() {
    GenericArray<Proveedor> proveedores = this->Listar();
    if(proveedores.Size() == 0) {
        Warning mi_warning("Listado de Proveedores", "No se encontraron proveedores para mostrar.");
        mi_warning.Show();
        return;
    }
    for(unsigned int i = 0; i < proveedores.Size(); i++) {
        for(unsigned int j = i + 1; j < proveedores.Size(); j++) {
            if(proveedores[i]->getNombreRazon() > proveedores[j]->getNombreRazon()) {
                proveedores.Swap(proveedores[i], proveedores[j]);
            }
        }
    }
    ProveedorManager::Imprimir(proveedores);
}

void ProveedorManager::ListarPorRubro() {
    GenericArray<Proveedor> proveedores = this->Listar();
    if(proveedores.Size() == 0) {
        Warning mi_warning("Listado de Proveedores", "No se encontraron proveedores para mostrar.");
        mi_warning.Show();
        return;
    }
    for(unsigned int i = 0; i < proveedores.Size(); i++) {
        for(unsigned int j = i + 1; j < proveedores.Size(); j++) {
            if(proveedores[i]->getRubro() > proveedores[j]->getRubro()) {
                proveedores.Swap(proveedores[i], proveedores[j]);
            }
        }
    }
    ProveedorManager::Imprimir(proveedores);
}

void ProveedorManager::ListarPorCUIT() {
    GenericArray<Proveedor> proveedores = this->Listar();
    if(proveedores.Size() == 0) {
        Warning mi_warning("Listado de Proveedores", "No se encontraron proveedores para mostrar.");
        mi_warning.Show();
        return;
    }
    for(unsigned int i = 0; i < proveedores.Size(); i++) {
        for(unsigned int j = i + 1; j < proveedores.Size(); j++) {
            if(proveedores[i]->getCuit() > proveedores[j]->getCuit()) {
                proveedores.Swap(proveedores[i], proveedores[j]);
            }
        }
    }
    ProveedorManager::Imprimir(proveedores);
}

void ProveedorManager::Imprimir(GenericArray<Proveedor>& proveedores) {
    if(proveedores.Size() == 0) {
        Warning mi_warning("Listado de Proveedores", "No se encontraron proveedores para mostrar.");
        mi_warning.Show();
        return;
    }

    const unsigned int altura = proveedores.Size(), columnas = 8;
    Tabling::Table mi_tabla(altura, columnas);

    Tabling::Row* header = new Tabling::Row(columnas);
    header->AddCell("CUIT", Proveedor::ColCuitSize());
    header->AddCell("Nombre/Razon", Proveedor::ColNombreRazonSize());
    header->AddCell("Rubro", 12);
    header->AddCell("Direccion", DatosPersonales::GetDireccionSize());
    header->AddCell("Correo", DatosPersonales::GetCorreoSize());
    header->AddCell("Telefono", DatosPersonales::GetTelefonoSize());
    header->AddCell("Celular", DatosPersonales::GetCelularSize());
    header->AddCell("Estado", DatosPersonales::GetEstadoSize());
    mi_tabla.AddRow(header);

    for(unsigned int i = 0; i < altura; i++) {
        Tabling::Row* row = new Tabling::Row(columnas);
        row->AddCell(proveedores[i]->getCuit(), Proveedor::ColCuitSize());
        row->AddCell(proveedores[i]->getNombreRazon(), Proveedor::ColNombreRazonSize());
        row->AddCell(proveedores[i]->getRubroNombre(), 12);
        row->AddCell(proveedores[i]->getDireccion(), DatosPersonales::GetDireccionSize());
        row->AddCell(proveedores[i]->getCorreo(), DatosPersonales::GetCorreoSize());
        row->AddCell(proveedores[i]->getTelefono(), DatosPersonales::GetTelefonoSize());
        row->AddCell(proveedores[i]->getCelular(), DatosPersonales::GetCelularSize());
        row->AddCell(proveedores[i]->getAlta() ? string("Activo") : string("Inactivo"), DatosPersonales::GetEstadoSize());
        mi_tabla.AddRow(row);
    }
    mi_tabla.Print();
}
