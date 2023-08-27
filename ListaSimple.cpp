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

void lista::InsertarInicio(int v) { //3 10 265
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

void lista::InsertarFinal(int v) { //76
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


void lista::InsertarPos(int v,int pos) {
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


void lista::Sumanum(int num) { //23456
	if (num == 0)
		cout << "Suma igual a 0";
	else {

		while (num!=0) {

			int temp=num%10;
			InsertarInicio(temp);
			num=num/10;
		}
		int suma=0;
		pnodo aux=primero;
		while(aux !=NULL) {
			suma=suma+aux->valor;
			aux=aux->siguiente;
		}
		cout<<suma<<endl;
	}

}

int lista::contarPares(int num) {
	if (num == 0) {
		return 1;
	}
	lista listatemp;
	int suma = 0;
	while (num!=0) {
		int temp=num%10;
		listatemp.InsertarInicio(temp);
		num=num/10;
	}
	pnodo aux = listatemp.primero;
	while (aux!=NULL) {
		if (aux->valor%2==0) {
			suma++;
		}
		aux = aux->siguiente;
	}
	return suma;
}

void lista::promedioDigitos(int num) {
	if (num == 0) {
		cout<<"El promedio es: "<<0;
		return;
	}
	lista listatemp;
	int suma = 0;
	int cuenta = 0;
	while (num!=0) {
		int temp=num%10;
		listatemp.InsertarInicio(temp);
		num=num/10;
		cuenta++;
		suma = suma+temp;
	}
	cout<<"El promedio es: "<<(suma*1.0)/cuenta;
	return;
}


void lista::invertirLista() {
	pnodo ant;
	pnodo sig=primero;
	while (primero!=NULL) {
		primero = primero ->siguiente;
		sig ->siguiente =ant;
		ant =sig;
		sig =primero;
	}
	primero =ant;
}

bool lista::buscarNum(int num) {
	pnodo aux = primero;
	while (aux!=NULL) {
		if (num==aux->valor) {
			return true;
		}
		aux= aux->siguiente;
	}
	return false;
}

bool lista::buscarNumPos (int num, int pos) {
	if(ListaVacia()) {
		return false;
	} else {
		if((pos>largoLista())||(pos<0)) {
			return false;
		} else {
			int cont=1;
			pnodo aux=  primero;
			while(cont<pos) {
				aux=aux->siguiente;
				cont++;
			}
			if (aux->valor==num) {
				return true;
			}
			return false;
		}
	}
}

void lista::sumaListasIgual(lista *L2) {
	pnodo aux1 = primero;
	pnodo aux2 = L2->primero;
	lista listaSuma;

	while (aux1!=NULL) {
		listaSuma.InsertarFinal(aux1->valor+aux2->valor);
		aux1= aux1->siguiente;
		aux2= aux2->siguiente;
	}

	listaSuma.Mostrar();
}

void lista::sumaListasDiff(lista *L2) {
	pnodo aux1,aux2;
	lista listaSuma;
	if(largoLista()>L2->largoLista()) {
		aux1 = primero;
		aux2 = L2->primero;
	} else {
		aux1 = L2->primero;
		aux2 = primero;
	}

	while (aux1!=NULL) {
		while (aux2!=NULL) {
			listaSuma.InsertarFinal(aux1->valor+aux2->valor);
			aux1= aux1->siguiente;
			aux2= aux2->siguiente;
		}
		listaSuma.InsertarFinal(aux1->valor);
		aux1= aux1->siguiente;
	}

	listaSuma.Mostrar();
}

void lista::sumarParMultImp(int num) {
	if (num == 0) {
		cout<<"Pares: "<<1<<endl;
		cout<<"Impares: "<<0<<endl;
		return;
	}
	int suma = 0, multi = 1;
	lista listatemp;
	bool bandera = false;

	while (num!=0) {
		int temp=num%10;
		listatemp.InsertarInicio(temp);
		num=num/10;
	}
	pnodo aux = listatemp.primero;
	while (aux!=NULL) {
		if (aux->valor%2==0) {
			suma = suma + aux->valor;
		} else {
			multi = multi * aux->valor;
			bandera= true;
		}
		aux = aux->siguiente;
	}
	cout<<"Pares: "<<suma<<endl;
	if (bandera==true) {
		cout<<"Impares: "<<multi<<endl;
	} else {
		cout<<"Impares: "<<0<<endl;
	}
}

void lista::sumaNodosLista(int num1, int num2) {

	lista listatemp1, listatemp2, listatemp3;
	if (num1 == 0) {
		listatemp1.InsertarInicio(0);
	} else {
		while (num1!=0) {
			int temp1=num1%10;
			num1=num1/10;
			listatemp1.InsertarInicio(temp1);
		}
	}
	if (num2==0) {
		listatemp2.InsertarInicio(0);
	} else {
		while (num2!=0) {
			int temp2=num2%10;
			num2=num2/10;
			listatemp2.InsertarInicio(temp2);
		}
	}

	if (listatemp1.largoLista()!=listatemp2.largoLista()) {
		cout<<endl<<"Los numeros son de distinto largo";
		return;
	}

	pnodo aux1 = listatemp1.primero;
	pnodo aux2 = listatemp2.primero;

	cout<<endl<<"Lista 1: ";
	listatemp1.Mostrar();
	cout<<endl<<"Lista 2: ";
	listatemp2.Mostrar();

	while (aux1!=NULL) {
		listatemp3.InsertarFinal(aux1->valor+aux2->valor);
		aux1 = aux1->siguiente;
		aux2 = aux2->siguiente;
	}
	cout<<endl<<"Lista suma: ";
	listatemp3.Mostrar();


}

void lista::potenciaParesImpares(int num) {
	if (num == 0) {
		cout<<"Lista Evaluada: "<<endl;
		return;
	}
	lista listatemp;

	while (num!=0) {
		int temp=num%10;
		num=num/10;
		if (temp%2==0) {
			listatemp.InsertarInicio(temp*temp*temp);
		} else {
			listatemp.InsertarInicio(temp*temp);
		}
	}

	listatemp.Mostrar();
}

int lista::contDigitos(int num) {
	if (num == 0) {
		return 1;
	}
	int cont= 0 ;
	while (num!=0) {
		num=num/10;
		cont++;
	}
	return cont;
}

void lista::centroSuma(int num) {
	int largoNum = contDigitos(num);
	if (largoNum%2==0) {
		cout<<"Ingrese un numero de cantidad de digitos par"<<endl;
		return;
	}
	if (num<0) {
		cout<<"Ingrese un numero positivo"<<endl;
		return;
	}

	lista listatemp;

	if (num==0) {
		listatemp.InsertarInicio(0);
	} else {
		while (num!=0) {
			int temp=num%10;
			num=num/10;
			listatemp.InsertarInicio(temp);
		}
	}

	cout<<endl<<"Lista: ";
	listatemp.Mostrar();

	int mitad = ((largoNum-1)/2)+1;
	pnodo aux = listatemp.primero;
	int cont=0, valorMitad=0;

	while (aux!=NULL) {
		if (cont+1==mitad) {
			valorMitad = aux->valor;
		} else {
			aux->valor= aux->valor+valorMitad;
		}
		aux = aux->siguiente;
		cont++;
	}
	cont=0;
	aux = listatemp.primero;
	while (cont+1!=mitad) {
		aux->valor= aux->valor+valorMitad;
		aux = aux->siguiente;
		cont++;
	}
	cout<<endl<<"Lista Evaluada: ";
	listatemp.Mostrar();
}

void lista::mezclar (int num1, int num2) {

	lista listatemp1, listatemp2;

	if(contDigitos(num1)!=6 || contDigitos(num2)!=6) {
		cout<<"Ingrese un numero de 6 digitos"<<endl;
		return;
	}
	if (num1<0 || num2<0) {
		cout<<"Ingrese numeros positivo"<<endl;
		return;
	}
	if (num1 == 0) {
		listatemp1.InsertarInicio(0);
	} else {
		while (num1!=0) {
			int temp1=num1%10;
			num1=num1/10;
			listatemp1.InsertarInicio(temp1);
		}
	}
	if (num2==0) {
		listatemp2.InsertarInicio(0);
	} else {
		while (num2!=0) {
			int temp2=num2%10;
			num2=num2/10;
			listatemp2.InsertarInicio(temp2);
		}
	}
	cout<<endl<<"Lista 1: ";
	listatemp1.Mostrar();
	cout<<endl<<"Lista 2: ";
	listatemp2.Mostrar();

/*
	int cont1=1, cont2=1, objLista2=2;
	pnodo aux1 = listatemp1.primero;
	pnodo aux2 = listatemp2.primero;
	pnodo temp2 = listatemp2.primero;
	int contTemp = 1;
	while (aux1!=NULL) {
		if (cont1%2!=0) {
			pnodo temp = aux1->siguiente;
			pnodo nodoObj = temp2;
			int objetivo = cont1+2;
			while (nodoObj!=NULL) {
				cout<<" * "<<contTemp<<" = "<<objetivo<<endl;
				if (contTemp==objetivo) {
					aux1->siguiente = nodoObj;
					aux1 = temp;
					int contLista2 = objLista2-1;
					aux2 = temp2;
					while (contLista2!=objLista2){
						cout<<" ** "<<contLista2<<" = "<<objLista2<<endl;
						aux2 = aux2->siguiente;
						contLista2++;
					}
					temp2 = aux2->siguiente;
					aux2->siguiente = temp;
					objLista2 = objLista2+2;
					break;
				}
				contTemp++;
				nodoObj = nodoObj->siguiente;
			}
			contTemp = objetivo+1;
		}
		cont1++;
		cout<<cont1<<" = "<<aux1->valor<<endl;
		aux1 = aux1->siguiente;
	}
	aux1->siguiente = listatemp2.primero;*/
	
	int cont1=1, cont2=1, contTemp = 1;
	pnodo aux1 = listatemp1.primero;
	pnodo aux2 = listatemp2.primero;
	pnodo temp1 = listatemp2.primero;
	pnodo temp2 = listatemp2.primero;
	
	while(aux1!=NULL){
		if (cont1%2!=0){
			temp1 = aux1->siguiente;
			cout<<cont1<<" = "<<aux1->valor<<endl;
			if (cont1+2>6){
				aux1->siguiente = listatemp2.primero;
			}
			else{
				while (cont1+2!=contTemp){
					temp2 = temp2->siguiente;
					contTemp++;
				}
				aux1->siguiente = temp2;
			}
			aux1=temp1;
//			
//				aux1->siguiente = listatemp2.primero;
//			}
			while (cont2%2!=0){
				aux2 = aux2->siguiente;
				cont2++;
			}
			aux2->siguiente = aux1;
			cont2++;
			aux2 = temp2;
		}
		else{
			aux1 = aux1->siguiente;
			temp1 = aux1;
		}
		cout<<endl<<endl<<"Lista 1 Evaluada: ";
		listatemp1.Mostrar();
		cout<<endl<<"Lista 2 Evaluada: ";
		listatemp2.Mostrar();
		cont1++;
	}
	
	cout<<endl<<endl<<"Lista 1 Evaluada: ";
	listatemp1.Mostrar();
	cout<<endl<<"Lista 2 Evaluada: ";
	listatemp2.Mostrar();
}



