#include<fstream>
#include<iostream>
#include<string>

using namespace std;

int main(){
	ifstream archivo;
	char codigo[4],valor[10],apuesta[20];
	archivo.open("listado.txt");
	if(archivo.fail()){
		cerr << "Error abriendo archivo";
		
	}
	
	int contador=0;	
	while(!archivo.eof()){
		archivo.getline(codigo,256,',');
		archivo.getline(valor,256,',');
		archivo.getline(apuesta,256,',');
		cout<<codigo<<" "<<valor<<" "<<apuesta;
	}
	archivo.close();
	return 0;
}
