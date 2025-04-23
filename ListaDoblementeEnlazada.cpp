#include <iostream>
using namespace std;
struct NodoListaDE{
	int dato;
	struct NodoListaDE* Anterior = NULL;
	struct NodoListaDE* Siguiente = NULL;
};

typedef struct NodoListaDE NListaDE;

bool isEmpty (NListaDE* Head){
	
	if (Head == NULL){
		return true;
	} else {
		return false;
	}
	
}

void Add(NListaDE*& Head, int dato){
	
	NListaDE* NuevoNodo = new (NListaDE);
	NuevoNodo->dato=dato;
	NuevoNodo->Siguiente = Head;
	if (Head!=NULL){
		Head->Anterior = NuevoNodo;
	}
	Head=NuevoNodo;
}	

void AddLast(NListaDE*& Head, int dato){
	
	NListaDE* NuevoNodo = new (NListaDE);
	NuevoNodo->dato = dato;
	
	if (Head==NULL){
		Head = NuevoNodo;
	} else {
		NListaDE* Aux = Head;
		while (Aux->Siguiente != NULL){
			Aux = Aux->Siguiente;
		}
		Aux->Siguiente = NuevoNodo;
		NuevoNodo->Anterior = Aux;
	}
	
}

void WriteLDE(NListaDE* Head){
	
	NListaDE* Aux = Head;
	while (Aux!=NULL){
		cout<<Aux->dato<<" ";
		Aux = Aux->Siguiente;
	}
	
}
	
void WriteLastFirst(NListaDE* Head){

	NListaDE* Aux = Head;
	
	while (Aux->Siguiente != NULL){
		Aux = Aux->Siguiente;
	}
	
	while (Aux != NULL){
		cout<<Aux->dato<<" ";
		Aux = Aux->Anterior;
	}

	
}	
int main(int argc, char *argv[]) {
	
	NListaDE* Head = NULL;

	Add(Head, 12);
	Add(Head, 9);
	Add(Head, 6);
	Add(Head, 3);
	Add(Head, 0);
	AddLast(Head, 8);
	Add(Head,5);
	Add(Head,4);


	cout<<endl;
	WriteLDE(Head);
	cout<<endl;
	WriteLastFirst(Head);



	
	return 0;
}

