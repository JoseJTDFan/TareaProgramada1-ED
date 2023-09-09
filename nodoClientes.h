//José Julián Brenes Garro y Gustavo Pacheco Morales
//c.2022272865
//Estructuras de Datos

#pragma once
#include <iostream>
#include "listaProductos.h"
using namespace std;

class nodoClientes { // Constructores
   public:
   	
	nodoClientes(int cedula_Parametro, string nombre)
    {
       cedula = cedula_Parametro;
       nombreCliente = nombre;
       siguiente = NULL;
    }

	nodoClientes(int cedula_Parametro, string nombre, nodoClientes  *signodoClientes)
    {
       cedula = cedula_Parametro;
       nombreCliente = nombre;
       siguiente = signodoClientes;
    }

   private:
    int cedula;
    string nombreCliente;
    nodoClientes *siguiente;// Clase Autoreferencia
    listaProductos productos;
    
    friend class listaClientes;
    friend class Menu;
    friend class cola;
    
   };
typedef nodoClientes *pnodoClientes; //Alias


