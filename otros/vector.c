#include<cstdio>
#include<iostream>

using namespace std;

int main(){
	int numero[5];
	numero[4]=2;
	numero[0]=3;
	numero[2]=5;
	numero[1]=9;
	numero[3]=9;
	for(int i=0;i<5;i++){
		printf("valor: %d | ",numero[i]);
	}
return 0;
}
