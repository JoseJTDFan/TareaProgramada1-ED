//Jos� Juli�n Brenes Garro y Gustavo Pacheco Morales
//c.2022272865
//Estructuras de Datos

#pragma once
#include "nodoProductos.h"
using namespace std;

class listaProductos {
   public:
    listaProductos() { primero =  NULL; }
    ~listaProductos();
    
    void InsertarInicio(int pais, int ciudad, int rest, int pmenu,int producto, string pnombre,int calorias, int precio);
    void InsertarFinal(int pais, int ciudad, int rest, int pmenu,int producto, string pnombre,int calorias, int precio);
    void InsertarPos (int pais, int ciudad, int rest, int pmenu,int producto, string pnombre,int calorias, int precio, int pos);
    bool ListaVacia() { return primero == NULL; } 
    void BorrarFinal();
    void BorrarInicio();
    void BorrarPosicion(int pos);
    void Mostrar();
    int largoLista();
    int getPosicion(int codigo);
    string getNombreProducto(int pos);
    int getKcalProducto(int pos);
    int getPrecioProducto(int pos);
    
    pnodoProductos buscarProducto(int prod);
    
   private:
    pnodoProductos primero;
  
};
