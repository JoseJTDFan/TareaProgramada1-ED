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
	    cantidad = 1;
	    cantCompra=0;
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
	    cantidad = 1;
	    cantCompra=0;
       	siguiente = NULL;
       	anterior =NULL;
       siguiente = signodo;
    }

nodoProductos(int pais, int ciudad, int rest, int pmenu,int producto, string pnombre,int calorias, int pprecio, int pcantidad)
    {
        codPais = pais;
	    codCiudad= ciudad;
	    codRest = rest;
	    codMenu = pmenu;
	    codProducto =producto;
	    nombre = pnombre;
	    kcal = calorias;
	    precio = pprecio;
	    cantidad = pcantidad;
	    cantCompra=0;
       	siguiente = NULL;
       	anterior =NULL;
    }

nodoProductos(int pais, int ciudad, int rest, int pmenu,int producto, int calorias, string pnombre, int pprecio, int pcantCompra)
    {
        codPais = pais;
	    codCiudad= ciudad;
	    codRest = rest;
	    codMenu = pmenu;
	    codProducto =producto;
	    nombre = pnombre;
	    kcal = calorias;
	    precio = pprecio;
	    cantidad = 0;
	    cantCompra=pcantCompra;
       	siguiente = NULL;
       	anterior =NULL;
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
	    int cantidad;
	    int cantCompra;
	    nodoProductos *siguiente;
	    nodoProductos *anterior;
        
   friend class listaProductos;
   friend class listaPaises;
   friend class Menu;
};

typedef nodoProductos *pnodoProductos;
