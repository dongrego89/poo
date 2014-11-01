//3.cc
//programa que simula el lanzamiento de dos dado
#include <iostream>
#include <cstdlib>
using namespace std;

#include "dados.h"

int main(){
int v1,v2;

system("clear");

Dados tirada;

v1=tirada.getDado1();
v2=tirada.getDado2();

cout << "Seteando Dados...\n";
cout << "Dado 1: " << v1 << " Dado 2:" << v2 << "\n";

tirada.lanzamiento();
	v1=tirada.getDado1();
	v2=tirada.getDado2();

	cout << "Tirada de Dados...\n";
	cout << "Dado 1: " << v1 << " Dado 2:" << v2 << "\n";

	cout << "Suma de Dados...\n";
	cout << tirada.getSuma() << "\n";

//cout << tirada.dado1 << "\n";


return 0;
}

