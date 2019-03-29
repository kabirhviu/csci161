#ifndef __STACKADT_H_INCLUDED__
#define __STACKADT_H_INCLUDED__

template <typename T>
class StackADT {
public:
  virtual void push(T element) = 0;
  virtual T pop() = 0;
  virtual T peek() = 0;
  virtual int getSize() = 0;
  virtual bool isEmpty() = 0;
};

#endif
