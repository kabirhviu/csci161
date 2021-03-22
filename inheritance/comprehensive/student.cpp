/**
 * @file: student.cpp
 * @author: Humayun Kabir
 */

#include <string>
#include <iostream>
#include <istream>
#include <ostream>

#include "student.h"

using namespace std;

/**
 * Default Constructor
 */
Student::Student(): Person(), id(string()), credits(0.0), gpa(0.0) {
	cout<<"Student::default constructor..."<<endl;
}

/**
 * Regular Constructor
 */
Student::Student(string name, string address, string email, string phone, string id, double credits, double gpa):
	Person(name, address, email, phone), id(id), credits(credits), gpa(gpa) {
	cout<<"Student::regular constructor...."<<endl;
}

/**
 * Copy Constructor
 */
Student::Student(const Student& student): Person(student), id(student.id), credits(student.credits), gpa(student.gpa) {
	cout<<"Student::copy constructor...."<<endl;
}

/**
 * Move Constructor
 */
Student::Student(Student&& student): Person(student), id(student.id), credits(student.credits), gpa(student.gpa) {
	cout<<"Student::move constructor..."<<endl;
}

/**
 * Copy Assignment
 */
Student& Student::operator = (const Student& student) {
	Person::operator = (student); //calls base class copy assignment operator function as the first statement inside the fucntion
	cout<<"Student::copy assignment..."<<endl;
	id = student.id;
	credits = student.credits;
	gpa = student.gpa;
	return *this;
}

/**
 * Move assignment
 */
Student& Student::operator = (Student&& student) {
	Person::operator = (dynamic_cast<Person&&>(student)); //calls base class move assignment operator as the first statement inside the function
	cout<<"Student::move assignment..."<<endl;
	id = student.id;
	credits = student.credits;
	gpa = student.gpa;
	return *this;
}

/**
 * Destructor
 */
Student::~Student() {
	cout<<"Student::destructor...."<<endl;
}

void Student::setId(string id) {
	this->id = id;
}

void Student::setCredits(double credits) {
	this->credits = credits;
}

void Student::setGpa(double gpa) {
	this->gpa = gpa;
}
string Student::getId() const {
	return id;
}

double Student::getCredits() const {
	return credits;
}

double Student::getGpa() const {
	return gpa;
}

string Student::getInfo() const {
	string info;
	info = Person::getInfo() + "\nStudent ID: " + id + "\nTotal Credits: " + to_string(credits) + "\nGPA: " + to_string(gpa);
	return info;
}

istream& operator >> (istream& in, Student& student) {
	operator>>(in, dynamic_cast<Person&>(student))>>student.id>>student.credits>>student.gpa;
	return in;
}

ostream& operator << (ostream& out, const Student& student) {
	out<<student.getInfo();
	return out;
}


