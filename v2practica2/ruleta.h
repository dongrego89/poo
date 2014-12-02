#ifndef _RULETA_H
#define _RULETA_H

#include <string>
#include <iostream>

#include "jugador.h"
#include "crupier.h"

using namespace std;

class Ruleta{
	private:
		int banca_;
		int bola_;
		list<Jugador> jugadores_;
		Crupier crupier_;
	public:
		Ruleta(Crupier &c);
		inline int getBanca()const{return banca_;}
		inline int getBola()const{return bola_;}

		inline bool setBanca(int v){
			if(v<=0){
				return false;
			}
			else{
				banca_=v;
				return true;
			}
		}

		inline bool setBola(int b){
			if((b<0) || (b>36)){
				return false;
			}
			else{
				bola_=b;
				return true;
			}
		}

		inline Crupier getCrupier()const{return crupier_;}
		inline void setCrupier(Crupier &c){crupier_=c;}

		inline list<Jugador> getJugadores()const{return jugadores_;}

		bool addJugador(Jugador &j);
		int deleteJugador(Jugador &j);
		int deleteJugador(string dni);
		
		void escribeJugadores();
		void leeJugadores();

		void getPremios();
		void giraRuleta();
		
		string apuestaColor(int b);
		string apuestaParidad(int b);
		string apuestaAltura(int b);
};
#endif
