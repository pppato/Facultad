#include "casillasinefecto.h"

CasillaSinEfecto::CasillaSinEfecto(int NumCasilla, QString Descripcion): Casilla(NumCasilla,Descripcion){}

int CasillaSinEfecto::getNumCasilla()
{
    return NumCasilla;
}

QString CasillaSinEfecto::EfectoCasilla(Jugador *jugador){
    return QString("");
}
