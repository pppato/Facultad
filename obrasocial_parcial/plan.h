#ifndef PLAN_H
#define PLAN_H
#include<string>
#include<vector>
class Plan
{
private:
    std::string NombreArchivo;
    std::vector<std::string> p;
public:
    Plan();
    Plan(std::string NombreArchivo);
    std::vector<std::string> getPrestaciones();
    void leerArchivo();
    bool verifPrestacion(std::string p);
   // static void GenerarArchivoPlanes();

};

#endif // PLAN_H
