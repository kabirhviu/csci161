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
	// int& getX() {return x;}
	// int& getY() {return y;}
	void show() {
		cout<<" x: "<<x<<", y: "<<y<<endl;
	}

	friend CVector operator+(const CVector &lhs, const CVector &rhs);
	friend CVector operator+(int lhs, const CVector &rhs);
	friend CVector operator+(const CVector lhs, int rhs);

};

CVector operator+(const CVector &lhs, const CVector &rhs) {
	CVector result;
	result.x = lhs.x + rhs.y;
	result.y = lhs.y + rhs.y;
	return result;
}

CVector operator+(int lhs, const CVector &rhs) {
	CVector result;
	result.x = lhs + rhs.x;
	result.y = lhs + rhs.y;
	return result;
}

CVector operator+(const CVector lhs, int rhs) {
	CVector result;
	result.x = lhs.x + rhs;
	result.y = lhs.y + rhs;
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
