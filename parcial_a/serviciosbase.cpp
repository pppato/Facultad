#include "serviciosbase.h"
#include <cstring>
ServiciosBase::ServiciosBase(): monto(0){}

void ServiciosBase::setNombre(const char *nom)
{
    this->nombre = new char [strlen(nom)+1];
    strcpy(nombre,nom);

}

char* ServiciosBase::getNombre(){
    return nombre;
}

int ServiciosBase::getMonto()
{
    return this->monto;
}



