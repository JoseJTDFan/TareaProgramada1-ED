//José Julián Brenes Garro y Gustavo Pacheco Morales
//c.2022272865
//Estructuras de Datos

#pragma once
#include <iostream>
using namespace std;

class nodoDC {
   public:
    nodoDC(int v)
    {
       valor = v;
       siguiente = NULL;
       anterior =NULL;
    }

   nodoDC(int v, nodoDC * signodo)
    {
       valor = v;
       siguiente = signodo;
    }

 private:
    int valor;
    nodoDC *siguiente;
    nodoDC *anterior;
    
        
   friend class listaDC;
};
typedef nodoDC *pnodoDC;
