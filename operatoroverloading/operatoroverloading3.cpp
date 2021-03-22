#include <iostream>
#include <string>

using namespace std;

class Point {
private:
	int x;
	int y;
public:
	Point(): x(0), y(0) {}					//Default constructor
	Point(int x, int y): x(x), y(y) {}			//Regular constructor
	Point(const Point& other): x(other.x), y(other.y) {}	//Copy constructor
	Point(Point&& temp): x(temp.x), y(temp.y) {}		//Move constructor
	~Point() {						//Destructor
		cout<< "Point destructor....."<<endl;
	}

	
	Point& operator = (const Point&);			//Copy assignment operator overloaded
	Point& operator = (Point&&);				//Move assignment operator overloaded
  	
	Point operator +(const Point&) const;			//Add operator overloaded
  	Point operator -(const Point&) const;			//Subtract operator overloaded
  	Point operator *(const Point&) const;			//Multiply operator overloaded

	
	Point& operator ++(); 					//Pre increment operator overloaded
	Point operator ++(int); 				//Post increment operator overloaded
  	Point& operator --(); 					//Pre decrement operator overloaded
	Point operator --(int); 				//Post decrement operator overloaded
 	Point operator -() const; 				//Negate operator overloaded
	int & operator [] (int);
  	bool operator == (const Point&) const;			//Boolean equal operator overloaded

  	friend istream & operator >> (istream &, Point &);	//Stream extractor operator overloaded
  	friend ostream & operator << (ostream &, const Point &);//Stream inserter operator overloaded

};

/*
 * Copy assignment operator overloaded function definition
 */
Point& Point::operator = (const Point &rhs) {
	x=rhs.x;
	y=rhs.y;
	return (*this);
}

/*
 * Move assignment operator overloaded function definition
 */
Point& Point::operator = (Point&& temp) {
	x= temp.x;
	y= temp.y;
	return (*this);
}

/*
 * Add operator overloaded function defintion
 */
Point Point::operator +(const Point &rhs) const {
	return Point(x+rhs.x, y+rhs.y);
}

/*
 * Subtract operator overloaded function definition
 */
Point Point::operator -(const Point &rhs) const {
	return Point(x-rhs.x, y-rhs.y);
}

/*
 * Multiply operator overloaded function defintion
 */
Point Point::operator *(const Point &rhs) const {
	return Point(x*rhs.x, y*rhs.y);
}

/*
 * Pre increment operator overloaded function defintion
 */
Point& Point::operator++() {
	x++;
	y++;
	return (*this);
}

/*
 * Post increment operator overloaded function defintion
 */
Point  Point::operator++(int dummy) {
	Point temp(x,y);
	x++;
	y++;
	return temp;
}

/*
 * Pre decrement operator overloaded function defintion
 */
Point&  Point::operator -- () {
	x--;
	y--;
	return (*this);
}

/*
 * Post decrement operator overloaded function defintion
 */
Point  Point::operator -- (int dummy) {
	Point temp(x,y);
	x--;
	y--;
	return temp;
}

/*
 * Negate operator overloaded function defintion
 */
Point Point::operator -() const {
	return Point(-x, -y);
}

/*
 * Index operator overloaded function definition
 */
int& Point::operator [] (int index) {
	if(index <0 || index>1) {
		string err;
		err = "Error! index " + to_string(index) + " is out of range.";
		throw err;
	}
	else {
		return (index==0? x : y);
	}
}

/*
 * Boolean equal operator overloaded function definition
 */
bool Point::operator == (const Point &rhs) const {
	return (x==rhs.x && y==rhs.y);
}

/*
 * Stream extractor operator overloaded function definition
 */
istream & operator >> (istream &in, Point &vec) {
	in>>vec.x>>vec.y;
	return in;
}

/*
 * Stream inserter operator overloaded function definition
 */
ostream & operator << (ostream &out, const Point &vec) {
	out<<"x: "<<vec.x<<", y: "<<vec.y;
	return out;
}

