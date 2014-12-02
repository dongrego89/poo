#include<iostream>
#include<list>

#include "jugador.h"

using namespace std;

int main(){
Jugador j1("30999999X","CODJ001","Benito","Perez Galdos");

cout << j1.getApellidosyNombre();

list<Apuesta> listado;
list<Apuesta>::iterator i;

j1.setApuestas();

listado=j1.getApuestas();

for(i=listado.begin();i!=listado.end();i++){
	cout << endl << i->tipo << " " << i->valor << " " << i->cantidad;
}

return 0;
}
