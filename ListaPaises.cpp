//José Julián Brenes Garro y Gustavo Pacheco Morales
//c.2022272865
//Estructuras de Datos

#include "listaPaises.h"
using namespace std;
                
listaPaises::~listaPaises()
{
   pnodoPaises aux;
   
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
   primero=NULL;
}
   

                        //  aux
int listaPaises::largoLista() //3-4-5    cont=0 1 2 3
{
    int cont=0;

    pnodoPaises aux;
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

void listaPaises::InsertarInicio(int pais, string pnombre)
{
  if (ListaVacia())
   {
   
     primero = new nodoPaises(pais, pnombre);
     primero->anterior=NULL;     
   }
   else
   {
     primero=new nodoPaises (pais, pnombre,primero);
     primero->siguiente->anterior=primero;
   }
}
 
void listaPaises::InsertarFinal(int pais, string pnombre)
{
   if (ListaVacia())
   {
   
     primero = new nodoPaises(pais, pnombre);
       
   }
   else
     { pnodoPaises aux = primero;
        while ( aux->siguiente != NULL)
          aux= aux->siguiente;
        aux->siguiente=new nodoPaises(pais, pnombre);
        aux->siguiente->anterior=aux;       
      }    
}


void listaPaises::InsertarPos(int pais, string pnombre, int pos)
{
   if (ListaVacia())
    {
   
     primero = new nodoPaises(pais, pnombre);
     primero->anterior=NULL;     
   }
   else{
        if(pos <=1)
          InsertarInicio(pais, pnombre);    
        else
        {
             pnodoPaises aux= primero;
             int i =2;
             while((i != pos )&&(aux->siguiente!= NULL)){
                   i++;
                   aux=aux->siguiente;
             }
             pnodoPaises nuevo= new nodoPaises(pais, pnombre);
             nuevo->siguiente=aux->siguiente;
			 nuevo->anterior=aux;
			   nuevo->siguiente->anterior=nuevo;
			   aux->siguiente=nuevo;                      
        }
    }
}   

void listaPaises::BorrarFinal()
{
  if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else{
        if (primero->siguiente == NULL)//solo un nodoPaises
		 {
        	pnodoPaises temp=primero;
            primero= NULL;
            delete temp;
            } 
			else 
			{

                pnodoPaises aux = primero;
                while (aux->siguiente->siguiente != NULL) 
                {
                    aux = aux->siguiente;
                }
                
              pnodoPaises temp = aux->siguiente;
              aux->siguiente= NULL;
                      
                delete temp;
            }
    }
}

void listaPaises::BorrarInicio()
{
     if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else{
        if (primero->siguiente == NULL) {
            pnodoPaises temp=primero;
            primero= NULL;
            delete temp;
            } 
			else
			{

                pnodoPaises aux = primero;
                primero=primero->siguiente;   
				primero->anterior=NULL;            
                delete aux;
            }
        }
}

int listaPaises::getPosicion(int codigo){
	if (primero==NULL){
		return 0;
	}
	pnodoPaises aux=primero;
	int cont=1;
	while(aux){
		if (aux->codPais==codigo){
			return cont;
		}
		aux = aux->siguiente;
		cont++;
	}
	return 0;
}

void listaPaises:: BorrarPosicion(int pos)
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
            pnodoPaises aux=  primero;
            while(cont<pos)
            {
             aux=aux->siguiente;
             cont++;
            }
            pnodoPaises temp=aux->siguiente;
            aux->siguiente=aux->siguiente->siguiente;
            aux->siguiente->anterior=aux;
            delete temp;
          }//else
        }//else
      }//else
    }//else
}

void listaPaises::Mostrar()
{
   pnodoPaises aux=primero;
   cout<<endl<<"		* PAIS -> NOMBRE"<<endl;
   	while(aux){
   		cout<<"		* "<<aux->codPais<<" -> "<<aux->nombre<<endl;
//   		aux->ciudades.Mostrar();
      	aux = aux->siguiente;
	}       
     cout<<endl;
}  

