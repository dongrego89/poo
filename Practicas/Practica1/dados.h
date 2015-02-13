/*
 * dados.h
 *
 *  Created on: 20/12/2014
 *      Author: grego
 */

#ifndef DADOS_H_
#define DADOS_H_

#include<vector>

using namespace std;

class Dados{

private:
	int dado1_,dado2_;
	int sumatorio1_,sumatorio2_;
	int nlanzamientos1_, nlanzamientos2_;

	vector<int> vector1_,vector2_;
public:
	Dados();

	//Simula el lanzamiento de 2 dados asignandoles valores aleatorios
	void lanzamiento();

	//Devuelve el valor del dado1
	inline int getDado1() const {
		return dado1_;
	}

	//Establece el valor del dado1
	inline bool setDado1(int dado1) {
		if(dado1>6 || dado1<1){
			return false;
		}
		else{
			dado1_ = dado1;
			sumatorio1_+=dado1_;

			vector1_[(nlanzamientos1_)%5]=dado1_;
			nlanzamientos1_+=1;
			return true;
		}
	}

	//Devuelve el valor del dado2
	inline int getDado2() const {
		return dado2_;
	}

	//Establece el valor del dado2
	inline bool setDado2(int dado2) {
		if(dado2>6 || dado2<1){
			return false;
		}
		else{
			dado2_ = dado2;
			sumatorio2_+=dado2_;
			vector2_[(nlanzamientos2_)%5]=dado2_;
			nlanzamientos2_+=1;
			return true;
		}
	}

	//Devuelve el valor de suma del ultimo lanzamiento
	int getSuma()const;

	//Devuelve la media de los valores del dado1
	float getMedia1()const;

	//Devuelve la media de los valores del dado2
	float getMedia2()const;

	//Devuelve el numero de lanzamientos del dado2
	inline int getNlanzamientos2() const {
		return nlanzamientos2_;
	}

	//Devuelve el numero de lanzamientos del dado1
	inline int getNlanzamientos1() const {
		return nlanzamientos1_;
	}
	//Recibe usando referencias un vector y le asigna el vector de 5 ultimos resultados de dado1
	inline void getUltimos1(vector<int> & vector){
		vector=vector1_;
	}

	//Recibe usando referencias un vector y le asigna el vector de 5 ultimos resultados de dado2
	inline void getUltimos2(vector<int> & vector){
		vector=vector2_;
	}

	//Devuelve la diferencia entre los 2 dados lanzados
	inline int getDiferencia(){
		if(dado1_ > dado2_){
			return dado1_ - dado2_;
		}
		else if(dado2_ > dado1_){
			return dado2_ - dado1_;		
		}	
		else{
			return 0;
		}
	}
};

#endif /* DADOS_H_ */
