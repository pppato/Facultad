#include "gestor.h"
#include<iostream>
#include<fstream>
#include <ctime>
#include <cstdlib>
#include<algorithm>
Gestor::Gestor() {}

std::vector<Produccion> Gestor::mayorValoracion()
{
    std::sort(producciones.begin(),producciones.end(),[](Produccion&p,Produccion&p2)->bool{return p.getPromedio()>p2.getPromedio();});
    std::vector<Produccion>mayorvaloracion = producciones;
    if (mayorvaloracion.size()>5){
        mayorvaloracion.resize(5);}
    return mayorvaloracion;
}

std::vector<Produccion> Gestor::masVotadas()
{
    std::vector<Produccion>MV;
    int VM=0;
    for (auto& it : producciones){
        if (it.getCantVotos()>VM){
            VM = it.getCantVotos();
        }
    }
    std::copy_if(producciones.begin(),producciones.end(),std::back_inserter(MV),[&VM](Produccion& a)->bool{return a.getCantVotos()==VM;});
    return MV;
}

std::map<std::string, int> Gestor::cantidadVotos()
{
    std::map<std::string,int>cantidad;
    cantidad["peliculas"]=0;
    cantidad["series"]=0;
    for (auto &it : producciones){
        if (it.getTipo() == 'p'){
            cantidad["peliculas"]+=it.getCantVotos();
        }
        if (it.getTipo() == 's'){
            cantidad["series"]+=it.getCantVotos();
        }
    }
    return cantidad;
}

void Gestor::leerArchivo()
{
    Prod p;
    Voto v;
    Produccion produ;
    std::ifstream prod("producciones.dat",std::ios::binary);
    std::ifstream voto("votos.dat",std::ios::binary);
    while (prod.read((char*)&p,sizeof(p))){
        produ.setStruct(p);
        producciones.push_back(produ);
    }
    while (voto.read((char*)&v,sizeof(v))){
        auto it = std::find_if(producciones.begin(),producciones.end(),[&v](Produccion& prd) { return prd.getNro() == v.nro; });
        if (it!=producciones.end()){
            it->agregarVoto(v.voto);
        }
    }
    prod.close();
    voto.close();
}

void Gestor::escribirArchivo()
{
    std::ofstream out("valoracion.txt");
    for(auto& it : producciones){
        it.promediar();//esta mal hacer esto aca
        out<<it.getNombre()<<"......"<<it.getPromedio()<<std::endl;
    }
    out.close();
}
