#include <iostream>
#include<vector>

using namespace std;

class Contador{
	private:
		int numero_;
		int cambios_;
		vector<int> vector_;

	public:
		
		Contador(int n) : numero_(n), vector_(10), cambios_(0){}
		inline int get(){return numero_;}
		Contador operator++(void); //Para ++c
		Contador operator++(int); //Para c++
		Contador operator--(void); //Para --c
		Contador operator--(int); //Para c--
		Contador operator=(const Contador &c){
             cout << "EJECUTANDO =";
			this->vector_[this->cambios_%10]=numero_;
			this->cambios_+=1;
			numero_=c.numero_;
            cout << "numero_ =" << numero_ << "cambios_" << cambios_ << endl;
			return *this;
		}

		int operator+(const int &num){
			return num + this->numero_;
		}
	
		friend int operator+(const int &num, const Contador &c){
			return num + c.numero_;
		}

		int operator-(const int &num){
			return (this->numero_) - num;
		}
	
		friend int operator-(const int &num, const Contador &c){
			return num - (c.numero_);
		}
		void imprimeVector(){
			int i;
			cout << endl << "VECTOR:";
			for(i=0;i<10;i++){
				cout << "[" << vector_[i] << "]";
			}
			cout << endl;
		}

};


Contador Contador::operator--(void){
	*this=*this-1;	
	return *this;
}

Contador Contador::operator--(int){

	*this=*this-1;	
	return *this;
}

Contador Contador::operator++(void){
	*this=*this+1;	
	return *this;
}


Contador Contador::operator++(int){
	*this=*this+1;	
	return *this;
}


int main(){


return 0;
}
