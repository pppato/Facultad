#include "dado.h"
#include <cstdlib>

Dado::Dado() {}

int Dado::LanzarDado()
{
    int semilla = (rand() % 6) + 1;
    return semilla;
}
