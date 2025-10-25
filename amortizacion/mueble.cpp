#include "mueble.h"

Mueble::Mueble() {}

void Mueble::actualizarValor()
{
    double v = getValor();
    if (v>10000){
        v -= (v*0.22);
    } else {
        v -= (v*0.02);
    }
    setValor(v);
}
