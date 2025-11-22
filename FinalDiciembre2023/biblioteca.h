#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include "libro.h"
#include <map>
class Biblioteca
{
private:
    std::vector<Libro> libros;
public:
    Biblioteca();
    void agregaLibro(Libro newLibro);
    void agregaEjemplar(int Id, Ejemplar nuevoEjemplar);
    bool ImprimirBin();
    bool LeerBin();
    bool ImprimirDatos(std::string nombre);
    std::vector<Libro> MayorCantidadEjemplares();
    std::map<std::string,int> ImpresosPorDiferentesEdit();
    std::map<std::string,int> EditorialConMasImpresiones();
};

#endif // BIBLIOTECA_H
