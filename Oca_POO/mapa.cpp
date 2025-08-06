#include "mapa.h"
#include "casillacalavera.h"
#include "casillacarcel.h"
#include "casillajardindelaoca.h"
#include "casillalaberinto.h"
#include "casillaoca.h"
#include "casillaposada.h"
#include "casillapozo.h"
#include "casillapuente.h"
#include "casillasinefecto.h"
#include "casillacalavera.h"
Mapa::Mapa() {
    for (int i=0;i<=63;i++){
        casillas.push_back(new CasillaSinEfecto(i, "Casilla normal"));
    }

    casillas[6]=new CasillaPuente(6,"Casilla Puente");
    for (int i = 9; i <= 54; i += 9) {
        casillas[i] = new CasillaOca(i, "Casilla Oca");
    }
    casillas[19]=new CasillaPosada(19,"Casilla Posada");
    casillas[31]=new CasillaPozo(31,"Casilla Pozo");
    casillas[42]=new CasillaLaberinto(42,"Casilla Laberinto");
    casillas[56]=new CasillaCarcel(56,"Casilla Carcel");
    casillas[58]=new CasillaCalavera(58,"Casilla Calavera");
    casillas[63]=new CasillaJardinDeLaOca(63,"Casilla Jardin De La Oca");
}

Casilla *Mapa::getCasilla(int pos)
{
    if (pos >=0 and pos < casillas.size()){
        return casillas[pos];
    }
}

Mapa::~Mapa()
{
    for (auto c : casillas) delete c;
    casillas.clear();
}
