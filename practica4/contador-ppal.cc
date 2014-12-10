#include<string>
#include<iostream>

#include "contador.h"

using namespace std;

int main(){
	Contador c(5);
	cout << "Valor inicial de C = " << c.get() << endl;
	
	c++;
	cout << "Incremento C++ = " << c.get() << endl;

	++c;
	cout << "Incremento ++C = " << c.get() << endl;

	c=c+2;
	cout << "Adicion de +2 a C = " << c.get() << endl;

	c=c+2;
	cout << "Adicion de +2 a C = " << c.get() << endl;

	c=c+2;
	cout << "Adicion de +2 a C = " << c.get() << endl;

	c=c+2;
	cout << "Adicion de +2 a C = " << c.get() << endl;

	c=c+2;
	cout << "Adicion de +2 a C = " << c.get() << endl;

	c=c+2;
	cout << "Adicion de +2 a C = " << c.get() << endl;

	c=c-3;
	cout << "Sustraccion de 3 a C = " << c.get() << endl;

	c=40;
	cout << "Asignacion de 40 a C = " << c.get() << endl;

	c=c-20;
	cout << "Sustraccion de 20 a C = " << c.get() << endl;

	c.imprimeVector();	

	c.undo(3);
	cout << "Deshacer 1 acciones" << endl;

	c.imprimeVector();

	cout << "Valor actual de C = " << c.get() << endl;
	return 0;
}
