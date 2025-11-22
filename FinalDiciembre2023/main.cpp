#include <iostream>
#include "biblioteca.h"
using namespace std;
/*
void agrega(Biblioteca& test){
    test.agregaLibro(Libro(001,"Harry Potter y la piedra filosofal","J. K. Rowling"));
    test.agregaEjemplar(001,Ejemplar(987,2010,"SALAMANDRA"));
    test.agregaEjemplar(001,Ejemplar(987,2010,"SALAMANDRA"));
    test.agregaEjemplar(001,Ejemplar(987,2010,"SALAMANDRA"));
    test.agregaEjemplar(001,Ejemplar(999,2001,"COQUI"));
    test.agregaEjemplar(001,Ejemplar(963,1997,"OROVERDE"));

    test.agregaLibro(Libro(002,"Harry Potter y la camara secreta","J. K. Rowling"));
    test.agregaEjemplar(002,Ejemplar(966,2010,"OROVERDE"));
    test.agregaEjemplar(002,Ejemplar(966,2010,"OROVERDE"));
    test.agregaEjemplar(002,Ejemplar(966,2010,"OROVERDE"));
    test.agregaEjemplar(002,Ejemplar(966,2010,"COQUI"));

    test.agregaLibro(Libro(003,"Harry Potter y el prisionero de Azkaban","J. K. Rowling"));
    test.agregaEjemplar(003,Ejemplar(968,2010,"COQUI"));
    test.agregaEjemplar(003,Ejemplar(968,2010,"COQUI"));
    test.agregaEjemplar(003,Ejemplar(968,2010,"COQUI"));
    test.agregaEjemplar(003,Ejemplar(968,2010,"COQUI"));
}
*/

int main()
{
    Biblioteca test;

    //agrega(test);
    //test.ImprimirBin();
    test.LeerBin();
    vector<Libro>MasCantidad = test.MayorCantidadEjemplares();

    for (auto& it : MasCantidad){
        cout<<it.getNombre()<<".\n -Ejemplares: "<<it.getCantidadEjemplares()<<endl;
    }
    map<string,int> dif = test.ImpresosPorDiferentesEdit();
    for (auto& it : dif){
        cout<< it.first<<" "<<it.second<<endl;
    }
    map<string,int>edit=test.EditorialConMasImpresiones();
    for (auto& it : edit){
        cout<< it.first<<" "<<it.second<<endl;
    }

    return 0;
}
