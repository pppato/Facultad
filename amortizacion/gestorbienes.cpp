#include "gestorbienes.h"
#include <fstream>
#include "terrenos.h"
#include "comun.h"
#include "mueble.h"
#include <cstdlib>  // rand
#include <ctime>
#include <iostream>
#include <algorithm>

std::vector<Bien *> GestorBienes::getBienes() const
{
    return Bienes;
}

GestorBienes::GestorBienes() {}

void GestorBienes::ActualizarValores()
{
    for (auto& it : Bienes){
        it->actualizarValor();
    }
}

void GestorBienes::leerArchivo()
{
    bienes b;
    Bien* Nuevo = nullptr;
    std::ifstream archi("Bienes.dat",std::ios::binary);
    while (archi.read((char*)&b, sizeof(b))){
        switch(b.tipo){
        case 't':
            Nuevo = new Terrenos;
            std::cout<<"ok t"<<std::endl;
            break;
        case 'c':
            Nuevo = new Comun;
            std::cout<<"ok c"<<std::endl;
            break;
        case 'm':
            Nuevo = new Mueble;
            std::cout<<"ok m"<<std::endl;
            break;
        }
        Nuevo->setStruct(b);
        Bienes.push_back(Nuevo);
    }
    archi.close();
}

void GestorBienes::escribirArchivo()
{
    std::ofstream out("valores.dat");
    if (!out.is_open()) return;
    for (auto& it : Bienes){
        out<<it->getCod()<<" "<<it->getTipo()<<"........$"<<it->getValor()<<'\n';
    }
    out.close();
}

void GestorBienes::genera()
{
    std::ofstream archi("bienes.dat", std::ios::binary);
    if (!archi) {
        std::cout << "Error al crear el archivo.\n";
        return;
    }
    std::srand(std::time(nullptr));
    const char tipos[] = {'t', 'c', 'm'};
    int cantidad = 10 + std::rand() % 21;
    for (int i = 0; i < cantidad; ++i) {
        bienes b;
        b.cod = i + 1;
        b.tipo = tipos[std::rand() % 3];
        b.valor = 10000 + (std::rand() % 90001);
        archi.write(reinterpret_cast<char*>(&b), sizeof(bienes));
    }
    archi.close();
    std::cout << "Archivo 'bienes.dat' generado con " << cantidad << " registros." << std::endl;
}

std::vector<Bien *> GestorBienes::MayorValor()
{
    std::vector<Bien *>mayores;
    std::sort(Bienes.begin(),Bienes.end(),[](Bien*I,Bien*J)->bool{return I->getValor()>J->getValor();});
    double mayor = (*Bienes.begin())->getValor();
    std::copy_if(Bienes.begin(),Bienes.end(),std::back_inserter(mayores),[&mayor](Bien*I)->bool{return I->getValor()>=mayor;});
    return mayores;
}

std::map<char, double> GestorBienes::PorTipo()
{
    std::map<char,double> tipos{
        {'t', 0.0},
        {'c', 0.0},
        {'m', 0.0}
    };

    for (auto& it : Bienes) {
        tipos[it->getTipo()] += it->getValor();
    }

    return tipos;
}
