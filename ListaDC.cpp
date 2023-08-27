//José Julián Brenes Garro y Gustavo Pacheco Morales
//c.2022272865
//Estructuras de Datos

#include "ListaDC.h"
using namespace std;
                
listaDC::~listaDC()
{
   pnodoDC aux;
   pnodoDC temp;
   
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
int listaDC::largoLista() //3-4-5    cont=0 1 2 3
{
    int cont=0;

    pnodoDC aux = primero->siguiente;
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

void listaDC::InsertarInicio(int v)
{
  
   if (ListaVacia())
   {
     primero = new nodoDC(v);
     primero->anterior=primero;
     primero->siguiente=primero;
   }  
   else
   {
     pnodoDC nuevo=new nodoDC (v);//1
     nuevo->siguiente=primero;//2
     nuevo->anterior= primero->anterior;//3
     primero->anterior->siguiente=nuevo;//4
     nuevo->siguiente->anterior=nuevo;//5   se puede cambiar primero->anterior=nuevo;
     primero= nuevo;//6
   }
}
 
void listaDC::InsertarFinal(int v)
{
   if (ListaVacia())
     {
     primero = new nodoDC(v);
     primero->anterior=primero;
     primero->siguiente=primero;
   }  
   else
   { 
     pnodoDC nuevo = new nodoDC(v);//1
     nuevo->anterior = primero->anterior;//2
     /*nuevo->siguiente=primero->anterior->siguiente;opcion para intruccion 3*/
	 nuevo->siguiente=primero;// coloca alguna de la dos 3
     primero->anterior->siguiente=nuevo;//4
     primero->anterior=nuevo;//5
    }    
}


void listaDC::InsertarPos(int v,int pos)
{
   if (ListaVacia())
   {
     primero = new nodoDC(v);
     primero->anterior=primero;
     primero->siguiente=primero;
   } 
   else
   {
      if(pos <=1)
        InsertarInicio(v);    
       else
       {
        if (pos==largoLista())
          InsertarFinal(v);
        else
        {     
             pnodoDC aux= primero;
             int i =2;
             while((i != pos )&&(aux->siguiente!= primero))
             {
                   i++;
                   aux=aux->siguiente;
             }
             pnodoDC nuevo= new nodoDC(v);//1
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

void listaDC::BorrarFinal()
{
    if (ListaVacia())
      cout << "No hay elementos en la lista:" << endl;
    else
    {
      if (primero->siguiente == primero)
      {
        pnodoDC temp= primero;
        primero= NULL;
        delete temp;
      }
      else 
      {
         pnodoDC aux = primero; //1
         while (aux->siguiente->siguiente != primero)
              aux = aux->siguiente;
         pnodoDC temp = aux->siguiente;//2
         aux->siguiente= primero;//3
         primero->anterior=aux;//4
         delete temp;//5
      }
    }
}

void listaDC::BorrarInicio()
{
    if (ListaVacia())
      cout << "No hay elementos en la lista:" << endl;
    else
    {
     if (primero->siguiente == primero)
     {
        pnodoDC temp= primero;
        primero= NULL;
        delete temp;
     }
     else
     {
        pnodoDC aux = primero->anterior;//1
        pnodoDC temp= primero;//2
        aux->siguiente=primero->siguiente;//3
        primero=primero->siguiente; //4
        primero->anterior=aux;//5
        delete temp;//6
      }
    }
}

void listaDC:: BorrarPosicion(int pos)
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
       pnodoDC aux=  primero;
       while(cont<pos)
       {
         aux=aux->siguiente;
         cont++;
       }
       pnodoDC temp = aux->siguiente;
       aux->siguiente=aux->siguiente->siguiente;
       aux->siguiente->anterior=aux;
       delete temp;
     }
    }
  }
}

void listaDC::Mostrar()
{
   pnodoDC aux=primero;
   while(aux->siguiente!=primero)
     {
                                
      cout << aux->valor << "-> ";
      aux = aux->siguiente;
     }
     cout<<aux->valor<<"->";
     //EXTRA
     cout<<endl;
    /* cout<< "primero";
     cout<<endl;
     cout<<aux->siguiente->valor<<"->";
     cout<<endl;
     cout<< "ultimo";
     cout<<endl;
     cout<<primero->anterior->valor<<"->";*/
}   

void listaDC::leerPasillo(listaDC &L2,lista &L1, string nombre){
	//Lee el archivo con los pasillos, los mete a una lista y luego lo carga a una lista doble circular con los datos correctos
  	string linea;
	ifstream archivo(nombre.c_str());
	
	while (!archivo.eof()) { //Cada line del archivo se mete a una lista simple
		getline(archivo, linea);
		L1.InsertarFinal(linea);}
    pnodoL aux=primero; //se crea un nodo en primero de la lista simple
    while(aux!=NULL){ 
		bool flag=true;
    	int temp =aux->valor.length(); //Crea un temp con la cantidad de caracteres que tenga cada linea del nodo
    	string num = "";
    	string nombre = "";
    	string tempNom=aux->valor; //Un temp que tiene la linea
    	for (int i = 0; i < temp; i++){ //Se hace un while con un contador mientras sea menor al temp
    		if (tempNom[i]!=';'){ //Hasta que no se encuentre un ; va a ingresar los caracteres a la variable num
    			if (flag==true){
    				num+=aux->valor[i];}
				else{
					nombre+=aux->valor[i];}}
			else{//Si se encuentra un ;, cambia la bandera a false y se lo salta
				flag=false;}
		}
		if (L2.verificar(stoi(num))==false){//Se verifica que el numero de pasillo no este ya ingresado en la lista
			L2.InsertarFinal(stoi(num), nombre);} //Si no se encontraba lo ingresa en la lista
		aux= aux->siguiente;}
	L1.~lista();}
