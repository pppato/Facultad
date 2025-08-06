
#ifndef CASILLAPOZO_H
#define CASILLAPOZO_H
#include "casilla.h"
#include "jugador.h"
#include <QString>

class CasillaPozo:public Casilla
{
public:
    CasillaPozo(int NumCasilla,QString Descripcion);
    QString EfectoCasilla(Jugador* jugador);
};

#endif // CASILLAPOZO_H
