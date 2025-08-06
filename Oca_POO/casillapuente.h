#ifndef CASILLAPUENTE_H
#define CASILLAPUENTE_H
#include "casilla.h"
#include "jugador.h"
#include <QString>
class CasillaPuente:public Casilla
{
public:
    CasillaPuente(int NumCasilla,QString Descripcion);
    QString EfectoCasilla(Jugador* jugador);
};

#endif // CASILLAPUENTE_H
