//José Julián Brenes Garro
//c.2022272865
//Estructuras de Datos

#include "ListaSimple.h"
using namespace std;


lista::~lista() {
	pnodo aux;

	while(primero) {
		aux = primero;
		primero = primero->siguiente;
		delete aux;
	}
	primero= NULL;
}

int lista::largoLista() {
	int cont=0;

	pnodo aux= primero;
	if(ListaVacia()) {
		return cont;
	} else {
		while(aux!=NULL) {
			aux=aux->siguiente;
			cont++;
		}
		return cont;
		cout<< endl;
	}

}

void lista::InsertarInicio(string v) { //3 10 265
	if (ListaVacia()) {

		primero = new nodo(v);//6

	} else {
		//primera forma
//  primero=new nodo (v,primero);
		//segunda forma
		pnodo nuevo=new nodo(v);
		nuevo->siguiente=primero;
		primero=nuevo;




	}
}

void lista::InsertarFinal(string v) { //76
	if (ListaVacia())
		primero = new nodo(v);
	else {
		//primera forma
		//pnodo aux = primero;
		//  while ( aux->siguiente != NULL)
		//   aux= aux->siguiente;
		//  aux->siguiente=new nodo(v);

		//segunda forma
		pnodo aux = primero;
		while ( aux->siguiente != NULL)
			aux= aux->siguiente;
		pnodo nuevo=new nodo(v);
		aux->siguiente=nuevo;
	}
}


void lista::InsertarPos(string v,int pos) {
	if (ListaVacia())
		primero = new nodo(v);
	else {
		if(pos <=1) {
			//OPcion1
			pnodo nuevo = new nodo(v);
			nuevo->siguiente= primero;
			primero= nuevo;
			//OPcion 2
			//InsertarInicio(v);
		} else {
			nodo *aux= primero;
			int i =2;
			while((i != pos )&&(aux->siguiente!= NULL)) {
				i++;
				aux=aux->siguiente;
			}
			pnodo nuevo= new nodo(v);
			nuevo->siguiente=aux->siguiente;
			aux->siguiente=nuevo;

		}
	}
}

void lista::BorrarFinal() {
	if (ListaVacia()) {
		cout << "No hay elementos en la lista:" << endl;

	} else {

		if (primero->siguiente == NULL) {
			pnodo temp=primero;
			primero= NULL;
			delete temp;;
		} else {

			pnodo aux = primero;
			while (aux->siguiente->siguiente != NULL) {
				aux = aux->siguiente;

			}

			pnodo temp = aux->siguiente;
			aux->siguiente= NULL;


			delete temp;
		}
	}
}

void lista::BorrarInicio() {
	if (ListaVacia()) {
		cout << "No hay elementos en la lista:" << endl;

	} else {
		if (primero->siguiente == NULL) {
			pnodo temp=primero;
			primero= NULL;
			delete temp;
		} else {

			pnodo aux = primero;
			primero=primero->siguiente;
			delete aux;
		}
	}
}



void lista:: borrarPosicion(int pos) {
	if(ListaVacia()) {
		cout << "Lista vacia" <<endl;
	} else {
		if((pos>largoLista())||(pos<0)) {
			cout << "Error en posicion" << endl;
		} else {
			if(pos==1) {
				pnodo temp=primero;
				primero=primero->siguiente;
				delete temp; //BorrarInicio();
			} else {
				int cont=2;
				pnodo aux=  primero;
				while(cont<pos) {
					aux=aux->siguiente;
					cont++;
				}
				pnodo temp=aux->siguiente;
				aux->siguiente=aux->siguiente->siguiente;
				delete temp;
			}
		}
	}

}


void lista::Mostrar() {
	nodo *aux;
	if (primero== NULL)
		cout << "No hay elementos AQUI";
	else {


		aux = primero;
		while(aux) {
			cout << aux->valor << "-> ";
			aux = aux->siguiente;
		}
		cout << endl;
	}
}


