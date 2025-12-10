# Gestión de Stock

## Trabajo Práctico — Programación 2 (UTN FRGP)

### 2º Cuatrimestre 2025

Descripción
- **Qué es**: Sistema de gestión de stock para el manejo de productos, clientes, proveedores y comprobantes (facturas, notas de crédito).
- **Estado**: Código fuente desarrollado en C++ y organizado en la carpeta `Gestion_De_Stock/` (incluye proyecto de Code::Blocks y la implementación en `Gestion_De_Stock/src/`).

Autores
- **Grupo 74**: Martín Fano, Agustín Rojas y Ezequiel Stanganelli

Estructura relevante
- `Gestion_De_Stock/` — proyecto principal (contiene `Gestion_De_Stock.cbp`, `main.cpp`, `src/`, `bin/`, etc.).
- `Gestion_De_Stock/src/` — código fuente en C++ (clases como `Producto`, `Cliente`, `ProductosManager`, `VentasManager`, entre otras).
- El proyecto incluye un archivo de proyecto de Code::Blocks (`Gestion_De_Stock/Gestion_De_Stock.cbp`) y una estructura pensada para compilación local.

## Índice de módulos

- `main_classes` : modelos y clases de dominio (clientes, proveedores, productos, comprobantes, ítems, fechas, tipos de responsables).
- `manager` : capa de persistencia y operaciones (managers para cada entidad).
- `controller` : utilidades y componentes para la UI de consola (tablas, modales, arreglos genéricos).
- `menu` : menú principal y submenús de interacción.
- `file_manager` : abstracción de persistencia (`FileSystem`).

## Cómo ejecutar con Code::Blocks (versión 21)

1. Abrir Code::Blocks (versión 21) en Windows.
2. Ir a `File -> Open...` y abrir `Gestion_De_Stock/Gestion_De_Stock.cbp`.
3. Verificar en `Settings -> Compiler...` que esté seleccionado `GNU GCC Compiler` o el compilador configurado por el curso.
4. En la barra del proyecto seleccionar la configuración `Debug` y luego `Build -> Build`.
5. Ejecutar con `Build -> Run` o presionando `F9`.

Notas:
- El proyecto fue preparado para Code::Blocks; usar la versión 21 (indicada por la cátedra) ayuda a evitar diferencias en el archivo `.cbp` o en configuraciones del IDE.
- Si necesitás, puedo crear un pequeño `build.ps1` para compilar desde PowerShell con MinGW/GCC.