#include <string>
#include <list>
#include <fstream>
#include <cstdlib>
#include <iostream>

#include "ruleta.h"
#include "jugador.h"
#include "crupier.h"

using namespace std;

/*
Constructor de la clase ruleta
Necesita de un crupier para inicializar
Setea los valores de bola a -1, carga banca a 1M e inicializa la semilla de no aleatorio
*/

namespace ruleta{
	Ruleta::Ruleta(Crupier &c):crupier_(c),bola_(-1),banca_(1000000){
		srand(time(NULL));
	}
	

	/*
	Método necesario par añadir un jugador a la lista de jugadores de la ruleta
	Requiere un jugador
	*/
	bool Ruleta::addJugador(const Jugador &j){
		list<Jugador>::iterator i;
		bool encontrado=false;
		fstream archivo;//Se declara fichero 
		string ruta;
	
		for(i=jugadores_.begin();i!=jugadores_.end();i++){
			if(i->getDNI()==j.getDNI()){//Comprobar si existe este jugador
				encontrado=true;
			}
		}
		if(encontrado==false){//En caso de que no se encuentre
			jugadores_.push_back(j);//Añade a la lista de jugadores

			ruta=j.getDNI() + ".txt";//El fichero se llamará como el dni del objeto parámetro

			archivo.open(ruta.c_str(), ios::in);//Intentamos abrir el archivo para comprobar si existe
			if(!archivo.is_open()){//Si no se abre es porque no existe
				archivo.open(ruta.c_str(), ios::out);
				archivo.close();
			}
		
		
			return true;
				
		}
		else{//En caso de que ya esté en la lista devuelve falso
			return false;
		}
	}

	/*
	Metodo para borrar un jugador de la lista de jugadores de la ruleta
	Requiere de un jugador 
	Devuelve 
		-1 si la lista esta vacía
		1 si se borra el jugador
		-2 si no existe el jugador
	*/
	int Ruleta::deleteJugador(const Jugador &j){
		list<Jugador>::iterator i;
	
		if(jugadores_.empty()){//Si la lista esta vacía devuelve -1
			return -1;
		}	
	
		for(i=jugadores_.begin();i!=jugadores_.end();i++){
			if(j.getDNI()==i->getDNI()){
				jugadores_.erase(i);
				return 1;//Si la lista encuentra coincidencia con el dni del jugador, lo borra de la lista y devuelve 1
			}
		}

		return -2;//Si no ocurre nada de lo anterior, devuelve -2

	}

	/*
	Metodo para borrar un jugador de la lista de jugadores de ruleta a partir de un DNI
	Requiere de un DNI
	Devuelve los mismos valores que la función anterior
	*/
	int Ruleta::deleteJugador(string dni){
		Jugador j(dni,"xxx");//Creamos un objeto jugador introduciendo el DNI necesario para buscarlo
		return deleteJugador(j);//Lanzamos el método anterior y su retorno será lo que retornemos
	}

	/*
	Metodo que toma los valores de la lista de jugadores de la ruleta y los almacena en un archivo llamado jugadores.txt
	No requiere parámetros ni devuelve nada
	*/
	void Ruleta::escribeJugadores(){
		ofstream archivo;
		list<Jugador>::iterator i;

		archivo.open("jugadores.txt");
		if(archivo.is_open()){
			for(i=jugadores_.begin();i!=jugadores_.end();i++){
				archivo << i->getDNI() << ",";
				archivo << i->getCodigo() << ",";
				archivo << i->getNombre() << ",";
				archivo << i->getApellidos() << ",";
				archivo << i->getDireccion() << ",";
				archivo << i->getLocalidad() << ",";
				archivo << i->getProvincia() << ",";
				archivo << i->getPais() << ",";
				archivo << i->getDinero() << "\n";
			}		
			archivo.close();
		}
	
	}

