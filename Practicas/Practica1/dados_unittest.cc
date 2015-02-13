// dados_unittest.cc: Juan A. Romero
// A sample program demonstrating using Google C++ testing framework.
//


// This sample shows how to write a more complex unit test for a class
// that has multiple member functions.
//
// Usually, it's a good idea to have one test for each method in your
// class.  You don't have to do that exactly, but it helps to keep
// your tests organized.  You may also throw in additional tests as
// needed.

#include<vector>
#include "dados.h"
#include "gtest/gtest.h"

// Tests the c'tor.
TEST(Dados, Constructor) {
  Dados d;
  EXPECT_EQ(1, d.getDado1());
  EXPECT_EQ(1, d.getDado2());
  EXPECT_EQ(2, d.getSuma()); 
  
}

// Tests diferencia.
TEST(Dados, Diferencia) {
  Dados d;
  for(int i=0;i<30;i++){
	d.lanzamiento();
	EXPECT_LT(d.getDiferencia(),6);
 	EXPECT_GT(d.getDiferencia(),(-1));
	}
  
  
}

// Tests operación lanzamiento
TEST(Dados, Lanzamiento) {
  Dados d;
  for (int i=0; i<100; i++){
  d.lanzamiento();
  EXPECT_GT(d.getDado1(), 0);
  EXPECT_LT(d.getDado1(), 7);
  EXPECT_GT(d.getDado2(), 0);
  EXPECT_LT(d.getDado2(), 7);
}

}

// Tests operación suma
TEST(Dados, Suma) {
  Dados d;
  
  EXPECT_EQ(d.getDado1()+d.getDado2(), d.getSuma());
}


// Test 5 ultimos
TEST(Dados, Ultimos){
Dados d;
vector<int> ultimos(5);
int i;


d.setDado1(1);
d.setDado1(3);
d.setDado1(2);
d.setDado1(4);
d.setDado1(6);

d.getUltimos1(ultimos);

for(i=0;i<5;i++){
	EXPECT_EQ(1,ultimos[0]);
	EXPECT_EQ(3,ultimos[1]);
	EXPECT_EQ(2,ultimos[2]);
	EXPECT_EQ(4,ultimos[3]);
	EXPECT_EQ(6,ultimos[4]);	
}

d.setDado2(3);
d.setDado2(4);
d.setDado2(5);
d.setDado2(6);
d.setDado2(1);

d.getUltimos2(ultimos);

for(i=0;i<5;i++){
	EXPECT_EQ(3,ultimos[0]);
	EXPECT_EQ(4,ultimos[1]);
	EXPECT_EQ(5,ultimos[2]);
	EXPECT_EQ(6,ultimos[3]);
	EXPECT_EQ(1,ultimos[4]);	
}

}

// Test de media
TEST(Dados, Media){
Dados d;
EXPECT_EQ(0,d.getMedia1());
EXPECT_EQ(0,d.getMedia2());


d.setDado1(5);
d.setDado1(4);
d.setDado1(3);

EXPECT_EQ(4,d.getMedia1());

d.setDado2(5);
d.setDado2(4);

EXPECT_EQ(4.5,d.getMedia2());


}


// Tests get lanzamientos
TEST(Dados, NLanzamientos) {
  Dados d;
  EXPECT_EQ(d.getNlanzamientos1(),0);
  EXPECT_EQ(d.getNlanzamientos2(),0);
	for(int i=1;i<=30;i++){
		d.lanzamiento();
	}
  EXPECT_EQ(d.getNlanzamientos1(),30);
  EXPECT_EQ(d.getNlanzamientos2(),30);
}

// Tests modificadores
TEST(Dados, Modificadores) {
  Dados d;
  
  EXPECT_FALSE(d.setDado1(9));
  EXPECT_FALSE(d.setDado1(-9));
  EXPECT_FALSE(d.setDado2(9));
  EXPECT_FALSE(d.setDado2(-9));
  d.setDado1(3);
  EXPECT_EQ(3, d.getDado1());
  d.setDado2(2);
  EXPECT_EQ(2, d.getDado2());
  EXPECT_EQ(5, d.getSuma());
}
