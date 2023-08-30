//José Julián Brenes Garro y Gustavo Pacheco Morales
//c.2022272865
//Estructuras de Datos


#include "ListaCiudades.h"
using namespace std;

listaCiudades::~listaCiudades()
{
   pnodoCiudades aux;
   
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
   primero=NULL;
}

int listaCiudades::largoLista(){
    int cont=0;

    pnodoCiudades aux;
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

void listaCiudades::InsertarInicio(int pais, int ciudad, string pnombre)
{
   if (ListaVacia())
   {
   
     primero = new nodoCiudades(pais, ciudad, pnombre);
     primero->anterior=NULL;     
   }
   else
   {
     primero=new nodoCiudades (pais, ciudad, pnombre);
     primero->siguiente->anterior=primero;
   }
   
}
//Otra forma ultimas dos lineas
// pnodoCiudades nuevo=new nodoCiudades(v);
//nuevo->siguiente=primero;
//primero->anterior=nuevo;
//primero=nuevo;
 
void listaCiudades::InsertarFinal(int pais, int ciudad, string pnombre)
{
   if (ListaVacia())
   {
   
     primero = new nodoCiudades(pais, ciudad, pnombre);
       
   }
   else
     { pnodoCiudades aux = primero;
        while ( aux->siguiente != NULL)
          aux= aux->siguiente;
        aux->siguiente=new nodoCiudades(pais, ciudad, pnombre);
        aux->siguiente->anterior=aux;       
      }    
}
//Otra forma cambia las ultimas dos instrucciones
//pnodoCiudades nuevo= new nodoCiudades(v);
//nuevo->anterior=aux;
//aux->siguiente=nuevo;


void listaCiudades::InsertarPos(int pais, int ciudad, string pnombre,int pos)
{
   if (ListaVacia())
    {
   
     primero = new nodoCiudades(pais, ciudad, pnombre);
     primero->anterior=NULL;     
   }
   else{
        if(pos <=1)
          InsertarInicio(pais, ciudad, pnombre);    
        else
        {
             pnodoCiudades aux= primero;
             int i =2;
             while((i != pos )&&(aux->siguiente!= NULL)){
                   i++;
                   aux=aux->siguiente;
             }
             pnodoCiudades nuevo= new nodoCiudades(pais, ciudad, pnombre);
             nuevo->siguiente=aux->siguiente;
			 nuevo->anterior=aux;
			   nuevo->siguiente->anterior=nuevo;
			   aux->siguiente=nuevo;                      
        }
        }
}
      
void listaCiudades::BorrarFinal()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else{
        if (primero->siguiente == NULL)//solo un nodoCiudades
		 {
        	pnodoCiudades temp=primero;
            primero= NULL;
            delete temp;
            } 
			else 
			{

                pnodoCiudades aux = primero;
                while (aux->siguiente->siguiente != NULL) 
                {
                    aux = aux->siguiente;
                }
                
              pnodoCiudades temp = aux->siguiente;
              aux->siguiente= NULL;
                      
                delete temp;
            }
        }
}

void listaCiudades::BorrarInicio()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else{
        if (primero->siguiente == NULL) {
            pnodoCiudades temp=primero;
            primero= NULL;
            delete temp;
            } 
			else
			{

                pnodoCiudades aux = primero;
                primero=primero->siguiente;   
				primero->anterior=NULL;            
                delete aux;
            }
        }
}



void listaCiudades:: BorrarPosicion(int pos)
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
            pnodoCiudades aux=  primero;
            while(cont<pos)
            {
             aux=aux->siguiente;
             cont++;
            }
            pnodoCiudades temp=aux->siguiente;
            aux->siguiente=aux->siguiente->siguiente;
            aux->siguiente->anterior=aux;
            delete temp;
          }//else
        }//else
      }//else
    }//else
}
 

void listaCiudades::Mostrar()
{
   nodoCiudades *aux;
   
   aux = primero;
   while(aux) {
   		
      cout <<"		*"<<aux->codPais << " -> "<<aux->codCiudad<<" -> "<<aux->nombre<<endl;
//      aux->restaurantes.Mostrar();
      aux = aux->siguiente;
   }
   cout << endl;
   
   
}

pnodoCiudades listaCiudades::buscarCiudad(int ciudad){
	if (primero==NULL){
		return NULL;
	}
	pnodoCiudades aux=primero;
	while(aux){
		if (aux->codCiudad==ciudad){
			return aux;
		}
		aux = aux->siguiente;
	}
	return NULL;
}

