#include <iostream>

using namespace std;

const int LIST_DEFAULT_CAPACITY = 20;

class ArrayListInt {
private:
  int capacity;
  int size;
  int* list;

public:
  ArrayListInt():capacity(LIST_DEFAULT_CAPACITY), size(0), list(new int[LIST_DEFAULT_CAPACITY]){}
  ArrayListInt(int capacity):capacity(capacity), size(0), list(new int[capacity]) {}
  ~ArrayListInt(){ delete [] list;}
  int getCapacity(){return capacity;}
  int getSize() {return size;}
  void add(int element);
  bool contains(int element);
  bool remove(int element);
  void clear();
  int* asArray();
};

void ArrayListInt::add(int element) {
  if(size<capacity) {
			list[size++] = element;
	}
  else {
    throw string("List is full!");
  }
}

bool ArrayListInt::contains(int element) {
  for(int i=0; i<size; i++) {
    if(list[i] == element) {
      return true;
    }
  }
  return false;
}

bool ArrayListInt::remove(int element) {
  for(int i=0; i<size; i++) {
    if(list[i] == element) {
      for(int j=i; j<size-1; j++) {
        list[j] = list[j+1];
      }
      size--;
      return true;
    }
  }
  return false;
}
void ArrayListInt::clear() {
  for(int i=0; i<size; i++) {
    list[i] = 0;
  }
  size = 0;
}

int* ArrayListInt::asArray() {
  int* copy = new int[size];
  for(int i=0; i<size; i++) {
    copy[i]=list[i];
  }
  return copy;
}


class ArrayListDouble {
private:
  int capacity;
  int size;
  double* list;

public:
  ArrayListDouble():capacity(LIST_DEFAULT_CAPACITY), size(0), list(new double[LIST_DEFAULT_CAPACITY]){}
  ArrayListDouble(int capacity):capacity(capacity), size(0), list(new double[capacity]) {}
  ~ArrayListDouble(){ delete [] list;}
  int getCapacity(){return capacity;}
  int getSize() {return size;}
  void add(double element);
  bool contains(double element);
  bool remove(double element);
  void clear();
  double* asArray();
};

void ArrayListDouble::add(double element) {
  if(size<capacity) {
			list[size++] = element;
	}
  else {
    throw string("List is full!");
  }
}

bool ArrayListDouble::contains(double element) {
  for(int i=0; i<size; i++) {
    if(list[i] == element) {
      return true;
    }
  }
  return false;
}

bool ArrayListDouble::remove(double element) {
  for(int i=0; i<size; i++) {
    if(list[i] == element) {
      for(int j=i; j<size-1; j++) {
        list[j] = list[j+1];
      }
      size--;
      return true;
    }
  }
  return false;
}
void ArrayListDouble::clear() {
  for(int i=0; i<size; i++) {
    list[i] = 0.0;
  }
  size = 0;
}

double* ArrayListDouble::asArray() {
  double* copy = new double[size];
  for(int i=0; i<size; i++) {
    copy[i]=list[i];
  }
  return copy;
}

template <typename T>
class ArrayListTemplate {
private:
  int capacity;
  int size;
  T* list;

public:
  ArrayListTemplate():capacity(LIST_DEFAULT_CAPACITY), size(0), list(new T[LIST_DEFAULT_CAPACITY]){}
  ArrayListTemplate(int capacity):capacity(capacity), size(0), list(new T[capacity]) {}
  ~ArrayListTemplate(){ delete [] list;}
  int getCapacity(){return capacity;}
  int getSize() {return size;}
  void add(T element);
  bool contains(T element);
  bool remove(T element);
  void clear();
  T* asArray();
};

template <typename T>
void ArrayListTemplate<T>::add(T element) {
  if(size<capacity) {
			list[size++] = element;
	}
  else {
    throw string("List is full!");
  }
}

template <typename T>
bool ArrayListTemplate<T>::contains(T element) {
  for(int i=0; i<size; i++) {
    if(list[i] == element) {
      return true;
    }
  }
  return false;
}

template <typename T>
bool ArrayListTemplate<T>::remove(T element) {
  for(int i=0; i<size; i++) {
    if(list[i] == element) {
      for(int j=i; j<size-1; j++) {
        list[j] = list[j+1];
      }
      size--;
      return true;
    }
  }
  return false;
}

template <typename T>
void ArrayListTemplate<T>::clear() {
  for(int i=0; i<size; i++) {
    list[i] = 0.0;
  }
  size = 0;
}

template <typename T>
T* ArrayListTemplate<T>::asArray() {
  T* copy = new T[size];
  for(int i=0; i<size; i++) {
    copy[i]=list[i];
  }
  return copy;
}

int main() {
  int capacity = 10;
  // ArrayListInt intList(capacity);
  // ArrayListDouble doubleList(capacity);

  ArrayListTemplate<int> intList(capacity);
  ArrayListTemplate<double> doubleList(capacity);
  for(int i=0; i<capacity; i++) {
    intList.add(i);
    doubleList.add(i+0.5);
  }
  int* intArray = intList.asArray();
  cout<<"Integer array from integer list: "<<endl;
  for(int i=0; i<capacity; i++) {
    cout<<intArray[i]<< " ";
  }
  cout<<endl;
  double* doubleArray = doubleList.asArray();

  cout<<"Double array from double list: "<<endl;
  for(int i=0; i<capacity; i++) {
    cout<<doubleArray[i]<< " ";
  }

  cout<<endl;

  delete [] intArray;
  delete [] doubleArray;

  return 0;
}
