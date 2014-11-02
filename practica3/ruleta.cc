#include "ruleta.h"
#include<fstream>
#include<string>
#include<list>

using namespace std;

void Ruleta::addJugador(Jugador jugador){

	String ruta=getDNI() + ".txt";
	fstream archivo(ruta.c_str(),fstream::app);// Modo añadir, si no existe crea
	jugadores_.push_back(jugador);
	archivo.close();
	
}

int Ruleta::deleteJugador(Jugador jugador){
	deleteJugador(jugador.getDNI());
}

int Ruleta::deleteJugador(string DNI){
	if(jugadores_.empty()){//La lista esta vacia
		return -2;
	}
	
	list<Jugador>::iterator i;
	bool encontrado=false;

	for(i=jugadores_.begin();i!=jugadores_.end;i++){
		if(i->getDNI()==DNI){
			i=jugadores_.erase(i)//lo ha encontrado	y lo saca 
			return 1;
		}
	}
	return -1;//si no lo encontro devuelve -1


}

void Ruleta::escribeJugadores(){
	list<Jugador>::iterator i;
	fstream archivo("jugadores.txt",fstream::out);

	if(archivo.is_open()){
		for(i=jugadores_.begin();i!=jugadores_end();i++){
			archivo << i->getDNI() << "," << i->getCodigo() << "," << i->getNombre() << "," << i->getApellidos() << "," << i->getDireccion() << "," << i->getLocalidad() << "," << i->getProvincia() << "," << i->getPais() << "," << i->getDinero() << "\n";
		}	
		archivo.close();
	}
}

void Ruleta::void leeJugadores(){
	jugadores_.clear();//limpia la lista de jugadores
	list<Jugador> aux;
	list<Jugador>::iterator i;
	fstream("jugadores.txt",fstream::in);
	if(archivo.is_open()){
		char DNI[50],codigo[50],nombre[50],apellidos[50],direccion[50],localidad[50],provincia[50],pais[50],dinero[50];

	for(i=jugadores_.begin();i!=jugadores_.end();i++){
		archivo.getline(DNI,250,',');
		archivo.getline(codigo,250,',');
		archivo.getline(nombre,250,',');
		archivo.getline(apellidos,250,',');
		archivo.getline(direccion,250,',');
		archivo.getline(localidad,250,',');
		archivo.getline(provincia,250,',');
		archivo.getline(pais,250,',');
		archivo.getline(dinero,250,'\n');
		
		aux.setDNI(DNI);
		aux.setCodigo(codigo);
		aux.setNombre(nombre);
		aux.setApellidos(apellidos);
		aux.setDireccion(direccion);
		aux.setLocalidad(localidad);
		aux.setProvincia(provincia);
		aux.setPais(pais);
		aux.setDinero(dinero);
	}
	archivo.close();
}
}