string listaPaises::DevolverReporte()
{
   pnodoPaises aux=primero;
   string reporte = "		* PAIS -> NOMBRE\n";
   	while(aux){
   		reporte=reporte+"		* "+to_string(aux->codPais)+" -> "+aux->nombre+"\n";
      	aux = aux->siguiente;
	}       
     cout<<endl;
    return reporte;
}  



pnodoPaises listaPaises::buscarPais(int pais){
	if (primero==NULL){
		return NULL;
	}
	pnodoPaises aux=primero;
	while(aux){
		if (aux->codPais==pais){
			return aux;
		}
		aux = aux->siguiente;
	}
	return NULL;
}

pnodoCiudades listaPaises::buscarCiudad( int pais, int ciudad){
	if (primero==NULL){
		return NULL;
	}
	pnodoPaises nodoPais = buscarPais(pais);
	if (nodoPais!=NULL){
		return nodoPais->ciudades.buscarCiudad(ciudad);
	}
	return NULL;
}

pnodoRest listaPaises::buscarRest(int pais,int ciudad,int rest){
	if (primero==NULL){
		return NULL;
	}
	pnodoCiudades nodoCiudad = buscarCiudad(pais,ciudad);
	if (nodoCiudad!=NULL){
		return nodoCiudad->restaurantes.buscarRest(rest);
	}
	return NULL;
}

pnodoMenu listaPaises::buscarMenu(int pais, int ciudad, int rest, int menu){
	if (primero==NULL){
		return NULL;
	}
	pnodoRest nodoRest = buscarRest(pais,ciudad, rest);
	if (nodoRest!=NULL){
		return nodoRest->menus.buscarMenu(menu);
	}
	return NULL;
}

pnodoProductos listaPaises::buscarProd(int pais, int ciudad, int rest, int menu, int prod){
	if (primero==NULL){
		return NULL;
	}
	pnodoMenu nodoMenu = buscarMenu(pais,ciudad, rest, menu);
	if (nodoMenu!=NULL){
		return nodoMenu->productos.buscarProducto(prod);
	}
	return NULL;
}

void listaPaises::insertarCiudad(int pais, int ciudad, string nombre){
	pnodoPaises nodoPais = buscarPais(pais);
	nodoPais->ciudades.InsertarFinal(pais,ciudad,nombre);
}

void listaPaises::insertarRest(int pais, int ciudad,int rest, string nombre){
	
	pnodoCiudades nodoCiudad = buscarCiudad(pais,ciudad);
	
	if (nodoCiudad!=NULL){
		nodoCiudad->restaurantes.InsertarFinal(pais, ciudad, rest, nombre);
	}
}

void listaPaises::insertarMenu(int pais, int ciudad,int rest, int menu, string nombre){
	
	pnodoRest nodoRest = buscarRest(pais,ciudad, rest);
	
	if (nodoRest!=NULL){
		nodoRest->menus.InsertarFinal(pais, ciudad, rest, menu,  nombre);
	}
}

void listaPaises::insertarProducto(int pais, int ciudad,int rest, int menu,int prod, string nombre, int kcal, int precio){
	
	pnodoMenu nodoMenu = buscarMenu(pais,ciudad, rest, menu);
	
	if (nodoMenu!=NULL){
		nodoMenu->productos.InsertarFinal(pais, ciudad, rest, menu, prod,nombre, kcal, precio);
	}
	
}


