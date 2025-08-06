#ifndef CASILLAOCA_H
#define CASILLAOCA_H
#include "casilla.h"
#include "jugador.h"
#include <QString>
class CasillaOca:public Casilla
{
public:
    CasillaOca(int NumCasilla,QString Descripcion);
    QString EfectoCasilla(Jugador* jugador);
};

#endif // CASILLAOCA_H
