#include<cstdio>
#include "dados.h"

int Dados::getDiferencia(){
	if(valor1_>valor2_){
		return valor1_-valor2_;
	}
	else if(valor2_>valor1_){
		return valor2_-valor1_;
	}
	else{
		return 0;
	}
}

void Dados::getUltimos1(int * vec){
		int i,saltos;
		saltos=5-(lanz1_%5);

		//copiamos el vector original 
		for(i=0;i<5;i++){
			vec[i]=ultimos1_[i];
		}
		
		ordenaVector(&vec[0],saltos);
	}

void Dados::ordenaVector(int * vec,int saltos){
		int i,j,aux;
		//hemos de desplazar los valores del vector a la derecha tantas veces como valga la diferencia de saltos y el tamaño del vector
		for(i=1;i!=saltos;i++){
			aux=vec[4];
			for(j=4;j>0;j--){
				vec[j]=vec[j-1];
				
			}
			vec[0]=aux;			
		}
}

void Dados::getUltimos2(int * vec){
		int i,saltos;
		saltos=5-(lanz2_%5);

		for(i=0;i<5;i++){
			vec[i]=ultimos2_[i];
		}
		ordenaVector(&vec[0],saltos);		
	}		
	
