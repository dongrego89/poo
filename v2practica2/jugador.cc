#include<fstream>
#include<list>
#include<iostream>
#include<string>
#include<cstdlib>

#include "jugador.h"

using namespace std;

void Jugador::setApuestas(){
	string ruta=getDNI() + ".txt";
	char tipo[50],valor[50],cantidad[50];
	Apuesta a;

	ifstream archivo(ruta.c_str());
	if(!archivo.is_open()){
		cout<<"Error abriendo archivo";
	}
	else{
		while(archivo.getline(tipo,250,',')){
			archivo.getline(valor,250,',');
			archivo.getline(cantidad,250,'\n');

			a.tipo=atoi(tipo);
			a.valor=valor;
			a.cantidad=atoi(cantidad);

			apuestas_.push_back(a);
		}
	}
}
