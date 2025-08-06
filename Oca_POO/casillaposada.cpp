#include "casillaposada.h"

CasillaPosada::CasillaPosada(int NumCasilla, QString Descripcion): Casilla(NumCasilla,Descripcion) {}

QString CasillaPosada::EfectoCasilla(Jugador *jugador)
{

    jugador->setcant_turnosbloq(1);
    jugador->setBloqueado(true);
    return QString("");
}
