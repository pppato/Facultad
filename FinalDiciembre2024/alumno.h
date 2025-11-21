#ifndef ALUMNO_H
#define ALUMNO_H
#include <iostream>
#include <vector>
struct AlumnoStruct{
    int codigo;
    char nombre [50];
    char tipo;
    double notas[5];
    int cantNotas;
};
class Alumno
{
private:
    int codigo;
    std::string nombre;
    std::vector<double> notas;
    char tipo;
public:
    Alumno();
    Alumno(int codigo, std::string nombre, char tipo);
    double getPromedio();
    int getCodigo() const;
    std::string getNombre() const;
    char getTipo() const;
    void AgregarNotas(const std::vector<double>& nuevasNotas);
    std::vector<double> getNotas() const;
    size_t cantidadNotas();
};

#endif // ALUMNO_H
