cmake_minimum_required(VERSION 3.16)

project(obrasocial_parcial LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(obrasocial_parcial main.cpp
    obrasocial.h obrasocial.cpp
    usuarios.h usuarios.cpp
    plan.h plan.cpp)

include(GNUInstallDirs)
install(TARGETS obrasocial_parcial
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
