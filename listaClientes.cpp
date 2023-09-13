//José Julián Brenes Garro y Gustavo Pacheco Morales
//c.2022272865
//Estructuras de Datos

#include "listaClientes.h"
using namespace std;

listaClientes::~listaClientes() 
{
	pnodoClientes aux;

	while(primero) {
		aux = primero;
		primero = primero->siguiente;
		delete aux;
	}
	primero= NULL;
}

int listaClientes::largoLista() {
	int cont=0;

	pnodoClientes aux= primero;
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

void listaClientes::InsertarInicio(int cedula_Parametro, string nombre) { 
	if (ListaVacia()) {

		primero = new nodoClientes(cedula_Parametro, nombre);

	} else {
		//primera forma
//  primero=new nodoClientes (v,primero);
		//segunda forma
		pnodoClientes nuevo=new nodoClientes(cedula_Parametro, nombre);
		nuevo->siguiente=primero;
		primero=nuevo;
	}
}

void listaClientes::InsertarFinal(int cedula_Parametro, string nombre) { //76
	if (ListaVacia())
		primero = new nodoClientes(cedula_Parametro, nombre);
	else {
		//primera forma
		//pnodoClientesClientes aux = primero;
		//  while ( aux->siguiente != NULL)
		//   aux= aux->siguiente;
		//  aux->siguiente=new nodoClientes(v);

		//segunda forma
		pnodoClientes aux = primero;
		while ( aux->siguiente != NULL)
			aux= aux->siguiente;
		pnodoClientes nuevo=new nodoClientes(cedula_Parametro, nombre);
		aux->siguiente=nuevo;
	}
}


void listaClientes::InsertarPos(int cedula_Parametro, string nombre,int pos) {
	if (ListaVacia())
		primero = new nodoClientes(cedula_Parametro, nombre);
	else {
		if(pos <=1) {
			//OPcion1
			pnodoClientes nuevo = new nodoClientes(cedula_Parametro, nombre);
			nuevo->siguiente= primero;
			primero= nuevo;
			//OPcion 2
			//InsertarInicio(v);
		} else {
			nodoClientes *aux= primero;
			int i =2;
			while((i != pos )&&(aux->siguiente!= NULL)) {
				i++;
				aux=aux->siguiente;
			}
			pnodoClientes nuevo= new nodoClientes(cedula_Parametro, nombre);
			nuevo->siguiente=aux->siguiente;
			aux->siguiente=nuevo;
		}
	}
}

void listaClientes::BorrarFinal() {
	if (ListaVacia()) {
		cout << "No hay elementos en la lista:" << endl;

	} else {

		if (primero->siguiente == NULL) {
			pnodoClientes temp=primero;
			primero= NULL;
			delete temp;;
		} else {

			pnodoClientes aux = primero;
			while (aux->siguiente->siguiente != NULL) {
				aux = aux->siguiente;

			}

			pnodoClientes temp = aux->siguiente;
			aux->siguiente= NULL;
			delete temp;
		}
	}
}

void listaClientes::BorrarInicio() {
	if (ListaVacia()) {
		cout << "No hay elementos en la lista:" << endl;

	} else {
		if (primero->siguiente == NULL) {
			pnodoClientes temp=primero;
			primero= NULL;
			delete temp;
		} else {

			pnodoClientes aux = primero;
			primero=primero->siguiente;
			delete aux;
		}
	}
}

void listaClientes::borrarPosicion(int pos) {
	if(ListaVacia()) {
		cout << "Lista vacia" <<endl;
	} else {
		if (pos == -1){
			cout << "Este cliente no está registrado" << endl;
		} else{
			if((pos>largoLista())||(pos<0))//no validas
        	{
        	cout << "Error en posicion" << endl;
			} else {
				if(pos==1) {
					pnodoClientes temp=primero;
					primero=primero->siguiente;
					delete temp; //BorrarInicio();
				} else {
					int cont=2;
					pnodoClientes aux=  primero;
					while(cont<pos) {
						aux=aux->siguiente;
						cont++;
					}
					pnodoClientes temp=aux->siguiente;
					aux->siguiente=aux->siguiente->siguiente;
					delete temp;
				}
			}
		}
	}
}

int listaClientes::buscarPos(int cedula_Parametro){		
	int pos = 1;
	pnodoClientes aux = primero;
	while(aux != NULL)	{
		if (aux->cedula == cedula_Parametro){
			return pos;
		}
		aux=aux->siguiente;
		pos++;
	}
	return 0;
}

string listaClientes::atributosCliente(int pos){
	if(ListaVacia()) {
		cout << "Lista vacia" <<endl;
	} else {
		if (pos == -1){
			cout << "Este cliente no está registrado" << endl;
		} else{
			if((pos>largoLista())||(pos<0))//no validas
        	{
        	cout << "Error en posicion" << endl;
			} else {
				if(pos==1) {
					pnodoClientes temp=primero;
					return primero->nombreCliente;
				} else {
					int cont=2;
					pnodoClientes aux=  primero;
					while(cont<pos) {
						aux=aux->siguiente;
						cont++;
					}
					pnodoClientes temp=aux->siguiente;
					return aux->nombreCliente;
				}
			}
		}
	}
}

void listaClientes::Mostrar() {
	nodoClientes *aux;
	if (primero== NULL)
		cout << "No hay elementos AQUI";
	else {
		cout<<endl<<"		* CEDULA -> NOMBRE"<<endl;
		aux = primero;
		while(aux) {
			cout<<"		* "<<aux->cedula<<" -> "<<aux->nombreCliente<<endl;
			aux = aux->siguiente;
		}
		cout << endl;
	}
}

string listaClientes::DevolverReporte() {
	nodoClientes *aux;
	string reporte;
	if (primero== NULL)
		reporte= "No hay elementos AQUI";
	else {
		reporte="		* CEDULA -> NOMBRE\n";
		aux = primero;
		while(aux) {
			reporte=reporte+"		* "+to_string(aux->cedula)+" -> "+aux->nombreCliente+"\n";
			aux = aux->siguiente;
		}
		cout << endl;
	}
	return reporte;
}

pnodoClientes listaClientes::buscarClientes(int cedula_parametro){
	if (primero==NULL){
		return NULL;
	}
	pnodoClientes aux=primero;
	while(aux){
		if (aux->cedula==cedula_parametro){
			return aux;
		}
		aux = aux->siguiente;
	}
	return NULL;
}

void listaClientes::leerClientes(string nombre){
	
  	string linea;
	ifstream archivo(nombre.c_str());
	
	lista L1;
	
	while (!archivo.eof()) { //Cada line del archivo se mete a una lista simple
		getline(archivo, linea);
		L1.InsertarFinal(linea);
		}
    pnodo aux= L1.primero; //se crea un nodo en primero de la lista simple
    
    while(aux!=NULL){ 
		bool flag=true;
    	int temp =aux->valor.length(); //Crea un temp con la cantidad de caracteres que tenga cada linea del nodo
    	string cedula = "";
    	string nombre = "";
    	string tempNom=aux->valor; //Un temp que tiene la linea
    	
//    	cout<<aux->valor.length()<<" = "<<tempNom<<endl;
    	for (int i = 0; i < temp; i++){ //Se hace un while con un contador mientras sea menor al temp
    		
    		if (tempNom[i]!=';'){ //Hasta que no se encuentre un ; va a ingresar los caracteres a la variable cedula
    			if (flag==true){
    				cedula+=aux->valor[i];}
				else{
					nombre+=aux->valor[i];}
			}
			else{//Si se encuentra un ;, cambia la bandera a false y se lo salta
				flag=false;}
		}
		
		if (buscarClientes(stoi(cedula))==NULL){//Se verifica que el numero de pasillo no este ya ingresado en la lista
			InsertarFinal(stoi(cedula), nombre);
		} //Si no se encontraba lo ingresa en la lista

		aux = aux->siguiente;
		}
	}
