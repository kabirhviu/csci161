#include <iostream>
#include <exception>
#include <string>
#include <typeinfo>

using namespace std;

class Polymorphic {
public:
  virtual ~Polymorphic() {}
  virtual void member(){}
};

int main () {
    int inumber = 0;
    double dnumber = 0.0;
    string id = "S001";
    Polymorphic m;
    Polymorphic* p1 = new Polymorphic();
    Polymorphic* p2 = NULL;
      
  try
  {
      cout<<"typeid int: "<<typeid(inumber).name()<<endl;
      cout<<"typeid double: "<<typeid(dnumber).name()<<endl;
      cout<<"typeid string: "<<typeid(id).name()<<endl;
      cout<<"typeid Polymorphic: "<<typeid(m).name()<<endl; 
      cout<<"typeid Polymorphic*: "<<typeid(p1).name()<<endl; 
      cout<<"typeid NULL Polymorphic*: "<<typeid(p2).name()<<endl; 
      cout<<"typeid Polymorphic* dereferrenced: "<<typeid(*p1).name()<<endl; 
      cout<<"typeid NULL Polymorphic* dereferrenced: "<<typeid(*p2).name()<<endl; //Throws a bad_typid exception 
     
  }
  catch (exception& e)
  {
    cerr << e.what() << endl;
  }
  
  delete p1;


  return 0;
}
