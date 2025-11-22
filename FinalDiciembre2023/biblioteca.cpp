#include "biblioteca.h"
#include <algorithm>
#include <fstream>
#include <cstring>
Biblioteca::Biblioteca() {}

void Biblioteca::agregaLibro(Libro newLibro)
{
    this->libros.push_back(newLibro);
}

void Biblioteca::agregaEjemplar(int Id, Ejemplar nuevoEjemplar)
{
    auto it = std::find_if(libros.begin(),libros.end(),[Id](Libro&a){return a.getId()==Id;});
    if (it != libros.end()){
        it->agregaEjemplar(nuevoEjemplar);
    } else return;
}

bool Biblioteca::ImprimirBin()
{
    std::ofstream outlibros("libros.dat",std::ios::binary | std::ios::out | std::ios::trunc);

    for (auto& it : libros){
        Libs librost{};
        std::vector<Ejemplar> ejs = it.getEjemplares();

        strncpy(librost.autor, it.getAutor().c_str(), sizeof(librost.autor));
                librost.autor[sizeof(librost.autor)-1] = '\0';
        strncpy(librost.nombre, it.getNombre().c_str(), sizeof(librost.nombre));
                librost.nombre[sizeof(librost.nombre)-1] = '\0';
        librost.id = it.getId();
        librost.cantidadEjemplares = it.getCantidadEjemplares();

        for (int i = 0 ; i < librost.cantidadEjemplares; i++){
            librost.Ejemplares[i].anio = ejs[i].getAnio();
            librost.Ejemplares[i].isbn = ejs[i].getIsbn();
            strncpy(librost.Ejemplares[i].editorial,ejs[i].getEditorial().c_str(),sizeof(librost.Ejemplares[i].editorial));
            librost.Ejemplares[i].editorial[sizeof(librost.Ejemplares[i].editorial)-1]='\0';
        }
        outlibros.write((char*)&librost,sizeof(Libs));
    }
    outlibros.close();
    return true;
}

bool Biblioteca::LeerBin()
{
    std::ifstream in("libros.dat", std::ios::binary);
    if (!in.is_open()) return false;
    Libs lectura{};

    while (in.read((char*)&lectura,sizeof(Libs))){
        Libro nuevoLibro;

        nuevoLibro.setAutor(std::string(lectura.autor));
        nuevoLibro.setNombre(std::string(lectura.nombre));
        nuevoLibro.setId(lectura.id);

        for (int i = 0 ; i<lectura.cantidadEjemplares; i++){
        Ejemplar nuevoEjemplar;
        nuevoEjemplar.setAnio(lectura.Ejemplares[i].anio);
        nuevoEjemplar.setIsbn(lectura.Ejemplares[i].isbn);
        nuevoEjemplar.setEditorial(std::string(lectura.Ejemplares[i].editorial));
        nuevoLibro.agregaEjemplar(nuevoEjemplar);
        }

        this->agregaLibro(nuevoLibro);
    }
    in.close();
    return true;
}

bool Biblioteca::ImprimirDatos(std::string nombre)
{
    std::vector<Ejemplar> ejs;

    auto it = std::find_if(libros.begin(),libros.end(),[nombre](Libro&a){return a.getNombre()==nombre;});

    if (it!=libros.end()){
        ejs = it->getEjemplares();
    } else return false;

    std::ofstream out(nombre+"_ejemplares.txt");
    if (!out.is_open()) return false;
    for (auto&it : ejs){
        out<<"isbn: "<<it.getIsbn()<<" | "<<"editorial: "<<it.getEditorial()<<" | "<<" año: "<<it.getAnio()<<std::endl;
    }
    out.close();

    return true;

}

std::vector<Libro> Biblioteca::MayorCantidadEjemplares()
{
    int cantidad = 0;
    std::vector<Libro> MasEjemplares;
    for (auto& it : libros){
        if (it.getCantidadEjemplares()>cantidad){
            cantidad = it.getCantidadEjemplares();
        }
    }
    for (auto& it : libros){
        if (it.getCantidadEjemplares()>=cantidad){
            MasEjemplares.push_back(it);
        }
    }

    return MasEjemplares;
}

std::map<std::string, int> Biblioteca::ImpresosPorDiferentesEdit()
{
    std::map<std::string,int>dif;

    for (auto& it: libros){
        dif[it.getNombre()] = 1;
        auto ejs = it.getEjemplares();
        std::string nombreEdit = ejs[0].getEditorial();
        for (auto& it2 : ejs){
            if (it2.getEditorial() != nombreEdit){
                dif[it.getNombre()]++;
            }
        }
    }

    for (auto& it : dif){
        if (it.second==1) dif.erase(it.first);
    }

    return dif;
}

std::map<std::string, int> Biblioteca::EditorialConMasImpresiones()
{
    std::map<std::string, int>MasImpresiones;

    for (auto& it : libros){
        auto ejs = it.getEjemplares();
        for (auto& it2:ejs){
            MasImpresiones[it2.getEditorial()] = 0;
        }
        for (auto& it2:ejs){
            MasImpresiones[it2.getEditorial()]++;
        }
    }

    return MasImpresiones;

}


