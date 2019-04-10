#include <iostream>

using namespace std;

class CVector {
public:
	int x;
	int y;
	CVector(): x(0), y(0) {}
	CVector(int x, int y): x(x), y(y) {}
	~CVector() {
		cout<< "CVector destructor....."<<endl;
	}

	void show() {
		cout<<" x: "<<x<<", y: "<<y<<endl;
	}

	// CVector operator + (CVector &rhs);
	CVector operator + (int rhs);

};

// CVector CVector::operator + (CVector &rhs) {
// 	cout<<"member function"<<endl;
// 	CVector result;
// 	result.x = x + rhs.x;
// 	result.y = y + rhs.y;
// 	return result;
// }

CVector operator + (CVector &lhs, CVector &rhs) {
	cout<<"non-member function"<<endl;
	CVector result;
	result.x = lhs.x + rhs.x;
	result.y = lhs.y + rhs.y;
	return result;
}

CVector operator + (int lhs, CVector &rhs) {
	CVector result;
	result.x = lhs + rhs.x;
	result.y = lhs + rhs.y;
	return result;
}


CVector CVector::operator + (int rhs) {
	CVector result;
	result.x = x + rhs;
	result.y = y + rhs;
	return result;
}

// CVector operator + (CVector lhs, int rhs) {
// 	CVector result;
// 	result.x = lhs.x + rhs;
// 	result.y = lhs.y + rhs;
// 	return result;
// }

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
