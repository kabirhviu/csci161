#include <iostream>

using namespace std;

int sum(int one, int two){
  return one + two;
}

int sum(int one, int two, int three) {
  return one + two + three;
}

/**
* Will not work.
* Changing only return type does not overload a function
*/
// double sum(int one, int two) {
//   return (double) (one + two);
// }

double sum(double one, double two) {
  return one + two;
}

double sum(double one, double two, double three) {
  return one + two + three;
}

int sum(int one, double two) {
  return one + (int)two;
}

double sum(double one, int two) {
  return one + (double)two;
}

template <typename T>
T sum(T one, T two) {
  return one + two;
}

template <typename T>
T sum(T one, T two, T three) {
  return one + two + three;
}

template <typename T, typename U>
T sum(T one, U two) {
  return one + (T)two;
}

int main() {
  cout << "sum(4, 5)= "<<sum(4,5)<<endl;
  cout << "sum(4, 5, 9)= "<<sum(4,5,9)<<endl;

  cout << "sum(4.5, 5.0)= "<<sum(4.5,5.0)<<endl;
  cout << "sum(4.5, 5.0, 9.0)= "<<sum(4.5,5.0,9.0)<<endl;

  cout << "int sum(4, 5.5)= "<<sum(4,5.5)<<endl;
  cout << "double sum(4.5, 5)= "<<sum(4.5,5)<<endl;

  cout << "sum<int>(4, 5)= "<<sum<int>(4,5)<<endl;
  cout << "sum<double>(4.5, 5.0)= "<<sum<double>(4.5,5.0)<<endl;

  cout << "sum<int>(4, 5, 9)= "<<sum<int>(4,5,9)<<endl;
  cout << "sum<double>(4.5, 5.0, 9.0)= "<<sum<double>(4.5,5.0,9.0)<<endl;

  cout << "sum<int, double>(4, 5.5)= "<<sum<int>(4,5.5)<<endl;
  cout << "sum<double, int>(4.5, 5)= "<<sum<double>(4.5,5)<<endl;
  return 0;
}
