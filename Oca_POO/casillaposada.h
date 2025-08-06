#ifndef CASILLAPOSADA_H
#define CASILLAPOSADA_H
#include "casilla.h"
#include "jugador.h"
#include <QString>
class CasillaPosada: public Casilla
{
public:
    CasillaPosada(int NumCasilla,QString Descripcion);
    QString EfectoCasilla(Jugador* jugador);
};

#endif // CASILLAPOSADA_H
