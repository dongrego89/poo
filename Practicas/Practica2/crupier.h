/*
 * crupier.h
 *
 *  Created on: 22/12/2014
 *      Author: grego
 */

#ifndef CRUPIER_H_
#define CRUPIER_H_
#include "persona.h"
#include<string>

using namespace std;

class Crupier: public Persona {

private:
	string codigo_;

public:
	/*Constructor de la clase Crupier, donde son obligatorios los parámetros
	 * @param dni: Indica el dni del crupier
	 * @param codigo: Indica el codigo de trabajador del crupier
	 */
	Crupier(string dni, string codigo, string nombre = "",
			string apellidos = "", string direccion = "", string localidad = "",
			string provincia = "", string pais = "") :
			Persona(dni, nombre, apellidos, direccion, localidad, provincia,
					pais), codigo_(codigo) {
	};

	//Método para retornar el codigo del crupier
	string getCodigo() const {
		return codigo_;
	}

	//Método para establecer el codigo del crupier
	void setCodigo(const string& codigo) {
		codigo_ = codigo;
	}

};

#endif /* CRUPIER_H_ */
