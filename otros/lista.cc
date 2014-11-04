#include<iostream>
#include<list>
#include<string>

using namespace std;

int main(){

list<string> apuestas;
apuestas.push_back("1,200,1000");
apuestas.push_back("2,300,1400");
//apuestas.clear();


list<string>::iterator i;

for(i=apuestas.begin();i!=apuestas.end();++i){
cout<<*i<<"\n";}
return 0;
}
