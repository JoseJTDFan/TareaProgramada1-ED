//José Julián Brenes Garro y Gustavo Pacheco Morales
//c.2022272865
//Estructuras de Datos


#include "Menu.h"
using namespace std;

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
/////////////////////////////////////////////////BUSCAR

void Menu::buscarPais(){
	
	system("cls");
	cout<<"****************************** BUSCAR PAIS ******************************"<<endl;
	//baseDeDatos.Mostrar();
	cout<<endl<<"Ingrese el codigo del pais a buscar: ";
	int codPais;
	cin>>codPais;
	
	pnodoPaises nodoPais = baseDeDatos.buscarPais(codPais);
	if (nodoPais!=NULL){
		system("cls");
		cout<<endl<<"		* El codigo del pais es: "<< nodoPais->codPais <<endl;
		cout<<endl<<"		* El nombre del pais es: "<< nodoPais->nombre <<endl<<endl;
		system("pause");
	}
	else{
		cout<<endl<<"Este codigo no se encuentra registrado."<<endl;
		system("pause");
	}
}

void Menu::buscarCiudad(){
	system("cls");
	cout<<"****************************** BUSCAR CIUDAD ******************************"<<endl<<endl;
	baseDeDatos.Mostrar();
	cout<<endl<<"Ingrese el codigo del pais que quiere buscar una ciudad: ";
	
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
	//nodoPais->ciudades.Mostrar();
	cout<<endl<<"Ingrese el codigo de la ciudad a buscar: ";
	int codCiudad;
	cin>>codCiudad;
	
	pnodoCiudades nodoCiudad = baseDeDatos.buscarCiudad(codPais, codCiudad);
	if (nodoCiudad!=NULL){
		system("cls");
		cout<<endl<<"		* El codigo de pais de la ciudad es: "<< nodoCiudad->codPais <<endl;
		cout<<endl<<"		* El codigo de la ciudad es: "<< nodoCiudad->codCiudad <<endl;
		cout<<endl<<"		* El nombre de la ciudad es: "<< nodoCiudad->nombre <<endl<<endl;
		system("pause");
	}
	else{
		cout<<endl<<"Este codigo no se encuentra registrado."<<endl;
		system("pause");
		return;
	}
	
}

void Menu::buscarRest(){
	system("cls");
	cout<<"****************************** BUSCAR RESTAURANTE ******************************"<<endl<<endl;
	baseDeDatos.Mostrar();
	cout<<endl<<"Ingrese el codigo del pais que quiere buscar un restaurante: ";
	
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
	cout<<endl<<"Ingrese el codigo de la ciudad que quiere buscar un restaurante: ";
	int codCiudad;
	cin>>codCiudad;
	pnodoCiudades nodoCiudad = baseDeDatos.buscarCiudad(codPais, codCiudad);
	if(nodoCiudad==NULL){
		cout<<endl<<"Ciudad Invalida o No Registrada"<<endl;
		system("pause");
		return;
	}
	system("cls");
	//nodoCiudad->restaurantes.Mostrar();
	cout<<endl<<"Ingrese el codigo del restaurante a buscar: ";
	int codRest;
	cin>>codRest;
	
	pnodoRest nodoRest = baseDeDatos.buscarRest(codPais,codCiudad,codRest);
	if (nodoRest!=NULL){
		system("cls");
		nodoRest->cantBusquedas=nodoRest->cantBusquedas+1;
		cout<<endl<<"		* El codigo de pais del restaurante es: "<< nodoRest->codPais <<endl;
		cout<<endl<<"		* El codigo de ciudad del restaurante es: "<< nodoRest->codCiudad <<endl;
		cout<<endl<<"		* El codigo del restaurante es: "<< nodoRest->codRest <<endl;
		cout<<endl<<"		* El nombre del restaurante es: "<< nodoRest->nombre <<endl<<endl;
		system("pause");
		
	}
	else{
		cout<<endl<<"Este codigo no se encuentra registrado."<<endl;
		system("pause");
		return;
	}
	
}

