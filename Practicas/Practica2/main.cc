#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "jugador.h"

using namespace std;

int main() {

	string nombre, apellidos, direccion, provincia, dni, localidad, pais,
			codigo;

	list<Apuesta> apuestas;
	list<Apuesta> :: iterator i;

	cout << "REGISTRO DE NUEVO JUGADOR::::::::::::::::::::::::::::::::" << endl
			<< endl;

	cout << "\tIntroduce nombre: ";
	getline(cin, nombre);
	cout << "\tIntroduce apellidos: ";
	getline(cin, apellidos);
	cout << "\tIntroduce dni: ";
	getline(cin, dni);
	cout << "\tIntroduce codigo de jugador: ";
	getline(cin, codigo);
	cout << "\tIntroduce direccion: ";
	getline(cin, direccion);
	cout << "\tIntroduce provincia: ";
	getline(cin, provincia);
	cout << "\tIntroduce localidad: ";
	getline(cin, localidad);
	cout << "\tIntroduce pais: ";
	getline(cin, pais);

	Jugador j(dni, codigo, nombre, apellidos, direccion, localidad, provincia,
			pais);

	j.setApuestas();

	apuestas=j.getApuestas();


	if(apuestas.size()!=0){

		cout << endl << "LISTA DE APUESTAS::::::::::::: " << endl<< endl;
		cout <<"\tJugador: "<< j.getApellidosyNombre()<< endl << endl;

		for(i=apuestas.begin();i!=apuestas.end();i++){
				cout << "\tTIPO " << i->tipo << ", VALOR " << i->valor << ", CANTIDAD " << i->cantidad << endl;
			}
	}
	else{
		cout << "No existen apuestas para este jugador";
	}


}
