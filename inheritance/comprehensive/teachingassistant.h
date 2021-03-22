/**
 * @file: teachingassistant.h
 * @author: Humayun Kabir
 */

#ifndef __TEACHING_ASSISTANT_HEADER__
#define __TEACHING_ASSISTANT_HEADER__

#include <string>
#include <istream>
#include <ostream>

#include "employee.h"
#include "student.h"

using namespace std;

class TeachingAssistant: public Employee, public Student {
	private:

	public:
		TeachingAssistant(); //Default constructor
		TeachingAssistant(string name, string address, string email, string phone, 
				string employeeNumber, string socialSecNumber, double salary, 
				string id, double credits, double gpa); //Regular constructor
		TeachingAssistant(const TeachingAssistant& ta); //Copy constructor
		TeachingAssistant(TeachingAssistant&& ta); //Move constructor
		TeachingAssistant& operator = (const TeachingAssistant& ta); //Copy assignment
		TeachingAssistant& operator = (TeachingAssistant&& ta); //Move assignment
		~TeachingAssistant(); //Destructor
		virtual string getInfo() const override;
		friend istream& operator >> (istream& in, TeachingAssistant&);
		friend ostream& operator << (ostream& out, const TeachingAssistant&);

};

#endif
