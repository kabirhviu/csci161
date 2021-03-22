#include <iostream>

using namespace std;

class Point {
private:
	int x;
	int y;
public:
	Point(): x(0), y(0) {}
	Point(int x, int y): x(x), y(y) {}
	~Point() {
		cout<< "Point destructor....."<<endl;
	}
	void show();
	
	/*
	 * Member operator overloaded function
	 */
  	Point operator +(const Point &rhs) const;
	
	/*
	 * Member operator overloaded function
	 */
	Point operator +(const int rhs) const;

	/*
	 * Friend operator overloaded function
	 */
	friend Point operator +(const int lhs, const Point &rhs);
};

void Point::show() {
	cout<<"x: "<<x<<", y: "<<y<<endl;
}

/*
 * Member operator overloaded function definition outside class body
 */
Point Point::operator +(const Point &rhs) const {
	Point temp(x+rhs.x, y+rhs.y);
	return temp;
}

/*
 * Member operator overloaded function definition outside class body
 */
Point Point::operator +(const int rhs) const {
	Point temp(x+rhs, y+rhs);
	return temp;
}

/*
 * Friend operator overloaded function defintion
 */
Point operator +(const int lhs, const Point &rhs) {
	Point temp(lhs+rhs.x, lhs+rhs.y);
	return temp;
}


int main() {

	Point p1(3,4);
	cout<<"p1:";
	p1.show();
	Point p2(5,6);
	cout<<"p2:";
	p2.show();
	Point p3 = p1 + p2;		//Calling operator overloaded function
	cout<<"p3 = p1 + p2 = ";
	p3.show();
	Point p4 = p3 + 2;		//Calling operator overloaded function
	cout<<"p4 = p3 + 2 =  ";
	p4.show();

	Point p5 = 3 + p4;		//Calling operator overloaded function
	cout<<"p5 = 3+ p4 = ";
	p5.show();

	return 0;
}
