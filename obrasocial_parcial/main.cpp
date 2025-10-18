#include <iostream>
#include "obrasocial.h"
#include "plan.h"
#include <vector>
#include "usuarios.h"
using namespace std;

int main()
{
   // Plan::GenerarArchivoPlanes();
    ObraSocial miObra;

    vector<string>Us;
    Us = miObra.getPrestaciones();

    for(auto& it : Us ){
        cout<<it<<endl;
    }

    vector<Usuarios>MasAct;
    MasAct = miObra.MasActivos();


    for(auto& it : MasAct ){
        cout<<it.getNombre()<<" "<<it.getCantidad()<<endl;
    }

    return 0;
}
