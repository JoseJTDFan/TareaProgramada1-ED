//José Julián Brenes Garro y Gustavo Pacheco Morales
//c.2022272865
//Estructuras de Datos

#include "listaRest.h"
using namespace std;
                
listaRest::~listaRest()
{
   pnodoRest aux;
   pnodoRest temp;
   
   while(primero) {
      temp = primero;
      aux=primero;
      primero = primero->siguiente;
      while (aux->siguiente!=primero)
           aux= aux->siguiente;
      aux->siguiente=primero;
      
      delete temp;
      primero=NULL;
   }
   primero= NULL;
}
   

                        //  aux
int listaRest::largoLista() //3-4-5    cont=0 1 2 3
{
    int cont=0;

    pnodoRest aux = primero->siguiente;
    if(ListaVacia())
    {
        return cont;
    }
    else
    {   cont=cont+1;
        while(aux!=primero)
        {
          aux=aux->siguiente;
          cont++;
        }
    return cont;
    }
    
}

void listaRest::InsertarInicio(int pais, int ciudad, int rest, string pnombre)
{
  
   if (ListaVacia())
   {
     primero = new nodoRest( pais, ciudad, rest, pnombre);
     primero->anterior=primero;
     primero->siguiente=primero;
   }  
   else
   {
     pnodoRest nuevo=new nodoRest ( pais, ciudad, rest, pnombre);//1
     nuevo->siguiente=primero;//2
     nuevo->anterior= primero->anterior;//3
     primero->anterior->siguiente=nuevo;//4
     nuevo->siguiente->anterior=nuevo;//5   se puede cambiar primero->anterior=nuevo;
     primero= nuevo;//6
   }
}
 
void listaRest::InsertarFinal(int pais, int ciudad, int rest, string pnombre)
{
   if (ListaVacia())
     {
     primero = new nodoRest( pais, ciudad, rest, pnombre);
     primero->anterior=primero;
     primero->siguiente=primero;
   }  
   else
   { 
     pnodoRest nuevo = new nodoRest( pais, ciudad, rest, pnombre);//1
     nuevo->anterior = primero->anterior;//2
     /*nuevo->siguiente=primero->anterior->siguiente;opcion para intruccion 3*/
	 nuevo->siguiente=primero;// coloca alguna de la dos 3
     primero->anterior->siguiente=nuevo;//4
     primero->anterior=nuevo;//5
    }    
}


void listaRest::InsertarPos(int pais, int ciudad, int rest, string pnombre,int pos)
{
   if (ListaVacia())
   {
     primero = new nodoRest( pais, ciudad, rest, pnombre);
     primero->anterior=primero;
     primero->siguiente=primero;
   } 
   else
   {
      if(pos <=1)
        InsertarInicio( pais, ciudad, rest, pnombre);    
       else
       {
        if (pos==largoLista())
          InsertarFinal( pais, ciudad, rest, pnombre);
        else
        {     
             pnodoRest aux= primero;
             int i =2;
             while((i != pos )&&(aux->siguiente!= primero))
             {
                   i++;
                   aux=aux->siguiente;
             }
             pnodoRest nuevo= new nodoRest( pais, ciudad, rest, pnombre);//1
             nuevo->siguiente=aux->siguiente;//2
             aux->siguiente=nuevo;//3
             aux->siguiente->anterior=aux;//4 o puede nuevo->anterio=aux
             nuevo->siguiente->anterior=nuevo;  //5    
			 int numero=3*3;
			 cout<<numero<<endl;                    
        }
       }
   }
}   

void listaRest::BorrarFinal()
{
    if (ListaVacia())
      cout << "No hay elementos en la lista:" << endl;
    else
    {
      if (primero->siguiente == primero)
      {
        pnodoRest temp= primero;
        primero= NULL;
        delete temp;
      }
      else 
      {
         pnodoRest aux = primero; //1
         while (aux->siguiente->siguiente != primero)
              aux = aux->siguiente;
         pnodoRest temp = aux->siguiente;//2
         aux->siguiente= primero;//3
         primero->anterior=aux;//4
         delete temp;//5
      }
    }
}

void listaRest::BorrarInicio()
{
    if (ListaVacia())
      cout << "No hay elementos en la lista:" << endl;
    else
    {
     if (primero->siguiente == primero)
     {
        pnodoRest temp= primero;
        primero= NULL;
        delete temp;
     }
     else
     {
        pnodoRest aux = primero->anterior;//1
        pnodoRest temp= primero;//2
        aux->siguiente=primero->siguiente;//3
        primero=primero->siguiente; //4
        primero->anterior=aux;//5
        delete temp;//6
      }
    }
}

void listaRest:: BorrarPosicion(int pos)
{
    
  if(ListaVacia())
    cout << "Lista vacia" <<endl;
  else
  {
   if((pos==1))
      
   {
   	BorrarInicio();
   	
   }
        
   else
   {
    if(pos>largoLista()||(pos<=0))
    {
       cout << "Error en posicion" << endl;
	}
        
    else
    {
       int cont=2;
       pnodoRest aux=  primero;
       while(cont<pos)
       {
         aux=aux->siguiente;
         cont++;
       }
       pnodoRest temp = aux->siguiente;
       aux->siguiente=aux->siguiente->siguiente;
       aux->siguiente->anterior=aux;
       delete temp;
     }
    }
  }
}

void listaRest::Mostrar()
{
	if (primero==NULL){
		return;
	}
   pnodoRest aux=primero;
   do
     {     
      cout <<"			*"<<aux->codPais << " -> "<<aux->codCiudad<<" -> "<<aux->codRest<<" -> "<<aux->nombre<<endl;
//      aux->menus.Mostrar();
      aux = aux->siguiente;
     } while(aux!=primero);
}   

pnodoRest listaRest::buscarRest(int rest){
	if (primero==NULL){
		return NULL;
	}
	pnodoRest aux=primero;
	do{
		if (aux->codRest==rest){
			return aux;
		}
		aux = aux->siguiente;
	}while(aux!=primero);
	return NULL;
}

int listaRest::getPosicion(int codigo){
	if (primero==NULL){
		return 0;
	}
	pnodoRest aux=primero;
	int cont=1;
	do{
		if (aux->codRest==codigo){
			return cont;
		}
		aux = aux->siguiente;
		cont++;
	}while(aux!=primero);
	return 0;
}
