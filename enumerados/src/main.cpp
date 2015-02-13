/*
 * Enumerados.cpp
 *
 *  Created on: 17/12/2014
 *      Author: i02coprg
 */

#include "Enumerados.h"

using namespace std;
using namespace enumerados;

int main(){
	int i=0;

	vector<int> v={2,7,1,6};

	Enumerados e(v,i);

	for(i=0;i<v.size();i++){
		e(v,i);//creamos el objeto
		e.operaciones();
	}

	return 0;
}
