#ifndef CRUPIER_H
#define CRUPIER_H

#include "persona.h" 
#include<string>

using namespace std;

class Crupier:public Persona{
private:
	string codigo_;
public:
	Crupier(string dni,string codigo, string nombre="", string apellidos="", string direccion="", string localidad="", string provincia="", string pais=""):Persona(dni,nombre,apellidos,direccion,localidad,provincia,pais){codigo_=codigo;}
	string getCodigo(){
		return codigo_;	
	}
	void setCodigo(string codigo){
		codigo_=codigo;
	}
	
};
#endif
