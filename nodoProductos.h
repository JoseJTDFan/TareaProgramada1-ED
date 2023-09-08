//José Julián Brenes Garro y Gustavo Pacheco Morales
//c.2022272865
//Estructuras de Datos

#pragma once
#include <iostream>
using namespace std;

class nodoProductos {
   public:
	nodoProductos(int pais, int ciudad, int rest, int pmenu,int producto, string pnombre,int calorias, int pprecio)
    {
        codPais = pais;
	    codCiudad= ciudad;
	    codRest = rest;
	    codMenu = pmenu;
	    codProducto =producto;
	    nombre = pnombre;
	    kcal = calorias;
	    precio = pprecio;
       	siguiente = NULL;
       	anterior =NULL;
    }

nodoProductos(int pais, int ciudad, int rest, int pmenu,int producto, string pnombre,int calorias, int pprecio, nodoProductos * signodo)
    {
        codPais = pais;
	    codCiudad= ciudad;
	    codRest = rest;
	    codMenu = pmenu;
	    codProducto =producto;
	    nombre = pnombre;
	    kcal = calorias;
	    precio = pprecio;
       	siguiente = NULL;
       	anterior =NULL;
       siguiente = signodo;
    }

   private:
    	int codPais;
	    int codCiudad;
	    int codRest;
	    int codMenu;
	    int codProducto;
	    string nombre;
	    int kcal;
	    int precio;
	    nodoProductos *siguiente;
	    nodoProductos *anterior;
        
   friend class listaProductos;
   friend class listaPaises;
   friend class Menu;
};

typedef nodoProductos *pnodoProductos;
