#include "empresa.h"
#include <algorithm>
#include <fstream>
#include <cstring>
bool Empresa::tienePermiso(int id, std::string fun)
{
    auto it = std::find_if(empleados.begin(),empleados.end(),[id](Usuario&a){return a.getId() == id;});
    if (it != empleados.end()){
        return it->tienePermiso(fun);
    } else return false;
}

bool Empresa::Guardar()
{
    std::ofstream usuarios("info.dat",std::ios::binary);

    if (!usuarios.is_open()) return false;

    for (auto& it : empleados){
        Usuarios us{};

        strncpy(us.nombre,it.getNombre(),sizeof(us.nombre));
        us.nombre[sizeof(us.nombre)-1] = '\0';

        us.id = it.getId();

        strncpy(us.nombreCargo,it.getNombreCargo().c_str(),sizeof(us.nombreCargo));
        us.nombreCargo[sizeof(us.nombreCargo)-1]='\0';

        usuarios.write((char*)&us,sizeof(Usuarios));
    }

    usuarios.close();

    std::ofstream archicargos("infocargos.dat",std::ios::binary);

    if (!archicargos.is_open()) return false;

    for (auto& it : cargos){
        cargostr c;
        auto f = it.getFunciones();
        c.cantidadfunciones = f.size();

        strncpy(c.nombre,it.getNombre().c_str(),sizeof(c.nombre));
        c.nombre[sizeof(c.nombre)-1]='\0';

        for (int i = 0; i < f.size(); i++){
            strncpy(c.funciones[i],f[i].c_str(),49);
            c.funciones[i][49]='\0';
        }
        archicargos.write((char*)&c,sizeof(cargostr));
    }

    archicargos.close();

    return true;

}

void Empresa::InstanciarCargos()
{
    cargos.push_back(Cargo("Administrador General",
                           {"gestionar usuarios", "asignar permisos", "ver reportes", "modificar configuraciones", "bailar"}));

    cargos.push_back(Cargo("Supervisor",
                           {"ver reportes", "gestionar usuarios", "ver stock"}));

    cargos.push_back(Cargo("Ventas",
                           {"ver stock", "realizar venta", "generar factura", "consultar clientes"}));

    cargos.push_back(Cargo("Compras",
                           {"ver proveedores", "realizar compra", "generar factura", "actualizar precio"}));

    cargos.push_back(Cargo("Deposito",
                           {"ver stock", "controlar inventario", "registrar ingreso mercaderia"}));

    cargos.push_back(Cargo("Atencion al Cliente",
                           {"abrir ticket", "responder ticket", "cerrar ticket", "consultar clientes"}));

    cargos.push_back(Cargo("RRHH",
                           {"cargar empleado", "registrar asistencia", "ver reportes"}));

    cargos.push_back(Cargo("Finanzas",
                           {"generar balance", "registrar pago", "emitir comprobante", "ver proveedores"}));

    cargos.push_back(Cargo("Soporte Tecnico",
                           {"diagnosticar equipo", "cerrar incidente", "abrir ticket"}));
}

void Empresa::InstanciarEmpleados()
{
    empleados.push_back(Usuario("Michael Scott",        201, this->cargos[0]));
    empleados.push_back(Usuario("Dwight Schrute",       202, this->cargos[1]));
    empleados.push_back(Usuario("Jim Halpert",          203, this->cargos[2]));
    empleados.push_back(Usuario("Pam Beesly",           204, this->cargos[5]));
    empleados.push_back(Usuario("Angela Martin",        205, this->cargos[7]));
    empleados.push_back(Usuario("Oscar Martinez",       206, this->cargos[7]));
    empleados.push_back(Usuario("Kevin Malone",         207, this->cargos[7]));
    empleados.push_back(Usuario("Stanley Hudson",       208, this->cargos[2]));
    empleados.push_back(Usuario("Phyllis Vance",        209, this->cargos[2]));
    empleados.push_back(Usuario("Creed Bratton",        210, this->cargos[3]));
    empleados.push_back(Usuario("Meredith Palmer",      211, this->cargos[3]));
    empleados.push_back(Usuario("Toby Flenderson",      212, this->cargos[6]));
    empleados.push_back(Usuario("Kelly Kapoor",         213, this->cargos[5]));
    empleados.push_back(Usuario("Ryan Howard",          214, this->cargos[2]));
    empleados.push_back(Usuario("Darryl Philbin",       215, this->cargos[4]));
    empleados.push_back(Usuario("Holly Flax",           216, this->cargos[6]));
}

std::map<std::string, int> Empresa::CargosConMasPermisos()
{
    std::map<std::string, int>maspermis;
    int max = 0;
    for (auto& it : cargos){
        if (it.cantidadPermisos() > 0){
            max = it.cantidadPermisos();
        }
    }
    for (auto& it :cargos){
        if (it.cantidadPermisos()>max){
            maspermis[it.getNombre()] = it.cantidadPermisos();
        }
    }

    return maspermis;
}

std::map<std::string, int> Empresa::PermisosEnVariosCargos()
{
    std::map<std::string, int>PermisosEnVarios;
    for (auto& it : cargos){
        std::vector<std::string>permisos = it.getFunciones();
        for (const std::string&it2 : permisos){
            PermisosEnVarios[it2]++;
        }
    }
    return PermisosEnVarios;
}

std::map<std::string, int> Empresa::UsuariosConMasPermisos()
{
    std::map<std::string, int>UsuariosConMasPermisos;

    std::sort(empleados.begin(),empleados.end(),[](Usuario&a,Usuario&b){return a.getCantidadPermisos() > b.getCantidadPermisos();});
    int max = empleados.begin()->getCantidadPermisos();
    for (auto&it : empleados){
        if (it.getCantidadPermisos() >= max){
        UsuariosConMasPermisos[it.getNombre()] = it.getCantidadPermisos();
        }
    }
    return UsuariosConMasPermisos;
}

Empresa::Empresa() {}
