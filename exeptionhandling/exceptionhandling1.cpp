#include <iostream>

using namespace std;

int division(int dividend, int divisor) {
   if( divisor == 0 ) {
      throw "Exception! Divide by Zero.";
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

   } catch (const char* ex) {
     cerr << ex << endl;
   }

   
   return 0;
}
