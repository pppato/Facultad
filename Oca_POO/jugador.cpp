#include "jugador.h"


int Jugador::getPos()
{
    return Pos;
}

void Jugador::setPos(int newPos)
{
    Pos = newPos;
}

int Jugador::getNumJugador()
{
    return NumJugador;
}

void Jugador::setNumJugador(int newNumJugador)
{
    NumJugador = newNumJugador;
}

bool Jugador::getBloqueado()
{
    return this->bloqueado;
}

void Jugador::setBloqueado(bool  newBloqueado)
{

    if(newBloqueado){
        this->bloqueado= true;
    }else{
        this->bloqueado=false;
    }
}

int Jugador::getcant_turnosbloq()
{
    return cant_turnosbloq;
}

void Jugador::setcant_turnosbloq(int turnos)
{
    this->cant_turnosbloq=turnos;
    if(this->cant_turnosbloq>0){
        this->bloqueado= true;
    }else{
        this->bloqueado=false;
    }
}

void Jugador::RestarTurnosbloq()
{
    if (cant_turnosbloq > 0){
        cant_turnosbloq--;
        if (cant_turnosbloq==0){
            this->bloqueado=false;
        }
    }
}

int Jugador::getContadorTurnos()
{
    return contadorTurnos;
}

void Jugador::setContadorTurnos(int newContadorTurnos)
{
    contadorTurnos += newContadorTurnos;
}

Jugador::Jugador(): Pos(0),NumJugador(0),bloqueado(false),cant_turnosbloq(0)
{

}

Jugador::Jugador(int NumJugador,int Pos,bool bloqueado):
    Pos(Pos),NumJugador(NumJugador),bloqueado(false),cant_turnosbloq(0),contadorTurnos(0){}
