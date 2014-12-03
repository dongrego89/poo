#ifndef _CRUPIER_H
#define _CRUPIER_H

#include<string>
#include "persona.h"


using namespace std;

namespace ruleta{
	class Crupier:public Persona{
	private:
		string codigo_;
	
	public:
		void setCodigo(string c){codigo_=c;}
		string getCodigo(){return codigo_;}
	
		Crupier(string dni,string codigo,string n="",string a="",string di="",string l="",string pr="",string p=""):Persona(dni,n,a,di,l,pr,p){
			codigo_=codigo;
		}

	};
}

#endif