string listaPaises::RestMasBuscado(){
	listaRest MasBuscados;
	pnodoPaises aux=primero;
   	while(aux){
		pnodoCiudades auxCiudad = aux->ciudades.primero;
		if (aux->ciudades.primero==NULL){
			aux = aux->siguiente;
			continue;
		}
		while(auxCiudad) {
			if (auxCiudad->restaurantes.primero==NULL){
				auxCiudad = auxCiudad->siguiente;
				continue;
			}
	   		pnodoRest auxRest=auxCiudad->restaurantes.primero;
	   		do{     
	   			if(MasBuscados.primero==NULL){
	   				MasBuscados.InsertarFinal(auxRest->codPais, auxRest->codCiudad,auxRest->codRest,auxRest->nombre,auxRest->cantBusquedas);
				}
				   
				else{
					if (auxRest->cantBusquedas>MasBuscados.primero->cantBusquedas){
		     			MasBuscados.~listaRest();
		     			MasBuscados.InsertarFinal(auxRest->codPais, auxRest->codCiudad,auxRest->codRest,auxRest->nombre,auxRest->cantBusquedas);
					 }
					 else{
					 	if(auxRest->cantBusquedas==MasBuscados.primero->cantBusquedas){
							MasBuscados.InsertarFinal(auxRest->codPais, auxRest->codCiudad,auxRest->codRest,auxRest->nombre,auxRest->cantBusquedas);
						}
					 	
					 }
				}
		    auxRest = auxRest->siguiente;
		    } while(auxRest!=auxCiudad->restaurantes.primero);
				auxCiudad = auxCiudad->siguiente;
		}
    aux = aux->siguiente;
	}  
	string reporte;    
	if(MasBuscados.primero->cantBusquedas!=0){
		reporte="		* RESTAURANTE(S) MAS BUSCADOS\n		* PAIS -> CIUDAD -> RESTAURANTE -> NOMBRE -> CANTIDAD DE BUSQUEDAS\n";
		pnodoRest auxReporte = MasBuscados.primero;
		do{     
			reporte=reporte+"		* "+to_string(auxReporte->codPais)+ " -> "+to_string(auxReporte->codCiudad)+" -> "+to_string(auxReporte->codRest)+" -> "+auxReporte->nombre+" -> "+to_string(auxReporte->cantBusquedas)+"\n";
	  		auxReporte = auxReporte->siguiente;
		} while(auxReporte!=MasBuscados.primero);
		return reporte;
	}
	else{
		reporte="No se ha buscado ningun restaurante";
	}
}

string listaPaises::MenuMasBuscado(){
	listaMenu MasBuscados;
	pnodoPaises aux=primero;
   	while(aux){
		pnodoCiudades auxCiudad = aux->ciudades.primero;
		if (aux->ciudades.primero==NULL){
			aux = aux->siguiente;
			continue;
		}
		while(auxCiudad) {
			pnodoRest auxRest=auxCiudad->restaurantes.primero;
			if (auxCiudad->restaurantes.primero==NULL){
				auxCiudad = auxCiudad->siguiente;
				continue;
			}
	   		do{ 
	   			if (auxRest->menus.primero==NULL){
	   				auxRest = auxRest ->siguiente;
	   				continue;
				}
				pnodoMenu auxMenu=auxRest->menus.primero;
		   		while(auxMenu){
//				   cout<<"viendo"<<endl;
//				   cout<<auxMenu->codPais<<auxMenu->codCiudad<<auxMenu->codRest<<auxMenu->codMenu<<auxMenu->nombre<<auxMenu->cantBusquedas<<endl;
		   			if(MasBuscados.primero==NULL){
//		   				cout<<auxMenu->cantBusquedas<<" - "<<MasBuscados.primero->cantBusquedas<<endl;
		   				MasBuscados.InsertarFinal(auxMenu->codPais, auxMenu->codCiudad,auxMenu->codRest,auxMenu->codMenu,auxMenu->nombre,auxMenu->cantBusquedas);
					}
					   
					else{
						
						if (auxMenu->cantBusquedas>MasBuscados.primero->cantBusquedas){
						 	MasBuscados.~listaMenu();
			     			MasBuscados.InsertarFinal(auxMenu->codPais, auxMenu->codCiudad,auxMenu->codRest,auxMenu->codMenu,auxMenu->nombre,auxMenu->cantBusquedas);
						}
						else{ 
						 	if(auxMenu->cantBusquedas==MasBuscados.primero->cantBusquedas){
								MasBuscados.InsertarFinal(auxMenu->codPais, auxMenu->codCiudad,auxMenu->codRest,auxMenu->codMenu,auxMenu->nombre,auxMenu->cantBusquedas);
							}	
						}
					}
				auxMenu = auxMenu->siguiente;
			    }
				auxRest = auxRest->siguiente;
			} while(auxRest!=auxCiudad->restaurantes.primero);
      	auxCiudad = auxCiudad->siguiente;
		} 
	aux = aux->siguiente; 
	}
	string reporte;  
	if(MasBuscados.primero->cantBusquedas!=0){
		reporte="		* MENU(S) MAS BUSCADOS\n		* PAIS -> CIUDAD -> RESTAURANTE -> MENU -> NOMBRE -> CANTIDAD DE BUSQUEDAS\n";
		pnodoMenu auxReporte = MasBuscados.primero;
		while (auxReporte)   {
			reporte=reporte+"		* "+to_string(auxReporte->codPais)+ " -> "+to_string(auxReporte->codCiudad)+" -> "+to_string(auxReporte->codRest)+" -> "+to_string(auxReporte->codMenu)+" -> "+auxReporte->nombre+" -> "+to_string(auxReporte->cantBusquedas)+"\n";
	  		auxReporte = auxReporte->siguiente;
		}
		return reporte;
	}
	else{
		reporte="No se ha buscado ningun menu";
	}
}

