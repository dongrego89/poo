/*
 * persona.h
 *
 *  Created on: 22/12/2014
 *      Author: grego
 */

#ifndef PERSONA_H_
#define PERSONA_H_

#include <string>

using namespace std;

class Persona {
private:
	string DNI_, nombre_, apellidos_, direccion_, localidad_, provincia_, pais_;
public:
	/*Constructor de la clase Persona, donde es obligatorio el parametro
	 * @param dni: Es el dni de dicha persona
	 */

	Persona(string dni, string nombre = "", string apellidos = "",
			string direccion = "", string localidad = "", string provincia = "",
			string pais = "") :
			DNI_(dni), nombre_(nombre), apellidos_(apellidos), direccion_(
					direccion), localidad_(localidad), provincia_(provincia), pais_(
					pais) {
	}
	;
	//Método para retornar el apellido, nombre de la persona
	string getApellidosyNombre() const {
		return apellidos_ + ", " + nombre_;
	}
	//Método para retornar los apellidos de la persona
	string getApellidos() const {
		return apellidos_;
	}
	//Método para establecer los apellidos de la persona
	void setApellidos(const string& apellidos) {
		apellidos_ = apellidos;
	}
	//Método para retornar la direccion de la persona
	string getDireccion() const {
		return direccion_;
	}
	//Método para establecer la direccion de la persona
	void setDireccion(const string& direccion) {
		direccion_ = direccion;
	}
	//Método para retornar el dni de la persona
	string getDNI() const {
		return DNI_;
	}
	//Método para establecer el dni de la persona
	void setDNI(const string& dni) {
		DNI_ = dni;
	}
	//Método para retornar la localidad de la persona
	string getLocalidad() const {
		return localidad_;
	}
	//Método para establecer la localidad de la persona
	void setLocalidad(const string& localidad) {
		localidad_ = localidad;
	}

	//Método para retornar el nombre de la persona
	string getNombre() const {
		return nombre_;
	}

	//Método para establecer el nombre de la persona
	void setNombre(const string& nombre) {
		nombre_ = nombre;
	}

	//Método para retornar el pais de la persona
	string getPais() const {
		return pais_;
	}

	//Método para establecer el pais de la persona
	void setPais(const string& pais) {
		pais_ = pais;
	}

	//Método para retornar la provincia de la persona
	string getProvincia() const {
		return provincia_;
	}

	//Método para establecer la provincia de la persona
	void setProvincia(const string& provincia) {
		provincia_ = provincia;
	}
};

#endif /* PERSONA_H_ */
