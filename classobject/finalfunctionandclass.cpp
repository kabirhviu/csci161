#include <iostream>
#include <cmath>

using namespace std;

class Triangle {
protected:
  double base;
  double height;
public:
  Triangle():base(0.0), height(0.0) {}
  Triangle(double base, double height): base(base), height(height) {}
  void setBase(double base) {
    this->base = base;
  }
  void setHeight(double height) {
    this->height = height;
  }
  //final can be used only to non-static virtual method
  virtual double area() final {
    cout<<"Triangle area..."<<endl;
    return 0.5*base*height;
  }
};

class RightTriangle: public Triangle {
public:
  RightTriangle(): Triangle() {}
  RightTriangle(double base, double height): Triangle(base, height) {}
  //virtual final method cannot be overriden
  // double area() {
  //   cout<<"RightTriangle area...."<<endl;
  //   return 0.5*base*height;
  // }
};

class Utility final {
public:
  double square(double number) {
    return number*number;
  }
};

//It is not allowed to define a subclass of
//final class
// class SubUtility: public Utility {
// public:
//   double squareRoot(double number) {
//     return sqrt(number);
//   }
// };

int main() {

  Triangle triangle(3,4);
  cout<<triangle.area()<<endl;
  RightTriangle rightTriangle(3,4);
  cout<<rightTriangle.area()<<endl;

  Triangle& refTriangle = triangle;
  // Triangle& refTriangle = rightTriangle;
  cout<<refTriangle.area()<<endl;

  double number = 4.0;
  Utility util;
  cout<<"The square of: "<<number<<" is: "<<util.square(number)<<endl;

  // SubUtility sUtil;
  // cout<<"The square root of: "<<number<<" is: "<<sUtil.squareRoot(number)<<endl;
}
