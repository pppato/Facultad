#include "usuario.h"
#include "cstring"
int Usuario::getId() const
{
    return id;
}

void Usuario::setId(int newId)
{
    id = newId;
}

Usuario::Usuario() {}

Usuario::Usuario(char* nombre, int id, Cargo &c)
{
    strncpy(this->nombre,nombre,sizeof(nombre));
    this->nombre[sizeof(nombre)-1] = '\0';
    this->id = id;
    this->c = &c;
}

bool Usuario::tienePermiso(std::string fun)
{
    return c->tienePermiso(fun);
}

const char *Usuario::getNombre() const
{
    return this->nombre;
}

std::string Usuario::getNombreCargo()
{
    return c->getNombre();
}

int Usuario::getCantidadPermisos()
{
    return c->cantidadPermisos();
}
