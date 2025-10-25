#include <iostream>
#include "gestor.h"
using namespace std;

int main()
{
    Gestor g;

    g.leerArchivo();
    g.escribirArchivo();
    vector<Produccion>m;
    m = g.mayorValoracion();
    for (auto&it : m){
        cout<<it.getNombre()<<endl;
    }
    cout<<"//"<<endl;
    m = g.masVotadas();
    for (auto&it : m){
        cout<<it.getNombre()<<endl;
    }
    std::map<std::string,int>cantidad;
    cantidad = g.cantidadVotos();
    cout<<"pelis: "<<cantidad["peliculas"]<<endl<<"series: "<<cantidad["series"];
    return 0;
}
