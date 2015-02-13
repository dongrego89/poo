/*
 * jugador.h
 *
 *  Created on: 22/12/2014
 *      Author: grego
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_

#include "persona.h"
#include <string>
#include <list>

using namespace std;

typedef struct {
	int tipo;
	string valor;
	int cantidad;
} Apuesta;

class Jugador: public Persona {
private:
	int dinero_;
	string codigo_;
	list<Apuesta> apuestas_;

public:
	/* Constructor de la clase jugador, donde son obligatorios los parámetros
	 * @param dni: El DNI que necesitamos para crear el objeto persona
	 * @param codigo: El codigo identificador de nuestro jugador en el sistema
	 * */
	Jugador(string dni, string codigo, string nombre = "",
			string apellidos = "", string direccion = "", string localidad = "",
			string provincia = "", string pais = "") :codigo_(codigo), dinero_(1000)
			,Persona(dni, nombre, apellidos, direccion, localidad, provincia,
					pais){
	}
	;
	//Método para establecer el dinero del jugador
	inline void setDinero(int dinero) {
		dinero_ = dinero;
	}
	//Método para retornar el dinero del jugador
	inline int getDinero() const {
		return dinero_;
	}
	//Método para retornar la lista de apuestas del jugador
	inline list<Apuesta> getApuestas() const {
		return apuestas_;
	}
	//Método para tomar las apuestas del jugador de su fichero y cargarlas en la lista de apuestas
	void setApuestas();

	//Método para retornar el codigo de jugador
	inline string getCodigo() const {
		return codigo_;
	}
	//Método para establecer el codigo del jugador
	inline void setCodigo(string codigo) {
		codigo_ = codigo;
	}

};

#endif /* JUGADOR_H_ */
