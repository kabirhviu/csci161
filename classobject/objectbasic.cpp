#include <iostream>

using namespace std;

class Rectangle {
	private:
		int width;
		int height;

	public:

		//Default constructor
		//Rectangle () {}

		//Customised default constructor
		// Rectangle() {
		// 	width = 0;
		// 	height = 0;
		// }
		//

		//Customised constructor syntax 1
		// Rectangle (int w, int h) {
		// 	width = w;
		// 	height = h;
		// }

		// Customised constructor syntax 2
		// Rectangle (int width, int height) {
		// 	this->width = width;
		// 	this->height = height;
		// }


		//Customised constructor syntax 3
		Rectangle (int width, int height): width(width), height(height) {}

		// Default destructor
		// ~Rectangle() {}

		~Rectangle() {
			cout<< "Rectangle destructor is being called....."<<endl;
		}

		int getWidth() {
			return width;
		}

		int getHeight() {
			return height;
		}

		int getArea() {
			return width*height;
		}
};

class Circle {
private:
	double radious;
public:

	// Circle () {}

	// Circle(double radious) {
	// 	this->radious = radious;
	// }


	Circle(double radious): radious(radious) { }

	~Circle() {
		cout<< "Circle destructor is being called....."<<endl;
	}

	double getCircum() {
		return 2.0*3.14*radious;
	}

	double getArea() {
		return 3.14*radious*radious;
	}
};

class Cylinder {
private:
	Circle base;
	double height;
public:

	/**
	This consttructor is not going to work when
	Circle does not have a default constructor.
	With this syntax Cylinder constructor first
	attempts to create a Circle object against
	the member variable 'base' using Circle's
	default constructor and if Circle's default
	constructor is missing, it will be an error
	*/
	// Cylinder(double radious, double height) {
	// 	this->base = radious;
	// 	this->height = height;
	// }

	/**
	This is safest syntax for Cylinder constructor
	*/
	Cylinder(double radious, double height): base(radious), height(height) {}

	~Cylinder() {
		cout<< "Cylinder destructor is being called....."<<endl;
	}

	double getVolume() {
		return base.getArea()*height;
	}
};

int main() {
	// Rectangle rect;

	//Rectangle rect(); //Not acceptable
	Rectangle rect(5,4);

	cout<<"Rectangle width: "<<rect.getWidth()<<endl;
	cout<<"Rectangle height: "<<rect.getHeight()<<endl;
	cout<<"Rectangle Area: "<<rect.getArea()<<endl;

	Circle foo(10.0);

	cout<<"foo circumference: "<<foo.getCircum()<<endl;
	cout<<"foo area: "<<foo.getArea()<<endl;

	Circle bar = 20.0;

	cout<<"bar circumference: "<<bar.getCircum()<<endl;
	cout<<"bar area: "<<bar.getArea()<<endl;

	Circle baz {30.0}; //uniform initializer

	cout<<"baz circumference: "<<baz.getCircum()<<endl;
	cout<<"baz area: "<<baz.getArea()<<endl;

	Circle qux = {40.0}; //uniform initializer

	cout<<"qux circumference: "<<qux.getCircum()<<endl;
	cout<<"qux area: "<<qux.getArea()<<endl;

	Cylinder cyl(5, 10);
	cout<< "Cylinder volume: "<<cyl.getVolume() << endl;

	return 0;
}
