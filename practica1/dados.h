#ifndef DADOS_H
#define DADOS_H

#include<cstdio>
#include<ctime>
#include<cstdlib>

using namespace std;

class Dados{
private:
	int valor1_,valor2_,lanz1_,lanz2_,acc1_,acc2_,ultimos1_[5],ultimos2_[5];
public:
	Dados(){
		valor1_=1;
		valor2_=1;
		lanz1_=0;
		lanz2_=0;
		srand(time(NULL));
		acc1_=0;
		acc2_=0;
	}
	void lanzamiento(){
		setDado1(1+rand()%6);
		setDado2(1+rand()%6);
	}
	bool setDado1(int v){
		lanz1_+=1;
		if(v<7 && v>0){
			ultimos1_[lanz1_%5]=v;
			valor1_=v;
			acc1_+=v;
			return true;	
		}
		else{
			return false;
		}
	}
	bool setDado2(int v){
		lanz2_+=1;
		if(v<7 && v>0){
			ultimos2_[lanz2_%5]=v;
			valor2_=v;
			acc2_+=v;
			return true;	
		}
		else{
			return false;
		}
	}
	int getSuma(){
		return valor1_+valor2_;
	}
	int getDado1(){
		return valor1_;	
	}
	int getDado2(){
		return valor2_;	
	}
	int getDiferencia();
	int getLanzamientos1(){return lanz1_;}
	int getLanzamientos2(){return lanz2_;}
	float getMedia1(){
		if(lanz1_==0){
			return 0;	
		}
		else{
			return (float)acc1_/lanz1_;
		}
	}
	float getMedia2(){
		if(lanz2_==0){
			return 0;	
		}
		else{
			return (float)acc2_/lanz2_;
		}
	}
	void getUltimos1(int * vec);
	void getUltimos2(int * vec);
	void ordenaVector(int * vec,int saltos);
};

#endif 
