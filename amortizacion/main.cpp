#include <iostream>
#include "gestorbienes.h"

using namespace std;

int main()
{   //test
    GestorBienes MiGestor;
    MiGestor.leerArchivo();
    vector<Bien*>b;
    b = MiGestor.MayorValor();
    for(auto&i : b){
        cout<<i->getCod()<<"    "<<i->getValor()<<endl;
    }
    map<char,double>tipos;
    tipos = MiGestor.PorTipo();
    for (auto& [tipo, valor] : tipos) {
        std::cout << tipo << " -> " << valor << std::endl;
    }
    MiGestor.escribirArchivo();
    return 0;
}
