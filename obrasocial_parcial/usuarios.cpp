#include "usuarios.h"
#include <string.h>
Usuarios::Usuarios() {}

void Usuarios::setPlan(Plan *p)
{
    this->planUsuario = p;
}

bool Usuarios::VerificarPrestacion(std::string prestacion)
{
    return this->planUsuario->verifPrestacion(prestacion);
}

void Usuarios::setStruct(DatosUsuarios str)
{
    strcpy(this->nombre,str.nombre);
    this->cantidad = str.cantidad;
    this->tipo = str.tipo;
    this->id = str.id;
}

int Usuarios::getCantidad() const
{
    return cantidad;
}

std::string Usuarios::getNombre() const
{
    std::string nombre(this->nombre);
    return nombre;
}

