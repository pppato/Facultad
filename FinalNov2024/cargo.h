#ifndef CARGO_H
#define CARGO_H
#include <vector>
#include <string>
struct cargostr{
    int cantidadfunciones;
    char nombre[50];
    char funciones[10][50];
};

class Cargo
{
private:
    std::vector<std::string>funciones;
    std::string nombre;
public:
    Cargo();
    Cargo(std::string nombre, std::vector<std::string>funciones);

    bool tienePermiso(std::string fun);

    std::vector<std::string> getFunciones() const;
    void setFunciones(const std::vector<std::string> &newFunciones);
    std::string getNombre() const;
    void setNombre(const std::string &newNombre);
    int cantidadPermisos ();
};

#endif // CARGO_H
