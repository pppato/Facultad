#include "obrasocial.h"
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <iostream>
void ObraSocial::CrearPlanes()
{
    Plan* PlanBasico = new Plan("PlanBasico.txt");
    Plan* PlanMedio = new Plan("PlanMedio.txt");
    Plan* PlanPremium = new Plan("PlanPremium.txt");

    this->Planes['b'] = PlanBasico;
    this->Planes['m'] = PlanMedio;
    this->Planes['p'] = PlanPremium;
}

ObraSocial::ObraSocial() {
    this->CrearPlanes();
    this->leerUsuarios();
    //this->GenerarUsuariosBinario();
}

void ObraSocial::leerUsuarios()
{
    std::ifstream Archi("usuarios.dat",std::ios::binary);
    DatosUsuarios str;
    Usuarios Us;
    if (!Archi.is_open()) {std::cout<<"error";};

    while (Archi.read((char*)&str,sizeof(str)))
    {
        switch (str.tipo){
        case 'b':
            Us.setPlan(this->Planes['b']);
            break;
        case 'm':
            Us.setPlan(this->Planes['m']);
            break;
        case 'p':
            Us.setPlan(this->Planes['p']);
            break;
        }
        Us.setStruct(str);
        this->usuario.push_back(Us);
    }
    Archi.close();
}

std::vector<std::string> ObraSocial::getPrestaciones()
{
    std::vector<std::string> prestaciones;
    for (char tipo : {'b','m','p'}){
        if (this->Planes.count(tipo)){
            std::vector<std::string> delPlan = this->Planes[tipo]->getPrestaciones();
            prestaciones.insert(prestaciones.end(),delPlan.begin(),delPlan.end());
        }
    }
    return prestaciones;
}

std::vector<Usuarios> ObraSocial::MasActivos()
{
    std::vector<Usuarios>Activos = this->usuario;
    std::sort(Activos.begin(),Activos.end(),
              [](const Usuarios& a, const Usuarios& b)
              {return a.getCantidad()>b.getCantidad();});

    if (Activos.size()>5){
        Activos.resize(5);
    }

    return Activos;

}

std::vector<Usuarios> ObraSocial::getUsuarios() const
{
    return this->usuario;
}
