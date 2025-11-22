#include "libro.h"

int Libro::getId() const
{
    return Id;
}

void Libro::setId(int newId)
{
    Id = newId;
}

std::string Libro::getNombre() const
{
    return nombre;
}

void Libro::setNombre(const std::string &newNombre)
{
    nombre = newNombre;
}

std::string Libro::getAutor() const
{
    return autor;
}

void Libro::setAutor(const std::string &newAutor)
{
    autor = newAutor;
}

void Libro::agregaEjemplar(Ejemplar newEjemplar)
{
    this->ejemplares.push_back(newEjemplar);
}

std::vector<Ejemplar> Libro::getEjemplares() const
{
    return ejemplares;
}

int Libro::getCantidadEjemplares()
{
    return this->ejemplares.size();
}

Libro::Libro() {}

Libro::Libro(int Id, std::string nombre, std::string autor)
{
    this->Id = Id;
    this->nombre = nombre;
    this->autor = autor;
}
