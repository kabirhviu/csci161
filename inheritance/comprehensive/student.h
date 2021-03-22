/**
 * @file: student.h
 * @author: Humayun Kabir
 */

#ifndef __STUDENT_HEADER__
#define __STUDENT_HEADER__

#include <string>
#include <istream>
#include <ostream>
#include "person.h"

using namespace std;

class Student: virtual public Person {
	private:
		string id;
		double credits;
		double gpa;
	public:
		Student(); //Defualt constructor
		Student(string name, string address, string email, string phone, string id, double credits, double gpa); //Regular constructor
		Student(const Student& student); //Copy constructor
		Student(Student&& student); //Move constructor
		Student& operator = (const Student& student); //Copy assignment
		Student& operator = (Student&& student); //Move assignment
		virtual ~Student(); //Destructor
		void setId(string id);
		void setCredits(double credits);
		void setGpa(double gpa);
		string getId() const;
		double getCredits() const;
		double getGpa() const;
		virtual string getInfo() const override;
		friend istream& operator >> (istream& in, Student& student);
		friend ostream& operator << (ostream& out, const Student& student);
};
#endif
