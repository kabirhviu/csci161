#include <iostream>

using namespace std;

int fpassbyvalue(int param) {
  param = 10;
  return param;
}

int fpassbyreference(int& param) {
  param = 10;
  return param;
}

int fpassbypointer(int* param) {
  *param = 10;
  return *param;
}

int* allocateandreturn() {
  int* param = new int;
  *param = 10;
  return param;
}

void allocatetopointer(int* param) {
  param = new int;
  *param = 10;
  cout<<"inside allocatetopointer() function *param="<<*param<<endl;
}

void allocatetoreferecnetopointer(int*& param) {
  param = new int;
  *param = 10;
  cout<<"inside allocatetoreferecnetopointer() function *param="<<*param<<endl;
}

int main() {
  int p = 0;
  cout<<"return value of fpassbyvalue(p): "<<fpassbyvalue(p)<<endl;
  cout<<"p after calling fpassbyvalue(p): "<<p<<endl;

  p=0;
  cout<<"return value of fpassbyreference(p): "<<fpassbyreference(p)<<endl;
  cout<<"p after calling fpassbyreference(p): "<<p<<endl;

  p=0;
  int* ptr = &p;
  cout<<"return value of fpassbypointer(p): "<<fpassbypointer(ptr)<<endl;
  cout<<"p after calling fpassbypointer(p): "<<p<<endl;

  ptr = NULL;

  ptr = allocateandreturn();
  cout<<"data pointed by ptr after executing 'ptr = allocateandreturn()': "<<*ptr<<endl;

  ptr = NULL;
  allocatetopointer(ptr);
  // cout<<"data pointed by ptr after executing 'allocatetopointer()': "<<*ptr<<endl;

  ptr = NULL;
  allocatetoreferecnetopointer(ptr);
  cout<<"data pointed by ptr after executing 'allocatetoreferecnetopointer()': "<<*ptr<<endl;
  return 0;
}
