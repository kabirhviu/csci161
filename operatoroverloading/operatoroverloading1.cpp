#include <iostream>

using namespace std;

class Point {
public:
	int x;
	int y;

	Point(): x(0), y(0) {}
	Point(int x, int y): x(x), y(y) {}
	~Point() {
		cout<< "Point destructor....."<<endl;
	}

	void show() {
		cout<<" x: "<<x<<", y: "<<y<<endl;
	}
	
	/*
	 * Member operator overloaded function
	 */
	 Point operator + (const Point &rhs);
	
	/*
	 * Member operator overloaded function
	 */
	Point operator + (const int rhs);

};

/*
 * Member operator overloaded function definition outside class body
 */
Point Point::operator + (const Point &rhs) {
 	cout<<"member function"<<endl;
 	Point result;
 	result.x = x + rhs.x;
 	result.y = y + rhs.y;
 	return result;
}

/*
 * Non-member operator overloaded function definition
 */
Point operator + (const Point &lhs, const Point &rhs) {
	cout<<"non-member function"<<endl;
	Point result;
	result.x = lhs.x + rhs.x;
	result.y = lhs.y + rhs.y;
	return result;
}

/*
 * Member operator overloaded function definition
 */
Point Point::operator + (const int rhs) {
	Point result;
	result.x = x + rhs;
	result.y = y + rhs;
	return result;
}


/*
 * Non-member operator overloaded functioon definition
 */
//Point operator + (Point lhs, int rhs) {
// 	Point result;
// 	result.x = lhs.x + rhs;
// 	result.y = lhs.y + rhs;
// 	return result;
//}



/*
 * Non-member operator overloaded function definition
 */
Point operator + (const int lhs, const Point &rhs) {
	Point result;
	result.x = lhs + rhs.x;
	result.y = lhs + rhs.y;
	return result;
}



int main() {

	Point p1(3,4);
	cout<<"p1:";
	p1.show();
	Point p2(5,6);
	cout<<"p2:";
	p2.show();
	Point p3 = p1 + p2; 		//Calling operator overloaded function
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
