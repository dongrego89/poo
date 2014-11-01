#ifndef PERSONA_H
#define PERSONA_H

#include<cstdio>
#include<string>

using namespace std;

class Persona{
private:
	string dni_,nombre_,apellidos_,direccion_,localidad_,provincia_,pais_;
public:
	Persona(string dni, string nombre="", string apellidos="", string direccion="", string localidad="", string provincia="", string pais=""){dni_=dni;nombre_=nombre,apellidos_=apellidos;localidad_=localidad;provincia_=provincia;pais_=pais;direccion_=direccion;};	
	
	void setDNI(string dni){
		dni_=dni;	
	}
	string getDNI(){
		return dni_;
	}

	void setNombre(string nombre){
		nombre_=nombre;
	}
	string getNombre(){
		return nombre_;	
	}

	void setApellidos(string apellidos){
		apellidos_=apellidos;
	}
	string getApellidos(){
		return apellidos_;	
	}

	void setDireccion(string direccion){
		direccion_=direccion;
	}
	string getDireccion(){
		return direccion_;
	}
	void setLocalidad(string localidad){
		localidad_=localidad;
	}
	string getLocalidad(){
		return localidad_;
	}

	void setProvincia(string provincia){
		provincia_=provincia;
	}
	string getProvincia(){
		return provincia_;
	}

	void setPais(string pais){
		pais_=pais;
	}
	string getPais(){
		return pais_;
	}

	string getApellidosyNombre(){
		return apellidos_ + ", " + nombre_;	
	}	
};

#endif