void Menu::buscarMenu(){
	system("cls");
	cout<<"****************************** BUSCAR MENU ******************************"<<endl<<endl;
	baseDeDatos.Mostrar();
	cout<<endl<<"Ingrese el codigo del pais en el que quiere buscar un menu: ";
	
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
	cout<<endl<<"Ingrese el codigo de la ciudad en el que quiere buscar un menu: ";
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
	cout<<endl<<"Ingrese el codigo del restaurante en el que quiere buscar un menu: ";
	int codRest;
	cin>>codRest;
	pnodoRest nodoRest = baseDeDatos.buscarRest(codPais, codCiudad,codRest);
	if(nodoRest==NULL){
		cout<<endl<<"Restaurante Invalido o No Registrado"<<endl;
		system("pause");
		return;
	}
	
	system("cls");
	//nodoRest->menus.Mostrar();
	cout<<endl<<"Ingrese el codigo del menu a buscar: ";
	int codMenu;
	cin>>codMenu;
	
	
	pnodoMenu nodoMenu = baseDeDatos.buscarMenu(codPais,codCiudad,codRest,codMenu);
	if (nodoMenu!=NULL){
		int posicion = nodoRest->menus.getPosicion(codMenu);
		string nombre = nodoRest->menus.atributosMenu(posicion);
		system("cls");
		//nodoRest->menus.Mostrar();
		cout<<endl<<"		* El codigo de pais del menu es: "<< nodoMenu->codPais <<endl;
		cout<<endl<<"		* El codigo de ciudad del menu es: "<< nodoMenu->codCiudad <<endl;
		cout<<endl<<"		* El codigo de restaurante del menu es: "<< nodoMenu->codRest <<endl;
		cout<<endl<<"		* El codigo del menu es: "<< nodoMenu->codMenu <<endl;
		cout<<endl<<"		* El nombre del menu es: "<< nombre <<endl<<endl;
		system("pause");
	}
	else{
		cout<<endl<<"Este codigo no se encuentra registrado."<<endl;
		system("pause");
		return;
	}
}

void Menu::buscarProducto(){
	system("cls");
	cout<<"****************************** BUSCAR PRODUCTO ******************************"<<endl<<endl;
	baseDeDatos.Mostrar();
	cout<<endl<<"Ingrese el codigo del pais en el que quiere buscar un producto: ";
	
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
	cout<<endl<<"Ingrese el codigo de la ciudad en el que quiere buscar un producto: ";
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
	cout<<endl<<"Ingrese el codigo del restaurante en el que quiere buscar un producto: ";
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
	cout<<endl<<"Ingrese el codigo del menu en el que quiere buscar un producto: ";
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
	//nodoMenu->productos.Mostrar();
	cout<<endl<<"Ingrese el codigo del producto a buscar: ";
	int codProd;
	cin>>codProd;
	
	
	pnodoProductos nodoProd = baseDeDatos.buscarProd(codPais,codCiudad,codRest,codMenu,codProd);
	if (nodoProd!=NULL){
		int posicion = nodoMenu->productos.getPosicion(codProd);
		string nombre = nodoMenu->productos.getNombreProducto(posicion);
		int kcal = nodoMenu->productos.getKcalProducto(posicion);
		int precio = nodoMenu->productos.getPrecioProducto(posicion);
		system("cls");
		cout<<endl<<"		* El codigo de pais del producto es: "<< nodoProd->codPais <<endl;
		cout<<endl<<"		* El codigo de ciudad del producto es: "<< nodoProd->codCiudad <<endl;
		cout<<endl<<"		* El codigo de restaurante del producto es: "<< nodoProd->codRest <<endl;
		cout<<endl<<"		* El codigo de menu del producto es: "<< nodoProd->codMenu <<endl;
		cout<<endl<<"		* El codigo  del producto es: "<< nodoProd->codProducto <<endl;
		cout<<endl<<"		* El nombre del producto es: "<< nombre <<endl;
		cout<<endl<<"		* Las calorias del producto son: "<< kcal <<endl;
		cout<<endl<<"		* El precio del producto es: "<< precio <<endl<<endl;
		system("pause");
	}
	else{
		cout<<endl<<"Este codigo no se encuentra registrado."<<endl;
		system("pause");
		return;
	}
}

void Menu::buscarClientes(){
	system("cls");
	cout<<"****************************** BUSCAR CLIENTE ******************************"<<endl;
	//clientes.Mostrar();
	cout<<endl<<"Ingrese la cedula del cliente a buscar: ";
	
	int cedula;
	cin>>cedula;
	
	pnodoClientes nodoClientes = clientes.buscarClientes(cedula);
	if (nodoClientes!=NULL){
		int pos = clientes.buscarPos(cedula);
		string nombre = clientes.atributosCliente(pos);
		//system("cls");
		cout<<endl<<"		* La cedula del cliente es: "<< nodoClientes->cedula <<endl;
		cout<<endl<<"		* El nombre del cliente es: "<< nodoClientes->nombreCliente <<endl<<endl;
		system("pause");
	}
	else{
		cout<<endl<<"Este cliente no se encuentra registrado."<<endl;
		system("pause");
	}
}

