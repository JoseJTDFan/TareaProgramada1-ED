//José Julián Brenes Garro y Gustavo Pacheco Morales
//c.2022272865
//Estructuras de Datos


#include "listaMenu.h"
using namespace std;

listaMenu::~listaMenu()
{
   pnodoMenu aux;
   
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
   primero=NULL;
}

int listaMenu::largoLista(){
    int cont=0;

    pnodoMenu aux;
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

void listaMenu::InsertarInicio(int pais, int ciudad, int rest, int pmenu, string pnombre)
{
   if (ListaVacia())
   {
   
     primero = new nodoMenu(pais, ciudad, rest, pmenu, pnombre);
     primero->anterior=NULL;     
   }
   else
   {
     primero=new nodoMenu (pais, ciudad, rest, pmenu, pnombre,primero);
     primero->siguiente->anterior=primero;
   }
}
//Otra forma ultimas dos lineas
// pnodoMenu nuevo=new nodoMenu(v);
//nuevo->siguiente=primero;
//primero->anterior=nuevo;
//primero=nuevo;
 
void listaMenu::InsertarFinal(int pais, int ciudad, int rest, int pmenu, string pnombre)
{
   if (ListaVacia())
   {
   
     primero = new nodoMenu(pais, ciudad, rest, pmenu, pnombre);
       
   }
   else
     { pnodoMenu aux = primero;
        while ( aux->siguiente != NULL)
          aux= aux->siguiente;
        aux->siguiente=new nodoMenu(pais, ciudad, rest, pmenu, pnombre);
        aux->siguiente->anterior=aux;       
      }    
}
//Otra forma cambia las ultimas dos instrucciones
//pnodoMenu nuevo= new nodoMenu(v);
//nuevo->anterior=aux;
//aux->siguiente=nuevo;


void listaMenu::InsertarPos(int pais, int ciudad, int rest, int pmenu, string pnombre,int pos)
{
   if (ListaVacia())
    {
   
     primero = new nodoMenu(pais, ciudad, rest, pmenu, pnombre);
     primero->anterior=NULL;     
   }
   else{
        if(pos <=1)
          InsertarInicio(pais, ciudad, rest, pmenu, pnombre);    
        else
        {
             pnodoMenu aux= primero;
             int i =2;
             while((i != pos )&&(aux->siguiente!= NULL)){
                   i++;
                   aux=aux->siguiente;
             }
             pnodoMenu nuevo= new nodoMenu(pais, ciudad, rest, pmenu, pnombre);
             nuevo->siguiente=aux->siguiente;
			 nuevo->anterior=aux;
			   nuevo->siguiente->anterior=nuevo;
			   aux->siguiente=nuevo;                      
        }
        }
}
      
void listaMenu::BorrarFinal()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else{
        if (primero->siguiente == NULL)//solo un nodoMenu
		 {
        	pnodoMenu temp=primero;
            primero= NULL;
            delete temp;
            } 
			else 
			{

                pnodoMenu aux = primero;
                while (aux->siguiente->siguiente != NULL) 
                {
                    aux = aux->siguiente;
                }
                
              pnodoMenu temp = aux->siguiente;
              aux->siguiente= NULL;
                      
                delete temp;
            }
        }
}

void listaMenu::BorrarInicio()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else{
        if (primero->siguiente == NULL) {
            pnodoMenu temp=primero;
            primero= NULL;
            delete temp;
            } 
			else
			{

                pnodoMenu aux = primero;
                primero=primero->siguiente;   
				primero->anterior=NULL;            
                delete aux;
            }
        }
}



void listaMenu:: BorrarPosicion(int pos)
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
            pnodoMenu aux=  primero;
            while(cont<pos)
            {
             aux=aux->siguiente;
             cont++;
            }
            pnodoMenu temp=aux->siguiente;
            aux->siguiente=aux->siguiente->siguiente;
            aux->siguiente->anterior=aux;
            delete temp;
          }//else
        }//else
      }//else
    }//else
}
 

void listaMenu::Mostrar()
{
   nodoMenu *aux;
   
   aux = primero;
   while(aux) {
      cout <<"				*"<<aux->codPais << " -> "<<aux->codCiudad<<" -> "<<aux->codRest<<" -> "<<aux->codMenu<<" -> "<<aux->nombre<<endl;
//      aux->productos.Mostrar();
      aux = aux->siguiente;
   }
   cout << endl;
}

pnodoMenu listaMenu::buscarMenu(int menu){
	if (primero==NULL){
		return NULL;
	}
	pnodoMenu aux=primero;
	while(aux){
		if (aux->codMenu==menu){
			return aux;
		}
		aux = aux->siguiente;
	}
	return NULL;
}

int listaMenu::getPosicion(int codigo){
	if (primero==NULL){
		return 0;
	}
	pnodoMenu aux=primero;
	int cont=1;
	while(aux){
		if (aux->codMenu==codigo){
			return cont;
		}
		aux = aux->siguiente;
		cont++;
	}
	return 0;
}

