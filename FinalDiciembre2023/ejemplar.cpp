#include "ejemplar.h"

int Ejemplar::getIsbn() const
{
    return isbn;
}

void Ejemplar::setIsbn(int newIsbn)
{
    isbn = newIsbn;
}

int Ejemplar::getAnio() const
{
    return anio;
}

void Ejemplar::setAnio(int newAnio)
{
    anio = newAnio;
}

std::string Ejemplar::getEditorial() const
{
    return editorial;
}

void Ejemplar::setEditorial(const std::string &newEditorial)
{
    editorial = newEditorial;
}

Ejemplar::Ejemplar() {}

Ejemplar::Ejemplar(int isbn, int anio, std::string editorial)
{
    this->isbn = isbn;
    this->anio = anio;
    this->editorial = editorial;
}
