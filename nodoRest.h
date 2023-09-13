//José Julián Brenes Garro y Gustavo Pacheco Morales
//c.2022272865
//Estructuras de Datos

#pragma once
#include <iostream>
#include "listaMenu.h"

using namespace std;

class nodoRest {
   public:
    nodoRest(int pais, int ciudad, int rest, string pnombre)
    {
        codPais = pais;
	    codCiudad= ciudad;
	    codRest = rest;
	    nombre = pnombre;
       	siguiente = NULL;
       	anterior =NULL;
       	cantBusquedas=0;
    }

   nodoRest(int pais, int ciudad, int rest, string pnombre, nodoRest * signodo)
    {
       codPais = pais;
	    codCiudad= ciudad;
	    codRest = rest;
	    nombre = pnombre;
       siguiente = signodo;
       cantBusquedas=0;
    }
    nodoRest(int pais, int ciudad, int rest, string pnombre, int pcantidadBusqueda)
    {
        codPais = pais;
	    codCiudad= ciudad;
	    codRest = rest;
	    nombre = pnombre;
       	siguiente = NULL;
       	anterior =NULL;
       	cantBusquedas=pcantidadBusqueda;
    }

 private:
    int codPais;
    int codCiudad;
    int codRest;
    string nombre;
    nodoRest *siguiente;
    nodoRest *anterior;
    listaMenu menus;
    int cantBusquedas;
    
        
   friend class listaRest;
   friend class listaPaises;
   friend class Menu;
};
typedef nodoRest *pnodoRest;
