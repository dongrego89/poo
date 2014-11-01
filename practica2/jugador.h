#ifndef JUGADOR_H
#define JUGADOR_H

#include "persona.h"
#include<iostream>
#include<list>
#include<string>

typedef struct{
	int tipo;
	string valor;
	int cantidad;
}Apuesta;

using namespace std;

class Jugador:public Persona{
private:
	int dinero_;
	string codigo_;
	list<Apuesta> apuestas_;//TIPO,VALOR,CANTIDAD
	
public:
	Jugador(string dni,string codigo, string nombre="", string apellidos="", string direccion="", string localidad="", string provincia="", string pais=""):Persona(dni,nombre,apellidos,direccion,localidad,provincia,pais){codigo_=codigo;dinero_=1000;};
	void setCodigo(string codigo){codigo_=codigo;}
	void setDinero(int dinero){dinero_=dinero;}
	
	int getDinero(){return dinero_;}
	string getCodigo(){return codigo_;}
	list<Apuesta> getApuestas(){return apuestas_;}
	void setApuestas();
	
};
#endif

