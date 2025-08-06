#ifndef CASILLAJARDINDELAOCA_H
#define CASILLAJARDINDELAOCA_H
#include "casilla.h"
#include "jugador.h"
#include <QString>
class CasillaJardinDeLaOca: public Casilla
{
public:
    CasillaJardinDeLaOca(int NumCasilla,QString Descripcion);
    QString EfectoCasilla(Jugador* jugador);
};

#endif // CASILLAJARDINDELAOCA_H
