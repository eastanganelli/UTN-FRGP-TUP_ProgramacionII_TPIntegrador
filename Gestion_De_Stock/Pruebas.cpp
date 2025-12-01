#include "Pruebas.h"

void Testing::Modals() {
//    Informational information("Hola Mundo", "mensaje");
//    information.Show();
//    cout << endl;
//    information.ShowYesNo();

//    Warning alerta("Hola Mundo", "mensaje");
//    alerta.Show();
//    cout << endl;
//    alerta.ShowYesNo();

//    Error error("Hola Mundo", "mensaje");
//    error.Show();
//    cout << endl;
//    error.ShowYesNo();
}

void Testing::Array() {
    GenericArray<int> misNumeros;
    int num1 = 1, num2 = 2, num3 = 3, num4 = 4;
    bool resultado = misNumeros+num1;
    resultado = misNumeros+num2;
    resultado = misNumeros+num3;
    resultado = misNumeros+num4;
    cout << resultado << endl;
    int cantidad = misNumeros.Size();
    for(int i = 0; i < cantidad; i++) {
        cout << "Pos: " << i << " -  Valor: " << *misNumeros[i] << endl;
    }

    cout << "---------------------" << endl;

    int* valor_remover = misNumeros[2];
    misNumeros-*valor_remover;
    cantidad = misNumeros.Size();
    for(int i = 0; i < cantidad; i++) {
        cout << "Pos: " << i << " -  Valor: " << *misNumeros[i] << endl;
    }

    cout << "---------------------" << endl;

    int nuevoVal=15;
    misNumeros.InsertAt(1,nuevoVal);
    cantidad = misNumeros.Size();
    for(int i = 0; i < cantidad; i++) {
        cout << "Pos: " << i << " -  Valor: " << *misNumeros[i] << endl;
    }
    misNumeros.RemoveAt(20);
    misNumeros.InsertAt(-1,nuevoVal);
    misNumeros.InsertAt(7,nuevoVal);
    misNumeros[-99];
    misNumeros[99];
}

void Testing::File() {
    FileSystem<int> miArchivo("mi_archivo_prueba.dat");

//    int aux_value = -99;
//    bool resultado = miArchivo.New(aux_value);

    cout << "Pre Update/Delete" << endl;
    for(unsigned int i; i < miArchivo.Count(); i++) {
        cout << "[" << i << "] : " << *miArchivo.At(i) << endl;
    }

    cout << "Post Update/" << endl;
    int aux = 235;
    miArchivo.Update(1, aux);
//    int newValue = 23;
//    miArchivo.New(newValue);
//    newValue = 1995;
//    miArchivo.New(newValue);
    for(unsigned int i; i < miArchivo.Count(); i++) {
        cout << "[" << i << "] : " << *miArchivo.At(i) << endl;
    }

    cout << "Post Delete" << endl;
    miArchivo.Delete(2);
    for(unsigned int i; i < miArchivo.Count(); i++) {
        cout << "[" << i << "] : " << *miArchivo.At(i) << endl;
    }

    miArchivo.Backup("archivo_backup.dat");
}

void Testing::ClientePrueba() {
    ClienteManager misClientes("clientes.dat");

    misClientes.ListarPorCuil_Cuit();
//    misClientes.ListarPorDNI();
//    misClientes.ListarPorApellido();

//    Cliente* miCliente = misClientes["34"];
//
//    if(miCliente != nullptr) {
//        miCliente->Print();
//    }
}

void Testing::TipoResponsablePrueba() {
    TipoResponsableManager misReponsables("tipo_responsable.dat");

    misReponsables.ListarPorPorcentaje();
}
