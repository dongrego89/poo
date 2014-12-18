/*
 * Enumerados.h
 *
 *  Created on: 17/12/2014
 *      Author: i02coprg
 */

#ifndef ENUMERADOS_H_
#define ENUMERADOS_H_

#include<string>
#include<iostream>
#include<vector>

using namespace std;

namespace enumerados {

class Enumerados {
private:
	vector<int> vector_;//vector completo
	int objetivo_;//
public:
	Enumerados(vector<int> numeros,int posicion);

	inline void getSolucion(string resultado){//Impresion por pantalla del resultado
		cout << resultado << endl;
	}
	void operaciones();		/*algoritmo*/
	void generaTabla();

};

} /* namespace enumerados */
#endif /* ENUMERADOS_H_ */
