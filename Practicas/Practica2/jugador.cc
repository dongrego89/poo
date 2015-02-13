/*
 * jugador.cc
 *
 *  Created on: 22/12/2014
 *      Author: grego
 */
#include "jugador.h"
#include<fstream>
#include<string>
#include<cstdlib>
#include<list>

using namespace std;

void Jugador::setApuestas(){
	char tipo[20],valor[20],cantidad[20];//Variables auxiliares tipo char para usarlas en el getline
	Apuesta temporal;//Objeto de tipo apuesta temporal

	apuestas_.clear();//Se vacía la lista de apuestas

	string ruta=getDNI() + ".txt";//Ruta del fichero formada por dni de jugador + .txt
	ifstream fichero(ruta.c_str());//La función ifstream requiere que sea una ruta tipo char, así que se transforma el string a char

	if(fichero.is_open()){//Si se abre el fichero
		while(fichero.getline(tipo,200,',')){//Mientras podamos sacar este elemento (y todos los demás)
			fichero.getline(valor,200,',');
			fichero.getline(cantidad,200,'\n');

			temporal.cantidad=atoi(cantidad);//Los valores de Apuesta enteros requerirán un atoi, ya que las variables auxiliares son char
			temporal.valor=valor;
			temporal.tipo=atoi(tipo);

			apuestas_.push_back(temporal);//Se añade el elemento temporal a la lista de apuestas
		}
		fichero.close();
	}


}

