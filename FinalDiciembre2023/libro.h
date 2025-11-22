#ifndef LIBRO_H
#define LIBRO_H
#include "ejemplar.h"
#include <vector>

struct Libs{
    int id;
    char nombre[100];
    char autor[100];
    int cantidadEjemplares;
    Ejms Ejemplares [10];
};

class Libro
{
private:
    int Id;
    std::string nombre;
    std::string autor;
    std::vector<Ejemplar> ejemplares;
public:
    Libro();
    Libro(int Id, std::string nombre, std::string autor);
    int getId() const;
    void setId(int newId);

    std::string getNombre() const;
    void setNombre(const std::string &newNombre);

    std::string getAutor() const;
    void setAutor(const std::string &newAutor);

    void agregaEjemplar(Ejemplar newEjemplar);

    std::vector<Ejemplar> getEjemplares() const;

    int getCantidadEjemplares();
};

#endif // LIBRO_H