string listaPaises::ProductoMasComprado(){
	listaProductos MasBuscados;
	pnodoPaises aux=primero;
   	while(aux){
		pnodoCiudades auxCiudad = aux->ciudades.primero;
		if (aux->ciudades.primero==NULL){
			aux = aux->siguiente;
			continue;
		}
		while(auxCiudad) {
			pnodoRest auxRest=auxCiudad->restaurantes.primero;
			if (auxCiudad->restaurantes.primero==NULL){
				auxCiudad = auxCiudad->siguiente;
				continue;
			}
	   		do{ 
	   			if (auxRest->menus.primero==NULL){
	   				auxRest = auxRest ->siguiente;
	   				continue;
				}
				pnodoMenu auxMenu=auxRest->menus.primero;
		   		while(auxMenu){
		   			pnodoProductos auxProd = auxMenu->productos.primero;
		   			if (auxMenu->productos.primero==NULL){
						auxMenu = auxMenu->siguiente;
						continue;
					}
					while(auxProd){
						if(MasBuscados.primero==NULL){
		   					MasBuscados.InsertarFinal(auxProd->codPais, auxProd->codCiudad,auxProd->codRest,auxProd->codMenu,auxProd->codProducto,auxProd->kcal,auxProd->nombre,auxProd->precio, auxProd->cantCompra);
						}
						   
						else{
							
							if (auxProd->cantCompra>MasBuscados.primero->cantCompra){
							 	MasBuscados.~listaProductos();
				     			MasBuscados.InsertarFinal(auxProd->codPais, auxProd->codCiudad,auxProd->codRest,auxProd->codMenu,auxProd->codProducto,auxProd->kcal,auxProd->nombre,auxProd->precio, auxProd->cantCompra);
							}
							else{ 
							 	if(auxProd->cantCompra==MasBuscados.primero->cantCompra){
									MasBuscados.InsertarFinal(auxProd->codPais, auxProd->codCiudad,auxProd->codRest,auxProd->codMenu,auxProd->codProducto,auxProd->kcal,auxProd->nombre,auxProd->precio, auxProd->cantCompra);
								}	
							}
						}
						auxProd = auxProd->siguiente;
					}	
				auxMenu = auxMenu->siguiente;
			    }
				auxRest = auxRest->siguiente;
			} while(auxRest!=auxCiudad->restaurantes.primero);
      	auxCiudad = auxCiudad->siguiente;
		} 
	aux = aux->siguiente; 
	}
	string reporte;  
	if(MasBuscados.primero->cantCompra!=0){
		reporte="		* PRODUCTO(S) MAS COMPRADOR\n		* PAIS -> CIUDAD -> RESTAURANTE -> MENU -> PRODUCTO -> NOMBRE -> CALORIAS -> PRECIO -> CANTIDAD DE COMPRAS\n";
		pnodoProductos auxReporte = MasBuscados.primero;
		while (auxReporte)   {
			reporte=reporte+"		* "+to_string(auxReporte->codPais)+ " -> "+to_string(auxReporte->codCiudad)+" -> "+to_string(auxReporte->codRest)+" -> "+to_string(auxReporte->codMenu)+" -> "+to_string(auxReporte->codProducto)+" -> "+auxReporte->nombre+" -> "+to_string(auxReporte->kcal)+" -> "+to_string(auxReporte->precio)+" -> "+to_string(auxReporte->cantCompra)+"\n";
	  		auxReporte = auxReporte->siguiente;
		}
		return reporte;
	}
	else{
		reporte="No se ha comprado ningun producto.";
	}
}

