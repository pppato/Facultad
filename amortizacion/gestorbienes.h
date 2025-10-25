#ifndef GESTORBIENES_H
#define GESTORBIENES_H
#include "Bien.h"
#include <vector>
#include <map>
class GestorBienes
{
private:
    std::vector<Bien*>Bienes;
public:
    GestorBienes();
    void ActualizarValores();
    void leerArchivo();
    void escribirArchivo();
    void genera();
    std::vector<Bien*>MayorValor();
    std::map<char,double>PorTipo();
    std::vector<Bien *> getBienes() const;
};

#endif // GESTORBIENES_H
