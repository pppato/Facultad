#include "sitioweb.h"
#include <string.h>
#include <algorithm>
int SitioWeb::getPuntaje() const
{
    return puntaje;
}

bool SitioWeb::formaDirecta()
{
    auto it = std::find_if(visita.begin(),visita.end(),[](const Visitas& a) -> bool {a.getOrigen() == 'D';});
    return it != visita.end();
}

SitioWeb::SitioWeb() {}

void SitioWeb::calcularPuntaje()
{
    for (auto& it : visita){
        switch (it.getOrigen()){
        case'B':
            this->puntaje += 10*it.getTiempoPermanencia();
            break;
        case 'D':
            this->puntaje += 15*it.getTiempoPermanencia();
            break;
        case 'O':
            this->puntaje += 1*it.getTiempoPermanencia();
            break;
        }
    }
}
char *SitioWeb::getURL() const
{
    return this->URL;
}

void SitioWeb::setStruct(strVisitas v)
{
    strcpy(this->URL,v.URL);
    visita.push_back(Visitas(visit.URL,visit.tiempoPermanencia,visit.origen));
}
