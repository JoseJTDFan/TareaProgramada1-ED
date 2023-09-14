//Jos� Juli�n Brenes Garro y Gustavo Pacheco Morales
//c.2022272865
//Estructuras de Datos

#pragma once
#include <iostream>
#include "listaProductos.h"
using namespace std;

class nodoMenu {
   public:
    nodoMenu(int pais, int ciudad, int rest, int pmenu, string pnombre)
    {
        codPais = pais;
	    codCiudad= ciudad;
	    codRest = rest;
	    codMenu = pmenu;
	    nombre = pnombre;
       	siguiente = NULL;
       	anterior =NULL;
    }
    
    nodoMenu(int pais, int ciudad, int rest, int pmenu, string pnombre, int cantBusquedas)
    {
        codPais = pais;
	    codCiudad= ciudad;
	    codRest = rest;
	    codMenu = pmenu;
	    nombre = pnombre;
	    cantBusquedas = 0;
       	siguiente = NULL;
       	anterior =NULL;
    }

    nodoMenu(int pais, int ciudad, int rest, int pmenu, string pnombre ,nodoMenu * signodo)
    {
        codPais = pais;
	    codCiudad= ciudad;
	    codRest = rest;
	    codMenu = pmenu;
	    nombre = pnombre;
       	siguiente = NULL;
       	anterior =NULL;
       siguiente = signodo;
    }

   private:
		int codPais;
	    int codCiudad;
	    int codRest;
	    int codMenu;
	    string nombre;
	    int cantBusquedas;
	    nodoMenu *siguiente;
	    nodoMenu *anterior;
	    listaProductos productos;
    
        
   friend class listaMenu;
   friend class listaPaises;
   friend class Menu;
};

typedef nodoMenu *pnodoMenu;
