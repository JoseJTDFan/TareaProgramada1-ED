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
#include <string.h>


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
		void insertarCiudad();
		void insertarRest();
		void insertarMenu();
		void insertarProducto();
		void insertarClientes();

		
		void eliminarPais();
		void eliminarCiudad();
		void eliminarRest();
		void eliminarMenu();
		void eliminarProducto();
		void eliminarClientes();

	private:
		listaPaises baseDeDatos;
		listaClientes clientes; //lista de clientes
};

void Menu::lecturaArchivos(){
	baseDeDatos.leerPaises("Paises.txt");
	baseDeDatos.leerCiudades("Ciudades.txt");
	baseDeDatos.leerRestaurantes("Restaurantes.txt");
	baseDeDatos.leerMenu("Menu.txt");
	baseDeDatos.leerProductos("Productos.txt");
	clientes.leerClientes("Clientes.txt");
}
//////////////////////////////////////////////////INSERTAR
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
		cin.ignore();
		getline(cin,nombre);
		baseDeDatos.InsertarInicio(codPais,nombre);
		system("cls");
		baseDeDatos.Mostrar();
		cout<<endl<<"Se ha insertado el pais."<<endl;
		system("pause");
	}
	else{
		cout<<endl<<"Este codigo ya se encuentra registrado."<<endl;
		system("pause");
	}
}

void Menu::insertarCiudad(){
	system("cls");
	cout<<"****************************** INSERTAR CIUDAD ******************************"<<endl<<endl;
	baseDeDatos.Mostrar();
	cout<<endl<<"Ingrese el codigo del pais que quiere insertar una ciudad: ";
	
	int codPais;
	string nombre;
	cin>>codPais;
	cout<<endl;
	
	pnodoPaises nodoPais = baseDeDatos.buscarPais(codPais);
	if(nodoPais==NULL){
		cout<<endl<<"Pais Invalido o No Registrado"<<endl;
		system("pause");
		return;
	}
	system("cls");
	cout<<endl<<"Ingrese el codigo de la ciudad a agregar: ";
	int codCiudad;
	cin>>codCiudad;
	
	pnodoCiudades nodoCiudad = baseDeDatos.buscarCiudad(codPais, codCiudad);
	if (nodoCiudad==NULL){
		cout<<endl<<"Ingrese el nombre de la ciudad a agregar: ";
		cin.ignore();
		getline(cin,nombre);
		baseDeDatos.insertarCiudad(codPais, codCiudad, nombre);
		system("cls");
		nodoPais->ciudades.Mostrar();
		cout<<endl<<"Se ha insertado la ciudad."<<endl;
		system("pause");
	}
	else{
		cout<<endl<<"Este codigo ya se encuentra registrado."<<endl;
		system("pause");
		return;
	}
	
}

void Menu::insertarRest(){
	system("cls");
	cout<<"****************************** INSERTAR RESTAURANTE ******************************"<<endl<<endl;
	baseDeDatos.Mostrar();
	cout<<endl<<"Ingrese el codigo del pais que quiere insertar un restaurante: ";
	
	int codPais;
	string nombre;
	cin>>codPais;
	cout<<endl;
	pnodoPaises nodoPais = baseDeDatos.buscarPais(codPais);
	if(nodoPais==NULL){
		cout<<endl<<"Pais Invalido o No Registrado"<<endl;
		system("pause");
		return;
	}
	if (nodoPais->ciudades.primero==NULL){
		cout<<endl<<"No hay ciudades registradas."<<endl;
		system("pause");
		return;
	}
	system("cls");
	nodoPais->ciudades.Mostrar();
	
	cout<<endl<<"Ingrese el codigo de la ciudad que quiere insertar un restaurante: ";
	int codCiudad;
	cin>>codCiudad;
	pnodoCiudades nodoCiudad = baseDeDatos.buscarCiudad(codPais, codCiudad);
	if(nodoCiudad==NULL){
		cout<<endl<<"Ciudad Invalida o No Registrada"<<endl;
		system("pause");
		return;
	}
	system("cls");
	cout<<endl<<"Ingrese el codigo del restaurante a agregar: ";
	int codRest;
	cin>>codRest;
	
	pnodoRest nodoRest = baseDeDatos.buscarRest(codPais,codCiudad,codRest);
	if (nodoRest==NULL){
		cout<<endl<<"Ingrese el nombre del restaurante a agregar: ";
		cin.ignore();
		getline(cin,nombre);
		baseDeDatos.insertarRest(codPais,codCiudad,codRest, nombre);
		system("cls");
		nodoCiudad->restaurantes.Mostrar();
		cout<<endl<<"Se ha insertado el restaurante."<<endl;
		system("pause");
	}
	else{
		cout<<endl<<"Este codigo ya se encuentra registrado."<<endl;
		system("pause");
		return;
	}
	
}

