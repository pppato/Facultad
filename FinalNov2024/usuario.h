#ifndef USUARIO_H
#define USUARIO_H
#include "cargo.h"
struct Usuarios {
    char nombre [200];
    int id;
    char nombreCargo[50];
};
class Usuario
{
private:
    char nombre [200];
    int id;
    Cargo* c;
public:
    Usuario();
    Usuario(char *nombre, int id, Cargo&c);
    bool tienePermiso(std::string fun);

    const char* getNombre() const;
    std::string getNombreCargo();

    int getCantidadPermisos();
    int getId() const;
    void setId(int newId);
};

#endif // USUARIO_H
