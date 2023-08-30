//José Julián Brenes Garro y Gustavo Pacheco Morales
//c.2022272865
//Estructuras de Datos

#pragma once
#include <iostream>
using namespace std;

class nodo { // Constructores
   public:
   	
   	
nodo(string v)//3
    {
       valor = v;
       siguiente = NULL;
    }

nodo(string v, nodo  *signodo)
    {
       valor = v;
       siguiente = signodo;
    }


   private:
    string valor="";
    nodo *siguiente;// Clase Autoreferencia
    
        
   friend class lista;
   friend class listaPaises;
   friend class listaClientes;
   };

typedef nodo *pnodo; //Alias

//void no retorna nada
//bool retorna False o True
//int retorna entero


