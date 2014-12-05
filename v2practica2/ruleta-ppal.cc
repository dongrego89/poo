#include<iostream>
#include<string>
#include<list>
#include<cstdlib>//system("clear")


#include "ruleta.h"
#include "jugador.h"

using namespace std;
using namespace ruleta;

void limpiaCin();
void rotulo(string s);
void linea();

void menu(int &opcion);

int main(){

Crupier c("8899","idcrupier1");
Ruleta r(c);

int nj,sd,nl,eb,opcion,banca;//Numero de jugadores, sumatorio de dinero en mesa, numero de lanzamientos, estado de la banca

list<Jugador>::iterator i,y;
list<Jugador> j,k;
list<Apuesta> a;

string dni, codigo, nombre, apellidos, direccion, localidad, provincia, pais;


do{
	menu(opcion);

	switch(opcion){
		case 1://cargar jugadores desde fichero
			system("clear");
			r.leeJugadores();
			rotulo("Jugadores leidos desde fichero");
			limpiaCin();
		break;
		case 2://escribe jugadores desde fichero
			system("clear");
			r.escribeJugadores();
			rotulo("Jugadores escritos desde fichero");
			limpiaCin();
		break;
		case 3://estado de la partida
			system("clear");
		
			r.getEstadoRuleta(nj,sd,nl,eb);
			rotulo("ESTADO DE RULETA");
			cout << "\tNumero de jugadores actuales: " << nj << endl << "\tSumatorio de dinero en mesa: " << sd << endl;
			cout << "\tNumero de lanzamientos de ruleta: " << nl << endl << "\tEstado de ganancias de banca: " << eb;
			linea();
			j=r.getJugadores();
			for(i=j.begin();i!=j.end();i++){
				cout << "\t" << i->getApellidosyNombre() << endl << "\tDinero Actual: " << i->getDinero() << endl<< endl;
			}
			cout << "\tDinero de Banca: " << r.getBanca() << endl;
			linea();
			limpiaCin();
		break;
		case 4://estado de la partida
			system("clear");
			rotulo("GIRAR RULETA");
			r.giraRuleta();
			cout << "\nBOLA: " << r.getBola() << endl;
		
			j=r.getJugadores();
			banca=r.getBanca();
			/*
			for(i=j.begin();i!=j.end();i++){
				cout << "\t" << i->getApellidosyNombre() << endl << "\tDinero Actual: " << i->getDinero() << endl<< endl;
			}
			
			cout << "\tDinero de Banca: " << r.getBanca() << endl;
			linea();*/

			r.getPremios();
			k=r.getJugadores();

			j=r.getJugadores();
			for(i=j.begin(),y=k.begin();i!=j.end(),y!=k.end();i++,y++){
				cout << "\t" << i->getApellidosyNombre() << endl << "\tDinero: " << i->getDinero()  << " + " << (y->getDinero())-(i->getDinero()) << " = " << y->getDinero()<< endl<< endl;//No funciona, hay que almacenar correctamente el dinero que tenian antes
			}
			
			cout << "\tDinero de Banca: " << banca << " + " << r.getBanca()-banca << " = " << r.getBanca() << endl;


			limpiaCin();
		break;
		case 5://eliminar jugador
			system("clear");
			rotulo("ELIMINAR JUGADOR");
			cout << "Introduce el dni del jugador a eliminar: " << endl;
			getline(cin, dni, '\n'); 
			if(r.deleteJugador(dni)==1){
				cout << endl << "Jugador eliminado satisfactoriamente";
			}
			linea();
			limpiaCin();
		break;
		case 6://añadir jugador
			limpiaCin();
			system("clear");
			rotulo("AÑADIR JUGADOR");
			cout << "Introduce los datos del nuevo jugador: " << endl;
			

			cout << "\tDni: ";
			getline(cin, dni, '\n'); 

			cout << "\tCodigo de jugador: ";
			getline(cin, codigo, '\n'); 

			cout << "\tNombre: ";
			getline(cin, nombre, '\n'); 

			cout << "\tApellidos: ";
			getline(cin, apellidos, '\n'); 

			cout << "\tDireccion: ";
			getline(cin, direccion, '\n'); 

			cout << "\tLocalidad: ";
			getline(cin, localidad, '\n'); 

			cout << "\tProvincia: ";
			getline(cin, provincia, '\n'); 
			cout << "\tPais: ";
			getline(cin, pais, '\n'); 

			Jugador s(dni,codigo,nombre,apellidos,direccion,localidad,provincia,pais);			
			if(r.addJugador(s)){
				cout << endl << "\tJugador añadido satisfactoriamente";
			}
			
			linea();
			limpiaCin();
		break;
	}
}while(opcion!=7);



return 0;
}

void menu(int &opcion){	
	bool correcto;
	
	system("clear");
	linea();
	cout << endl << "\tRULETA";
	rotulo("MENU PRINCIPAL");
	cout << "\t1) Cargar jugadores desde fichero jugadores.txt" << endl;
	cout << "\t2) Guardar jugadores en el fichero jugadores.txt" << endl;
	cout << "\t3) Ver estado de la ruleta, dinero de banca y jugadores" << endl;
	cout << "\t4) Girar la ruleta mostrando bola, premios y ganancia de banca" << endl;
	cout << "\t5) Eliminar jugador de la mesa" << endl;
	cout << "\t6) Añadir jugador a la mesa" << endl;
	cout << "\t7) Salir del juego" << endl << endl;
	linea();
	do{
		cout << endl << "\tSu opcion: ";
		cin >> opcion;
		switch(opcion){
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
				correcto=true;
				break;
			default:
				correcto=false;
		}
	}while(correcto==false);
}


void limpiaCin(){
	cin.ignore(10000,'\n');
	cin.clear();
	cin.get();
}


void rotulo(string s){
	cout << endl<<"\t________________________________________________________________________" << endl << endl;	
	cout << "\t" << s  << endl;
	cout << "\t________________________________________________________________________" << endl << endl;
}

void linea(){
	cout << endl <<"\t________________________________________________________________________" << endl;
}
