//Jos� Juli�n Brenes Garro y Gustavo Pacheco Morales
//c.2022272865
//Estructuras de Datos

#pragma once
#include <iostream>
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
    
    friend class listaClientes;
    
   };
typedef nodoClientes *pnodoClientes; //Alias

