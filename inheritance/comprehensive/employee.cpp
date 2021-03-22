/**
 * @file: employee.cpp
 * @author: Humayun Kabir
 */
#include <string>
#include <istream>
#include <ostream>
#include <iostream>

#include "employee.h"

using namespace std;

/**
 * Default Constructor
 */
Employee::Employee():Person(),employeeNumber(string()), socialSecNumber(string()), salary(0.0) {
	cout<<"Employee::default constructor...."<<endl;
}

/**
 * Regular Constructor
 */
Employee::Employee(string name, string address, string email, string phone, string employeeNumber, string socialSecNumber, double salary): 
	Person(name, address, email, phone), employeeNumber(employeeNumber), socialSecNumber(socialSecNumber), salary(salary) {
	cout<<"Employee::regular constructor...."<<endl;
}

/**
 * Copy Constructor
 */
Employee::Employee(const Employee& employee): Person(employee), 
	employeeNumber(employee.employeeNumber), socialSecNumber(employee.socialSecNumber), salary(employee.salary) {
	cout<<"Employee::copy constructor..."<<endl;
}

/**
 * Move Constructor
 */
Employee::Employee(Employee&& employee):  Person(employee), 
	employeeNumber(employee.employeeNumber), socialSecNumber(employee.socialSecNumber), salary(employee.salary) {
	cout<<"Employee::move constructor..."<<endl;
}

/**
 * Copy Assignment
 */
Employee& Employee::operator = (const Employee& employee) {
	Person::operator=(employee); //calls base class copy assignment operator function as the first statement inside the function
	cout<<"Employee::copy assignment...."<<endl;
	employeeNumber = employee.employeeNumber;
	socialSecNumber = employee.socialSecNumber;
	salary = employee.salary;
	return *this;
}


/**
 * Move Assignment
 */
Employee& Employee::operator = (Employee&& employee) {
	Person::operator=(dynamic_cast<Person&&>(employee)); //calls base class move assignment operator function as the first statement inside the function
	cout<<"Employee::move assignment....."<<endl;
	employeeNumber = employee.employeeNumber;
	socialSecNumber = employee.socialSecNumber;
	salary = employee.salary;
	return *this;
}

/**
 * Destructor
 */
Employee::~Employee() {
	cout<<"Employee::destructor....."<<endl;
}

void Employee::setEmployeeNumber(string employeeNumber) {
	this->employeeNumber = employeeNumber;
}

void Employee::setSocialSecNumber (string socialSecNumber) {
	this->socialSecNumber = socialSecNumber;
}

void Employee::setSalary(double salary) {
	this->salary = salary;
}

string Employee::getEmployeeNumber() const {
	return employeeNumber;
}

string Employee::getSocialSecNumber() const {
	return socialSecNumber;
}

double Employee::getSalary() const {
	return salary;
}

string Employee::getInfo() const {
	string info;
        info = Person::getInfo() + "\nEmployee Number: ;" + employeeNumber + "\nSocial Security Number: " + socialSecNumber + "\nSalary: " + to_string(salary);
	return info;
}

istream& operator >> (istream& in, Employee& employee) {
	operator>>(in, dynamic_cast<Person&>(employee))>>employee.employeeNumber>>employee.socialSecNumber>>employee.salary;
	return in;
}

ostream& operator << (ostream& out, const Employee& employee) {
	out<<employee.getInfo();
	return out;
}

