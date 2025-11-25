#ifndef EMPRESA_H
#define EMPRESA_H
#include "usuario.h"
#include <map>
class Empresa
{
private:
    std::vector<Usuario>empleados;
    std::vector<Cargo>cargos;
public:
    bool tienePermiso(int id, std::string fun);
    bool Guardar();
    void InstanciarCargos();
    void InstanciarEmpleados();
    std::map<std::string, int> CargosConMasPermisos();
    std::map<std::string, int> PermisosEnVariosCargos();
    std::map<std::string, int> UsuariosConMasPermisos();


    Empresa();
};

#endif // EMPRESA_H
