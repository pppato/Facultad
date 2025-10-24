#include "monitor.h"
#include <fstream>
#include <cstring>
#include <algorithm>
Monitor::Monitor() {}

void Monitor::leerArchivo()
{
    strVisitas visit;
    bool encontrado = false;
    std::ifstream archi("info.dat",std::ios::binary);
    while (archi.read((char*)&visit, sizeof(visit))){
        for (auto& it : sitios){
            if (strcmp(it.getURL(), visit.URL) == 0){
                it.visita.push_back(Visitas(visit.URL,visit.tiempoPermanencia,visit.origen));
                encontrado = true;
                break;
            }
        }
            if (!encontrado){
            SitioWeb sitio;
            sitio.setStruct(visit);
            sitios.push_back(sitio);
            }
    }
    archi.close();
}

void Monitor::escribirArchivo()
{
    std::ofstream archi("salida.txt");
    for (auto it : sitios){
        archi<<it.getURL()<<"......"<<it.getPuntaje()<<endl;
    }
    archi.close();
}

void Monitor::actualizarPuntaje()
{
    for (auto& it : sitios){
        it.calcularPuntaje();
    }
}

std::vector<SitioWeb> Monitor::mayorPuntaje()
{
    std::sort(sitios.begin(),sitios.end(),[](SitioWeb a, SitioWeb b)-> bool {return a.getPuntaje()>b.getPuntaje();});
    std::vector<SitioWeb>mayores = sitios;
    if (mayores.size() > 5){
        mayores.resize(5);
    }
    return mayores;
}

std::vector<SitioWeb> Monitor::formaDirecta()
{
    std::vector<SitioWeb> formaDirecta;
    for (auto it : sitios){
        if (it.formaDirecta()){
            formaDirecta.push_back(it);
        }
    }
    return formaDirecta;
}

