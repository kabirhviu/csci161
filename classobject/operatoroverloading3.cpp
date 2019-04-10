#include <iostream>

using namespace std;

class CVector {
private:
	int x;
	int y;
public:
	CVector(): x(0), y(0) {}
	CVector(int x, int y): x(x), y(y) {}
	~CVector() {
		cout<< "CVector destructor....."<<endl;
	}

	CVector & operator = (const CVector &);
  CVector & operator ++(); //Pre increment
	CVector & operator ++(int); //Post increment
  CVector & operator --(); //Pre deccrement
	CVector & operator --(int); //Post decrement
  CVector operator -() const; //New CVector by negating x and y value
  CVector operator +(const CVector &) const;
  CVector operator -(const CVector &) const;
  CVector operator *(const CVector &) const;
  // int & operator [] (int) throw (string);
	int & operator [] (int);
  bool operator == (const CVector &) const;

  friend istream & operator >> (istream &, CVector &);
  friend ostream & operator << (ostream &, const CVector &);

};

CVector & CVector::operator = (const CVector &rhs) {
	x=rhs.x;
	y=rhs.y;
	return (*this);
}

CVector & CVector::operator++() {
	x++;
	y++;
	return (*this);
}

CVector & CVector::operator++(int dummy) {
	x++;
	y++;
	return (*this);
}

CVector & CVector::operator -- () {
	x--;
	y--;
	return (*this);
}

CVector & CVector::operator -- (int dummy) {
	x--;
	y--;
	return (*this);
}

CVector CVector::operator -() const {
	CVector temp(-x,-y);
	return temp;
}

CVector CVector::operator +(const CVector &rhs) const {
	CVector temp(x+rhs.x, y+rhs.y);
	return temp;
}

CVector CVector::operator -(const CVector &rhs) const {
	CVector temp(x-rhs.x, y-rhs.y);
	return temp;
}
CVector CVector::operator *(const CVector &rhs) const {
	CVector temp(x*rhs.x, y*rhs.y);
	return temp;
}

// int & CVector::operator [] (int index) throw (string) {
// 	if(index <0 || index>1) {
// 		throw string("Index out of range!");
// 	}
// 	else {
// 		return (index==0? x : y);
// 	}
// }

int & CVector::operator [] (int index) {
	if(index <0 || index>1) {
		throw string("Index out of range!");
	}
	else {
		return (index==0? x : y);
	}
}

bool CVector::operator == (const CVector &rhs) const {
	return (x==rhs.x && y==rhs.y);
}

istream & operator >> (istream &in, CVector &vec) {
	in>>vec.x>>vec.y;
	return in;
}

ostream & operator << (ostream &out, const CVector &vec) {
	out<<"x: "<<vec.x<<", y: "<<vec.y;
	return out;
}

int main() {

	CVector v1(3,4);
	cout<<v1<<endl;
	++v1;
	cout<<"After pre increment: "<<endl;
	cout<<v1<<endl;

	v1++;
	cout<<"After post increment: "<<endl;
	cout<<v1<<endl;

	--v1;
	cout<<"After pre deccrement: "<<endl;
	cout<<v1<<endl;

	v1--;
	cout<<"After post deccrement: "<<endl;
	cout<<v1<<endl;

	CVector v2(2,2);
	CVector v3(2,2);
	cout<<"v1==v3: "<<(v1==v3? "true": "false")<<endl;
	cout<<"v2==v3: "<<(v2==v3? "true": "false")<<endl;

 	CVector v4 = -v1;
	cout<<"Constructor v4=-v1: "<<v4<<endl;

	CVector v5;
	v5=-v1;
	cout<<"Assignment v5=-v1: "<<v5<<endl;

	CVector v6 = v1+v2;
	cout<<"Constructor v6=v1+v2: "<<v6<<endl;

	CVector v7;
	v7=v1+v2;
	cout<<"Assignment v7=v1+v2: "<<v7<<endl;

	CVector v8 = v1-v2;
	cout<<"Constructor v8=v1-v2: "<<v8<<endl;

	CVector v9;
	v9=v1-v2;
	cout<<"Assignment v9=v1-v2: "<<v9<<endl;

	CVector v10 = v1*v2;
	cout<<"Constructor v10=v1*v2: "<<v10<<endl;

	CVector v11;
	v11=v1*v2;
	cout<<"Assignment v11=v1*v2: "<<v11<<endl;

	cout<<"Enter your CVector<x y>: ";
	CVector v20;
	cin>>v20;
	cout<<"You enetered: "<<v20<<endl;

	try{
		cout<<"v20[0]: "<<v20[0]<<", v20[1]: "<<v20[1]<<endl;
		cout<<"v20[-1]: "<<v20[-1]<<", v20[2]: "<<v20[2]<<endl;
		// throw 11;
	}
	catch(string err) {
		cout<<err<<endl;
	}
	catch(int e) {
		cout<<"Caught: "<<e<<endl;
	}
	catch(...) {
		cout<<"Caught excpetion"<<endl;
	}



	// cout<<"v20[0]: "<<v20[0]<<", v20[1]: "<<v20[1]<<endl;
	// cout<<"v20[-1]: "<<v20[-1]<<", v20[2]: "<<v20[2]<<endl;


	return 0;
}
