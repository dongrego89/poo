#include<iostream>
#include<vector>

#include "contador.h"
using namespace std;

//Incrementos
Contador Contador::operator++(void){
	*this=*this+1;//numero_+=1;
	return *this;
}

Contador Contador::operator++(int){
	*this=*this+1;//numero_+=1;
	return *this;
}

//Decrementos
Contador Contador::operator--(void){
	*this=*this-1;//numero_-=1;
	return *this;
}

Contador Contador::operator--(int){
	*this=*this-1;//numero_-=1;
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
	return num+this->numero_;
}

int operator+(int num, const Contador &c){
	return num + c.numero_;
}

int Contador::operator-(int num){
	return this->numero_- num;
}

int operator-(int num, const Contador &c){
	return num - c.numero_;
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

bool Contador::undo(int v){
	if((v>cambios_) || (v>10)){//10 es el limite de cambios en el vector
		return false;
	}
	numero_=v_[(cambios_-v)%10];//Reasignar valor correspondiente
	cambios_-=v;//Restablecer el valor de cambios con las operaciones de undo

	return true;
}

