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

/*void Plan::GenerarArchivoPlanes()
{
    std::ofstream basico("PlanBasico.txt");
    if (basico.is_open()) {
        basico << "Consulta médica general\n";
        basico << "Análisis de sangre básico\n";
        basico << "Atención ambulatoria\n";
        basico.close();
        std::cout << "Archivo PlanBasico.txt generado correctamente.\n";
    } else {
        std::cout << "Error al crear PlanBasico.txt\n";
    }

    std::ofstream medio("PlanMedio.txt");
    if (medio.is_open()) {
        medio << "Consulta médica general\n";
        medio << "Análisis de sangre completo\n";
        medio << "Radiografía\n";
        medio << "Electrocardiograma\n";
        medio.close();
       std:: cout << "Archivo PlanMedio.txt generado correctamente.\n";
    } else {
       std:: cout << "Error al crear PlanMedio.txt\n";
    }

   std::ofstream premium("PlanPremium.txt");
    if (premium.is_open()) {
        premium << "Consulta médica general\n";
        premium << "Análisis de sangre completo\n";
        premium << "Resonancia magnética\n";
        premium << "Cirugía menor\n";
        premium << "Internación completa\n";
        premium.close();
        std::cout << "Archivo PlanPremium.txt generado correctamente.\n";
    } else {
        std::cout << "Error al crear PlanPremium.txt\n";
    }
}*/
