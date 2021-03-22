/**
 * @file: teachingassistant.cpp
 * @author: Humayun Kabir
 */

#include <string>
#include <istream>
#include <ostream>
#include <iostream>

#include "teachingassistant.h"

using namespace std;

/**
 * Default Constructor
 */
TeachingAssistant::TeachingAssistant(): Person(), Employee(), Student() {
	cout<<"TeachingAssistant::default constructor....."<<endl;
}

/**
 * Regular Constructor
 */
TeachingAssistant::TeachingAssistant(string name, string address, string email, string phone, 
		string employeeNumber, string socialSecNumber, double salary, 
		string id, double credits, double gpa): 
		Person(name, address, email, phone),
		Employee(name, address, email, phone, employeeNumber, socialSecNumber,  salary), 
		Student(name, address, email, phone, id, credits, gpa) {
	cout<<"TeachingAssistant::regular constructor....."<<endl;
}


/**
 * Copy Constructor
 */
TeachingAssistant::TeachingAssistant(const TeachingAssistant& ta): Person(ta), Employee(ta), Student(ta) {
	cout<<"TeachingAssistant::copy constructor...."<<endl;
}

/**
 * Move Constructor
 */
TeachingAssistant::TeachingAssistant(TeachingAssistant&& ta) : Person(ta), Employee(ta), Student(ta) {
	cout<<"TeachingAssistant::move constructor..."<<endl;
}

/**
 * Copy assignment
 */
TeachingAssistant& TeachingAssistant::operator = (const TeachingAssistant& ta) {
	Person::operator=(ta);
	Employee::operator=(ta);
	Student::operator=(ta);
	cout<<"TeachingAssistant::copy assignment...."<<endl;
	return *this;
}

/**
 * Move assignment
 */
TeachingAssistant& TeachingAssistant::operator = (TeachingAssistant&& ta) {
//	Person::operator=(dynamic_cast<Person&&>(ta));
	Employee::operator=(dynamic_cast<Employee&&>(ta));
	Student::operator=(dynamic_cast<Student&&>(ta));
	cout<<"TeachingAssistant::move assignment...."<<endl;
	return *this;
}

/**
 * Destructor
 */
TeachingAssistant::~TeachingAssistant() {
	cout<<"TeachingAssistant::destructor...."<<endl;
}

string TeachingAssistant::getInfo() const {
	string info;
	info = Person::getInfo() + "\nEmployee number: " + getEmployeeNumber() +
		"\nSocial Security Number: " + getSocialSecNumber() +
		"\nSalary: " + to_string(getSalary()) +
		"\nStudent ID: " + getId() +
		"\nTotal Credits: " + to_string(getCredits()) +
		"\nGPA: :" + to_string(getGpa());
	return info;
}

istream& operator >> (istream& in, TeachingAssistant& ta) {
	operator>>(in, dynamic_cast<Person&>(ta));
	string employeeNumber;
	string socialSecNumber;
	double salary;
	string id;
	double credits;
	double gpa;

	in>>employeeNumber;
	in>>socialSecNumber;
	in>>salary;
	in>>id;
	in>>credits;
	in>>gpa;

	ta.setEmployeeNumber(employeeNumber);
	ta.setSocialSecNumber(socialSecNumber);
	ta.setSalary(salary);
	ta.setId(id);
	ta.setCredits(credits);
	ta.setGpa(gpa);
	return in;
}

ostream& operator << (ostream& out, const TeachingAssistant& ta) {
	out<<ta.getInfo();
	return out;
}



