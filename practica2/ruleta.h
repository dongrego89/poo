#ifndef RULETA_H
#define RULETA_H


#include "crupier.h"
#include "jugador.h"

class Ruleta{
private:
	int banca_;
	int bola_;
	list<Jugador> jugadores;
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

};

#endif
