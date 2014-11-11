#include<cstdio>
#include<cstring>
#include "jugador.h"
#include "crupier.h"
#include "ruleta.h"

using namespace std;

int main(){

	string dni,cod,nombre,apellidos;
	int seccion;

	cout<<"Registrando Croupier:\n\tIntroduce tu DNI: ";
	getline(cin,dni);
	cout<<"\tIntroduce tu Codigo: ";
	getline(cin,cod);
	cout<<"\tIntroduce tu Nombre: ";
	getline(cin,nombre);
	cout<<"\tIntroduce tus Apellidos: ";
	getline(cin,apellidos);

	Crupier c(dni,cod,nombre,apellidos);

	Ruleta r(c);


do{
	cout<<"CASINO : RULETA ::::::::::::::::::::::::::::::::::::::::::::::"<<endl<<endl;
	cout<<"1. Registrar jugador"<<endl;
	cout<<"2. Borrar jugador"<<endl;
	cout<<"3. Borrar jugador"<<endl;

	
}while(seccion!=0);

return 0;
}
