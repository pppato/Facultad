#include "visitas.h"
#include <string.h>
char Visitas::getOrigen() const
{
    return origen;
}

int Visitas::getTiempoPermanencia() const
{
    return tiempoPermanencia;
}

Visitas::Visitas()
{

}

Visitas::Visitas(char *URL, int tiempoPermanencia, char origen) {
    strcpy(this->URL,URL);
    this->tiempoPermanencia = tiempoPermanencia;
    this->origen = origen;
}
