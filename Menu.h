//José Julián Brenes Garro y Gustavo Pacheco Morales
//c.2022272865
//Estructuras de Datos

#include <iostream>
#include "ListaSimple.h"
#include "ListaDC.h"
#include "ListaDoble.h"
#include "ListaPaises.h"
#include "listaRest.h"
#include "listaClientes.h"
#include <cstdlib>


using namespace std;



class Menu {
	public:
		void lecturaArchivos();
		void menu();
		void insertar();
		void eliminar();
		void buscar();
		void modificar();
		void reportes();
		
		void insertarPais();
		void insertarClientes();
		
	private:
		listaPaises baseDeDatos;
		listaClientes clientes; //lista de clientes
};

void Menu::lecturaArchivos(){
	baseDeDatos.leerPaises("Paises.txt");
	baseDeDatos.leerCiudades("Ciudades.txt");
	baseDeDatos.leerRestaurantes("Restaurantes.txt");
	clientes.leerClientes("Clientes.txt");
}

void Menu::insertarPais(){
	system("cls");
	cout<<"****************************** INSERTAR PAIS ******************************"<<endl;
	cout<<endl<<"Ingrese el codigo del pais a agregar: ";
	
	int codPais;
	string nombre;
	
	cin>>codPais;
	pnodoPaises nodoPais = baseDeDatos.buscarPais(codPais);
	if (nodoPais==NULL){
		cout<<endl<<"Ingrese el nombre del pais a agregar: ";
		cin>>nombre;
		baseDeDatos.InsertarInicio(codPais,nombre);
		system("cls");
		baseDeDatos.Mostrar();
		system("pause");
	}
	else{
		cout<<endl<<"Este codigo ya se encuentra registrado."<<endl;
		system("pause");
	}
}

void Menu::insertarClientes(){
	system("cls");
	cout<<"****************************** INSERTAR CLIENTE ******************************"<<endl;
	cout<<endl<<"Ingrese la cedula del cliente a agregar: ";
	
	int cedula;
	string nombreCliente;
	
	cin>>cedula;
	pnodoClientes nodoClientes = clientes.buscarClientes(cedula);
	if (nodoClientes==NULL){
		cout<<endl<<"Ingrese el nombre del cliente a agregar: ";
		cin>>nombreCliente;
		clientes.InsertarFinal(cedula,nombreCliente);
		system("cls");
		clientes.Mostrar();
		system("pause");
	}
	else{
		cout<<endl<<"Esta cedula ya se encuentra registrada."<<endl;
		system("pause");
	}
}

void Menu::insertar(){
	bool bandera=true;
	do{
		system("cls");
		cout<<"****************************** INSERTAR ******************************"<<endl;
		cout<<endl<<"Ingrese que desea insertar"<<endl<<endl;
		cout<<"1. Un pais."<<endl;
		cout<<"2. Una ciudad."<<endl;
		cout<<"3. Un restaurante."<<endl;
		cout<<"4. Un menu."<<endl;
		cout<<"5. Un producto."<<endl;
		cout<<"6. Un cliente."<<endl;
		cout<<"7. Salir."<<endl;
		cout<<endl<<"----> ";
		int opcion;
	
		cin>>opcion;
		cout<<endl;
		switch (opcion){
			case 1:
				insertarPais();
				break;
			case 2:
				menu();
				break;
			case 3:
				menu();
				break;
			case 4:
				menu();
				break;
			case 5:
				menu();
				break;
			case 6:
				insertarClientes();
				break;
			case 7:
				bandera=false;
				break;
			default:
				cout<<"Ingrese un numero valido"<<endl;
				system("pause");
				break;
			}
	}while(bandera);
	
}
	
void Menu::menu(){
	bool bandera=true;
	do{
		system("cls");
		cout<<"****************************** MC'DONALD'S ******************************"<<endl;
		cout<<endl<<"¡Bienvenido a la base de datos de McDonald's! ¿Que desea realizar?"<<endl<<endl;
		cout<<"1. Insertar."<<endl;
		cout<<"2. Eliminar."<<endl;
		cout<<"3. Buscar."<<endl;
		cout<<"4. Modificar"<<endl;
		cout<<"5. Reportar"<<endl;
		cout<<"6. Salir"<<endl;
		cout<<endl<<"----> ";
		int opcion;
		cin>>opcion;
		cout<<endl;
		switch (opcion){
		case 1:
			insertar();
			menu();
			break;
		case 2:
			menu();
			break;
		case 3:
			menu();
			break;
		case 4:
			menu();
			break;
		case 5:
			menu();
			break;
		case 6:
			bandera=false;
			break;
		default:
			cout<<"Ingrese un numero valido"<<endl;
			system("pause");
			break;
		}
	}while(bandera);
	
	
}