void Menu::insertarMenu(){
	system("cls");
	cout<<"****************************** INSERTAR MENU ******************************"<<endl<<endl;
	baseDeDatos.Mostrar();
	cout<<endl<<"Ingrese el codigo del pais que quiere insertar un menu: ";
	
	int codPais;
	string nombre;
	cin>>codPais;
	cout<<endl;
	pnodoPaises nodoPais = baseDeDatos.buscarPais(codPais);
	if(nodoPais==NULL){
		cout<<endl<<"Pais Invalido o No Registrado"<<endl;
		system("pause");
		return;
	}
	if (nodoPais->ciudades.primero==NULL){
		cout<<endl<<"No hay ciudades registradas."<<endl;
		system("pause");
		return;
	}
	
	system("cls");
	nodoPais->ciudades.Mostrar();
	cout<<endl<<"Ingrese el codigo de la ciudad que quiere insertar un menu: ";
	int codCiudad;
	cin>>codCiudad;
	pnodoCiudades nodoCiudad = baseDeDatos.buscarCiudad(codPais, codCiudad);
	if(nodoCiudad==NULL){
		cout<<endl<<"Ciudad Invalida o No Registrada"<<endl;
		system("pause");
		return;
	}
	if (nodoCiudad->restaurantes.primero==NULL){
		cout<<endl<<"No hay restaurantes registrados."<<endl;
		system("pause");
		return;
	}
	
	system("cls");
	nodoCiudad->restaurantes.Mostrar();
	cout<<endl<<"Ingrese el codigo del restaurante que quiere insertar un menu: ";
	int codRest;
	cin>>codRest;
	pnodoRest nodoRest = baseDeDatos.buscarRest(codPais, codCiudad,codRest);
	if(nodoRest==NULL){
		cout<<endl<<"Restaurante Invalido o No Registrado"<<endl;
		system("pause");
		return;
	}
	
	system("cls");
	cout<<endl<<"Ingrese el codigo del menu a agregar: ";
	int codMenu;
	cin>>codMenu;
	
	pnodoMenu nodoMenu = baseDeDatos.buscarMenu(codPais,codCiudad,codRest,codMenu);
	if (nodoMenu==NULL){
		cout<<endl<<"Ingrese el nombre del menu a agregar: ";
		cin.ignore();
		getline(cin,nombre);
		baseDeDatos.insertarMenu(codPais,codCiudad,codRest,codMenu, nombre);
		system("cls");
		nodoRest->menus.Mostrar();
		cout<<endl<<"Se ha insertado el menu."<<endl;
		system("pause");
	}
	else{
		cout<<endl<<"Este codigo ya se encuentra registrado."<<endl;
		system("pause");
		return;
	}
}

