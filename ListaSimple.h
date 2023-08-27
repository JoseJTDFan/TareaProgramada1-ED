//José Julián Brenes Garro y Gustavo Pacheco Morales
//c.2022272865
//Estructuras de Datos

#pragma once
#include <iostream>
#include "NodoSimple.h"
using namespace std;


class lista {
   public:
    lista() { primero =  NULL; }//constructor
    ~lista();//destructor
    
    void InsertarInicio(int v);//No retornan nada
    void InsertarFinal(int v);
    void InsertarPos (int v, int pos);
    bool ListaVacia() { return primero == NULL; } //retorna True o False
    void Mostrar();//imprimir
    void BorrarFinal();
    void BorrarInicio();
    void borrarPosicion(int pos);
    void Sumanum(int num);
    int largoLista();// retorno un valor numerico
    void promedioDigitos(int num);
    void invertirLista();
    int contDigitos(int num);
    bool buscarNum(int num);
    bool buscarNumPos (int num, int pos);
    void sumaListasIgual(lista *L2);
    void sumaListasDiff(lista *L2);
    int contarPares(int num);
    void sumarParMultImp(int num);
    void sumaNodosLista(int num1, int num2);
    void potenciaParesImpares(int num);
    
    //Tarea 4
    void mezclar (int num1, int num2);
    void centroSuma(int num);
    
   private:
    pnodo primero;
   
};


