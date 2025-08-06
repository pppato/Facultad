#include "casilla.h"

Casilla::Casilla(int NumCasilla, QString Descripcion): NumCasilla(NumCasilla),Descripcion(Descripcion) {}
int Casilla::getNumCasilla()
{
    return this->NumCasilla;
}
