#include "alumno.h"
#include <numeric>
int Alumno::getCodigo() const
{
    return codigo;
}

std::string Alumno::getNombre() const
{
    return nombre;
}

char Alumno::getTipo() const
{
    return tipo;
}

void Alumno::AgregarNotas(const std::vector<double> &nuevasNotas)
{
    this->notas = nuevasNotas;
}

std::vector<double> Alumno::getNotas() const
{
    return notas;
}

size_t Alumno::cantidadNotas()
{
    return this->notas.size();
}

Alumno::Alumno() {

}

Alumno::Alumno(int codigo, std::string nombre, char tipo)
{
    this->codigo = codigo;
    this->nombre = nombre;
    this->tipo = tipo;

    switch(tipo){
    case 'i':
        this->notas.resize(1);
        break;
    case 'm':
        this->notas.resize(3);
        break;
    case 'p':
        this->notas.resize(5);
        break;
    }

}

double Alumno::getPromedio()
{
    double promedio = 0.0;
    promedio = std::accumulate(notas.begin(),notas.end(),0.0);
    return promedio / notas.size();
}