int main() {

	Point p0;					//Calling defualt constructor
	cout<<"p0: "<<p0<<endl;				//Calling inserter operator function

	Point p1(3,3);					//Calling regular constructor
	cout<<"p1: "<<p1<<endl;				//Calling inserter operator function

	Point ccp1 = p1; 				//Calling copy constructor
	cout<<"ccp1: "<<ccp1<<endl;			//Calling inserter operator function
	
	Point cap1;					//Calling default constructor
	cout<<"cap1: "<<cap1<<endl;			//Calling inserter operator function
	
	cap1 = p1;					//Calling copy assignment function
	cout<<"cap1: "<<cap1<<endl;			//Calling inserter operator function

	cout<<"Pre-increment: "<<++p1<<endl;           	//Calling pre-increment operator function
	cout<<"After pre-increment p1: "<<p1<<endl;	//Calling inserter operator function


	cout<<"Post increment: "<<p1++<<endl;		//Calling post-increment operator function	
	cout<<"After post-increment p1: "<<p1<<endl;	//Calling inserter operator function

	
	cout<<"Pre decrement: "<<--p1<<endl;		//Calling pre-decrement operator function
	cout<<"After pre-decrement p1: "<<p1<<endl;	//Calling inserter operator function

	
	cout<<"Post decrement: "<<p1--<<endl;		//Calling post-decrement operator function
	cout<<"After post-decrement p1: "<<p1<<endl;	//Calling inserter operator function

	Point p2(4,4);					//Calling regular constructor
	cout<<"p2: "<<p2<<endl;				//Calling inseter operator function

	Point p3(4,4);					//Calling regular constructor
	cout<<"p3: "<<p3<<endl;				//Calling inserter operator function
	
	cout<<"p1==p3: "<<(p1==p3? "true": "false")<<endl;	//Calling equal operator function
	cout<<"p2==p3: "<<(p2==p3? "true": "false")<<endl;	//Calling equal operator function

 	Point p4 = -p1;					//Calling negate operator function and move constructor
	cout<<"p4=-p1: "<<p4<<endl;			//Calling inserter operator function

	Point p5;					//Calling default constructor
	cout<<"p5: "<<p5<<endl;				//Calling inserter operator function

	p5=-p1;						//Calling negate operator and move assignment operator
	cout<<"p5=-p1: "<<p5<<endl;			//Calling inserter operator function

	Point p6 = p1+p2;				//Calling add operator function and move constructor
	cout<<"p6=p1+p2: "<<p6<<endl;			//Calling inserter operator function

	Point p7;					//Calling default constructor
	cout<<"p7: "<<p7<<endl;				//Calling inserter operator function

	p7=p1+p2;					//Calling add operator function and move assignment  
	cout<<"p7=p1+p2: "<<p7<<endl;			//Calling inserter operator function

	Point p8 = p1-p2;				//Calling subtract operator and move constructor			
	cout<<"p8=p1-p2: "<<p8<<endl;			//Calling inserter operator function

	Point p9;					//Calling regular constructor
	cout<<"p9: "<<p9<<endl;				//Calling inserter operator function

	p9=p1-p2;					//Caaling subtract operator function and move assignment
	cout<<"p9=p1-p2: "<<p9<<endl;			//Calling inserter operator function

	Point p10 = p1*p2;				//Calling multiply operator function and move constructor
	cout<<"p10=p1*p2: "<<p10<<endl;			//Calling inserter operator function

	Point p11;					//Calling default constructor
	cout<<"p11: "<<p11<<endl;			//Calling inserter operator function
	
	p11=p1*p2;					//Calling multiply operator function and move assignment
	cout<<"p11=p1*p2: "<<p11<<endl;			//Calling inserter operator function

	Point p20;					//Calling default constructor
	cout<<"p20: "<<p20<<endl;			//Calling inseter operator function
	
	cout<<"Enter your Point<x y>: ";
	cin>>p20;					//Calling extractor operator function
	cout<<"p20: "<<p20<<endl;			//Calling inserter operator function

	try {
		cout<<"p20[0]: "<<p20[0]<<endl;		//Calling index operator function
		cout<<"p20[1]: "<<p20[1]<<endl;		//Calling index operator function
		
		p20[0] = 100;				//Calling index operator function
		p20[1] = 200;				//Calling index operator function

		cout<<"p20: "<<p20<<endl;		//Calling inserter operator function
		
		cout<<"p20[2]: "<<p20[2]<<endl;		//Calling index operator function
	}	
	catch(string err) {
		cout<<err<<endl;
	}

	return 0;
}