void Menu::insertarProducto(){
	system("cls");
	cout<<"****************************** INSERTAR PRODUCTO ******************************"<<endl<<endl;
	baseDeDatos.Mostrar();
	cout<<endl<<"Ingrese el codigo del pais que quiere insertar un producto: ";
	
	int codPais;
	string nombre;
	cin>>codPais;
	cout<<endl;
	pnodoPaises nodoPais = baseDeDatos.buscarPais(codPais);
	if(nodoPais==NULL){
		cout<<endl<<"Pais Invalido o No Registrado"<<endl;
		system("pause");
		return;
	}
	if (nodoPais->ciudades.primero==NULL){
		cout<<endl<<"No hay ciudades registradas."<<endl;
		system("pause");
		return;
	}
	
	system("cls");
	nodoPais->ciudades.Mostrar();
	cout<<endl<<"Ingrese el codigo de la ciudad que quiere insertar un producto: ";
	int codCiudad;
	cin>>codCiudad;
	pnodoCiudades nodoCiudad = baseDeDatos.buscarCiudad(codPais, codCiudad);
	if(nodoCiudad==NULL){
		cout<<endl<<"Ciudad Invalida o No Registrada"<<endl;
		system("pause");
		return;
	}
	if (nodoCiudad->restaurantes.primero==NULL){
		cout<<endl<<"No hay restaurantes registrados."<<endl;
		system("pause");
		return;
	}
	
	system("cls");
	nodoCiudad->restaurantes.Mostrar();
	cout<<endl<<"Ingrese el codigo del restaurante que quiere insertar un producto: ";
	int codRest;
	cin>>codRest;
	pnodoRest nodoRest = baseDeDatos.buscarRest(codPais, codCiudad,codRest);
	if(nodoRest==NULL){
		cout<<endl<<"Restaurante Invalido o No Registrado"<<endl;
		system("pause");
		return;
	}
	if (nodoRest->menus.primero==NULL){
		cout<<endl<<"No hay menus registrados."<<endl;
		system("pause");
		return;
	}
	
	system("cls");
	nodoRest->menus.Mostrar();
	cout<<endl<<"Ingrese el codigo del menu que quiere insertar un producto: ";
	int codMenu;
	cin>>codMenu;
	pnodoMenu nodoMenu = baseDeDatos.buscarMenu(codPais, codCiudad,codRest,codMenu);
	if(nodoMenu==NULL){
		cout<<endl<<"Menu Invalido o No Registrado"<<endl;
		system("pause");
		return;
	}
	
	system("cls");
	cout<<endl<<"Ingrese el codigo del producto a agregar: ";
	int codProd;
	cin>>codProd;
	
	pnodoProductos nodoProd = baseDeDatos.buscarProd(codPais,codCiudad,codRest,codMenu, codProd);
	if (nodoProd==NULL){
		int kcal, precio;
		cout<<endl<<"Ingrese el nombre del producto a agregar: ";
		cin.ignore();
		getline(cin,nombre);
		cout<<endl<<endl<<"Ingrese las calorias del producto a agregar: ";
		cin>>kcal;
		cout<<endl<<endl<<"Ingrese el precio del producto a agregar: ";
		cin>>precio;
		baseDeDatos.insertarProducto(codPais,codCiudad,codRest,codMenu, codProd, nombre, kcal, precio);
		system("cls");
		nodoMenu->productos.Mostrar();
		cout<<endl<<"Se ha insertado el producto."<<endl;
		system("pause");
	}
	else{
		cout<<endl<<"Este codigo ya se encuentra registrado."<<endl;
		system("pause");
		return;
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
		cin.ignore();
		getline(cin,nombreCliente);
		clientes.InsertarFinal(cedula,nombreCliente);
		system("cls");
		clientes.Mostrar();
		cout<<endl<<"Se ha insertado el cliente."<<endl;
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
				insertarCiudad();
				break;
			case 3:
				insertarRest();
				break;
			case 4:
				insertarMenu();
				break;
			case 5:
				insertarProducto();
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

//////////////////////////////////////////////ELIMINAR
void Menu::eliminarPais(){
	system("cls");
	cout<<"****************************** ELIMINAR PAIS ******************************"<<endl;
	baseDeDatos.Mostrar();
	cout<<endl<<"Ingrese el codigo del pais a eliminar: ";
	int codPais;
	cin>>codPais;
	
	pnodoPaises nodoPais = baseDeDatos.buscarPais(codPais);
	if (nodoPais!=NULL){
		int posicion = baseDeDatos.getPosicion(codPais);
		baseDeDatos.BorrarPosicion(posicion);
		system("cls");
		baseDeDatos.Mostrar();
		cout<<endl<<"Se ha eliminado el pais."<<endl;
		system("pause");
	}
	else{
		cout<<endl<<"Este codigo no se encuentra registrado."<<endl;
		system("pause");
	}
}

void Menu::eliminarCiudad(){
	system("cls");
	cout<<"****************************** ELIMINAR CIUDAD ******************************"<<endl<<endl;
	baseDeDatos.Mostrar();
	cout<<endl<<"Ingrese el codigo del pais que quiere eliminar una ciudad: ";
	
	int codPais;
	cin>>codPais;
	cout<<endl;
	
	pnodoPaises nodoPais = baseDeDatos.buscarPais(codPais);
	if(nodoPais==NULL){
		cout<<endl<<"Pais Invalido o No Registrado"<<endl;
		system("pause");
		return;
	}
	system("cls");
	nodoPais->ciudades.Mostrar();
	cout<<endl<<"Ingrese el codigo de la ciudad a eliminar: ";
	int codCiudad;
	cin>>codCiudad;
	
	pnodoCiudades nodoCiudad = baseDeDatos.buscarCiudad(codPais, codCiudad);
	if (nodoCiudad!=NULL){
		int posicion = nodoPais->ciudades.getPosicion(codCiudad);
		nodoPais->ciudades.BorrarPosicion(posicion);
		system("cls");
		nodoPais->ciudades.Mostrar();
		cout<<endl<<"Se ha eliminado la ciudad."<<endl;
		system("pause");
	}
	else{
		cout<<endl<<"Este codigo no se encuentra registrado."<<endl;
		system("pause");
		return;
	}
	
}

void Menu::eliminarRest(){
		system("cls");
	cout<<"****************************** ELIMINAR RESTAURANTE ******************************"<<endl<<endl;
	baseDeDatos.Mostrar();
	cout<<endl<<"Ingrese el codigo del pais que quiere eliminar un restaurante: ";
	
	int codPais;
	cin>>codPais;
	cout<<endl;
	
	pnodoPaises nodoPais = baseDeDatos.buscarPais(codPais);
	if(nodoPais==NULL){
		cout<<endl<<"Pais Invalido o No Registrado"<<endl;
		system("pause");
		return;
	}
	if (nodoPais->ciudades.primero==NULL){
		cout<<endl<<"No hay ciudades registradas."<<endl;
		system("pause");
		return;
	}
	system("cls");
	nodoPais->ciudades.Mostrar();
	cout<<endl<<"Ingrese el codigo de la ciudad que quiere eliminar un restaurante: ";
	int codCiudad;
	cin>>codCiudad;
	pnodoCiudades nodoCiudad = baseDeDatos.buscarCiudad(codPais, codCiudad);
	if(nodoCiudad==NULL){
		cout<<endl<<"Ciudad Invalida o No Registrada"<<endl;
		system("pause");
		return;
	}
	system("cls");
	nodoCiudad->restaurantes.Mostrar();
	cout<<endl<<"Ingrese el codigo del restaurante a eliminar: ";
	int codRest;
	cin>>codRest;
	
	pnodoRest nodoRest = baseDeDatos.buscarRest(codPais,codCiudad,codRest);
	if (nodoRest!=NULL){
		int posicion = nodoCiudad->restaurantes.getPosicion(codRest);
		nodoCiudad->restaurantes.BorrarPosicion(posicion);
		system("cls");
		nodoCiudad->restaurantes.Mostrar();
		cout<<endl<<"Se ha eliminado el restaurante."<<endl;
		system("pause");
	}
	else{
		cout<<endl<<"Este codigo no se encuentra registrado."<<endl;
		system("pause");
		return;
	}
	
}

void Menu::eliminarMenu(){
	system("cls");
	cout<<"****************************** ELIMINAR MENU ******************************"<<endl<<endl;
	baseDeDatos.Mostrar();
	cout<<endl<<"Ingrese el codigo del pais que quiere eliminar un menu: ";
	
	int codPais;
	cin>>codPais;
	cout<<endl;
	
	pnodoPaises nodoPais = baseDeDatos.buscarPais(codPais);
	if(nodoPais==NULL){
		cout<<endl<<"Pais Invalido o No Registrado"<<endl;
		system("pause");
		return;
	}
	if (nodoPais->ciudades.primero==NULL){
		cout<<endl<<"No hay ciudades registradas."<<endl;
		system("pause");
		return;
	}
	system("cls");
	nodoPais->ciudades.Mostrar();
	cout<<endl<<"Ingrese el codigo de la ciudad que quiere eliminar un menu: ";
	int codCiudad;
	cin>>codCiudad;
	pnodoCiudades nodoCiudad = baseDeDatos.buscarCiudad(codPais, codCiudad);
	if(nodoCiudad==NULL){
		cout<<endl<<"Ciudad Invalida o No Registrada"<<endl;
		system("pause");
		return;
	}
	if (nodoCiudad->restaurantes.primero==NULL){
		cout<<endl<<"No hay restaurantes registrados."<<endl;
		system("pause");
		return;
	}
	
	system("cls");
	nodoCiudad->restaurantes.Mostrar();
	cout<<endl<<"Ingrese el codigo del restaurante que quiere eliminar un menu: ";
	int codRest;
	cin>>codRest;
	pnodoRest nodoRest = baseDeDatos.buscarRest(codPais, codCiudad,codRest);
	if(nodoRest==NULL){
		cout<<endl<<"Restaurante Invalido o No Registrado"<<endl;
		system("pause");
		return;
	}
	
	system("cls");
	nodoRest->menus.Mostrar();
	cout<<endl<<"Ingrese el codigo del menu a eliminar: ";
	int codMenu;
	cin>>codMenu;
	
	
	pnodoMenu nodoMenu = baseDeDatos.buscarMenu(codPais,codCiudad,codRest,codMenu);
	if (nodoMenu!=NULL){
		int posicion = nodoRest->menus.getPosicion(codMenu);
		nodoRest->menus.BorrarPosicion(posicion);
		system("cls");
		nodoRest->menus.Mostrar();
		cout<<endl<<"Se ha eliminado el menu."<<endl;
		system("pause");
	}
	else{
		cout<<endl<<"Este codigo no se encuentra registrado."<<endl;
		system("pause");
		return;
	}
}


void Menu::eliminarProducto(){
	system("cls");
	cout<<"****************************** ELIMINAR PRODUUCTO ******************************"<<endl<<endl;
	baseDeDatos.Mostrar();
	cout<<endl<<"Ingrese el codigo del pais que quiere eliminar un producto: ";
	
	int codPais;
	cin>>codPais;
	cout<<endl;
	
	pnodoPaises nodoPais = baseDeDatos.buscarPais(codPais);
	if(nodoPais==NULL){
		cout<<endl<<"Pais Invalido o No Registrado"<<endl;
		system("pause");
		return;
	}
	if (nodoPais->ciudades.primero==NULL){
		cout<<endl<<"No hay ciudades registradas."<<endl;
		system("pause");
		return;
	}
	system("cls");
	nodoPais->ciudades.Mostrar();
	cout<<endl<<"Ingrese el codigo de la ciudad que quiere eliminar un producto: ";
	int codCiudad;
	cin>>codCiudad;
	pnodoCiudades nodoCiudad = baseDeDatos.buscarCiudad(codPais, codCiudad);
	if(nodoCiudad==NULL){
		cout<<endl<<"Ciudad Invalida o No Registrada"<<endl;
		system("pause");
		return;
	}
	if (nodoCiudad->restaurantes.primero==NULL){
		cout<<endl<<"No hay restaurantes registrados."<<endl;
		system("pause");
		return;
	}
	
	system("cls");
	nodoCiudad->restaurantes.Mostrar();
	cout<<endl<<"Ingrese el codigo del restaurante que quiere eliminar un producto: ";
	int codRest;
	cin>>codRest;
	pnodoRest nodoRest = baseDeDatos.buscarRest(codPais, codCiudad,codRest);
	if(nodoRest==NULL){
		cout<<endl<<"Restaurante Invalido o No Registrado"<<endl;
		system("pause");
		return;
	}
		
	system("cls");
	nodoRest->menus.Mostrar();
	cout<<endl<<"Ingrese el codigo del menu que quiere eliminar un producto: ";
	int codMenu;
	cin>>codMenu;
	pnodoMenu nodoMenu = baseDeDatos.buscarMenu(codPais, codCiudad,codRest,codMenu);
	if(nodoMenu==NULL){
		cout<<endl<<"Menu Invalido o No Registrado"<<endl;
		system("pause");
		return;
	}
	if (nodoRest->menus.primero==NULL){
		cout<<endl<<"No hay menus registrados."<<endl;
		system("pause");
		return;
	}
	
	
	system("cls");
	nodoMenu->productos.Mostrar();
	cout<<endl<<"Ingrese el codigo del producto a eliminar: ";
	int codProd;
	cin>>codProd;
	
	
	pnodoProductos nodoProd = baseDeDatos.buscarProd(codPais,codCiudad,codRest,codMenu,codProd);
	if (nodoProd!=NULL){
		int posicion = nodoMenu->productos.getPosicion(codProd);
		nodoMenu->productos.BorrarPosicion(posicion);
		system("cls");
		nodoMenu->productos.Mostrar();
		cout<<endl<<"Se ha eliminado el producto."<<endl;
		system("pause");
	}
	else{
		cout<<endl<<"Este codigo no se encuentra registrado."<<endl;
		system("pause");
		return;
	}
}

void Menu::eliminarClientes(){
	system("cls");
	cout<<"****************************** ELIMINAR CLIENTE ******************************"<<endl;
	clientes.Mostrar();
	cout<<endl<<"Ingrese la cedula del cliente a eliminar: ";
	
	int cedula;
	cin>>cedula;
	
	pnodoClientes nodoClientes = clientes.buscarClientes(cedula);
	if (nodoClientes!=NULL){
		int pos = clientes.buscarPos(cedula);
		clientes.borrarPosicion(pos);
		system("cls");
		clientes.Mostrar();
		cout<<endl<<"Se ha eliminado el cliente"<<endl;
		system("pause");
	}
	else{
		cout<<endl<<"Este cliente no se encuentra registrado."<<endl;
		system("pause");
	}
}

void Menu::eliminar(){
	bool bandera=true;
	do{
		system("cls");
		cout<<"****************************** ELIMINAR ******************************"<<endl;
		cout<<endl<<"Ingrese que desea eliminar"<<endl<<endl;
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
				eliminarPais();
				break;
			case 2:
				eliminarCiudad();
				break;
			case 3:
				eliminarRest();
				break;
			case 4:
				eliminarMenu();
				break;
			case 5:
				eliminarProducto();
				break;
			case 6:
				eliminarClientes();
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
//>>>>>>> ff534163c532414660d5c840752eb5a9513927b6
	
void Menu::menu(){
	bool bandera=true;
	do{
		system("cls");
		cout << "				   $$$    $$$" << endl;
	    cout << "				  $   $  $   $" << endl;
	    cout << "				 $     $$     $" << endl;
	    cout << "				$$     $$     $$" << endl;
	    cout << "				$$     $$     $$" <<endl;
	    cout << "				$$     $$     $$" <<endl;
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
			eliminar();
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
