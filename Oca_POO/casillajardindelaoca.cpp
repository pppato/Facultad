#include "casillajardindelaoca.h"
#include <iostream>

CasillaJardinDeLaOca::CasillaJardinDeLaOca(int NumCasilla, QString Descripcion): Casilla(NumCasilla,Descripcion) {}

QString CasillaJardinDeLaOca::EfectoCasilla(Jugador *jugador)
{
    QString msj= QString("¡Felicitaciones! El jugador %1 ha ganado el juego!").arg(jugador->getNumJugador());
    return msj;
}
