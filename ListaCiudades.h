//José Julián Brenes Garro y Gustavo Pacheco Morales
//c.2022272865
//Estructuras de Datos

#pragma once
#include "nodoCiudades.h"
#include <iostream>
#include <fstream>
#include <string>
#include "ListaSimple.h"


using namespace std;



class listaCiudades {
   public:
    listaCiudades() { primero = NULL; }
    ~listaCiudades();
    
    void InsertarInicio(int pais, int ciudad, string pnombre);
    void InsertarFinal(int pais, int ciudad, string pnombre);
    void InsertarPos (int pais, int ciudad, string pnombre, int pos);
    bool ListaVacia() { return primero == NULL; } 
    void Imprimir();
    void Mostrar();
    void BorrarFinal();
    void BorrarInicio();
    void BorrarPosicion(int pos);
    int largoLista();
    
    pnodoCiudades buscarCiudad(int ciudad);
    
   private:
    pnodoCiudades primero;
   
};
