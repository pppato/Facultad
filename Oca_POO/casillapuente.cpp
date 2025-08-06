#include "casillapuente.h"
#include <iostream>

CasillaPuente::CasillaPuente(int NumCasilla,QString Descripcion): Casilla(NumCasilla,Descripcion) {}

QString CasillaPuente::EfectoCasilla(Jugador *jugador)
{
    QString msj= QString("Del puente a la posada. El jugador %1 avanza a la casilla 12").arg(jugador->getNumJugador());
    jugador->setPos(12);
    return msj;

}
