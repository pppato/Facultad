#include "casillalaberinto.h"

CasillaLaberinto::CasillaLaberinto(int NumCasilla, QString Descripcion): Casilla(NumCasilla,Descripcion) {}

QString CasillaLaberinto::EfectoCasilla(Jugador *jugador)
{
    jugador->setPos(30);
    return QString ("");
}
