//José Julián Brenes Garro y Gustavo Pacheco Morales
//c.2022272865
//Estructuras de Datos

#pragma once
#include "NodoDC.h"
#include <iostream>
#include <fstream>
#include <string>
#include "ListaSimple.h"


using namespace std;



class listaDC {
   public:
    listaDC() { primero = NULL; }
    ~listaDC();
    
    void InsertarInicio(int v);
    void InsertarFinal(int v);
    void InsertarPos (int v, int pos);
    bool ListaVacia() { return primero == NULL; } 
    void Imprimir();
    void Borrar(int v);
    void Mostrar();
    void BorrarFinal();
    void BorrarInicio();
    void BorrarPosicion(int pos);
    int largoLista();
    
        
    void leerPasillo(listaDC &L2,lista &L1, string nombre);
    
   private:
    pnodoDC primero;
   
};
