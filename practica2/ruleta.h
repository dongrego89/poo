#ifndef RULETA_H
#define RULETA_H

#include "crupier.h"
#include "jugador.h"
#include<list>

using namespace std;

class Ruleta{
private:
	int banca_;
	int bola_;
	list<Jugador> jugadores_;
	Crupier crupier_;	

	string bajoalto(int valor);

	string parimpar(int valor);

	string color(int valor);
public:
	Ruleta(Crupier c);

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

	void giraRuleta();

	void getPremios();
};

#endif
