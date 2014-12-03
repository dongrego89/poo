#ifndef _RULETA_H
#define _RULETA_H

#include <string>
#include <iostream>

#include "jugador.h"
#include "crupier.h"

using namespace std;
namespace ruleta{
	class Ruleta{
		private:
			int banca_;
			int bola_;
			list<Jugador> jugadores_;
			Crupier crupier_;

			int njugadores_;//Numero de jugadores actualmente en la ruleta
			int sdinero_;//Sumatorio del dinero de todos los jugadores + el dinero de banca
			int nlanzamientos_;//Contador de lanzamientos de bola que se han efectuado en la ruleta
			int gbanca_;//Valor de ganancia o perdida de la banca
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

			bool addJugador(const Jugador &j);
			int deleteJugador(const Jugador &j);
			int deleteJugador(string dni);
		
			void escribeJugadores();
			void leeJugadores();

			void getPremios();
			void giraRuleta();
		
			string apuestaColor(int b);
			string apuestaParidad(int b);
			string apuestaAltura(int b);

			
	};
}
#endif
