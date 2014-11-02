#ifndef RULETA_H
#define RULETA_H


#include "../practica2/crupier.h"
#include "../practica2/jugador.h"
#include<list>

using namspace std;

class Ruleta{
private:
	int banca_;
	int bola_;
	list<Jugador> jugadores_;
	Crupier crupier_;
public:
	Ruleta(Crupier crupier){
		bola_=-1;
		banca_=1000000;
		crupier_=crupier;
	}
	int getBanca(){
		return banca_;	
	}
	void setBanca(int valor){
		if(valor>0){	
			banca_=valor;
		}
	}
	
	int getBola(){
		return bola_;
	}	
	void setBola(int valor){
		if((valor>=0) && (valor<=36)){
			bola_=valor;
		}
	}
	Crupier getCrupier(){
		return crupier_;
	}
	void setCrupier(Crupier crupier){
		crupier_=crupier;
	}

	list<Jugador> getJugadores(){
		return jugadores_;
	}

	void addJugador(Jugador jugador);

	int deleteJugador(string DNI);

	int deleteJugador(Jugador jugador);

	void escribeJugadores();

	void leeJugadores();

};

#endif
