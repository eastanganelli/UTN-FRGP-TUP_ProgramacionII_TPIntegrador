#include "product_generator.h"

void DataGenerator::GenerateProduct(unsigned int count, bool printLog) {
    srand(static_cast<unsigned int>(time(NULL)));
    ProveedorManager proveedores;
    ProductoManager productos;

    string descripcionProducto[] = {"Laptop", "Smartphone", "Tablet", "Monitor", "Teclado",
                                     "Ratón", "Impresora", "Cámara", "Auriculares", "Altavoces",
                                     "Disco Duro", "Memoria USB", "Router", "Smartwatch", "Proyector"};

    if(productos.Count() == 0) {
        std::cout << "--- Datos de Productos Generados ---" << std::endl;
        unsigned int totalProveedores = proveedores.Count();
        if (totalProveedores == 0) {
            std::cout << "No hay proveedores cargados. No se generaron productos." << std::endl;
            return;
        }

        for (unsigned int i = 0; i < count; ++i) {
            DatosProducto dp;
            dp.codigo = DataGenerator::generarCodigoAlfaNumerico(Producto::GetCodigoSize());
            unsigned int idx = rand() % totalProveedores;
            Proveedor* p = proveedores.At(idx);
            dp.codigoProveedor = "";
            if (p != nullptr) {
                dp.codigoProveedor = p->getCuit();
                delete p;
            }
            dp.descripcion = "Producto " + dp.codigo;
            dp.precio = static_cast<float>((rand() % 10000) / 100.0 + 1.0);
            dp.stock = rand() % 100 + 1;

            Producto dataProducto(dp.codigo, dp.codigoProveedor, dp.descripcion, dp.precio, dp.stock);
            if (printLog) {
                cout << endl << "Producto agregado? >> " << (productos.New(dataProducto) ? "Si" : "No") << endl;
                dataProducto.Print();
                cout << endl;
            } else {
                productos.New(dataProducto);
            }
        }
        if (printLog)
            std::cout << "\n-------------------------------------\n" << std::endl;
    } else {
        std::cout << "Los productos ya existen. No se generaron nuevos datos." << std::endl;
    }
}
