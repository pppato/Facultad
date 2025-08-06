#include "casillapozo.h"
#include <iostream>
#include <ostream>


CasillaPozo::CasillaPozo(int NumCasilla, QString Descripcion): Casilla(NumCasilla,Descripcion) {}

QString CasillaPozo::EfectoCasilla(Jugador* jugador){
    QString msj=QString("¡El jugador %1 ha caido en la casilla Pozo. No puede moverse hasta que otro jugador caiga en la misma casilla...").arg(jugador->getNumJugador());
    jugador->setcant_turnosbloq(999);
    jugador->setBloqueado(true);
    return msj;

}
