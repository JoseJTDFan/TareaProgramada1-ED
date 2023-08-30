//José Julián Brenes Garro y Gustavo Pacheco Morales
//c.2022272865
//Estructuras de Datos

#pragma once
#include "nodoMenu.h"
using namespace std;

class listaMenu {
   public:
    listaMenu() { primero =  NULL; }
    ~listaMenu();
    
    void InsertarInicio(int pais, int ciudad, int rest, int pmenu, string pnombre);
    void InsertarFinal(int pais, int ciudad, int rest, int pmenu, string pnombre);
    void InsertarPos (int pais, int ciudad, int rest, int pmenu, string pnombre, int pos);
    bool ListaVacia() { return primero == NULL; } 
    void BorrarFinal();
    void BorrarInicio();
    void BorrarPosicion(int pos);
    void Mostrar();
    int largoLista();
    int getPosicion(int codigo);
    
    pnodoMenu buscarMenu(int menu);
    
   private:
    pnodoMenu primero;
  
  friend class Menu;
};
