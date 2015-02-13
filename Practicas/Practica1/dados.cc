/*
 * dados.cpp
 *
 *  Created on: 20/12/2014
 *      Author: grego
 */
#include "dados.h"
#include<cstdlib>
#include<ctime>
#include<vector>

using namespace std;

//Constructor de objeto dados que inicializa valores privados y genera semilla para aleatorios
Dados::Dados():dado1_(1),dado2_(1),sumatorio1_(0),sumatorio2_(0),nlanzamientos1_(0),nlanzamientos2_(0),vector1_(5),vector2_(5){
	srand(time(NULL));
}


void Dados::lanzamiento(){
	this->setDado1(rand()%6+1);
	this->setDado2(rand()%6+1);


}

int Dados::getSuma()const{
	return dado1_+dado2_;
}

float Dados::getMedia1()const{
	if(nlanzamientos1_==0){
		return 0;
	}
	else{
		return sumatorio1_/nlanzamientos1_;
	}
}

float Dados::getMedia2()const{
	if(nlanzamientos2_==0){
		return 0;
	}
	else{
		return (float)sumatorio2_/(float)nlanzamientos2_;
	}
}
