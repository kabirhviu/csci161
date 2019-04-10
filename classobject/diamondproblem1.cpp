#include <iostream>

using namespace std;
//This code does not compile due to diamond problem
//in inheritance hierarchy
class Living {
  public:
  void breathe(){
    cout<<"I am living, I am breathing"<<endl;
  }
};

class Animal : public Living {
  public:
    //Overriding breathe() will not help to
    //avoid diamond problem
    // void breathe(){
    //   cout<<"I am Animal, I am breathing"<<endl;
    // }
};

class Reptile : public Living {
  public:
    //Overriding breathe() will not help
    //avoid diamond problem
    // void breathe(){
    //   cout<<"I am Reptile, I am breathing"<<endl;
    // }
};

//Diamond problem exhibits in snake
//since it has two branches to inherite breathe()
//method from Living.
//One through Animal and the other through Reptile.
//Snake is in confusion about which branch it should
//use.
class Snake: public Animal, public Reptile {
  public:
  //If Snake override breathe() method, diamond problem
  //does not exhibit.
  // void breathe(){
  //   cout<<"I am Snake, I am breathing"<<endl;
  // }
};

int main() {
  Living living;
  Animal animal;
  Reptile reptile;
  Snake snake;

  living.breathe();
  animal.breathe();
  reptile.breathe();
  snake.breathe();

  return 0;
}
