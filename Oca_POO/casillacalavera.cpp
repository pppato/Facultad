#include "casillacalavera.h"

CasillaCalavera::CasillaCalavera(int NumCasilla, QString Descripcion): Casilla(NumCasilla,Descripcion)  {}

QString CasillaCalavera::EfectoCasilla(Jugador *jugador)
{
    jugador->setPos(1);
    return QString("");
}
