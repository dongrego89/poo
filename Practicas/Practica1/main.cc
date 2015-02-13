/*
 * main.cpp
 *
 *  Created on: 21/12/2014
 *      Author: grego
 */
#include "dados.h"
#include <iostream>
#include <vector>

using namespace std;

int main(){
	Dados d;
	int i;
	vector<int> ultimos1,ultimos2;

	for(i=0;i<7;i++){
		d.lanzamiento();
		cout << "El resultado del dado 1 es " << d.getDado1() << endl;
		cout << "El resultado del dado 2 es " << d.getDado2() << endl << endl;
	}

	d.getUltimos1(ultimos1);
	d.getUltimos2(ultimos2);

	cout << endl << "Ultimos 5 valores de dado 1: ";
	for(i=0;i<(int)ultimos1.size();i++){
		cout << "[" << ultimos1[i] << "]";
	}

	cout << endl << "Ultimos 5 valores de dado 2: ";
	for(i=0;i<(int)ultimos2.size();i++){
		cout << "[" << ultimos2[i] << "]";
	}

	cout << endl;
	return 0;
}
