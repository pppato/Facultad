#ifndef CASILLACALAVERA_H
#define CASILLACALAVERA_H
#include "casilla.h"
#include "jugador.h"
#include <QString>
class CasillaCalavera: public Casilla
{
public:
    CasillaCalavera(int NumCasilla,QString Descripcion);
    QString EfectoCasilla(Jugador* jugador);
};

#endif // CASILLACALAVERA_H
