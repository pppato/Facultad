#include <iostream>
#include "empresa.h"
using namespace std;

int main()
{
    Empresa test;

    test.InstanciarCargos();
    test.InstanciarEmpleados();
    cout<<test.tienePermiso(208,"registrar pago")<<'\n';
  //cout<<test.Guardar();

    map<string,int> maspermisos=test.CargosConMasPermisos();

    for (auto&it:maspermisos){
        cout<<it.first<<" "<<it.second<<endl;
    }

    map<string,int> permisosvarios=test.PermisosEnVariosCargos();
    cout<<'\n';
    for(auto&it : permisosvarios){
        if (it.second != 1){
        cout<<it.first<<" "<<it.second<<endl;
        }
    }

    map<string,int>us = test.UsuariosConMasPermisos();
    cout<<'\n';
    for (auto&it : us){
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;
}
