#ifndef _PERSONA_H
#define _PERSONA_H

#include<string>
#include<iostream>
using namespace std;

namespace ruleta{
	class Persona{

	private:
		string DNI_,nombre_,apellidos_,direccion_,localidad_,provincia_,pais_;
	public:
		Persona(string d,string n="",string a="",string di="",string l="",string pr="",string p=""){
			DNI_=d;
			nombre_=n;
			apellidos_=a;
			direccion_=di;
			localidad_=l;
			provincia_=pr;
			pais_=p;
		}	
	
		void setDNI(string d){DNI_=d;}
		void setNombre(string n){nombre_=n;}
		void setApellidos(string a){apellidos_=a;}
		void setDireccion(string d){direccion_=d;}
		void setLocalidad(string l){localidad_=l;}
		void setProvincia(string p){provincia_=p;}
		void setPais(string p){pais_=p;}

		string getDNI()const{return DNI_;}
		string getNombre()const{return nombre_;}
		string getApellidos()const{return apellidos_;}
		string getDireccion()const{return direccion_;}
		string getLocalidad()const{return localidad_;}
		string getProvincia()const{return provincia_;}
		string getPais()const{return pais_;}

		string getApellidosyNombre()const{return apellidos_ + ", " + nombre_;}
	};
}
#endif
