cmake_minimum_required(VERSION 3.5)

project(parcial_a LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(parcial_a main.cpp
    serviciosbase.h serviciosbase.cpp
    horas.h horas.cpp
    mensual.h mensual.cpp
    solicitud.h solicitud.cpp
    cliente.h cliente.cpp
    gestor.h gestor.cpp
)

include(GNUInstallDirs)
install(TARGETS parcial_a
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
