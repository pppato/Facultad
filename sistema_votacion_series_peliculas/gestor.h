#ifndef GESTOR_H
#define GESTOR_H
#include "produccion.h"
#include <map>
struct Voto{
    int nro;
    int voto;
};
class Gestor
{
private:
    std::vector<Produccion>producciones;
public:
    Gestor();
    std::vector<Produccion> mayorValoracion();
    std::vector<Produccion> masVotadas();
    std::map<std::string,int> cantidadVotos();
    void leerArchivo();
    void escribirArchivo();


};

#endif // GESTOR_H
