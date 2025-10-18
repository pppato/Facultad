#ifndef USUARIOS_H
#define USUARIOS_H
#include "plan.h"

struct DatosUsuarios
{
    int id;
    char nombre[200];
    char tipo;
    int cantidad;
};

class Usuarios
{
private:
    int id;
    char nombre[200];
    char tipo;
    int cantidad;
    Plan* planUsuario;
public:
    Usuarios();
    void setPlan(Plan* p);
    bool VerificarPrestacion(std::string prestacion);
    void setStruct(DatosUsuarios str);
    int getCantidad() const;
    std::string getNombre() const;

};

#endif // USUARIOS_H
