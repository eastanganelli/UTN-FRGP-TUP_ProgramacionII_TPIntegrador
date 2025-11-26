#include "cliente_manager.h"

#include "../../rlutil.h"

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

unsigned int ClienteManager::Cantidad() {
    return this->Count();
}

bool ClienteManager::Modificar(string dni, Cliente* cliente) {
    unsigned int index = 0;
    if(!this->IndexOf(*cliente, index)) {
        Error mi_error("Modificacion de Cliente", "Cliente con DNI " + dni + " no encontrado.");
        mi_error.Show();
        return false;
    }
    return this->Update(index, *cliente);
}

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

void ClienteManager::Splitter(char Separator) {
    const int totalWidth = Cliente::GetDniSize() + Cliente::GetNombreSize() + Cliente::GetApellidoSize() + Cliente::GetCuilCuitSize()
                        + DatosPersonales::GetCorreoSize() + DatosPersonales::GetTelefonoSize() + DatosPersonales::GetCelularSize()
                        + DatosPersonales::GetDireccionSize() + DatosPersonales::GetEstadoSize();
    
    for(int s = 0; s < totalWidth; s++)
        putchar(Separator);

    putchar('\n');
}

void ClienteManager::ImprimirHeader() {
    rlutil::saveDefaultColor();
    rlutil::setBackgroundColor(rlutil::BLUE);
    rlutil::setColor(rlutil::WHITE);
    printf("%-*s%-*s%-*s%-*s%-*s%-*s%-*s%-*s%-*s\n",
            Cliente::GetDniSize(), "DNI", Cliente::GetApellidoSize(), "Apellido", Cliente::GetNombreSize(), "Nombre",
            Cliente::GetCuilCuitSize(), "CUIL/CUIT", DatosPersonales::GetCorreoSize(),"Correo",
            DatosPersonales::GetTelefonoSize(), "Telefono", DatosPersonales::GetCelularSize(), "Celular",
            DatosPersonales::GetDireccionSize(), "Direccion", DatosPersonales::GetEstadoSize(), "Estado");
    rlutil::resetColor();
}

void ClienteManager::Imprimir(GenericArray<Cliente>& clientes) {
    if(clientes.Size() == 0) {
        Warning mi_warning("Listado de Clientes", "No se encontraron clientes para mostrar.");
        mi_warning.Show();
        return;
    }

    ClienteManager::ImprimirHeader();
    ClienteManager::Splitter('=');
    for(unsigned int i = 0; i < clientes.Size(); i++) {
        clientes[i]->Print();
    }
    ClienteManager::Splitter('=');
}
