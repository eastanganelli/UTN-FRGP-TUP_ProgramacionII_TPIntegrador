cmake_minimum_required(VERSION 3.16)

project(Gestor_De_Stock LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Gestor_De_Stock
    main.cpp
    include/Cliente.h include/ClientesManager.h include/Comprobante.h  include/DatosPersonales.h include/Factura.h include/FacturasManager.h include/Fecha.h  include/Item.h include/Menu.h include/NotaDeCredito.h include/NotaDeCreditosManager.h include/Producto.h include/ProductosManager.h include/Proveedor.h include/ProveedoresManager.h include/TipoResponsable.h src/Cliente.cpp src/ClientesManager.cpp src/Comprobante.cpp  src/DatosPersonales.cpp src/Factura.cpp src/FacturasManager.cpp src/Fecha.cpp  src/Item.cpp src/Menu.cpp src/NotaDeCredito.cpp src/NotaDeCreditosManager.cpp src/Producto.cpp src/ProductosManager.cpp src/Proveedor.cpp src/ProveedoresManager.cpp src/TipoResponsable.cpp

    )

include(GNUInstallDirs)
install(TARGETS Gestor_De_Stock
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
