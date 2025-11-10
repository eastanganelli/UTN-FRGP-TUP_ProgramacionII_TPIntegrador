cmake_minimum_required(VERSION 3.10.0)
project(tp_integrador VERSION 0.1.0 LANGUAGES C CXX)

add_executable(tp_integrador Gestion_De_Stock/main.cpp)

## Add headers and source files
target_include_directories(tp_integrador PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Gestion_De_Stock/include)
file(GLOB_RECURSE SOURCES "Gestion_De_Stock/src/*.cpp" "Gestion_De_Stock/include/*.h")
target_sources(tp_integrador PRIVATE ${SOURCES})

set_target_properties(tp_integrador PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)