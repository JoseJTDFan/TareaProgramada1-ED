//José Julián Brenes Garro y Gustavo Pacheco Morales
//c.2022272865
//Estructuras de Datos

#include <iostream>
#include "nodoClientes.h"
using namespace std;

class cola 
{
private:
    int frente;
    int fondo;
    pnodoClientes Cola[5]; // Definición del arreglo de punteros a nodoClientes

public:
    cola() {
        frente = 0;
        fondo = -1;
        for (int i = 0; i < 5; i++) {
            Cola[i] = nullptr; // Inicializar punteros como nullptr
        }
    }

    bool ColaVacia() { return fondo < frente; }
    bool ColaLlena() { return fondo == 4;}
	int getPosicion(int cedula);
    void insertar(pnodoClientes cliente);
    void eliminar();
    void imprimir();
    bool buscar(int cedula);
    void eliminarPorPosicion(int posicion);
};
