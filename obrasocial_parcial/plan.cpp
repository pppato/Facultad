#include "plan.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
Plan::Plan(std::string NombreArchivo) {
    this->NombreArchivo = NombreArchivo;
    this->leerArchivo();
}

std::vector<std::string> Plan::getPrestaciones()
{
    return this->p;
}

void Plan::leerArchivo()
{
    std::ifstream Archi (this->NombreArchivo);
    std::string buffer;
    while (getline(Archi,buffer)){
        this->p.push_back(buffer);
    }
    Archi.close();

}

bool Plan::verifPrestacion(std::string p)
{
    bool existe = std::find(this->p.begin(),this->p.end(),p) != this->p.end();
    return existe;
}


