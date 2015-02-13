/*
 * ruleta-main.cc
 *
 *  Created on: 10/1/2015
 *      Author: grego
 */
#include "crupier.h"
#include "jugador.h"
#include "ruleta.h"

#include<string>
#include<stdio.h>
#include<list>
#include<iostream>
#include<cstdlib>//system

using namespace std;

void pausa(){
	fflush(stdin);
	cin.clear();
	getchar();
}

void mensaje (string cuerpo){
	cout << endl << "\t\t" << cuerpo << endl;
}
void cabeceraGrafico(string titulo){
	system("clear");
	cout << endl << "\t" << titulo << "::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
}
void pieGrafico(){
	cout << endl<< endl << "\t::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
}

void rellenaJugador(Jugador &jc){
	string nombre, apellidos,dni,codigo;
	mensaje("Datos de Jugador::::::::::::::::::::" );
	cout << "\t\tNombre: ";
	getline(cin,nombre);
	cout << "\t\tApellidos: ";
	getline(cin,apellidos);
	cout << "\t\tDNI: ";
	getline(cin,dni);
	cout << "\t\tCodigo: ";
	getline(cin,codigo);

	jc.setNombre(nombre);
	jc.setApellidos(apellidos);
	jc.setDNI(dni);
	jc.setCodigo(codigo);

}

void rellenaCrupier(Crupier &cc){
	string nombre,apellidos,dni,codigo;
	mensaje("Datos de Crupier::::::::::::::::::::");
	cout << "\t\tNombre: ";
	getline(cin,nombre);
	cout << "\t\tApellidos: ";
	getline(cin,apellidos);
	cout << "\t\tDNI: ";
	getline(cin,dni);
	cout << "\t\tCodigo: ";
	getline(cin,codigo);

	cc.setNombre(nombre);
	cc.setApellidos(apellidos);
	cc.setDNI(dni);
	cc.setCodigo(codigo);
}

int main(){

	Jugador jc("","");
	Crupier cc("","");
	Ruleta r(cc);

	list<Jugador>jugadoresc,jugadoresc2;
	list<Jugador>::iterator i,j;

	string opcion,cadenac;
	int contador,nj,sd,ro,gb,numero;

	rellenaCrupier(cc);

	do{
		cabeceraGrafico("MENU PRINCIPAL");

		cout <<endl << "\t\t1. Cargar los jugadores del fichero jugadores.txt";
		cout <<endl << "\t\t2. Guardar los jugadores en el fichero jugadores.txt";
		cout <<endl << "\t\t3. Estado de ruleta, dinero de banca y de jugadores";
		cout <<endl << "\t\t4. Girar la ruleta y mostrar premios de jugadores y banca";
		cout <<endl << "\t\t5. Eliminar un jugador de la mesa";
		cout <<endl << "\t\t6. Añadir un jugador da la mesa";
		cout <<endl << "\t\t0. Salir del programa";

		pieGrafico();

		cout << endl << "\tElije una opcion: ";

		getline(cin,opcion);

		switch(atoi(opcion.c_str())){
		case 1:
			cabeceraGrafico("CARGAR VALORES .TXT");
			r.leeJugadores();
			jugadoresc=r.getJugadores();

			contador=0;

			for(i=jugadoresc.begin();i!=jugadoresc.end();i++){
				contador++;
				printf("\n\t\t%d. %-20.20s %-40.35s %-10.10s %-10.10s",contador, i->getNombre().c_str(), i->getApellidos().c_str(), i->getDNI().c_str(),i->getCodigo().c_str());
			}

			pieGrafico();

			pausa();
			break;

		case 2:
			cabeceraGrafico("ESCRIBE JUGADORES");

			r.escribeJugadores();

			mensaje("Lista de Jugadores escrita en el fichero");

			pieGrafico();
			pausa();
			break;

		case 3:
			cabeceraGrafico("ESTADO DE LA RULETA");
			r.getEstadoRuleta(nj,sd,ro,gb);//numero jugadores, suma dinero en mesa, ronda, ganancias banca

			cout << endl << endl << "\t\tNumero de jugadores: " << nj << " | Dinero en la mesa: " << sd << " | Ronda Actual: " << ro << " | Ganancias de banca: " << gb << endl<< endl;
			cout << endl << "\t\tDinero de la banca: " << r.getBanca() << endl;

			jugadoresc=r.getJugadores();

			contador=0;

			for(i=jugadoresc.begin();i!=jugadoresc.end();i++){
							contador++;
							printf("\n\t\t%d. %-20.20s %-40.35s %3.2d",contador, i->getNombre().c_str(), i->getApellidos().c_str(), i->getDinero());
						}

			pieGrafico();
			pausa();
			break;

		case 4:
			cabeceraGrafico("GIRAR LA RULETA");
			jugadoresc2=r.getJugadores();

			numero=r.getBanca();

			r.giraRuleta();

			cout << "\n\t\tEl numero de bola ha sido: " << r.getBola() << endl << endl;

			r.getPremios();
			jugadoresc=r.getJugadores();

			for(i=jugadoresc.begin(),j=jugadoresc2.begin();i!=jugadoresc.end(),j!=jugadoresc2.end();i++,j++){

				printf("\n\t\tGanancias de %-20.20s %-40.35s %8.2d", i->getNombre().c_str(), i->getApellidos().c_str(), i->getDinero()-j->getDinero());
			}

			cout << endl << "\n\t\tGanancias de la banca: " << r.getBanca() - numero << endl;

			pieGrafico();
			pausa();
			break;

		case 5:
			cabeceraGrafico("ELIMINAR JUGADOR");

			jugadoresc=r.getJugadores();

			contador=0;

			for(i=jugadoresc.begin();i!=jugadoresc.end();i++){
				contador++;
				printf("\n\t\t%d. %-20.20s %-35.35s %-10.10s %-10.10s",contador, i->getNombre().c_str(), i->getApellidos().c_str(), i->getDNI().c_str(),i->getCodigo().c_str());
			}

			mensaje("Escribe el dni del jugador que desees eliminar:");
			getline(cin,cadenac);

			if(r.deleteJugador(cadenac)==1){
				mensaje("Jugador Borrado con exito");
			}
			else{
				mensaje("Lista vacía o Jugador no existente");
			}

			pieGrafico();
			pausa();
			break;

		case 6:
				cabeceraGrafico("NUEVO JUGADOR");
				rellenaJugador(jc);
				if(r.addJugador(jc)){
					mensaje("Jugador añadido con exito");
				}
				else{
					mensaje("Error añadiendo Jugador");
				}
				pieGrafico();

				pausa();
			break;


		}

	}while(opcion!="0");

return 0;
}

