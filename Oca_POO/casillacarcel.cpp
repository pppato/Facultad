#include "casillacarcel.h"

CasillaCarcel::CasillaCarcel(int NumCasilla, QString Descripcion): Casilla(NumCasilla,Descripcion) {}

QString CasillaCarcel::EfectoCasilla(Jugador *jugador)
{
    jugador->setcant_turnosbloq(2);
    jugador->setBloqueado(true);
    return QString("");
}
