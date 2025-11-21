#include <iostream>
#include "alumno.h"
#include "curso.h"
using namespace std;

int main()
{
    Alumno P = Alumno(001,"Patricio",'i');//inv
    Alumno S = Alumno(002,"Sofia",'p');//pre
    Alumno M = Alumno(003,"Marcelo",'m');//med
    Alumno L = Alumno(004,"Luciano",'i');
    Alumno C = Alumno(005,"Celia",'p');
    Alumno G = Alumno(006,"Giuliana",'m');
    Alumno N = Alumno(007,"Nahuel",'p');

    P.AgregarNotas({63.5});
    S.AgregarNotas({70.7, 80.3, 75.5, 78.2, 71.3});
    M.AgregarNotas({50.5, 65.8, 68.5});
    L.AgregarNotas({73.0});
    C.AgregarNotas({68.9, 71.2, 69.5, 77.3, 66.6});
    G.AgregarNotas({90.9,88.6,99.9});
    N.AgregarNotas({90.9,87.5,88.6,87.3,99.1});

    Curso test;

    test.AgregarAlumnos({P,S,M,L,C,G,N});

    vector<Alumno> Aprobaron = test.Aprobados();

    for (auto& it : Aprobaron){
        cout<<it.getNombre()<<" \n";
    }

    cout<<'\n';

    auto alumnosportipo = test.CantidadAlumnosPorTipo();

    map<string,double> promedios = test.PromediosMasAltos();

    for (auto& it : promedios){
        cout<<it.first<<": "<<it.second<<'\n';
    }

    cout<<"invitados: "<<alumnosportipo['i']<<'\n';
    cout<<"medios: "<<alumnosportipo['m']<<'\n';
    cout<<"premium: "<<alumnosportipo['p']<<'\n';

    cout<<test.CambiarAlumnoInvitado(004,'p');

    return 0;
}
