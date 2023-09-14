//José Julián Brenes Garro y Gustavo Pacheco Morales
//c.2022272865
//Estructuras de Datos

#include "cola.h"
using namespace std;

void cola::insertar(pnodoClientes cliente) {
    if (fondo < 5 - 1) {
        fondo++;
        Cola[fondo] = cliente;
    }
    else {
        cout << "La cola está llena" << endl;
    }
} 


void cola:: eliminar ()
{
         if(!ColaVacia()){
            frente++;
         }
         else{
         cout<<"La cola esta vacia";  
         }
}  

void cola:: imprimir(){
	if (ColaVacia()){
		return;
	}
	cout<<endl<<"COLA	* CEDULA -> NOMBRE -> PRODUCTOS -> CANTIDAD"<<endl;
	for (int i = frente; i <= fondo; i++) {
		if(Cola[i]!=NULL){
	        cout<<Cola[i]->cedula<<" -> "<<Cola[i]->nombreCliente<<" -> "<<endl;
	        Cola[i]->productos.MostrarCompra();
		}
    }
}

bool cola::buscar(int cedula) {
	
	if (ColaVacia()){
		return false;
	}
	for (int i = frente; i <= fondo; i++) {
        if (Cola[i] != NULL && Cola[i]->cedula == cedula) {
            return true;
        }
	}
    return false;
}

int cola::getPosicion(int cedula) {
	
	if (ColaVacia()){
		return -1;
	}
	for (int i = frente; i <= fondo; i++) {
        if (Cola[i] != NULL && Cola[i]->cedula == cedula) {
            return i;
        }
	}
    return -1;
}

void cola::eliminarPorPosicion(int posicion) {
    if (posicion < frente || posicion > fondo || ColaVacia()) {
        cout << "La posicion especificada no es válida o la cola esta vacía." << endl;
        return;
    }

    for (int i = posicion; i < fondo; i++) {
        Cola[i] = Cola[i + 1];
    }

    Cola[fondo] = nullptr; // Eliminar el último elemento
    fondo--;
}
