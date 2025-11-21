#include "curso.h"
#include "algorithm"
#include <fstream>
#include <cstring>
Curso::Curso() {}

void Curso::AgregarAlumnos(std::vector<Alumno> nuevosAlumnos)
{
    this->Alumnos = nuevosAlumnos;
}

std::vector<Alumno> Curso::Aprobados()
{
    std::vector<Alumno>Aprobados;
    std::vector<double>notas;

    for (auto& it : Alumnos){
        notas = it.getNotas();
        switch (it.getTipo()){
        case 'i':{
            if (notas[0]>60.0)
                Aprobados.push_back(it);
            break;
        }
        case 'm':{
            auto it2 = std::find_if(notas.begin(),notas.end(),[](double n){ return n<60.0;});
            if (it2==notas.end() && it.getPromedio() > 70.0){
                Aprobados.push_back(it);
            }
            break;
        }
        case 'p':{
            auto it3 = std::find_if(notas.begin(),notas.end(),[](double n){ return n<70.0;});
            if (it3==notas.end() && it.getPromedio() > 80.0){
                Aprobados.push_back(it);
            }
            break;
        }
        }
        notas.clear();
    }

    return Aprobados;
}

bool Curso::GuardarAlumnosBin()
{
    std::ofstream AlumnosCurso("Alumnos.dat",std::ios::binary|std::ios::app);
    AlumnoStruct Als{};
    if (!AlumnosCurso.is_open()) return false;
    for (auto& it: Alumnos){
        Als.codigo = it.getCodigo();
        std::strncpy(Als.nombre, it.getNombre().c_str(), sizeof(Als.nombre));
        Als.nombre[sizeof(Als.nombre) - 1] = '\0';
        Als.tipo = it.getTipo();
        Als.cantNotas = it.cantidadNotas();
        auto notas = it.getNotas();
        for (int i = 0; i < Als.cantNotas ; i++){
            Als.notas[i] = notas[i];
        }
        AlumnosCurso.write((char*)&Als,sizeof(AlumnoStruct));
    }
    return true;
}

bool Curso::CambiarAlumnoInvitado(int codigo, char nuevotipo)
{
    for (auto& it : Alumnos){
        if (it.getCodigo() == codigo && it.getTipo() == 'i'){
            it = Alumno(codigo,it.getNombre(),nuevotipo);
            return true;
        }
    }
    return false;
}

std::map<std::string, double> Curso::PromediosMasAltos()
{
    std::map<std::string,double>Promedios;
    double mayorProm = 0.0;
    for (auto& it : Alumnos){
        if (it.getPromedio()>mayorProm){
            mayorProm = it.getPromedio();
        }
    }

    for (auto& it : Alumnos){
        if (it.getPromedio()>=mayorProm){
            Promedios[it.getNombre()] = it.getPromedio();
        }
    }

    return Promedios;
}

std::map<char, int> Curso::CantidadAlumnosPorTipo()
{
    std::map<char,int>CantidadPorTipo;
    CantidadPorTipo['i'] = 0;
    CantidadPorTipo['p'] = 0;
    CantidadPorTipo['m'] = 0;
    for (auto& it : Alumnos){
        CantidadPorTipo[it.getTipo()]++;
    }

    return CantidadPorTipo;

}
