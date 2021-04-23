#include <iostream>
#include <exception>

using namespace std;

int main() {

	try {
		throw exception();
	}
	catch(exception e) {
		cout<<"exception.what(): "<<e.what()<<endl;
	}

	return 0;
}
