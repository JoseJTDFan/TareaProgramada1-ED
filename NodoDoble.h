//José Julián Brenes Garro y Gustavo Pacheco Morales
//c.2022272865
//Estructuras de Datos

#pragma once
#include <iostream>
using namespace std;

class nodoDoble {
   public:
    nodoDoble(int v)
    {
       valor = v;
       siguiente = NULL;
       anterior =NULL;
    }

nodoDoble(int v, nodoDoble * signodo)
    {
       valor = v;
       siguiente = signodo;
    }

   private:
    int valor;
    nodoDoble *siguiente;
    nodoDoble *anterior;
    
        
   friend class listaDoble;
};

typedef nodoDoble *pnodoDoble;
