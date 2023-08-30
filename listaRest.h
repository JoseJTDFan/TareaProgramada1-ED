//José Julián Brenes Garro y Gustavo Pacheco Morales
//c.2022272865
//Estructuras de Datos

#pragma once
#include "nodoRest.h"
#include <iostream>
#include <fstream>
#include <string>
#include "ListaSimple.h"


using namespace std;



class listaRest {
   public:
    listaRest() { primero = NULL; }
    ~listaRest();
    
    void InsertarInicio(int pais, int ciudad, int rest, string pnombre);
    void InsertarFinal(int pais, int ciudad, int rest, string pnombre);
    void InsertarPos (int pais, int ciudad, int rest, string pnombre, int pos);
    bool ListaVacia() { return primero == NULL; } 
    void Imprimir();
    void Borrar(int v);
    void Mostrar();
    void BorrarFinal();
    void BorrarInicio();
    void BorrarPosicion(int pos);
    int largoLista();
    
    pnodoRest buscarRest(int rest);
    
   private:
    pnodoRest primero;
   
};
