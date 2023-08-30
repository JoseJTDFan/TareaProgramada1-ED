//José Julián Brenes Garro y Gustavo Pacheco Morales
//c.2022272865
//Estructuras de Datos

#pragma once
#include "nodoRest.h"
#include "nodoCiudades.h"
#include "nodoPaises.h"
#include <iostream>
#include <fstream>
#include <string>
#include "ListaSimple.h"


using namespace std;



class listaPaises {
   public:
    listaPaises() { primero = NULL; }
    ~listaPaises();
    
    void InsertarInicio(int pais, string pnombre);
    void InsertarFinal(int pais, string pnombre);
    void InsertarPos (int pais, string pnombre, int pos);
    bool ListaVacia() { return primero == NULL; } 
    void Imprimir();
    void Mostrar();
    void BorrarFinal();
    void BorrarInicio();
    void BorrarPosicion(int pos);
    int largoLista();
    bool verificar(int num);
    int getPosicion(int codigo);
        
    void leerPaises(string nombre);
    void leerCiudades(string nombre);
    void leerRestaurantes(string nombre);
    void leerMenu(string nombre);
    void leerProductos(string nombre);
    
    pnodoPaises buscarPais(int pais);
    pnodoCiudades buscarCiudad(int pais, int ciudad);
    pnodoRest buscarRest(int pais, int ciudad, int rest);
    pnodoMenu buscarMenu(int pais, int ciudad, int rest, int menu);
    pnodoProductos buscarProd(int pais, int ciudad, int rest, int menu, int prod);
    
    void insertarCiudad(int pais, int ciudad, string nombre);
    void insertarRest(int pais, int ciudad,int rest, string nombre);
    void insertarMenu(int pais, int ciudad,int rest, int menu, string nombre);
    void insertarProducto(int pais, int ciudad,int rest, int menu,int prod, string nombre, int kcal, int precio);
    
	 
   private:
    pnodoPaises primero;
   
};
