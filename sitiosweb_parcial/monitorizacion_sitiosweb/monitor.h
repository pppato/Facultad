#ifndef MONITOR_H
#define MONITOR_H
#include "sitioweb.h"
class Monitor
{
private:
    std::vector<SitioWeb> sitios;
public:
    Monitor();
    void leerArchivo();
    void escribirArchivo();
    void actualizarPuntaje();
    std::vector<SitioWeb> mayorPuntaje();
    std::vector<SitioWeb> formaDirecta();
};

#endif // MONITOR_H
