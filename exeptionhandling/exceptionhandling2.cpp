#include <iostream>
#include <exception>

using namespace std;

class DBZException: public exception {
public:
  const char* what() const noexcept override {
    return "Exception! Divide by Zero.";
  }
};

class FakeException: public exception {
public:
	const char* what() const noexcept override {
		return "Exception! Fake.";
	}
};


int division(int dividend, int divisor) {
   if( divisor == 0 ) {
      throw DBZException();
   }
   return (dividend/divisor);
}

int main () {
   int dividend;
   int divisor;
   int quotient;

   cout<<"Enter your dividend and divisor: ";
   cin>>dividend>>divisor;
   
   try {
      
 	quotient = division(dividend, divisor);
      	cout<<dividend<<"/"<<divisor<<" = "<<quotient<<endl;
	throw FakeException(); 

   } catch (exception& ex) {
     	cerr << ex.what() << endl;
   }
  
    
   return 0;
}

