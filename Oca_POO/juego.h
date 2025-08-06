#ifndef JUEGO_H
#define JUEGO_H
#include "mapa.h"
#include "jugador.h"
#include <QString>
class Juego
{
private:
    std::vector <Jugador*> jugadores;
    Mapa mapa;
    int TurnoActual;
    QString msj;
public:
    Juego();
    Juego(int cantJugadores);
    void JugarTurno();
    bool Ganador();
    void SiguienteTurno();
    void AdministrarTurno(Jugador* jugador);
    void CrearJugadores(int cantJugadores);
    QString rescatarDelPozo(int posicion, Jugador*rescatista);
    Mapa *getMapa();//Para la parte visual
    Jugador* getJugador(int index);
    int cantJugadores();
    QString getMsj();
    QString Bonus(Jugador *jugador);
    ~Juego();
   void BorrarMsj();
};

#endif // JUEGO_H
