#ifndef JUGADOR_H
#define JUGADOR_H
class Jugador
{
private:
    int Pos;
    int NumJugador;
    bool bloqueado;
    int cant_turnosbloq;
    int contadorTurnos=0;
public:
    Jugador();
    Jugador(int NumJugador,int Pos=0,bool bloqueado=false);
    int getPos();
    void setPos(int newPos);
    int getNumJugador();
    void setNumJugador(int newNumJugador);
    bool getBloqueado();
    void setBloqueado(bool newBloqueado);
    int getcant_turnosbloq();
    void setcant_turnosbloq(int turnos);
    void RestarTurnosbloq();
    int getContadorTurnos();
    void setContadorTurnos(int newContadorTurnos);
};

#endif // JUGADOR_H
