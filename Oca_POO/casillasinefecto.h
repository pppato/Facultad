#ifndef CASILLASINEFECTO_H
#define CASILLASINEFECTO_H
#include "casilla.h"
#include <QString>
class CasillaSinEfecto:public Casilla
{
public:
    CasillaSinEfecto(int NumCasilla,QString Descripcion);
    int getNumCasilla();
    QString EfectoCasilla(Jugador* jugador);
};

#endif // CASILLASINEFECTO_H
