#ifndef CASILLALABERINTO_H
#define CASILLALABERINTO_H
#include "casilla.h"
#include "jugador.h"
#include <QString>
class CasillaLaberinto:public Casilla
{
public:
    CasillaLaberinto(int NumCasilla,QString Descripcion);
    QString EfectoCasilla(Jugador* jugador);
};

#endif // CASILLALABERINTO_H