void listaPaises::leerPaises(string nombre){
	
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
    	string ciudad = "";
    	string nombre = "";
    	string tempNom=aux->valor; //Un temp que tiene la linea
    	
//    	cout<<aux->valor.length()<<" = "<<tempNom<<endl;
    	for (int i = 0; i < temp; i++){ //Se hace un while con un contador mientras sea menor al temp
    		
    		if (tempNom[i]!=';'){ //Hasta que no se encuentre un ; va a ingresar los caracteres a la variable ciudad
    			if (flag==true){
    				ciudad+=aux->valor[i];}
				else{
					nombre+=aux->valor[i];}
			}
			else{//Si se encuentra un ;, cambia la bandera a false y se lo salta
				flag=false;}
		}
		
		if (buscarPais(stoi(ciudad))==NULL){//Se verifica que el numero de pasillo no este ya ingresado en la lista
			InsertarFinal(stoi(ciudad), nombre);
		} //Si no se encontraba lo ingresa en la lista

		aux = aux->siguiente;
		}
	}

void listaPaises::leerCiudades(string nombre){
  	string linea;
	ifstream archivo(nombre.c_str());
	
	lista L1;
	
	while (!archivo.eof()) {	//Cada linea del archivo de productos se mete a una lista simple
		getline(archivo, linea);
		L1.InsertarFinal(linea);
    }
    pnodo aux=L1.primero; //se crea un nodo en primero de la lista simple
    while(aux!=NULL){ 
		int cont=0; 
    	int temp =aux->valor.length(); //Crea un temp con la cantidad de caracteres que tenga cada linea del nodo
    	string pais="";
    	string ciudad = "";
    	string nombre = "";
    	string tempNom=aux->valor;  //Un temp que tiene la linea
    	for (int i=0; i< temp; i++){ //Se hace un while con un contador mientras sea menor al temp
    		if (tempNom[i]==';'){ //Cuando se encuentra con un ; aumenta 1 al cont, esto para cambiar a la varibale a la que se le esta
    			cont++;}		  //agregando los caracteres
			else{ //Dependiendo del cont se le agrega a una variable o a otra
				if (cont==0){
					pais+=aux->valor[i];}
				if (cont==1){
					ciudad+=aux->valor[i];}
    			if (cont==2){
    				nombre+=aux->valor[i];}
			}
		}
		
		pnodoPaises nodoPais = buscarPais(stoi(pais));
		
		if(nodoPais!=NULL){ //Se verifica que el numero de pasillo se encuentre ingresado en la lista
			pnodoCiudades nodoCiudad = buscarCiudad(stoi(pais),stoi(ciudad));
			if (nodoCiudad==NULL){ //Se verifica que el numero de producto no este ya ingresado en la lista
				insertarCiudad(stoi(pais), stoi(ciudad), nombre);
			} //Si cumple las condiciones ingresa el prducto
		}
		aux= aux->siguiente;}
	L1.~lista();
}

