#include "manager_cliente.h"

ClienteManager::ClienteManager(const string& clientePath) : FileSystem<Cliente>(clientePath)/*, CondicionIVAManager(nullptr)*/ {

}

ClienteManager::~ClienteManager() {

}

GenericArray<Cliente> ClienteManager::Listar() {
    GenericArray<Cliente> clientes;
    const unsigned int cantidad = this->Count();
    for(unsigned int i = 0; i < cantidad; i++) {
        Cliente* aux = this->At(i);
        clientes + (*aux);
        delete aux;
    }
    return clientes;
}

bool ClienteManager::Modificar(string dni, Cliente* cliente) {
    const unsigned int cantidad = this->Count();
    unsigned int index = 0;
    for(unsigned int i = 0; i < cantidad; i++) {
        Cliente* aux = this->At(i);
        if(aux != nullptr && aux->getDNI() == dni) {
            index = i;
            delete aux;
            return this->Update(index, *cliente);
        }
        delete aux;
    }
    return this->Update(index, *cliente);
}

Cliente* ClienteManager::operator[](string dni) {
    const unsigned int cantidad = this->Count();
    Cliente* aux = nullptr;
    for(unsigned int i = 0; i < cantidad; i++) {
        aux = this->At(i);
        if(aux->getDNI() == dni) {
            break;
        }
        delete aux;
        aux = nullptr;
    }
    if(aux == nullptr) {
        Warning mi_warning("Busqueda de Cliente", "No se encontro cliente con DNI " + dni + ".");
        mi_warning.Show();
    }
    return aux;
}

GenericArray<Cliente> ClienteManager::BuscarPorCUIL_CUIT(string cuil_cuit) {
    GenericArray<Cliente> resultados;
    const unsigned int cantidad = this->Count();
    if(cantidad == 0) {
        Warning mi_warning("Busqueda de Cliente", "No hay clientes registrados.");
        mi_warning.Show();
        return resultados;
    }
    for(unsigned int i = 0; i < cantidad; i++) {
        Cliente* aux = this->At(i);
        if(aux->getCuilCuit() == cuil_cuit) {
            resultados + (*aux);
        }
        delete aux;
    }
    if(resultados.Size() == 0) {
        Warning mi_warning("Busqueda de Cliente", "No se encontraron clientes con CUIL/CUIT " + cuil_cuit + ".");
        mi_warning.Show();
    }
    return resultados;
}

GenericArray<Cliente> ClienteManager::BuscarPorDNI(string dni) {
    GenericArray<Cliente> resultados;
    const unsigned int cantidad = this->Count();
    if(cantidad == 0) {
        Warning mi_warning("Busqueda de Cliente", "No hay clientes registrados.");
        mi_warning.Show();
        return resultados;
    }
    for(unsigned int i = 0; i < cantidad; i++) {
        Cliente* aux = this->At(i);
        if(aux->getDNI() == dni) {
            resultados + (*aux);
        }
        delete aux;
    }
    if(resultados.Size() == 0) {
        Warning mi_warning("Busqueda de Cliente", "No se encontraron clientes con DNI " + dni + ".");
        mi_warning.Show();
    }
    return resultados;
}

GenericArray<Cliente> ClienteManager::BuscarPorNombreApellido(string nombre, string apellido) {
    GenericArray<Cliente> resultados;
    const unsigned int cantidad = this->Count();
    if(cantidad == 0) {
        Warning mi_warning("Busqueda de Cliente", "No hay clientes registrados.");
        mi_warning.Show();
        return resultados;
    }
    for(unsigned int i = 0; i < cantidad; i++) {
        Cliente* aux = this->At(i);
        if(aux->getNombre() == nombre && aux->getApellido() == apellido) {
            resultados + (*aux);
        }
        delete aux;
    }
    if(resultados.Size() == 0) {
        Warning mi_warning("Busqueda de Cliente", "No se encontraron clientes con nombre " + nombre + " y apellido " + apellido + ".");
        mi_warning.Show();
    }
    return resultados;
}

GenericArray<Cliente> ClienteManager::BuscarPorCorreo(string correo) {
    GenericArray<Cliente> resultados;
    const unsigned int cantidad = this->Count();
    if(cantidad == 0) {
        Warning mi_warning("Busqueda de Cliente", "No hay clientes registrados.");
        mi_warning.Show();
        return resultados;
    }
    for(unsigned int i = 0; i < cantidad; i++) {
        Cliente* aux = this->At(i);
        if(aux->getCorreo() == correo) {
            resultados + (*aux);
        }
        delete aux;
    }
    if(resultados.Size() == 0) {
        Warning mi_warning("Busqueda de Cliente", "No se encontraron clientes con correo " + correo + ".");
        mi_warning.Show();
    }
    return resultados;
}

