#ifndef SITIOWEB_H
#define SITIOWEB_H
#include "visitas.h"
#include <vector>
class SitioWeb
{
private:
    char URL [20];
    std::vector<Visitas>visita;
    int puntaje = 0;
public:
    SitioWeb();
    void calcularPuntaje();
    char* getURL() const;
    void setStruct(strVisitas v);
    int getPuntaje() const;
    bool formaDirecta();
};

#endif // SITIOWEB_H
