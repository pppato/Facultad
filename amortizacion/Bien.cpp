#include "Bien.h"

char Bien::getTipo() const
{
    return tipo;
}

double Bien::getValor() const
{
    return valor;
}

void Bien::setValor(double newValor)
{
    valor = newValor;
}

void Bien::setStruct(bienes b)
{
    cod = b.cod;
    tipo = b.tipo;
    valor = b.valor;
}

int Bien::getCod() const
{
    return cod;
}
