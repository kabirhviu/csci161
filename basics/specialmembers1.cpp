#include <iostream>
#include <string>

using namespace std;

class Point {
private:
	int _x;
	int _y;
public:
	Point();						//Default constructor
	Point(int x, int y);					//Regular constructor
	Point(const Point& other);				//Copy constructor
	Point(Point&& temp);					//Move constructor
	Point& operator = (const Point&);			//Copy assignment operator overloaded
	Point& operator = (Point&&);				//Move assignment operator overloaded
	~Point();						//Destructor
	int x();
	int y();

};

/*
 * Default constructor
 */ 	
Point::Point(): _x(0), _y(0) {}					

/*
 * Regular constructor
 */
Point::Point(int x, int y): _x(x), _y(y) {}

/*
 * Copy constructor
 */	
Point::Point(const Point& other): _x(other._x), _y(other._y) {}

/*
 * Move constructor
 */	
Point::Point(Point&& temp): _x(temp._x), _y(temp._y) {}


/*
 * Copy assignment operator overloaded function definition
 */
Point& Point::operator = (const Point &rhs) {
	_x=rhs._x;
	_y=rhs._y;
	return (*this);
}

/*
 * Move assignment operator overloaded function definition
 */
Point& Point::operator = (Point&& temp) {
	_x= temp._x;
	_y= temp._y;
	return (*this);
}

/*
 * Destructor
 */
Point::~Point() {						
		cout<< "Point destructor....."<<endl;
	}
	
int Point::x() {
	return _x;
}

int Point::y() {
	return _y;
}

Point createPoint(int x, int y) {
	return Point(x, y);
}


int main() {

	Point p0;						//Calling defualt constructor
	cout<<"p0 = x: "<<p0.x()<<", y: "<<p0.y()<<endl;				

	Point p1(1,1);						//Calling regular constructor
	cout<<"p1 = x: "<<p1.x()<<", y: "<<p1.y()<<endl;				

	Point p2 = p1; 						//Calling copy constructor
	cout<<"p2 = x: "<<p2.x()<<", y: "<<p2.y()<<endl;		
	
	Point p3 = createPoint(3,3);				//Calling move constructor
	cout<<"p3 = x: "<<p3.x()<<", y: "<<p3.y()<<endl;		

	Point p4;						//Calling default constructor
	cout<<"p4 = x: "<<p4.x()<<", y: "<<p4.y()<<endl;			
	
	p4 = p1;						//Calling copy assignment function
	cout<<"p4 = x: "<<p4.x()<<", y: "<<p4.y()<<endl;		
	
	Point p5; 						//Calling default constructor
	cout<<"p5 = x: "<<p5.x()<<", y: "<<p5.y()<<endl;
	p5 = createPoint(5,5);					//Calling move assignment
	cout<<"p5 = x: "<<p5.x()<<", y: "<<p5.y()<<endl;			

	return 0;
}
