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

	//Constructor
	Student(const string &id, const string &name, double gpa):
	id(new string(id)), name(new string(name)), gpa(gpa) {}

	// Copy constructor
	Student(const Student& other):id(new string(*other.id)), name(new string(*other.name)),gpa(other.gpa) {}

	//Copy assignment
	// Student& operator= (const Student& other) {
	// 	delete id;
	// 	id = new string(*other.id);
	// 	delete name;
	// 	name = new string(*other.name);
	// 	gpa = other.gpa;
	// 	return *this;
	// }

	//Copy assignment version 2
	Student& operator= (const Student& other) {
		*id = *other.id;		//Does not need to do delete and new on *id and *name since they are string objects
		*name = *other.name;		//string class has copy assignment function defined, copy assignment function takes care of the memory
		gpa = other.gpa;
		return *this;
	}


	//Move constructor
	Student(Student&& temp): id(temp.id), name(temp.name),
														gpa(temp.gpa) {
															temp.id = NULL;
															temp.name = NULL;
														}

	//Move assignment
	Student& operator= (Student&& temp) {
		delete id;
		id = temp.id;
		temp.id = NULL;
		delete name;
		name = temp.name;
		temp.name = NULL;
		gpa = temp.gpa;
		return *this;
	}

	//Destructor
	~Student(){
		cout<<"Student destructor freeing memory (id and name)..."<<endl;
		delete id;
		delete name;
	}

	string getId() const {return *id;}
	string getName() const {return *name;}
	double getGpa() const {return gpa;}
	void show() {
		cout<<"Student Id: "<<getId()<<", Name: "<<getName()<<", GPA: "<<getGpa()<<endl;
	}

};

Student createStudent(string id, string name, double gpa) {
	return Student(id, name, gpa);
}

int main() {

	string id = "S0001";
	string name = "Tim";
	double gpa = 5.0;

	//Calls constructor
	Student student1(id, name, gpa);
	student1.show();

	//Calls copy constructor
	Student student2(student1);
	student2.show();

	//Calls copy constructor
	Student student3 = student1;
	student3.show();

	Student student5;
	//Calls copy assignment
	student5 = student1;
	student5.show();

	//Calls move constructor
	Student student6 = Student("S0002", "Tom", 4.5);
	student6.show();

	//Calls move constructor
	Student student7 = createStudent("S0003", "Jerry", 4.0);
	student7.show();

	Student student8;
	//Calls move assignment
	student8 = Student("S0004", "Dave", 3.5);
	student8.show();

	Student student9;
	//Calls move assignment
	student9 = createStudent("S0005", "Lucas", 2.5);
	student9.show();

	return 0;
}
