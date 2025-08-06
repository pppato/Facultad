#ifndef CASILLACARCEL_H
#define CASILLACARCEL_H
#include "casilla.h"
#include "jugador.h"
#include <QString>
class CasillaCarcel: public Casilla
{
public:
    CasillaCarcel(int NumCasilla,QString Descripcion);
    QString EfectoCasilla(Jugador* jugador);
};

#endif // CASILLACARCEL_H
