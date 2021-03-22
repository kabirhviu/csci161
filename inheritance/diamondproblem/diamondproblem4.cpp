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
//problem at Snake.
//After making Living virtual superclass to
//both Animal and Reptile, if both Animal and
//Reptile override breathe()mthod then diamond
//problem reappears in Snake
class Animal : virtual public Living {
  public:
    //If only Animal overrides breathe() and
    //Reptile does not then diamond problem
    //does not exhibit in Snake.
    void breathe(){
      cout<<"I am Animal, I am breathing"<<endl;
    }
};

//Making Living virtual superclass of both
//Animal and Reptile will resolve diamond
//problem at Snake.
//After making Living virtual superclass to
//both Animal and Reptile, if both Animal and
//Reptile override breathe()mthod then diamond
//problem reappears in Snake
class Reptile : virtual public Living {
  public:
    //If only Reptile overrides breathe() and
    //Animal does not then diamond problem
    //does not exhibit in Snake.
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
