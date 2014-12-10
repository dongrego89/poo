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
	Contador(int n):cambios_(0),numero_(n),v_(10){
	}
	
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

	void imprimeVector();
	bool undo(int v=1);

/*
cute gtk IGUs
*/

};

#endif