void listaPaises::leerRestaurantes(string nombre){
  	string linea;
	ifstream archivo(nombre.c_str());
	
	lista L1;
	
	while (!archivo.eof()) {	//Cada linea del archivo de productos se mete a una lista simple
		getline(archivo, linea);
		L1.InsertarFinal(linea);
    }
    pnodo aux=L1.primero; //se crea un nodo en primero de la lista simple
    while(aux!=NULL){ 
		int cont=0; 
    	int temp =aux->valor.length(); //Crea un temp con la cantidad de caracteres que tenga cada linea del nodo
    	string pais="";
    	string ciudad = "";
    	string nombre = "";
    	string rest = "";
    	string tempNom=aux->valor;  //Un temp que tiene la linea
    	for (int i=0; i< temp; i++){ //Se hace un while con un contador mientras sea menor al temp
    		if (tempNom[i]==';'){ //Cuando se encuentra con un ; aumenta 1 al cont, esto para cambiar a la varibale a la que se le esta
    			cont++;}		  //agregando los caracteres
			else{ //Dependiendo del cont se le agrega a una variable o a otra
				if (cont==0){
					pais+=aux->valor[i];}
				if (cont==1){
					ciudad+=aux->valor[i];}
    			if (cont==2){
    				rest+=aux->valor[i];}
    			if (cont==3){
    				nombre+=aux->valor[i];}
				
			}
		}
		
		pnodoPaises nodoPais = buscarPais(stoi(pais));
		if(nodoPais!=NULL){ //Se verifica que el numero de pasillo se encuentre ingresado en la lista
			pnodoCiudades nodoCiudad = buscarCiudad(stoi(pais),stoi(ciudad));
			if (nodoCiudad!=NULL){ //Se verifica que el numero de producto no este ya ingresado en la lista
				pnodoRest nodoRest = buscarRest(stoi(pais), stoi(ciudad), stoi(rest));
				if (nodoRest==NULL){
					insertarRest(stoi(pais), stoi(ciudad), stoi(rest), nombre);
				}
			} //Si cumple las condiciones ingresa el prducto
		}
		aux= aux->siguiente;}
	L1.~lista();
}

void listaPaises::leerMenu(string nombre){
	string linea;
	ifstream archivo(nombre.c_str());
	
	lista L1;
	
	while (!archivo.eof()) {	//Cada linea del archivo de productos se mete a una lista simple
		getline(archivo, linea);
		L1.InsertarFinal(linea);
    }
    pnodo aux=L1.primero; //se crea un nodo en primero de la lista simple
    while(aux!=NULL){ 
		int cont=0; 
    	int temp =aux->valor.length(); //Crea un temp con la cantidad de caracteres que tenga cada linea del nodo
    	string pais="";
    	string ciudad = "";
    	string nombre = "";
    	string rest = "";
    	string menu = "";
    	string tempNom=aux->valor;  //Un temp que tiene la linea
    	for (int i=0; i< temp; i++){ //Se hace un while con un contador mientras sea menor al temp
    		if (tempNom[i]==';'){ //Cuando se encuentra con un ; aumenta 1 al cont, esto para cambiar a la varibale a la que se le esta
    			cont++;}		  //agregando los caracteres
			else{ //Dependiendo del cont se le agrega a una variable o a otra
				if (cont==0){
					pais+=aux->valor[i];}
				if (cont==1){
					ciudad+=aux->valor[i];}
    			if (cont==2){
    				rest+=aux->valor[i];}
    			if (cont==3){
    				menu+=aux->valor[i];}
				if (cont==4){
    				nombre+=aux->valor[i];}
			}
		}
		pnodoPaises nodoPais = buscarPais(stoi(pais));
		if(nodoPais!=NULL){ //Se verifica que el numero de pasillo se encuentre ingresado en la lista
			pnodoCiudades nodoCiudad = buscarCiudad(stoi(pais),stoi(ciudad));
			if (nodoCiudad!=NULL){ //Se verifica que el numero de producto no este ya ingresado en la lista
				pnodoRest nodoRest = buscarRest(stoi(pais), stoi(ciudad), stoi(rest));
				if (nodoRest!=NULL){
					pnodoMenu nodoMenu = buscarMenu(stoi(pais), stoi(ciudad), stoi(rest), stoi(menu));
					if (nodoMenu==NULL){
						insertarMenu(stoi(pais), stoi(ciudad), stoi(rest), stoi(menu), nombre);
					}
				}
			} //Si cumple las condiciones ingresa el prducto
		}
		aux= aux->siguiente;}
	L1.~lista();
}

