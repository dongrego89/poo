/*
 * ruleta.h
 *
 *  Created on: 9/1/2015
 *      Author: grego
 */

#ifndef RULETA_H_
#define RULETA_H_

#include "crupier.h"
#include "jugador.h"
#include<list>
#include<string>

using namespace std;

class Ruleta{

private:
	int banca_;
	int bola_;
	list<Jugador>jugadores_;
	Crupier crupier_;
	int lanzamientos_;
	int dineroJugadores_;
	int numeroJugadores_;

public:
	//Constructor de la clase Ruleta, el cual requiere de un crupier e inicializa la semilla para numeros aleatorios
	Ruleta(Crupier c);
	//Metodo que retorna el dinero de banca
	inline int getBanca() const {
		return banca_;
	}
	//Metodo que setea la banca a valores positivos
	inline bool setBanca(int banca) {
		if(banca>0){
			banca_ = banca;
			return true;
		}
		return false;
	}

	//Metodo que retorna el valor de la bola
	inline int getBola() const {
		return bola_;
	}

	//Metodo que setea la bola aceptando valores entre 0 y 36
	bool setBola(int bola) {
		if(bola>=0 && bola<=36){
			bola_ = bola;
			return true;
		}
		return false;
	}

	//Metodo que retorna el crupier de la mesa
	Crupier getCrupier() const {
		return crupier_;
	}

	//Metodo que setea el crupier de la mesa
	void setCrupier(const Crupier &c) {
		crupier_ = c;
	}

	//Metodo que retorna la lista de jugadores jugando actualmente
	list<Jugador> getJugadores()const{
		return jugadores_;
	}

	//Metodo que añade un jugador a la mesa
	bool addJugador(const Jugador &j);

	//Metodo que borra un jugador de la mesa, recibiendo a este como objeto o por su dni
	int deleteJugador(string dni);
	int deleteJugador(const Jugador &j);

	//Metodo que guarda la lista de jugadores
	void escribeJugadores();
	//Metodo que carga la lista de jugadores
	void leeJugadores();
	//Metodo que simula el giro de la ruleta y establece un valor de bola
	void giraRuleta();
	//Metodo que carga las ganancias o perdidas de cada jugador y banca
	void getPremios();

	void getEstadoRuleta(int &numeroJugadores,int &sumaDinero, int &lanzamientosBola, int &gananciasBanca);

	//Metodo para saber si la apuesta ha sido negro/rojo observando la bola
	string apuestaColor();
	//Metodo para saber si la apuesta ha sido alta/baja
	string apuestaAltura();
	//Metodo para saber si la apuesta ha sido par/impar
	string apuestaParidad();


};
#endif /* RULETA_H_ */