	/*
	Metodo que toma los jugadores del listado jugadores.txt y los carga en la lista de jugadores de la ruleta
	No requiere parámetro ni devuelve nada
	*/
	void Ruleta::leeJugadores(){
		Jugador j("","");
		ifstream archivo;	

		char dni[50],codigo[50],nombre[50],apellidos[50],direccion[50],localidad[50],provincia[50],pais[50],dinero[50];

		jugadores_.clear();
		archivo.open("jugadores.txt");


		if(archivo.is_open()){



			while(archivo.getline(dni,256,',')){
				archivo.getline(codigo,256,',');
				archivo.getline(nombre,256,',');
				archivo.getline(apellidos,256,',');
				archivo.getline(direccion,256,',');
				archivo.getline(localidad,256,',');
				archivo.getline(provincia,256,',');
				archivo.getline(pais,256,',');
				archivo.getline(dinero,256,'\n');

				j.setDNI(dni);
				j.setCodigo(codigo);
				j.setNombre(nombre);
				j.setApellidos(apellidos);
				j.setDireccion(direccion);
				j.setLocalidad(localidad);
				j.setProvincia(provincia);
				j.setPais(pais);
				j.setDinero(atoi(dinero));
			
				jugadores_.push_back(j);

			}		
			archivo.close();
		}
	}


	/*
	Método que simula el giro de una ruleta, estableciendo el valor de la bola en un valor aleatorio entre 0 y 36
	No requiere parámetro ni retorna valor
	*/
	void Ruleta::giraRuleta(){
		bola_=rand()%37;
	}


	/*
	Método que recorre la lista de jugadores de la ruleta y sus listas de apuestas, comprueban si han ganado o perdido y actualizan los valores de dinero de jugador y de banca de la ruleta
	No requiere parámetro ni retorna valor
	*/
	void Ruleta::getPremios(){
		list<Jugador>::iterator j;
		list<Apuesta>::iterator a;
		list<Apuesta> la;
		ifstream archivo;	
		string ruta;

		for(j=jugadores_.begin();j!=jugadores_.end();j++){
			ruta=j->getDNI() + ".txt";
			archivo.open(ruta.c_str());

			if(archivo.is_open()){
				j->setApuestas();
				la=j->getApuestas();
	
				for(a=la.begin();a!=la.end();a++){
					switch(a->tipo){
						case 1:
							if(atoi(a->valor.c_str())==bola_){
								j->setDinero(j->getDinero()+(a->cantidad*35));
								banca_-=a->cantidad*35;	
							}
							else{
								j->setDinero(j->getDinero() - (a->cantidad));
								banca_+=a->cantidad;
							}
						break;	
						case 2:
							if(a->valor == apuestaColor(bola_)){
								j->setDinero(j->getDinero() + (a->cantidad));
								banca_-=a->cantidad;
							}
							else{
								j->setDinero(j->getDinero() - (a->cantidad));
								banca_+=a->cantidad;
							}
						break;	
						case 3:
							if(a->valor == apuestaParidad(bola_)){
								j->setDinero(j->getDinero() + (a->cantidad));
								banca_-=a->cantidad;
							}
							else{
								j->setDinero(j->getDinero() - (a->cantidad));
								banca_+=a->cantidad;
							}
						break;	
						case 4:
							if(a->valor == apuestaAltura(bola_)){
								j->setDinero(j->getDinero() + (a->cantidad));
								banca_-=a->cantidad;
							}
							else{
								j->setDinero(j->getDinero() - (a->cantidad));
								banca_+=a->cantidad;
							}
						break;					
					}
				}

			archivo.close();
			}
		}

	}


	/*
	Método que retorna el color de un número en el paño de la ruleta
	Requiere de un valor entero dado por la bola
	Retorna una cadena "rojo","negro" o "cero"
	*/
	string Ruleta::apuestaColor(int b){
		switch(b){
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

	/*
	Metodo que retorna si el valor es par, impar o cero
	Requiere de un valor entero dado por la bola
	Retorna "cero", "par" o "impar"
	*/
	string Ruleta::apuestaParidad(int b){
		if(b==0){
			return "cero";
		}
		else if(b%2==0){
			return "par";		
		}
		else{
			return "impar";
		}
	}


	/*
	Metodo que retorna si una tirada ha sido alta o baja
	Requiere de un valor entero dado por la bola
	Retorna "alto","bajo" o "cero"
	*/
	string Ruleta::apuestaAltura(int b){
		if(b==0){
			return "cero";
		}
		else if((b>0) && (b<19)){
			return "bajo";		
		}
		else{
			return "alto";
		}
	}
}

