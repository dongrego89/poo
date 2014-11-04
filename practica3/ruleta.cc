#include "ruleta.h"
#include<fstream>
#include<string>
#include<time>
#include<cstdlib>
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

void Ruleta::giraRuleta(){
	srand(time(NULL));
	setBola(rand()%37);
}

void Ruleta::getPremios(){
	
	list<Jugador>::iterator i;
	list<Apuesta>::iterator j;
	Apuesta aux;

	for(i=jugadores_.begin();i!=jugadores_.end();i++){//Recorremos la lista de objetos jugador
		
		i->setApuestas();//Actualizamos la lista de apuestas a partir del archivo dni
		
		aux=i->getApuestas();//Sacamos la lista de apuestas de este objeto
		
		for(j=aux.begin();j!=aux.end();j++){//Recorremos la lista de apuestas

			switch(aux.tipo){//Analizamos segun el tipo de apuesta generada
				case 1://Numero de 0 a 36, se gana x35 de lo apostado
					if( bola_ == atoi(j->valor.c_str()) ){//Si gana la apuesta
						i->setDinero(i->getDinero()+j->cantidad*35);
						banca_-=j->cantidad*35;
					}
					else{//Si pierde la apuesta
						i->setDinero(i->getDinero()-j->cantidad);
						banca_+=j->.cantidad;
					}
				break;
				case 2://Rojo o Negro, se gana 1 a 1. Si sale 0 se pierde
					if((j->valor.c_str())==color(bola_)){
						i->setDinero(i->getDinero()+j->cantidad);
						banca_-=j->cantidad;	
					}
					else{
						i->setDinero(i->getDinero()-j->cantidad);
						banca-+=j->cantidad;
					}
				break;

				case 3://Par o impar, se gana 1 a 1. Si sale 0 se pierde
					if((j->valor.c_str())==parimpar(bola_)){
						i->setDinero(i->getDinero()+j->cantidad);
						banca_-=j->cantidad;	
					}
					else{
						i->setDinero(i->getDinero()-j->cantidad);
						banca_+=j->cantidad;
					}

				break;

				case 4://Alto(19-36) o bajo(1-18). Se gana 1 a 1. Si sale 0 se pierde
					if((j->valor.c_str())==bajoalto(bola_)){
						i->setDinero(i->getDinero()+j->cantidad);
						banca_-=j->cantidad;	
					}
					else{
						i->setDinero(i->getDinero()-j->cantidad);
						banca_+=j->cantidad;
					}

				break;

			
			}
		}
		
	}
	
}


string Ruleta::bajoalto(int bola){
	if((bola>=1) && (bola<=18)){
		return "bajo";
	}
	else if((bola>=19) && (bola<=36)){
		return "alto";
	}
	else{
		return "cero";
	}
}

string Ruleta::parimpar(int bola){
	if(bola%2==0){
		return "par";	
	}
	else if(bola%2!=0){
		return "impar";	
	}
	else{
		return "cero";
	}

}

string Ruleta::color(int bola){
	switch(bola){
		case 1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36:
			return "rojo";
			break;
		case 0:
			return "cero";
			break;
		default:
			return "negro";
	}
}

}


