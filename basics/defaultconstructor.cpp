#include <iostream>

using namespace std;

class Point {
private:
  int x;
  int y;
public:
  /*
  A default constructor is required to allow
  the creation of an array of objects of Point type.
   or
  to dynamically allocate memory for several
  objects of Point type.
  */
  Point(): x(0), y(0) {}

  Point(int x, int y):x(x), y(y) {}
  void show() {
    cout<<"Point x: "<<x<<", y: "<<y<<endl;
  }
};

int main(){
  Point p(3,4);
  p.show();

  Point aPoints[2];
  aPoints[0].show();
  aPoints[1].show();

  Point *pPoints = new Point[2];
  pPoints[0].show();
  pPoints[1].show();

  delete [] pPoints;

  return 0;
}
