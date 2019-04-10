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
	int getX() const {return x;}
	int getY() const {return y;}
	int& getX() {return x;}
	int& getY() {return y;}
	void show() {
		cout<<" x: "<<x<<", y: "<<y<<endl;
	}

	CVector operator + (const CVector &rhs);

};

CVector CVector::operator + (const CVector &rhs) {
	cout<<"member function"<<endl;
	CVector result;
	result.x = x + rhs.y;
	result.y = y + rhs.y;
	return result;
}

CVector operator + (const CVector &lhs, const CVector &rhs) {
	cout<<"non-member function"<<endl;
	CVector result;
	result.getX() = lhs.getX() + rhs.getX();
	result.getY() = lhs.getY() + rhs.getY();
	return result;
}

CVector operator + (int lhs, const CVector &rhs) {
	CVector result;
	result.getX() = lhs + rhs.getX();
	result.getY() = lhs + rhs.getY();
	return result;
}

CVector operator + (const CVector lhs, int rhs) {
	CVector result;
	result.getX() = lhs.getX() + rhs;
	result.getY() = lhs.getY() + rhs;
	return result;
}

int main() {

	CVector v1(3,4);
	cout<<"v1:";
	v1.show();
	CVector v2(5,6);
	cout<<"v2:";
	v2.show();
	CVector v3 = v1 + v2;
	cout<<"v3 = v1 + v2 = ";
	v3.show();
	CVector v4 = v3 + 2;
	cout<<"v4 = v3 + 2 =  ";
	v4.show();

	CVector v5 = 3 + v4;
	cout<<"v5 = 3+ v4 = ";
	v5.show();

	return 0;
}
