cmake_minimum_required(VERSION 3.16)

project(Gestor_De_Stock LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Gestor_De_Stock
    main.cpp
    src/Cliente.cpp src/Cliente.h src/ClientesManager.cpp src/ClientesManager.h src/Comprobante.cpp src/Comprobante.h src/DatosPersonales.cpp src/DatosPersonales.h src/Factura.cpp src/Factura.h src/FacturasManager.cpp src/FacturasManager.h src/Fecha.cpp src/Fecha.h src/Item.cpp src/Item.h src/menu.cpp src/Menu.h src/NotaDeCredito.cpp src/NotaDeCredito.h src/NotaDeCreditosManager.cpp src/NotaDeCreditosManager.h src/Producto.cpp src/Producto.h src/ProductosManager.cpp src/ProductosManager.h
    src/Proveedor.cpp src/Proveedor.h src/ProveedoresManager.cpp src/ProveedoresManager.h
    Pruebas.h Pruebas.cpp
    )

include(GNUInstallDirs)
install(TARGETS Gestor_De_Stock
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