unsigned int ClienteManager::Cantidad() { return this->Count(); }

void ClienteManager::ListarPorCuil_Cuit() {
    GenericArray<Cliente> clientes = this->Listar();
    if(clientes.Size() == 0) {
        Warning mi_warning("Listado de Clientes", "No se encontraron clientes para mostrar.");
        mi_warning.Show();
        return;
    }
    for(unsigned int i = 0; i < clientes.Size(); i++) {
        for(unsigned int j = i + 1; j < clientes.Size(); j++) {
            if(clientes[i]->getCuilCuit() > clientes[j]->getCuilCuit()) {
                clientes.Swap(clientes[i], clientes[j]);
            }
        }
    }
    ClienteManager::Imprimir(clientes);
}

void ClienteManager::ListarPorDNI() {
    GenericArray<Cliente> clientes = this->Listar();
    if(clientes.Size() == 0) {
        Warning mi_warning("Listado de Clientes", "No se encontraron clientes para mostrar.");
        mi_warning.Show();
        return;
    }
    for(unsigned int i = 0; i < clientes.Size(); i++) {
        for(unsigned int j = i + 1; j < clientes.Size(); j++) {
            if(clientes[i]->getDNI() > clientes[j]->getDNI()) {
                clientes.Swap(clientes[i], clientes[j]);
            }
        }
    }
    ClienteManager::Imprimir(clientes);
}

void ClienteManager::ListarPorApellido() {
    GenericArray<Cliente> clientes = this->Listar();
    if(clientes.Size() == 0) {
        Warning mi_warning("Listado de Clientes", "No se encontraron clientes para mostrar.");
        mi_warning.Show();
        return;
    }
    for(unsigned int i = 0; i < clientes.Size(); i++) {
        for(unsigned int j = i + 1; j < clientes.Size(); j++) {
            if(clientes[i]->getApellido() > clientes[j]->getApellido()) {
                clientes.Swap(clientes[i], clientes[j]);
            }
        }
    }
    ClienteManager::Imprimir(clientes);
}

void ClienteManager::Imprimir(GenericArray<Cliente>& clientes) {
    if(clientes.Size() == 0) {
        Warning mi_warning("Listado de Clientes", "No se encontraron clientes para mostrar.");
        mi_warning.Show();
        return;
    }

    const unsigned int altura = clientes.Size(),
                        columnas = 9;
    Tabling::Table mi_tabla(altura, columnas);

    Tabling::Row* header = new Tabling::Row(9);
    header->AddCell("DNI", Cliente::GetDniSize());
    header->AddCell("Nombre", Cliente::GetNombreSize());
    header->AddCell("Apellido", Cliente::GetApellidoSize());
    header->AddCell("CUIL/CUIT", Cliente::GetCuilCuitSize());
    header->AddCell("Direccion", DatosPersonales::GetDireccionSize());
    header->AddCell("Correo", DatosPersonales::GetCorreoSize());
    header->AddCell("Telefono", DatosPersonales::GetTelefonoSize());
    header->AddCell("Celular", DatosPersonales::GetCelularSize());
    header->AddCell("Estado", DatosPersonales::GetEstadoSize());
    mi_tabla.AddRow(header);

    for(unsigned int i = 0; i < altura; i++) {
        Tabling::Row* row = new Tabling::Row(columnas);
        row->AddCell(clientes[i]->getDNI(), Cliente::GetDniSize());
        row->AddCell(clientes[i]->getNombre(), Cliente::GetNombreSize());
        row->AddCell(clientes[i]->getApellido(), Cliente::GetApellidoSize());
        row->AddCell(clientes[i]->getCuilCuit(), Cliente::GetCuilCuitSize());
        row->AddCell(clientes[i]->getDireccion(), DatosPersonales::GetDireccionSize());
        row->AddCell(clientes[i]->getCorreo(), DatosPersonales::GetCorreoSize());
        row->AddCell(clientes[i]->getTelefono(), DatosPersonales::GetTelefonoSize());
        row->AddCell(clientes[i]->getCelular(), DatosPersonales::GetCelularSize());
        row->AddCell(clientes[i]->Estado(), DatosPersonales::GetEstadoSize());
        mi_tabla.AddRow(row);
    }
    mi_tabla.Print();
}