void Menu::buscar(){
	bool bandera=true;
	do{
		system("cls");
		cout<<"****************************** BUSCAR ******************************"<<endl;
		cout<<endl<<"Ingrese que desea buscar"<<endl<<endl;
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
				buscarPais();
				break;
			case 2:
				buscarCiudad();
				break;
			case 3:
				buscarRest();
				break;
			case 4:
				buscarMenu();
				break;
			case 5:
				buscarProducto();
				break;
			case 6:
				buscarClientes();
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

void Menu::modificarPais(){
	
	system("cls");
	cout<<"****************************** MODIFICAR PAIS ******************************"<<endl;
	baseDeDatos.Mostrar();
	cout<<endl<<"Ingrese el codigo del pais a modificar: ";
	int codPais;
	cin>>codPais;
	
	pnodoPaises nodoPais = baseDeDatos.buscarPais(codPais);
	if (nodoPais!=NULL){
		system("cls");
		string nombre;
		cout<<endl<<"Ingrese el nuevo nombre del pais: ";
		cin.ignore();
		getline(cin,nombre);
		nodoPais->nombre = nombre;
		system("cls");
		baseDeDatos.Mostrar();
		cout<<endl<<"Se ha modificado el pais."<<endl;
		system("pause");
	}
	else{
		cout<<endl<<"Este codigo no se encuentra registrado."<<endl;
		system("pause");
	}
}

void Menu::modificarCiudad(){
	system("cls");
	cout<<"****************************** MODIFICAR CIUDAD ******************************"<<endl<<endl;
	baseDeDatos.Mostrar();
	cout<<endl<<"Ingrese el codigo del pais que quiere modificar una ciudad: ";
	
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
	cout<<endl<<"Ingrese el codigo de la ciudad a modificar: ";
	int codCiudad;
	cin>>codCiudad;
	
	pnodoCiudades nodoCiudad = baseDeDatos.buscarCiudad(codPais, codCiudad);
	if (nodoCiudad!=NULL){
		system("cls");
		string nombre;
		cout<<endl<<"Ingrese el nuevo nombre de la ciudad: ";
		cin.ignore();
		getline(cin,nombre);
		nodoCiudad->nombre = nombre;
		system("cls");
		nodoPais->ciudades.Mostrar();
		cout<<endl<<"Se ha modificado la ciudad."<<endl;
		system("pause");
	}
	else{
		cout<<endl<<"Este codigo no se encuentra registrado."<<endl;
		system("pause");
		return;
	}
}

void Menu::modificarRest(){
		system("cls");
	cout<<"****************************** MODIFICAR RESTAURANTE ******************************"<<endl<<endl;
	baseDeDatos.Mostrar();
	cout<<endl<<"Ingrese el codigo del pais que quiere modificar un restaurante: ";
	
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
	cout<<endl<<"Ingrese el codigo de la ciudad que quiere modificar un restaurante: ";
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
	cout<<endl<<"Ingrese el codigo del restaurante a modificar: ";
	int codRest;
	cin>>codRest;
	
	pnodoRest nodoRest = baseDeDatos.buscarRest(codPais,codCiudad,codRest);
	if (nodoRest!=NULL){
		system("cls");
		string nombre;
		cout<<endl<<"Ingrese el nuevo nombre del restaurante: ";
		cin.ignore();
		getline(cin,nombre);
		nodoRest->nombre = nombre;
		system("cls");
		nodoCiudad->restaurantes.Mostrar();
		cout<<endl<<"Se ha modificado el restaurante."<<endl;
		system("pause");
	}
	else{
		cout<<endl<<"Este codigo no se encuentra registrado."<<endl;
		system("pause");
		return;
	}
	
}

void Menu::modificarMenu(){
		system("cls");
	cout<<"****************************** MODIFICAR MENU ******************************"<<endl<<endl;
	baseDeDatos.Mostrar();
	cout<<endl<<"Ingrese el codigo del pais que quiere modificar un menu: ";
	
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
	cout<<endl<<"Ingrese el codigo de la ciudad que quiere modificar un menu: ";
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
	cout<<endl<<"Ingrese el codigo del restaurante que quiere modificar un menu: ";
	int codRest;
	cin>>codRest;
	pnodoRest nodoRest = baseDeDatos.buscarRest(codPais,codCiudad,codRest);
	if (nodoRest==NULL){
		cout<<endl<<"Restaurante Invalido o No Registrado"<<endl;
		system("pause");
		return;
	}
	system("cls");
	nodoRest->menus.Mostrar();
	cout<<endl<<"Ingrese el codigo del menu a modificar: ";
	int codMenu;
	cin>>codMenu;
	pnodoMenu nodoMenu = baseDeDatos.buscarMenu(codPais,codCiudad,codRest,codMenu);
	if (nodoMenu!=NULL){
		system("cls");
		string nombreNuevo;
		cout<<endl<<"Ingrese el nuevo nombre del menu: ";
		cin.ignore();
		getline(cin,nombreNuevo);
		nodoMenu->nombre = nombreNuevo;
		system("cls");
		nodoRest->menus.Mostrar();
		cout<<endl<<"Se ha modificado el menu."<<endl;
		system("pause");
	}else{
		cout<<endl<<"Menu Invalido o No Registrado"<<endl;
		system("pause");
		return;
	}
	
}

void Menu::modificarProducto(){
		system("cls");
	cout<<"****************************** MODIFICAR PRODUCTO ******************************"<<endl<<endl;
	baseDeDatos.Mostrar();
	cout<<endl<<"Ingrese el codigo del pais que quiere modificar un menu: ";
	
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
	cout<<endl<<"Ingrese el codigo de la ciudad que quiere modificar un menu: ";
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
	cout<<endl<<"Ingrese el codigo del restaurante que quiere modificar un menu: ";
	int codRest;
	cin>>codRest;
	pnodoRest nodoRest = baseDeDatos.buscarRest(codPais,codCiudad,codRest);
	if (nodoRest==NULL){
		cout<<endl<<"Restaurante Invalido o No Registrado"<<endl;
		system("pause");
		return;
	}
	system("cls");
	nodoRest->menus.Mostrar();
	cout<<endl<<"Ingrese el codigo del menu que quiere modificar un producto: ";
	int codMenu;
	cin>>codMenu;
	pnodoMenu nodoMenu = baseDeDatos.buscarMenu(codPais,codCiudad,codRest,codMenu);
	if (nodoMenu==NULL){
		cout<<endl<<"Menu Invalido o No Registrado"<<endl;
		system("pause");
		return;
	}
	system("cls");
	nodoMenu->productos.Mostrar();
	cout<<endl<<"Ingrese el codigo del producto a modificar: ";
	int codProducto;
	cin>>codProducto;
	pnodoProductos nodoProductos = baseDeDatos.buscarProd(codPais, codCiudad, codRest, codMenu, codProducto);
	if (nodoProductos!=NULL){
		system("cls");
		bool bandera=true;
		do{
		system("cls");
		cout<<"****************************** MODIFICAR PRODUCTO ******************************"<<endl;
		cout<<endl<<"Ingrese que desea modificar"<<endl<<endl;
		cout<<"1. El nombre."<<endl;
		cout<<"2. Las calorias."<<endl;
		cout<<"3. El precio."<<endl;
		cout<<"4. Salir."<<endl;
		cout<<endl<<"----> ";
		int opcion;
		cin>>opcion;
		cout<<endl;
		switch (opcion){
			case 1:{
				system("cls");
				string nombreNuevo;
				cout<<endl<<"Ingrese el nuevo nombre del producto: ";
				cin.ignore();
				getline(cin,nombreNuevo);
				nodoProductos->nombre = nombreNuevo;
				system("cls");
				nodoMenu->productos.Mostrar();
				cout<<endl<<"Se ha modificado el producto."<<endl;
				system("pause");
				break;
			}
			case 2:{
				system("cls");
				int kcalNuevo;
				cout<<endl<<"Ingrese las nuevas calorias del producto: ";
				cin>>kcalNuevo;
				nodoProductos->kcal = kcalNuevo;
				system("cls");
				nodoMenu->productos.Mostrar();
				cout<<endl<<"Se ha modificado el producto."<<endl;
				system("pause");
				break;
			}
			case 3:{
				system("cls");
				int precioNuevo;
				cout<<endl<<"Ingrese el nuevo precio del producto: ";
				cin>>precioNuevo;
				nodoProductos->precio = precioNuevo;
				system("cls");
				nodoMenu->productos.Mostrar();
				cout<<endl<<"Se ha modificado el producto."<<endl;
				system("pause");
				break;
			}
			case 4:
				bandera=false;
				break;
			default:
				cout<<"Ingrese un numero valido"<<endl;
				system("pause");
				break;
			}
		}while(bandera);
	}else{
		cout<<endl<<"Producto Invalido o No Registrado"<<endl;
		system("pause");
		return;
	}
}

void Menu::modificarCliente(){
	system("cls");
	cout<<"****************************** MODIFICAR CLIENTE ******************************"<<endl;
	clientes.Mostrar();
	cout<<endl<<"Ingrese la cedula del cliente a modificar: ";
	int cedula;
	cin>>cedula;
	
	pnodoClientes nodoClientes = clientes.buscarClientes(cedula);
	if (nodoClientes!=NULL){
		system("cls");
		string nombreNuevo;
		cout<<endl<<"Ingrese el nuevo nombre: ";
		cin.ignore();
		getline(cin,nombreNuevo);
		nodoClientes->nombreCliente = nombreNuevo;
		system("cls");
		clientes.Mostrar();
		system("pause");
	}
	else{
		cout<<endl<<"Este codigo no se encuentra registrado."<<endl;
		system("pause");
	}
}

void Menu::modificarCompra(){
	system("cls");
	cout<<"****************************** MODIFICAR COMPRA ******************************"<<endl;
	
	cout<<endl<<"Ingrese su numero de cedula: ";
	int cedula;
	cin>>cedula;
	 
	pnodoClientes nodoClientes = clientes.buscarClientes(cedula);
	
	if(colaClientes.buscar(cedula)==false){
		cout<<endl<<"El cliente no esta en la cola."<<endl;
		system("pause");
		return;
	}
	bool bandera=true;
	do{
		system("cls");
		cout<<endl<<"Que desea modificar?"<<endl;
		cout<<"1.Cantidad de un producto"<<endl;
		cout<<"2.Un producto"<<endl;
		cout<<endl<<"--> ";
		int opcion;
		cin>>opcion;
		switch (opcion){
			case 1:
				system("cls");
				int prod,cantidad;
				nodoClientes->productos.MostrarCompra();
				cout<<endl<<"Que cantidad desea modificar? (Ingrese Codigo de Producto): ";
				cin>>prod;
				cout<<endl<<endl<<"Nueva Cantidad: ";
				cin>>cantidad;
				pnodoProductos producto;
				producto = nodoClientes->productos.buscarProducto(prod);
				producto->cantidad = cantidad;
				system("cls");
				nodoClientes->productos.MostrarCompra();
				cout<<endl<<"Cantidad cambiada con exito."<<endl;
				system("pause");
				bandera=false;
				break;
			case 2:
				system("cls");
				
				int prodCambio, pos;
				nodoClientes->productos.MostrarCompra();
				cout<<endl<<"Que producto desea modificar? (Ingrese Codigo de Producto): ";
				cin>>prodCambio;
				
				nodoClientes->productos.BorrarPosicion(nodoClientes->productos.getPosicion(prodCambio));
				
				bool bandera2;
				bandera2=true;
				do{
					system("cls");
					cout<<endl<<endl;
					baseDeDatos.Mostrar();
					cout<<endl<<"Ingrese el codigo del pais en el que quiere comprar: ";
					
					int codPais;
					cin>>codPais;
					cout<<endl;
					pnodoPaises nodoPais;
					nodoPais = baseDeDatos.buscarPais(codPais);
					if(nodoPais==NULL){
						cout<<endl<<"Pais Invalido o No Registrado"<<endl;
						system("pause");
						bandera2 = desicion(bandera2);
						continue;
					}
					if (nodoPais->ciudades.primero==NULL){
						cout<<endl<<"No hay ciudades registradas."<<endl;
						system("pause");
						bandera2 = desicion(bandera2);
						continue;
					}
					system("cls");
					nodoPais->ciudades.Mostrar();
					cout<<endl<<"Ingrese el codigo de la ciudad en el que quiere comprar: ";
					int codCiudad;
					cin>>codCiudad;
					pnodoCiudades nodoCiudad;
					nodoCiudad = baseDeDatos.buscarCiudad(codPais, codCiudad);
					if(nodoCiudad==NULL){
						cout<<endl<<"Ciudad Invalida o No Registrada"<<endl;
						system("pause");
						bandera2 = desicion(bandera2);
						continue;
					}
					if (nodoCiudad->restaurantes.primero==NULL){
						cout<<endl<<"No hay restaurantes registrados."<<endl;
						system("pause");
						bandera2 = desicion(bandera2);
						continue;
					}
					
					system("cls");
					nodoCiudad->restaurantes.Mostrar();
					cout<<endl<<"Ingrese el codigo del restaurante en el que quiere comprar: ";
					int codRest;
					cin>>codRest;
					
					pnodoRest nodoRest;
					nodoRest = baseDeDatos.buscarRest(codPais, codCiudad,codRest);
					if(nodoRest==NULL){
						cout<<endl<<"Restaurante Invalido o No Registrado"<<endl;
						system("pause");
						bandera2 = desicion(bandera2);
						continue;
					}
						
					system("cls");
					nodoRest->menus.Mostrar();
					cout<<endl<<"Ingrese el codigo del menu en el que quiere comprar: ";
					int codMenu;
					cin>>codMenu;
					pnodoMenu nodoMenu = baseDeDatos.buscarMenu(codPais, codCiudad,codRest,codMenu);
					if(nodoMenu==NULL){
						cout<<endl<<"Menu Invalido o No Registrado"<<endl;
						system("pause");
						bandera2 = desicion(bandera2);
						continue;
					}
					if (nodoRest->menus.primero==NULL){
						cout<<endl<<"No hay menus registrados."<<endl;
						system("pause");
						bandera2 = desicion(bandera2);
						continue;
					}
					
					
					system("cls");
					nodoMenu->productos.Mostrar();
					cout<<endl<<"Ingrese el codigo del producto que quiere comprar: ";
					int codProd;
					cin>>codProd;
					
					pnodoProductos nodoProd;
					nodoProd = baseDeDatos.buscarProd(codPais,codCiudad,codRest,codMenu,codProd);
					if (nodoProd!=NULL){
						int cantidad;
						cout<<endl<<"¿Cuantas unidades desea comprar de "<<nodoProd->nombre<<"?: ";
						cin>>cantidad;
						nodoClientes->productos.InsertarFinal(codPais,codCiudad,codRest,codMenu,codProd,nodoProd->nombre,nodoProd->kcal,nodoProd->precio,cantidad);
						system("cls");
						nodoClientes->productos.MostrarCompra();
						cout<<endl<<"Se ha insertado el producto a su carrito."<<endl;
						system("pause");
						bandera2 = desicion(bandera2);
					}
					else{
						cout<<endl<<"Este codigo no se encuentra registrado."<<endl;
						system("pause");
						bandera2 = desicion(bandera2);
					}
				}while(bandera2==true);
				bandera=false;
				break;
			default:
				cout<<"Ingrese un numero valido"<<endl;
				system("pause");
		}
	}while(bandera==true);	
}

void Menu::modificar(){
	bool bandera=true;
	do{
		system("cls");
		cout<<"****************************** MODIFICAR ******************************"<<endl;
		cout<<endl<<"Ingrese que desea modificar"<<endl<<endl;
		cout<<"1. Un pais."<<endl;
		cout<<"2. Una ciudad."<<endl;
		cout<<"3. Un restaurante."<<endl;
		cout<<"4. Un menu."<<endl;
		cout<<"5. Un producto."<<endl;
		cout<<"6. Un cliente."<<endl;
		cout<<"7. Una compra"<<endl;
		cout<<"8. Salir."<<endl;
		cout<<endl<<"----> ";
		int opcion;
	
		cin>>opcion;
		cout<<endl;
		switch (opcion){
			case 1:
				modificarPais();
				break;
			case 2:
				modificarCiudad();
				break;
			case 3:
				modificarRest();
				break;
			case 4:
				modificarMenu();
				break;
			case 5:
				modificarProducto();
				break;
			case 6:
				modificarCliente();
				break;
			case 7:
				modificarCompra();
				break;
			case 8:
				bandera=false;
				break;
			default:
				cout<<"Ingrese un numero valido"<<endl;
				system("pause");
				break;
			}
	}while(bandera);	
}

void Menu::guardarEnArchivo(string nombreArchivo, string texto){
	ofstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
        return;
    }

    archivo << texto;

    archivo.close();

    cout << "Reporte realizado en el archivo: " << nombreArchivo << endl;
    system("pause");
}


void Menu::reportarPais(){
	system("cls");
	cout<<"****************************** REPORTE DE PAISES ******************************"<<endl<<endl;
	guardarEnArchivo("Lista de Paises.txt", baseDeDatos.DevolverReporte());
}

void Menu::reportarCiudad(){
	system("cls");
	cout<<"****************************** REPORTE DE CIUDADES ******************************"<<endl<<endl;
	
	baseDeDatos.Mostrar();
	cout<<endl<<"Ingrese el codigo del pais que ver sus ciudades: ";
	
	int codPais;
	cin>>codPais;
	cout<<endl;
	
	pnodoPaises nodoPais = baseDeDatos.buscarPais(codPais);
	if(nodoPais==NULL){
		cout<<endl<<"Pais Invalido o No Registrado"<<endl;
		system("pause");
		return;
	}
	
	if(nodoPais->ciudades.primero==NULL){
		cout<<endl<<"No hay ciudades para reportar"<<endl;
		system("pause");
		return;
	}
	
	guardarEnArchivo("Lista de Ciudades en "+nodoPais->nombre+".txt", nodoPais->ciudades.DevolverReporte());
}

void Menu::reportarRest(){
	system("cls");
	cout<<"****************************** REPORTE DE RESTAURANTES ******************************"<<endl<<endl;
	baseDeDatos.Mostrar();
	cout<<endl<<"Ingrese el codigo del pais que ver los restaurantes de una ciudad: ";
	
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
	cout<<"****************************** REPORTE DE RESTAURANTES ******************************"<<endl<<endl;
	nodoPais->ciudades.Mostrar();
	cout<<endl<<"Ingrese el codigo de la ciudad que quiere ver sus restaurantes: ";
	int codCiudad;
	cin>>codCiudad;
	pnodoCiudades nodoCiudad = baseDeDatos.buscarCiudad(codPais, codCiudad);
	if(nodoCiudad==NULL){
		cout<<endl<<"Ciudad Invalida o No Registrada"<<endl;
		system("pause");
		return;
	}
	
	if(nodoCiudad->restaurantes.primero==NULL){
		cout<<endl<<"No hay restaurantes para reportar"<<endl;
		system("pause");
		return;
	}
	
	guardarEnArchivo("Lista de Restaurantes en "+nodoCiudad->nombre+", "+nodoPais->nombre+".txt", nodoCiudad->restaurantes.DevolverReporte());
}

void Menu::reportarCliente(){
	system("cls");
	cout<<"****************************** REPORTE DE CLIENTES ******************************"<<endl<<endl;
	guardarEnArchivo("Lista de Clientes.txt", clientes.DevolverReporte());
}

void Menu::reportarRestMasBuscado(){
	system("cls");
	cout<<"****************************** RESTAURANTE MAS BUSCADO ******************************"<<endl<<endl;
	guardarEnArchivo("Restaurante Mas Buscado.txt", baseDeDatos.RestMasBuscado());
}

void Menu::reportarPrecio(){
	system("cls");
	system("cls");
	cout<<"****************************** REPORTE DE PRECIO ******************************"<<endl<<endl;
	baseDeDatos.Mostrar();
	cout<<endl<<"Ingrese el codigo del pais en el que quiere buscar el precio de un producto: ";
	
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
	cout<<endl<<"Ingrese el codigo de la ciudad en el que quiere buscar el precio de un producto: ";
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
	cout<<endl<<"Ingrese el codigo del restaurante en el que quiere buscar el precio de un producto: ";
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
	cout<<endl<<"Ingrese el codigo del menu en el que quiere buscar el precio de un producto: ";
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
	nodoMenu->productos.MostrarReportePrecio();
	cout<<endl<<"Ingrese el codigo del producto a consultar precio: ";
	int codProd;
	cin>>codProd;
	
	
	pnodoProductos nodoProd = baseDeDatos.buscarProd(codPais,codCiudad,codRest,codMenu,codProd);
	if (nodoProd!=NULL){
		guardarEnArchivo("Precio de un producto.txt", "El precio de "+nodoProd->nombre+" es: "+to_string(nodoProd->precio)+" colones.");
	}
	else{
		cout<<endl<<"Este codigo no se encuentra registrado."<<endl;
		system("pause");
		return;
	}
}

void Menu::reportes(){
	bool bandera=true;
	do{
		system("cls");
		cout<<"****************************** REPORTAR ******************************"<<endl;
		cout<<endl<<"Ingrese que desea reportar"<<endl<<endl;
		cout<<"1. Lista de todos los paises."<<endl;
		cout<<"2. Ciudades de un pais."<<endl;
		cout<<"3. Restaurantes de un pais y ciudad especifica."<<endl;
		cout<<"4. Lista de clientes."<<endl;
		cout<<"5. Restaurante mas buscado."<<endl;
		cout<<"6. Menu mas buscado."<<endl;
		cout<<"7. Producto mas comprado."<<endl;
		cout<<"8. Consultar el precio de un producto."<<endl;
		cout<<"9. Salir."<<endl;
		cout<<endl<<"----> ";
		int opcion;
	
		cin>>opcion;
		cout<<endl;
		switch (opcion){
			case 1:
				reportarPais();
				break;
			case 2:
				reportarCiudad();
				break;
			case 3:
				reportarRest();
				break;
			case 4:
				reportarCliente();
				break;
			case 5:
				reportarRestMasBuscado();
				break;
			case 6:
				modificarCliente();
				break;
			case 7:
				modificarCompra();
				break;
			case 8:
				reportarPrecio();
				break;
			case 9:
				bandera=false;
				break;
			default:
				cout<<"Ingrese un numero valido"<<endl;
				system("pause");
				break;
			}
	}while(bandera);	
}

bool Menu::desicion(bool bandera){
	bool bandera2=true;
	do{
		system("cls");
		cout<<endl<<"Desea seguir comprando?"<<endl;
		cout<<"1.Si"<<endl;
		cout<<"2.No"<<endl;
		cout<<endl<<"-->";
		int opcion;
		cin>>opcion;
		switch (opcion){
			case 1:
				bandera2=false;
				break;
			case 2:
				bandera=false;
				bandera2=false;
				break;
			default:
				cout<<"Ingrese un numero valido"<<endl;
				system("pause");
				
		}
	}while(bandera2==true);
	return bandera;
}

void Menu::comprar(){
	system("cls");
	cout<<"****************************** COMPRAR ******************************"<<endl;
	
	if(colaClientes.ColaLlena()){
		cout<<endl<<"La cola esta llena, no puede comprar."<<endl;
		system("pause");
		return;
	}
	
	cout<<endl<<"Ingrese su numero de cedula: ";
	int cedula;
	cin>>cedula;
	
	pnodoClientes nodoClientes = clientes.buscarClientes(cedula);
	
	if(colaClientes.buscar(cedula)==true){
		cout<<endl<<"El cliente ya esta en la cola."<<endl;
		system("pause");
		return;
	}
	
	if (nodoClientes!=NULL){
		bool bandera =true, banderaCompra=false;
		do{
			banderaCompra=false;
			system("cls");
			cout<<endl<<endl;
			baseDeDatos.Mostrar();
			cout<<endl<<"Ingrese el codigo del pais en el que quiere comprar: ";
			
			int codPais;
			cin>>codPais;
			cout<<endl;
			
			pnodoPaises nodoPais = baseDeDatos.buscarPais(codPais);
			if(nodoPais==NULL){
				cout<<endl<<"Pais Invalido o No Registrado"<<endl;
				system("pause");
				bandera = desicion(bandera);
				continue;
			}
			if (nodoPais->ciudades.primero==NULL){
				cout<<endl<<"No hay ciudades registradas."<<endl;
				system("pause");
				bandera = desicion(bandera);
				continue;
			}
			system("cls");
			nodoPais->ciudades.Mostrar();
			cout<<endl<<"Ingrese el codigo de la ciudad en el que quiere comprar: ";
			int codCiudad;
			cin>>codCiudad;
			pnodoCiudades nodoCiudad = baseDeDatos.buscarCiudad(codPais, codCiudad);
			if(nodoCiudad==NULL){
				cout<<endl<<"Ciudad Invalida o No Registrada"<<endl;
				system("pause");
				bandera = desicion(bandera);
				continue;
			}
			if (nodoCiudad->restaurantes.primero==NULL){
				cout<<endl<<"No hay restaurantes registrados."<<endl;
				system("pause");
				bandera = desicion(bandera);
				continue;
			}
			
			system("cls");
			nodoCiudad->restaurantes.Mostrar();
			cout<<endl<<"Ingrese el codigo del restaurante en el que quiere comprar: ";
			int codRest;
			cin>>codRest;
			pnodoRest nodoRest = baseDeDatos.buscarRest(codPais, codCiudad,codRest);
			if(nodoRest==NULL){
				cout<<endl<<"Restaurante Invalido o No Registrado"<<endl;
				system("pause");
				bandera = desicion(bandera);
				continue;
			}
				
			system("cls");
			nodoRest->menus.Mostrar();
			cout<<endl<<"Ingrese el codigo del menu en el que quiere comprar: ";
			int codMenu;
			cin>>codMenu;
			pnodoMenu nodoMenu = baseDeDatos.buscarMenu(codPais, codCiudad,codRest,codMenu);
			if(nodoMenu==NULL){
				cout<<endl<<"Menu Invalido o No Registrado"<<endl;
				system("pause");
				bandera = desicion(bandera);
				continue;
			}
			if (nodoRest->menus.primero==NULL){
				cout<<endl<<"No hay menus registrados."<<endl;
				system("pause");
				bandera = desicion(bandera);
				continue;
			}
			
			
			system("cls");
			nodoMenu->productos.Mostrar();
			cout<<endl<<"Ingrese el codigo del producto que quiere comprar: ";
			int codProd;
			cin>>codProd;
			
			
			pnodoProductos nodoProd = baseDeDatos.buscarProd(codPais,codCiudad,codRest,codMenu,codProd);
			if (nodoProd!=NULL){
				int cantidad;

				cout<<endl<<"¿Cuantas unidades desea comprar de "<<nodoProd->nombre<<"?: ";
				cin>>cantidad;
				nodoClientes->productos.InsertarFinal(codPais,codCiudad,codRest,codMenu,codProd,nodoProd->nombre,nodoProd->kcal,nodoProd->precio,cantidad);
				system("cls");
				nodoClientes->productos.MostrarCompra();
				cout<<endl<<"Se ha insertado el producto a su carrito."<<endl;
				banderaCompra=true;
				system("pause");
				bandera = desicion(bandera);
			}
			else{
				cout<<endl<<"Este codigo no se encuentra registrado."<<endl;
				system("pause");
				bandera = desicion(bandera);
			}
			
		}while(bandera==true);
		system("cls");
		if(banderaCompra==true){
					colaClientes.insertar(nodoClientes);
		colaClientes.imprimir();
		system("pause");
		}
		
	}
	else{
		cout<<endl<<"Este cliente no se encuentra registrado."<<endl;
		system("pause");
	}
}

void Menu::menu(){
	bool bandera=true;
	do{
		system("cls");
		cout << "			       $$$    $$$" << endl;
	    cout << "			      $   $  $   $" << endl;
	    cout << "			     $     $$     $" << endl;
	    cout << "		   	    $$     $$     $$" << endl;
	    cout << "			    $$     $$     $$" <<endl;
	    cout << "			    $$     $$     $$" <<endl;
		cout<<"****************************** MC'DONALD'S ******************************"<<endl;
		cout<<endl<<"¡Bienvenido a la base de datos de McDonald's! ¿Que desea realizar?"<<endl<<endl;
		cout<<"1. Insertar."<<endl;
		cout<<"2. Eliminar."<<endl;
		cout<<"3. Buscar."<<endl;
		cout<<"4. Modificar"<<endl;
		cout<<"5. Reportar"<<endl;
		cout<<"6. Comprar"<<endl;
		cout<<"7. Salir"<<endl;
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
			buscar();
			break;
		case 4:
			modificar();
			break;
		case 5:
			reportes();
			break;
		case 6:
			comprar();
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
