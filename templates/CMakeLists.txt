cmake_minimum_required(VERSION 3.5)

project(templates LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(templates main.cpp
    MiVector.h
    NodoGenerico.h
    Lista.h
    Pila.h
    Cola.h
)

include(GNUInstallDirs)
install(TARGETS templates
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
