#ifndef MAPA_H
#define MAPA_H
#include "casilla.h"
#include <vector>
class Mapa
{
private:
    std::vector<Casilla*> casillas;
public:
    Mapa();
    Casilla* getCasilla(int pos);
    ~Mapa();
};

#endif // MAPA_H
