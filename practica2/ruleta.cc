#include "ruleta.h"
#include<fstream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<list>


using namespace std;

Ruleta::Ruleta(Crupier c): crupier_(c), bola_(-1), banca_(1000000){
srand(time(NULL));
}

void Ruleta::addJugador(Jugador jugador){

	string ruta;
	ruta=jugador.getDNI() + ".txt";
	fstream archivo(ruta.c_str(),fstream::app);// Modo añadir, si no existe crea
	jugadores_.push_back(jugador);
	archivo.close();
	
}

int Ruleta::deleteJugador(Jugador jugador){
	return deleteJugador(jugador.getDNI());
}

int Ruleta::deleteJugador(string DNI){
	if(jugadores_.empty()){//Si La lista esta vacia
		return -1;
	}
	
	list<Jugador>::iterator i;

	for(i=jugadores_.begin();i!=jugadores_.end();i++){
		if(i->getDNI()==DNI){
			i=jugadores_.erase(i);//si hay resultado lo borra 
			return 1;
		}
	}
	return -2;//si no encontro el dni


}

void Ruleta::escribeJugadores(){
	list<Jugador>::iterator i;
	fstream archivo("jugadores.txt",fstream::out);

	if(archivo.is_open()){
		for(i=jugadores_.begin();i!=jugadores_.end();i++){
			archivo << i->getDNI() << "," << i->getCodigo() << "," << i->getNombre() << "," << i->getApellidos() << "," << i->getDireccion() << "," << i->getLocalidad() << "," << i->getProvincia() << "," << i->getPais() << "," << i->getDinero() << "\n";
		}	
		archivo.close();
	}
}

void Ruleta::leeJugadores(){
	jugadores_.clear();//limpia la lista de jugadores
	Jugador aux("xxxx","xxxx");
	list<Jugador>::iterator i;
	fstream archivo("jugadores.txt",fstream::in);
	if(archivo.is_open()){
		char DNI[50],codigo[50],nombre[50],apellidos[50],direccion[50],localidad[50],provincia[50],pais[50],dinero[50];
		
		while(archivo.getline(DNI,250,',')){
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
			aux.setDinero(atoi(dinero));
	
			jugadores_.push_back(aux);
		}
	archivo.close();
	}
}
void Ruleta::giraRuleta(){
	srand(time(NULL));
	setBola(rand()%37);
}

void Ruleta::getPremios(){
	
	list<Jugador>::iterator i;
	list<Apuesta>::iterator j;
	list<Apuesta> aux;

	for(i=jugadores_.begin();i!=jugadores_.end();i++){//Recorremos la lista de objetos jugador
		i->setApuestas();//Actualizamos la lista de apuestas a partir del archivo dni
		
		aux=i->getApuestas();//Sacamos la lista de apuestas de este objeto
		
		for(j=aux.begin();j!=aux.end();j++){//Recorremos la lista de apuestas

			switch(j->tipo){//Analizamos segun el tipo de apuesta generada
				case 1://Numero de 0 a 36, se gana x35 de lo apostado
					if( bola_ == atoi(j->valor.c_str()) ){//Si gana la apuesta
						i->setDinero(i->getDinero()+(j->cantidad*35));
						banca_-=j->cantidad*35;
					}
					else{//Si pierde la apuesta
						i->setDinero(i->getDinero()-j->cantidad);
						banca_+=j->cantidad;
					}
				break;
				case 2://Rojo o Negro, se gana 1 a 1. Si sale 0 se pierde
					if((j->valor.c_str())==color(bola_)){
						i->setDinero(i->getDinero()+j->cantidad);
						banca_-=j->cantidad;	
					}
					else{
						i->setDinero(i->getDinero()-j->cantidad);
						banca_+=j->cantidad;
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
	if(bola==0){
		return "cero";
	}	
	else if(bola%2==0){
		return "par";	
	}
	else{
		return "impar";	
	}	
}

string Ruleta::color(int bola){
	switch(bola){
		case 1: case 3: case 5: case 7: case 9: case 12: case 14: case 16: case 18: case 19: case 21: case 23: case 25: case 27:case 30: case 32: case 34: case 36:
			return "rojo";
			break;
		case 0:
			return "cero";
			break;
		default:
			return "negro";
	}
}

//}



