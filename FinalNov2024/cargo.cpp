#include "cargo.h"
#include <algorithm>
std::vector<std::string> Cargo::getFunciones() const
{
    return funciones;
}

void Cargo::setFunciones(const std::vector<std::string> &newFunciones)
{
    funciones = newFunciones;
}

std::string Cargo::getNombre() const
{
    return nombre;
}

void Cargo::setNombre(const std::string &newNombre)
{
    nombre = newNombre;
}

int Cargo::cantidadPermisos()
{
    return funciones.size();
}

Cargo::Cargo() {}

Cargo::Cargo(std::string nombre, std::vector<std::string> funciones)
{
    this->nombre = nombre;
    this->funciones = funciones;
}

bool Cargo::tienePermiso(std::string fun)
{
    auto it = std::find_if(funciones.begin(),funciones.end(),[fun] (std::string f) { return f == fun; });
    if (it!=funciones.end()) return true;
    return false;
}
