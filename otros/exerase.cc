// erasing from list
#include <iostream>
#include <list>

using namespace std;

int main ()
{
  list<int> lista;
  list<int>::iterator it1;

for (int i=1; i<10; ++i) lista.push_back(i*10);

for(it1=lista.begin();it1!=lista.end();++it1){cout<<*it1<<"\n";}

for(it1=lista.begin();it1!=lista.end();++it1){
	if(*it1==10){
		it1=lista.erase(it1);
	}
}

for(it1=lista.begin();it1!=lista.end();++it1){cout<<*it1<<"\n";}

/*
  // set some values:


                              // 10 20 30 40 50 60 70 80 90
  it1 = it2 = mylist.begin(); // ^^
  advance (it2,6);            // ^                 ^
  ++it1;                      //    ^              ^

  it1 = mylist.erase (it1);   // 10 30 40 50 60 70 80 90
                              //    ^           ^

  it2 = mylist.erase (it2);   // 10 30 40 50 60 80 90
                              //    ^           ^

  ++it1;                      //       ^        ^
  --it2;                      //       ^     ^

  mylist.erase (it1,it2);     // 10 30 60 80 90
                              //        ^

  std::cout << "mylist contains:";
  for (it1=mylist.begin(); it1!=mylist.end(); ++it1)
    std::cout << ' ' << *it1;
  std::cout << '\n';
*/
  return 0;
}
