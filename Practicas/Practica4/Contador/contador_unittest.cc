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

#include "contador.h"
#include "gtest/gtest.h"

#include<iostream>

using namespace std;

TEST(Contador, Declaracion) {
  Contador c(2);

  EXPECT_EQ(2,c.get());
}

TEST(Contador,Incremento){
	Contador c(0);
	c++;
	++c;
	EXPECT_EQ(2,c.get());
}

TEST(Contador,Decremento){
	Contador c(0);
	c--;
	--c;
	EXPECT_EQ(-2,c.get());
}
TEST(Contador,EnteroMasContador){
	Contador c(5);
	EXPECT_EQ(6,1 + c.get());
}
TEST(Contador,ContadorMasEntero){
	Contador c(5);
	EXPECT_EQ(6,c.get()+1);
}
TEST(Contador,EnteroMenosContador){
	Contador c(5);
	EXPECT_EQ(3,8 - c.get());
}
TEST(Contador,ContadorMenosEntero){
	Contador c(5);
	EXPECT_EQ(2,c.get()-3);
}
TEST(Contador,AsignacionEntera){
	Contador c(5);
	c=2;
	EXPECT_EQ(2,c.get());
}

TEST(Contador,AsignacionContador){
	Contador c(5);
	Contador c2(77);
	c=c2;
	EXPECT_EQ(77,c.get());
}
TEST(Contador,Undo3Acciones){
	Contador c(0);
	c++;//1
	cout << "[c++] ->" << c.get() << endl;
	c=c+5;//6
	cout << "[c+5] ->" << c.get()<< endl;
	c++;//7
	cout << "[c++] ->" << c.get()<< endl;
	c=10;//10
	cout << "[c=10] ->" << c.get()<< endl;
	c--;//9
	cout << "[c--] ->" << c.get();
	c.undo(3);

	c.imprimeVector();

	EXPECT_EQ(6,c.get());
}

