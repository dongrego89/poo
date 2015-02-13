#ifndef _CONTADOR_H
#define _CONTADOR_H

#include <iostream>
#include <vector>


using namespace std;

class Contador{

private:
	int numero_;
	vector<int> v_;
	int cambios_;
	
public:
	/*Metodo constructor de la clase Contador,
	 * @param n: Indica el valor con el que se desea inicializar el contador
	 * Además se reserva memoria para 10 elementos del vector v_, y se inicializa cambios_ a 0
	 */
    Contador(int n):v_(10),numero_(n),cambios_(0){
    };
	
	int get(){return numero_;}

	//Incrementos
	Contador operator++(void);//++c
	Contador operator++(int);//c++

	//Decrementos
	Contador operator--(void);//--c
	Contador operator--(int);//c--

	//Asignaciones
	Contador operator=(const Contador &c);
	Contador operator=(int num);

	//Sumas con int
	friend int operator+(int num, const Contador &c);
	int operator+(int num);

	//Restas con int
	friend int operator-(int num, const Contador &c);
	int operator-(int num);

	//Método que imprime el vector v_ con formato
	void imprimeVector();
	//Método que deshace v operaciones
	bool undo(int v=1);

};

#endif
