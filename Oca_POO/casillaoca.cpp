#include "casillaoca.h"
#include <iostream>
#include <ostream>

CasillaOca::CasillaOca(int NumCasilla, QString Descripcion): Casilla(NumCasilla,Descripcion) {}

QString CasillaOca::EfectoCasilla(Jugador* jugador)
{
    QString msj;
    msj = QString("¡De oca en oca y tiro porque me toca! Jugador %1 vuelve a tirar.")
                    .arg(jugador->getNumJugador());
    int auxpos=jugador->getPos();
    int SigOca= auxpos+9;
    jugador->setPos(SigOca);
    return msj;
}
