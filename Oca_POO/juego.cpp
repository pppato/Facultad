#include "juego.h"
#include "dado.h"
#include <iostream>
#include <QMessageBox>
Juego::Juego() {
    CrearJugadores(2);
    this->TurnoActual=0;
}

Juego::Juego(int cantJugadores)
{
    CrearJugadores(cantJugadores);
    this->TurnoActual=0;
}

void Juego::JugarTurno() {
    if (Ganador()) {
        msj="¡Hay un ganador!";
        return;
    }
    Jugador* jugadoractual = jugadores[TurnoActual];
    if (jugadoractual->getBloqueado()) {
        msj=QString("El jugador %1 está bloqueado. Pierde el turno.").arg(jugadoractual->getNumJugador());
        jugadoractual->RestarTurnosbloq();
        SiguienteTurno();
        return;
    }else{

    AdministrarTurno(jugadoractual);
    SiguienteTurno();
    }
  }

bool Juego::Ganador()
{
    for (auto jugador : jugadores){
        if (jugador->getPos()==63){
            return true;
        }
    }
    return false;
}

void Juego::SiguienteTurno()
{
    this->TurnoActual=(this->TurnoActual+1) % jugadores.size();
}

void Juego::AdministrarTurno(Jugador *jugador)
{
    int resu;
    Dado dado;
    resu=dado.LanzarDado();
    int auxpos=jugador->getPos()+resu;
    jugador->setPos(auxpos);
    QString msjcasilla;
    if (auxpos > 63) {
        auxpos = 63 - (auxpos - 63); // Rebote
        jugador->setPos(auxpos);
        msj= QString("se pasa y rebota a la casilla %1").arg(auxpos);
    } else {
        msj=QString("El jugador %1 lanza el dado y obtiene %3 avanza a la casilla %2").arg(jugador->getNumJugador()).arg(auxpos).arg(resu);
    }
    Casilla* casilla= mapa.getCasilla(auxpos);
    if (casilla){
        msjcasilla=casilla->EfectoCasilla(jugador);
        if (!msjcasilla.isEmpty()){
            msj+="\n"+msjcasilla;
        }
    }
    //rescate del pozo, comprueba todo el tiempo
    QString msjpozo;
    if(jugador->getPos()==31){
       msjpozo=rescatarDelPozo(31,jugador);
        if (!msjpozo.isEmpty()){
           msj+="\n"+msjpozo;
        }
    }
    jugador->setContadorTurnos(1);
    QString msjbono;
    if (jugador->getContadorTurnos()==10){
        msj=QString("¡El jugador %1 ha llegado a las 10 tiradas, obtiene un efecto especial!").arg(jugador->getNumJugador());
        msjbono= Bonus(jugador);
        if (!msjbono.isEmpty()){
            msj+="\n"+msjbono;
        }
        jugador->setContadorTurnos(0);//Resetea su contador de turnos
    }
}

void Juego::CrearJugadores(int cantJugadores)
{
    for (int i=0;i<cantJugadores;i++){
        jugadores.push_back(new Jugador(i+1));
    }
}

QString Juego::rescatarDelPozo(int posicion, Jugador *rescatista)
{
    for (Jugador* j : jugadores) {
        if (j != rescatista && j->getPos() == posicion && j->getBloqueado()) {
            j->setBloqueado(false);
            j->setcant_turnosbloq(0);
            return QString("El jugador %1 ha sido rescatado del pozo por el jugador %2").arg(j->getNumJugador()).arg(rescatista->getNumJugador());
            break; // Solo rescata al primero que encuentre
        }
    }
    return QString("");
}

Mapa *Juego::getMapa()
{
    return &this->mapa;
}

Jugador *Juego::getJugador(int index)
{
    if (index>=0 and index<jugadores.size()){
        return jugadores[index];
    }
    return nullptr;
}

int Juego::cantJugadores()
{
    return jugadores.size();
}

QString Juego::getMsj()
{
    return msj;
}

void Juego::BorrarMsj()
{
    msj="";
}

QString Juego::Bonus(Jugador *jugador)
{
    srand(time(NULL));
    int semilla=(rand()%6)+1;
    switch(semilla){
    case 1:
        return QString("¡El jugador %1 efecto especial:Adelanta 5 pasos ").arg(jugador->getNumJugador());
        break;
   case 2:
        return QString("¡El jugador %1 efecto especial: Envia al jugador a la casilla El Pozo").arg(jugador->getNumJugador());
        break;
    case 3:
        jugador->setBloqueado(true);
        jugador->setcant_turnosbloq(1);
        return QString("¡El jugador %1 efecto especial:  queda bloqueado 1 turno ").arg(jugador->getNumJugador());
        break;
    case 4:
        jugador->setPos(1);
        return QString("¡El jugador %1 efecto especial:  vuelve a la casilla 1 ").arg(jugador->getNumJugador());
        break;
    case 5:
        int index;
        do{
            index=rand()% jugadores.size();
        }while (jugadores[index]==jugador);//Se evita a si mismo
        Jugador* victima=jugadores[index];
        victima->setBloqueado(true);
        victima->setcant_turnosbloq(2);
        return QString("¡El jugador %1 efecto especial: bloquea 2 turnos a un jugador al azar ").arg(jugador->getNumJugador());
        break;
    }
    return QString("");
}


Juego::~Juego()
{
    for (auto jugadores : jugadores){
        delete jugadores;
    }
}

