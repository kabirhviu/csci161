#include <iostream>

using namespace std;

class Living {
  public:
  void breathe(){
    cout<<"I am living, I am breathing"<<endl;
  }
};

//Making Living virtual superclass of both
//Animal and Reptile will resolve diamond
//problem at Snake
class Animal : virtual public Living {
  public:
    //Overriding breathe() will not help to
    //avoid diamond problem
    // void breathe(){
    //   cout<<"I am Animal, I am breathing"<<endl;
    // }
};

//Making Living virtual superclass of both
//Animal and Reptile will resolve diamond
//problem at Snake
class Reptile : virtual public Living {
  public:
    //Overriding breathe() will not help to
    //avoid diamond problem
    // void breathe(){
    //   cout<<"I am Reptile, I am breathing"<<endl;
    // }
};

class Snake: public Animal, public Reptile {
  public:

  //If Snake override, breathe diamond problem
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
