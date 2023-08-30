//José Julián Brenes Garro y Gustavo Pacheco Morales
//c.2022272865
//Estructuras de Datos

#pragma once
#include "nodoClientes.h"
#include "ListaSimple.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;



class listaClientes {
   public:
    listaClientes() { primero =  NULL; }//constructor
    ~listaClientes();//destructor
    
    void InsertarInicio(int cedula_Parametro, string nombre);//No retornan nada
    void InsertarFinal(int cedula_Parametro, string nombre);
    void InsertarPos (int cedula_Parametro, string nombre, int pos);
    bool ListaVacia() { return primero == NULL; } //retorna True o False
    void Mostrar();//imprimir
    void BorrarFinal();
    void BorrarInicio();
    void borrarPosicion(int pos);
    int largoLista();// retorno un valor numerico
    bool buscarNum(int num);
    pnodoClientes buscarClientes(int cedula_parametro);
    void leerClientes(string nombre);
    
   private:
    pnodoClientes primero;
};

