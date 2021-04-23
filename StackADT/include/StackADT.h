#ifndef __STACKADT_H_INCLUDED__
#define __STACKADT_H_INCLUDED__

#include <iostream>

template <typename T>
class StackADT {
public:
	StackADT() {
		std::cout<<"StackADT::constructor......"<<std::endl;
	}
	virtual ~StackADT() {
		std::cout<<"StackADT::desctructor......"<<std::endl;
	}
  	virtual void push(T element) = 0;
  	virtual T pop() = 0;
  	virtual T peek() = 0;
  	virtual int getSize() = 0;
  	virtual bool isEmpty() = 0;
};

#endif
