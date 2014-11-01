#include<list>
#include<string>
#include<fstream>
#include<cstdlib>
#include "jugador.h"

using namespace std;

void Jugador::setApuestas(){

	ifstream archivo;
	char tipo[10],valor[10],cantidad[10];
	string ruta;
	Apuesta a;
	
	ruta=getDNI() + ".txt";
	
	archivo.open(ruta.c_str());
	if(archivo.fail()){
		cerr << "Error abriendo archivo";
		
	}
	
	apuestas_.clear();
	
	while(archivo.getline(tipo,256,',')){
		archivo.getline(valor,256,',');
		archivo.getline(cantidad,256,'\n');
		
		a.tipo=atoi(tipo);
		a.valor=valor;
		a.cantidad=atoi(cantidad);

		apuestas_.push_back(a);
	}
	archivo.close();
}

	
