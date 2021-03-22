/**
 * @file: employee.h
 * @author: Humayun Kabir
 */

#ifndef __EMPLOYEE_HEADER__
#define __EMPLOYEE_HEADER__

#include <string>
#include <istream>
#include <ostream>
#include "person.h"

using namespace std;

class Employee: virtual public Person {
	private:
		string employeeNumber;
		string socialSecNumber;
		double salary;
	public:
		Employee(); //Default constructor
		Employee(string name, string address, string email, string phone, string employeeNumber, string socialSecNumber, double salary); //Regular constructor
		Employee(const Employee& employee); //Copy constructor
		Employee(Employee&& employee); //Move constructor
		Employee& operator = (const Employee& employee); //Copy assignment
		Employee& operator = (Employee&& employee); //Move assignment
		virtual ~Employee(); //Destructor
		void setEmployeeNumber(string employeeNumber);
		void setSocialSecNumber(string socialSecNumber);
		void setSalary(double salary);
		string getEmployeeNumber() const;
		string getSocialSecNumber() const;
		double getSalary() const;
		virtual string getInfo() const override;
		friend istream& operator >> (istream& in, Employee& employee);
		friend ostream& operator << (ostream& out, const Employee& employee);
};
#endif
