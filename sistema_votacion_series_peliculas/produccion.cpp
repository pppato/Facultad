#include "produccion.h"
#include <numeric>
int Produccion::getNro() const
{
    return nro;
}

std::string Produccion::getNombre() const
{
    return nombre;
}

int Produccion::getCantVotos() const
{
    return votacion.size();
}

char Produccion::getTipo() const
{
    return tipo;
}

Produccion::Produccion() {}

void Produccion::setStruct(Prod p)
{
    this->nro = p.nro;
    this->nombre = p.nombre;
    this->tipo = p.tipo;
    this->promedio = 0.0;
}

void Produccion::agregarVoto(int v)
{
    votacion.push_back(v);
}

void Produccion::promediar()
{
    promedio = std::accumulate(votacion.begin(),votacion.end(),0.0)/votacion.size();
}

float Produccion::getPromedio() const
{
    return promedio;
}
