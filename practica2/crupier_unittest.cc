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

#include "crupier.h"
#include "gtest/gtest.h"

TEST(Crupier, Constructor){//Construimos objeto y lo comprobamos con metodo 
	Crupier c("33XX","A3BZ8");
	EXPECT_EQ("A3BZ8",c.getCodigo());
}

TEST(Crupier, Codigo){//Completamos el codigo de empleado a posteriori y lo comprobamos
	Crupier c("33XX","");
	c.setCodigo("A3BZ8");
	EXPECT_EQ("A3BZ8",c.getCodigo());
}

TEST(Crupier, DNI){//Inicializamos objeto y usamos metodo de clase padre
	Crupier c("30998747L","BJ0001");
	EXPECT_EQ(c.getDNI(),"30998747L");
}
TEST(Crupier,Ficha){//Usamos variables y metodos de clase padre
	Crupier c("30998747L","BJ0001");
	c.setNombre("Rodolfo");
	c.setApellidos("Cantamañanas Tirititran");
	EXPECT_EQ("Cantamañanas Tirititran, Rodolfo",c.getApellidosyNombre());
}
TEST(Crupier, Copia){
	Crupier c("99xx","PK007"),d("","");
	d=c;
	EXPECT_EQ(d.getCodigo(),c.getCodigo());
	
}
