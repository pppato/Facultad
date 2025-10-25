#include "comun.h"

Comun::Comun() {}

void Comun::actualizarValor()
{
    double v = getValor();
    v -= (v*0.05);
    setValor(v);
}
