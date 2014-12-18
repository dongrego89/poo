/*
 * Enumerados.cpp
 *
 *  Created on: 17/12/2014
 *      Author: i02coprg
 */

#include "Enumerados.h"
#include <vector>

using namespace std;

namespace enumerados {

void Enumerados::operaciones(){
	int i,resultado;
	for(i=0;i<vector_.size();i++){
		resultado+=vector_[i];

	}
}

Enumerados::Enumerados(vector<int> numeros,int posicion){
	objetivo_=numeros[posicion];
	numeros.erase(numeros.begin()+posicion);
	vector_=numeros;
}

void Enumerados::generaTabla(){//VAMOS POR AQUI
	  const unsigned n = 3;
	    std::vector<std::vector<int> > output(n, std::vector<int>(1 << n));

	    unsigned num_to_fill = 1U << (n - 1);
	    for(unsigned col = 0; col < n; ++col, num_to_fill >>= 1U)
	    {
	        for(unsigned row = num_to_fill; row < (1U << n); row += (num_to_fill * 2))
	        {
	            std::fill_n(&output[col][row], num_to_fill, 1);
	        }
	    }

	    // These loops just print out the results, nothing more.
	    for(unsigned x = 0; x < (1 << n); ++x)
	    {
	        for(unsigned y = 0; y < n; ++y)
	        {
	            std::cout << output[y][x] << " ";
	        }
	        std::cout << std::endl;
	    }
}
} /* namespace enumerados */
