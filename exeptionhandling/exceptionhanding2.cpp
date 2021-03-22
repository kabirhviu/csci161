#include <iostream>
#include <exception>
#include <string>
#include <typeinfo>

using namespace std;

class DivideByZeroException: public exception {
public:
  const char* what() const noexcept {
    return "Cannot divide by zero.";
  }
};

double division(int a, int b) {
   if( b == 0 ) {
      throw DivideByZeroException();
   }
   return (a/b);
}

class Polymorphic {
public:
  virtual ~Polymorphic() {}
  virtual void member(){}
};

int main () {
   int x = 50;
   int y = 0;
   double z = 0.0;

   try {
      z = division(x, y);
      cout << z << endl;
    }
   catch(DivideByZeroException ex) {
     cerr << ex.what() << endl;
   }
   catch(exception ex) {
     cerr<<ex.what()<<endl;
   }

   try
  {
    int number=100;
    cout<<typeid(number).name()<<endl;
    string id = "S001";
    cout<<typeid(id).name()<<endl;
    // Polymorphic * pb = new Polymorphic();
    Polymorphic * pb = NULL;
    cout<<typeid(*pb).name()<<endl;  // throws a bad_typeid exception
    // delete pb;
  }
  catch (exception& e)
  {
    std::cerr << "exception caught: " << e.what() << '\n';
  }

  cout<<"Program ended"<<endl;

  return 0;
}
