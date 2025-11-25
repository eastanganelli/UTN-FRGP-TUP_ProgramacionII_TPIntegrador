#include "product_generator.h"

void DataGenerator::GenerateProduct(unsigned int count) {
    srand(static_cast<unsigned int>(time(NULL)));
    ProveedorManager proveedores("Proveedores.dat");  
    ProductoManager productos("Productos.dat");

    string descripcionProducto[] = {"Laptop", "Smartphone", "Tablet", "Monitor", "Teclado",
                                     "Ratón", "Impresora", "Cámara", "Auriculares", "Altavoces",
                                     "Disco Duro", "Memoria USB", "Router", "Smartwatch", "Proyector"};

    if(productos.Contar() == 0 || count > 0) {
        std::cout << "--- Datos de Productos Generados ---" << std::endl;
        for (int i = 0; i < 30; ++i) {
            DatosProducto dp;
            dp.codigo = productos.generarCodigo() + "\0";
            dp.codigoProveedor = proveedores.SeleccionarRandom()->getCuit() + "\0";
            dp.descripcion = "Producto " + dp.codigo + "\0";
            dp.precio = static_cast<float>((rand() % 10000) / 100.0 + 1.0);
            dp.stock = rand() % 100 + 1;

            Producto dataProducto(dp.codigo, dp.codigoProveedor, dp.descripcion, dp.precio, dp.stock);
            cout << "Producto agregado? >> " << (productos.Crear(dataProducto) ? "Si" : "No") << endl;

            std::cout << "Producto " << i + 1 << ": " << dp.codigo
                        << " | Codigo Proveedor: " << dp.codigoProveedor << " | Descripcion: " << dp.descripcion
                        << " | Precio: " << dp.precio << " | Stock: " << dp.stock << std::endl;
        }
        std::cout << "\n-------------------------------------\n" << std::endl;
    }
}