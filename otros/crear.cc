#include<fstream>
#include<iostream>
#include<string>
//#include<cstdlib>

using namespace std;

int main(){

fstream archivo("perro.txt",fstream::app); //Declaración y apertura de fichero en modo salida y añadiendo
/*

if(!archivo.is_open()){
	cout<<"Fichero no existe. Habra que crearlo\n";
}
else{*/
	cout<<"Fichero existe.\n";
	archivo.close();
/*}*/



return 0;
}