void listaPaises::leerProductos(string nombre){
		string linea;
	ifstream archivo(nombre.c_str());
	
	lista L1;
	
	while (!archivo.eof()) {	//Cada linea del archivo de productos se mete a una lista simple
		getline(archivo, linea);
		L1.InsertarFinal(linea);
    }
    pnodo aux=L1.primero; //se crea un nodo en primero de la lista simple
    while(aux!=NULL){ 
		int cont=0; 
    	int temp =aux->valor.length(); //Crea un temp con la cantidad de caracteres que tenga cada linea del nodo
    	string pais="";
    	string ciudad = "";
    	string nombre = "";
    	string rest = "";
    	string menu = "";
    	string prod = "";
    	string kcal = "";
    	string precio = "";
    	string tempNom=aux->valor;  //Un temp que tiene la linea
    	for (int i=0; i< temp; i++){ //Se hace un while con un contador mientras sea menor al temp
    		if (tempNom[i]==';'){ //Cuando se encuentra con un ; aumenta 1 al cont, esto para cambiar a la varibale a la que se le esta
    			cont++;}		  //agregando los caracteres
			else{ //Dependiendo del cont se le agrega a una variable o a otra
				if (cont==0){
					pais+=aux->valor[i];}
				if (cont==1){
					ciudad+=aux->valor[i];}
    			if (cont==2){
    				rest+=aux->valor[i];}
    			if (cont==3){
    				menu+=aux->valor[i];}
				if (cont==4){
    				prod+=aux->valor[i];}
    			if (cont==5){
    				nombre+=aux->valor[i];}
    			if (cont==6){
    				kcal+=aux->valor[i];}
    			if (cont==7){
    				precio+=aux->valor[i];}
			}
		}
//		cout<<pais<<"-"<<ciudad<<"-"<<rest<<"-"<<menu<<"-"<<prod<<"-"<<nombre<<"-"<<kcal<<"-"<<precio<<endl;
		pnodoPaises nodoPais = buscarPais(stoi(pais));
		if(nodoPais!=NULL){ //Se verifica que el numero de pasillo se encuentre ingresado en la lista
			pnodoCiudades nodoCiudad = buscarCiudad(stoi(pais),stoi(ciudad));
			if (nodoCiudad!=NULL){ //Se verifica que el numero de producto no este ya ingresado en la lista
				pnodoRest nodoRest = buscarRest(stoi(pais), stoi(ciudad), stoi(rest));
				if (nodoRest!=NULL){
					pnodoMenu nodoMenu = buscarMenu(stoi(pais), stoi(ciudad), stoi(rest), stoi(menu));
					if (nodoMenu!=NULL){
						pnodoProductos nodoProd = buscarProd(stoi(pais), stoi(ciudad), stoi(rest), stoi(menu), stoi(rest));
						if (nodoProd==NULL){
							insertarProducto(stoi(pais), stoi(ciudad), stoi(rest), stoi(menu),stoi(prod), nombre,stoi(kcal),stoi(precio));
						}
					}
				}
			} //Si cumple las condiciones ingresa el prducto
		}
		aux= aux->siguiente;}
	L1.~lista();
}

