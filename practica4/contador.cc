#include<iostream>
#include<vector>

#include "contador.h"
using namespace std;

//Incrementos
Contador Contador::operator++(void){
	//numero_+=1;
	*this=*this+1;
	return *this;
}

Contador Contador::operator++(int){
	//numero_+=1;
	*this=*this+1;
	return *this;
}

//Decrementos
Contador Contador::operator--(void){
	//numero_-=1;
	*this=*this-1;
	return *this;
}

Contador Contador::operator--(int){
	//numero_-=1;
	*this=*this-1;
	return *this;
}

//Asignaciones
Contador Contador::operator=(const Contador &c){
	this->v_[this->cambios_%10]=numero_;
	this->cambios_=this->cambios_+1;
	
	numero_=c.numero_;
	return *this;
}

Contador Contador::operator=(int num){
	this->v_[this->cambios_%10]=numero_;
	this->cambios_=this->cambios_+1;

	numero_=num;
	return *this;
}

//Métodos Friend

int Contador::operator+(int num){
	return num+this.numero_;
}

int Contador::operator+(const Contador &c, int num){
	return num+c.numero_;//vigilar este
}

int Contador::operator-(int num){
	return num - numero_;//vigilar este
}

int Contador::operator-(const Contador &c, int num){
	return c.numero_ - num;
}

//Otros Métodos

void Contador::imprimeVector(){
	int i;
	
	cout << endl << "Vector: ";

	for(i=0;i<10;i++){
		cout << "[" << v_[i] << "]";
	}	

	cout << endl;

}
/*
bool Contador::undo(int v=1){
	if((v>cambios_) || (v>10)){//10 es el limite de cambios en el vector
		return false;
	}
	/*
	Reasignar el valor correspondiente al contador
	Restar a cambios el valor de v
	
	return true;
}*/

