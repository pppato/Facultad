#ifndef CASILLA_H
#define CASILLA_H
#include "jugador.h"
#include <QString>

class Casilla
{
protected:
    int NumCasilla;
    QString Descripcion;
public:
    Casilla(int NumCasilla,QString Descripcion);
    int getNumCasilla();
    virtual QString EfectoCasilla(Jugador* jugador)=0;
};

#endif // CASILLA_H
