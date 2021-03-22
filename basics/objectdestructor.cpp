#include <iostream>

using namespace std;

class Student {
private:
	string *id;  //Memory will be allocated dynamically
	string *name; //Memory will be allocated dynamically
	double gpa;
public:
	//Default constructor
	Student():id(new string), name(new string), gpa(0.0) {}
	//Regular constructor
	Student(const string &id, const string &name, double gpa):
	id(new string(id)), name(new string(name)), gpa(gpa) {}

	//Must need a destructor to free dynamically allocated memory
	~Student(){
		cout<<"Student destructor freeing memory (id and name)..."<<endl;
		delete id;
		delete name;
	}

	string getId() {return *id;}
	string getName() {return *name;}
	double getGpa() {return gpa;}
	void show() {
		cout<<"Student Id: "<<getId()<<", Name: "<<getName()<<", GPA: "<<getGpa()<<endl;
	}

};

int main() {

	string id = "S0001";
	string name = "Tim";
	double gpa = 5.0;

	Student student(id, name, gpa);
	student.show();
	return 0;
}
