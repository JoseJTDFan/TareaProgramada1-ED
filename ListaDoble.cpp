//Jos� Juli�n Brenes Garro y Gustavo Pacheco Morales
//c.2022272865
//Estructuras de Datos


#include "ListaDoble.h"
using namespace std;

listaDoble::~listaDoble()
{
   pnodoDoble aux;
   
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
   primero=NULL;
}

int listaDoble::largoLista(){
    int cont=0;

    pnodoDoble aux;
    aux = primero;
    if(ListaVacia()){
        return cont;
    }else{
        while(aux!=NULL){
        aux=aux->siguiente;
        cont++;
    }
    return cont;
    }
    
}

void listaDoble::InsertarInicio(int v)
{
   if (ListaVacia())
   {
   
     primero = new nodoDoble(v);
     primero->anterior=NULL;     
   }
   else
   {
     primero=new nodoDoble (v,primero);
     primero->siguiente->anterior=primero;
   }
}
//Otra forma ultimas dos lineas
// pnodoDoble nuevo=new nodoDoble(v);
//nuevo->siguiente=primero;
//primero->anterior=nuevo;
//primero=nuevo;
 
void listaDoble::InsertarFinal(int v)
{
   if (ListaVacia())
   {
   
     primero = new nodoDoble(v);
       
   }
   else
     { pnodoDoble aux = primero;
        while ( aux->siguiente != NULL)
          aux= aux->siguiente;
        aux->siguiente=new nodoDoble(v);
        aux->siguiente->anterior=aux;       
      }    
}
//Otra forma cambia las ultimas dos instrucciones
//pnodoDoble nuevo= new nodoDoble(v);
//nuevo->anterior=aux;
//aux->siguiente=nuevo;


void listaDoble::InsertarPos(int v,int pos)
{
   if (ListaVacia())
    {
   
     primero = new nodoDoble(v);
     primero->anterior=NULL;     
   }
   else{
        if(pos <=1)
          InsertarInicio(v);    
        else
        {
             pnodoDoble aux= primero;
             int i =2;
             while((i != pos )&&(aux->siguiente!= NULL)){
                   i++;
                   aux=aux->siguiente;
             }
             pnodoDoble nuevo= new nodoDoble(v);
             nuevo->siguiente=aux->siguiente;
			 nuevo->anterior=aux;
			   nuevo->siguiente->anterior=nuevo;
			   aux->siguiente=nuevo;                      
        }
        }
}
      
void listaDoble::BorrarFinal()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else{
        if (primero->siguiente == NULL)//solo un nodoDoble
		 {
        	pnodoDoble temp=primero;
            primero= NULL;
            delete temp;
            } 
			else 
			{

                pnodoDoble aux = primero;
                while (aux->siguiente->siguiente != NULL) 
                {
                    aux = aux->siguiente;
                }
                
              pnodoDoble temp = aux->siguiente;
              aux->siguiente= NULL;
                      
                delete temp;
            }
        }
}

void listaDoble::BorrarInicio()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else{
        if (primero->siguiente == NULL) {
            pnodoDoble temp=primero;
            primero= NULL;
            delete temp;
            } 
			else
			{

                pnodoDoble aux = primero;
                primero=primero->siguiente;   
				primero->anterior=NULL;            
                delete aux;
            }
        }
}



void listaDoble:: BorrarPosicion(int pos)
{
     if(ListaVacia())
     {
              cout << "Lista vacia" <<endl;
     }
     else
     {
        if((pos>largoLista())||(pos<0))//no validas
        {
        cout << "Error en posicion" << endl;
        }
        else
        {
        if(pos==1)
           BorrarInicio();
        else
        {
          if (pos == largoLista())   
             BorrarFinal();
          else
          {   
            int cont=2;
            pnodoDoble aux=  primero;
            while(cont<pos)
            {
             aux=aux->siguiente;
             cont++;
            }
            pnodoDoble temp=aux->siguiente;
            aux->siguiente=aux->siguiente->siguiente;
            aux->siguiente->anterior=aux;
            delete temp;
          }//else
        }//else
      }//else
    }//else
}
 

void listaDoble::Mostrar()
{
   nodoDoble *aux;
   
   aux = primero;
   while(aux) {
      cout << aux->valor << "-> ";
      aux = aux->siguiente;
   }
   cout << endl;
}

