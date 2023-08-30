//José Julián Brenes Garro y Gustavo Pacheco Morales
//c.2022272865
//Estructuras de Datos

#pragma once
#include <iostream>
#include "ListaCiudades.h"
using namespace std;

class nodoPaises {
   public:
    nodoPaises(int pais, string pnombre)
    {
       codPais = pais;
       nombre = pnombre;
       siguiente = NULL;
       anterior =NULL;
    }

   nodoPaises(int pais, string pnombre, nodoPaises * signodo)
    {
       codPais = pais;
       nombre = pnombre;
       siguiente = signodo;
    }

 private:
    int codPais;
    string nombre;
    nodoPaises *siguiente;
    nodoPaises *anterior;
    listaCiudades ciudades;
    
        
   friend class listaPaises;
   friend class Menu;
};
typedef nodoPaises *pnodoPaises;


