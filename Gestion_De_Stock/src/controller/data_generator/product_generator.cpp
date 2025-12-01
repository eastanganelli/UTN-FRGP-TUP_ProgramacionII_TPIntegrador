#include "product_generator.h"

void DataGenerator::GenerateProduct(unsigned int count) {
    srand(static_cast<unsigned int>(time(NULL)));
    ProveedorManager proveedores;
    ProductoManager productos;

    string descripcionProducto[] = {"Laptop", "Smartphone", "Tablet", "Monitor", "Teclado",
                                     "Ratón", "Impresora", "Cámara", "Auriculares", "Altavoces",
                                     "Disco Duro", "Memoria USB", "Router", "Smartwatch", "Proyector"};

    if(productos.Count() == 0) {
        std::cout << "--- Datos de Productos Generados ---" << std::endl;
        for (unsigned int i = 0; i < count; ++i) {
            DatosProducto dp;
            dp.codigo = DataGenerator::generarCodigoAlfaNumerico(Producto::GetCodigoLength());
            dp.codigoProveedor = proveedores.SeleccionarRandom()->getCuit();
            dp.descripcion = "Producto " + dp.codigo;
            dp.precio = static_cast<float>((rand() % 10000) / 100.0 + 1.0);
            dp.stock = rand() % 100 + 1;

            Producto dataProducto(dp.codigo, dp.codigoProveedor, dp.descripcion, dp.precio, dp.stock);
            cout << endl << "Producto agregado? >> " << (productos.New(dataProducto) ? "Si" : "No") << endl;

            dataProducto.Print();
            cout << endl;
        }
        std::cout << "\n-------------------------------------\n" << std::endl;
    }
}
