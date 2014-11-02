#include<list>
#include<string>
#include<iostream>

using namespace std;

typedef struct{
	string nombre;
	int edad;
}persona;


int main(){


list<persona> lista;
persona aux;
string valor;
bool bandera=false;

if(lista.empty()){
	cout << "La lista esta vacia \n";
}

aux={"Grego",23};
lista.push_back(aux);
aux={"Lore",20};
lista.push_back(aux);
aux={"Juan",29};
lista.push_back(aux);
aux={"Marcos",23};
lista.push_back(aux);


list<persona>::iterator i;

for(i=lista.begin();i!=lista.end();++i){
	cout<<"-"<<*i.nombre<<" \n";
}

cout<<"\nQue valor eliminamos?: ";
cin >> valor;
cout<<"\n";

for(i=lista.begin();i!=lista.end();++i){
	if(*i==valor){	
		cout<<"-"<<*i.nombre<<" es un bandido \n";
		
		
	}
	else{
		cout<<"-"<<*i.nombre<<" \n";
	}

}




cout<<"\n Quedando la lista asi\n";

for(i=lista.begin();i!=lista.end();++i){
	cout<<"-"<<*i.nombre<<" \n";
	if(*i==valor)bandera=true;
}
lista.remove(valor);
if(bandera==false){
	cout<<"\n Elemento no hallado en la lista";
}
return 0;
}
