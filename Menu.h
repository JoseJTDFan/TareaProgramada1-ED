//José Julián Brenes Garro y Gustavo Pacheco Morales
//c.2022272865
//Estructuras de Datos

#include <iostream>
#include "ListaSimple.h"
#include "ListaPaises.h"
#include "listaRest.h"
#include "listaClientes.h"
#include "cola.h"
#include <cstdlib>
#include <string.h>


using namespace std;



class Menu {
	public:
		//Menu
		void lecturaArchivos();
		void menu();
		void insertar();
		void eliminar();
		void buscar();
		void modificar();
		void reportes();
		void comprar();
		
		//Insertar
		void insertarPais();
		void insertarCiudad();
		void insertarRest();
		void insertarMenu();
		void insertarProducto();
		void insertarClientes();

		//Eliminar
		void eliminarPais();
		void eliminarCiudad();
		void eliminarRest();
		void eliminarMenu();
		void eliminarProducto();
		void eliminarClientes();
		
		//Buscar
		void buscarPais();
		void buscarCiudad();
		void buscarRest();
		void buscarMenu();
		void buscarProducto();
		void buscarClientes();
		
		//Modificar
		void modificarPais();
		void modificarCiudad();
		void modificarRest();
		void modificarMenu();
		void modificarProducto();
		void modificarCliente();
		void modificarCompra();
		
		//Reportes
		void reportarPais();
		void reportarCiudad();
		void reportarRest();
		void reportarCliente();
		void reportarRestMasBuscado();
		void reportarMenuMasBuscado();
		void reportarPrecio();
		
		//Extra
		bool desicion(bool bandera);
		void guardarEnArchivo(string nombreArchivo, string texto);

	private:
		listaPaises baseDeDatos;
		listaClientes clientes; //lista de clientes
		cola colaClientes;
};

