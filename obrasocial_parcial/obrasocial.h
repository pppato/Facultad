#ifndef OBRASOCIAL_H
#define OBRASOCIAL_H
#include <vector>
#include <map>
#include <string>
#include "usuarios.h"
#include "plan.h"


class ObraSocial
{
private:
    std::vector<Usuarios> usuario;
    std::map<char,Plan*>Planes;
    void CrearPlanes();
    //void GenerarUsuariosBinario();
public:
    ObraSocial();
    void leerUsuarios();
    bool tienePrestacion(int id, std::string prestacion);
    std::vector<std::string> getPrestaciones();
    std::vector<Usuarios> MasActivos();
    std::vector<Usuarios> getUsuarios() const;
};

#endif // OBRASOCIAL_H
