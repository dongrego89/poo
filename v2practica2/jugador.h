#ifndef _JUGADOR_H
#define _JUGADOR_H

#include<list>
#include<string>

#include "persona.h"

using namespace std;

typedef struct{
	int tipo;
	string valor;
	int cantidad;	
}Apuesta;

class Jugador : public Persona{
private:
	int dinero_;
	string codigo_;
	list<Apuesta> apuestas_;
public:
	Jugador(string dni,string cod,string n="",string a="",string di="",string l="",string pr="",string p=""):Persona(dni,n,a,di,l,pr,p){
		codigo_=cod;
		dinero_=1000;
	}

	void setDinero(int d){dinero_=d;}	
	int getDinero()const{return dinero_;}

	void setCodigo(string c){codigo_=c;}
	string getCodigo()const{return codigo_;}

	list<Apuesta> getApuestas()const {return apuestas_;}
	void setApuestas();
};

#endif
