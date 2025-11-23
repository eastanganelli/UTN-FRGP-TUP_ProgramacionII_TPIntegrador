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

bool ClienteManager::Existe(Cliente& cliente) {
    const unsigned int cantidad = this->Count();
    unsigned int i = 0;
    while(i < cantidad) {
        Cliente* aux = this->At(i);
        if(*aux == cliente) {
            return true;
        }
        i++;
    }
    return false;
}

unsigned int ClienteManager::Cantidad() {
    return this->Count();
}

bool ClienteManager::Modificar(string dni, Cliente* cliente) {
    unsigned int index = 0;
    Cliente tempCliente;
    tempCliente.setDNI(dni);
    if(!this->IndexOf(tempCliente, index)) {
        cerr << "Error: Cliente con DNI " << dni << " no encontrado." << endl;
        return false;
    }
    return this->Update(index, *cliente);
}

void ClienteManager::ListarPorCuil_Cuit() {
    GenericArray<Cliente> clientes = this->Listar();
    if(clientes.Size() == 0) {
        cerr << "No hay clientes disponibles" << endl;
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
        cerr << "No hay clientes disponibles" << endl;
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
        cerr << "No hay clientes disponibles" << endl;
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
    unsigned int index = 0;
    Cliente tempCliente;
    tempCliente.setDNI(dni);
    if(!this->IndexOf(tempCliente, index)) {
        return nullptr;
    }
    return this->At(index);
}

GenericArray<Cliente> ClienteManager::BuscarPorCUIL_CUIT(string cuil_cuit) {
    GenericArray<Cliente> resultados;
    const unsigned int cantidad = this->Count();
    for(unsigned int i = 0; i < cantidad; i++) {
        Cliente* aux = this->At(i);
        if(aux->getCuilCuit() == cuil_cuit) {
            resultados + (*aux);
        }
        delete aux;
    }
    return resultados;
}

GenericArray<Cliente> ClienteManager::BuscarPorDNI(string dni) {
    GenericArray<Cliente> resultados;
    const unsigned int cantidad = this->Count();
    for(unsigned int i = 0; i < cantidad; i++) {
        Cliente* aux = this->At(i);
        if(aux->getDNI() == dni) {
            resultados + (*aux);
        }
        delete aux;
    }
    return resultados;
}

GenericArray<Cliente> ClienteManager::BuscarPorNombreApellido(string nombre, string apellido) {
    GenericArray<Cliente> resultados;
    const unsigned int cantidad = this->Count();
    for(unsigned int i = 0; i < cantidad; i++) {
        Cliente* aux = this->At(i);
        if(aux->getNombre() == nombre && aux->getApellido() == apellido) {
            resultados + (*aux);
        }
        delete aux;
    }
    return resultados;
}

GenericArray<Cliente> ClienteManager::BuscarPorCorreo(string correo) {
    GenericArray<Cliente> resultados;
    const unsigned int cantidad = this->Count();
    for(unsigned int i = 0; i < cantidad; i++) {
        Cliente* aux = this->At(i);
        if(aux->getCorreo() == correo) {
            resultados + (*aux);
        }
        delete aux;
    }
    return resultados;
}

void ClienteManager::Imprimir(GenericArray<Cliente>& clientes) {
    if(clientes.Size() == 0) {
        Warning mi_warning("Listado de Clientes", "No se encontraron clientes para mostrar.");
        mi_warning.Show();
        return;
    }

    const int wDNI = 12,
            wNombre = 20,
            wApellido = 20,
            wCuil = 18,
            wCorreo = 30;

    rlutil::saveDefaultColor();
    rlutil::setBackgroundColor(rlutil::BLUE);
    rlutil::setColor(rlutil::WHITE);
    printf("%-*s%-*s%-*s%-*s%-*s\n", wDNI, "DNI", wApellido, "Apellido", wNombre, "Nombre",
            wCuil, "CUIL/CUIT", wCorreo, "Correo");
    rlutil::resetColor();

    const int totalWidth = wDNI + wNombre + wApellido + wCuil + wCorreo;
    for(int s = 0; s < totalWidth; s++) putchar('-');
    putchar('\n');

    // Rows (use C-style printing, converting std::string to C-string)
    for(unsigned int i = 0; i < clientes.Size(); i++) {
        Cliente* c = clientes[i];
        printf("%-*s%-*s%-*s%-*s%-*s\n",
               wDNI, c->getDNI().c_str(),
               wApellido, c->getApellido().c_str(),
               wNombre, c->getNombre().c_str(),
               wCuil, c->getCuilCuit().c_str(),
               wCorreo, c->getCorreo().c_str());
    }
}
