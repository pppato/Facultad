#ifndef CURSO_H
#define CURSO_H
#include "alumno.h"
#include <map>
class Curso
{
private:
    std::vector<Alumno>Alumnos;
public:
    Curso();
    void AgregarAlumnos(std::vector<Alumno>nuevosAlumnos);
    std::vector<Alumno> Aprobados();
    bool GuardarAlumnosBin();
    bool CambiarAlumnoInvitado(int codigo, char nuevotipo);
    std::map<std::string,double> PromediosMasAltos();
    std::map<char,int> CantidadAlumnosPorTipo();
};

#endif // CURSO_H
