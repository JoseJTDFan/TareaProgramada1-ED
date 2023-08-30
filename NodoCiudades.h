//José Julián Brenes Garro y Gustavo Pacheco Morales
//c.2022272865
//Estructuras de Datos

#pragma once
#include <iostream>
#include "listaRest.h"
using namespace std;

class nodoCiudades {
   public:
    nodoCiudades(int pais, int ciudad, string pnombre)
    {
        codPais = pais;
	    codCiudad= ciudad;
	    nombre = pnombre;
       siguiente = NULL;
       anterior =NULL;
    }

nodoCiudades(int pais, int ciudad, string pnombre, nodoCiudades * signodo)
    {
        codPais = pais;
	    codCiudad= ciudad;
		nombre = pnombre;
        siguiente = signodo;
    }

   private:
    int codPais;
    int codCiudad;
    string nombre;
    nodoCiudades *siguiente;
    nodoCiudades *anterior;
    listaRest restaurantes;
    
        
   friend class listaCiudades;
   friend class listaPaises;
   friend class Menu;
};

typedef nodoCiudades *pnodoCiudades;
