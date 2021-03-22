/**
 * @file: main.cpp
 * @author: Humayun Kabir
 */

#include <iostream>
#include <string>

using namespace std;

#include "person.h"
#include "employee.h"
#include "student.h"
#include "teachingassistant.h"

int main() {

	
	Person* persons[25];
	int i = 0;
	
	/**
	 * Testing Person::default parameters
	 */
	cout<<"Testing Person:: default constructor with default parameters."<<endl;
	Person nobody;
	cout<<"Nobody...."<<nobody<<endl;
	
	/**
	 * Testing Person::operator>>
	 */

	/*
	cout<<"Testing Person::operator >>"
	Person anybody;
	cin>>anybody;
	cout<<"Anybody...."<<anybody<<endl;
	*/
	
	/**
	 * Testing Person::regular constructor
	 */
	cout<<"testing Person::regular constructor"<<endl;
	Person person1("Humayun Kabir", "Victoria, BC", "humayun@domain.com", "250-555-7777");
	cout<<"___Person 1___"<<person1<<endl;

	persons[i++] = &person1;
	
	/**
	 * Testing Person::copy constructor
	 */
	cout<<"Testing Person::copy constructor."<<endl;
	Person person2(person1);
	cout<<"___Copy Constructed Person___"<<person2<<endl;

	persons[i++] = &person2;
	/**
	 * Testing Person::move constructor
	 */
	cout<<"Testing Person::move constructor"<<endl;
	Person person3 = Person("Merlin Hansen", "Nanaimo, BC", "merlin@nanaimo.ca", "250-777-9999");
	cout<<"___Move Constructed Person___"<<person3<<endl;

	persons[i++] = &person3;
	/**
	 * Testing Person::copy assignment
	 */
	cout<<"Testing Person::copy assignment"<<endl;
	Person person4;
	person4 = person3;
	cout<<"___Copy Assigned Person___"<<person4<<endl;
	
	persons[i++] = &person4;
	/**
	 * Testing Person::move assignment
	 */
	cout<<"Tesitng Person::move assignment"<<endl;
	Person person5;
	person5 = Person("Dave Wassels", "Victoria, BC", "wassels@wassels.com", "250-999-4444");
	cout<<"___Move Assigned Person___"<<person5<<endl;

	persons[i++] = &person5;
	/**
	 * Testing Employee::default constructor
	 */
	cout<<"Testing Employee::defualt constructor"<<endl;
	Employee anonymousEmp;
	cout<<anonymousEmp<<endl;
		
	/**
	 * Testing Employee::operator>>
	 */
	/**
	cout<<"Testing Employee:: operator >>"<<endl;
	cin>>anonymousEmp;
	cout<<"___Inserted Employee___"<<anonymousEmp<<endl;
	*/

	/**
	 * Testing Employee::regular constructor
	 */
	cout<<"Testing Employee::regular constructor"<<endl;
	Employee emp1("Humayun Kabir", "Victoria, BC", "humayun@domain.com", "250-555-7777", "EMP1000200", "SN2340889", 10000000.0);
       	cout<<"___Regularly Constructed Employee___"<<emp1<<endl;	

	persons[i++] = &emp1;
	/**
	 * Testing Employee::copy constructor
	 */
	cout<<"Testing Employee::copy constructor....."<<endl;
	Employee emp2(emp1);
	cout<<"___Copy Constructed Employee___"<<emp2;
	persons[i++] = &emp2;

	/**
	 * Testing Employee::move constructor
	 */
	cout<<"Testing Employee::move contructor"<<endl;
	Employee emp3 = Employee("Humayun Kabir", "Victoria, BC", "humayun@domain.com", "250-555-7777", "EMP1000200", "SN2340889", 10000000.0);
	cout<<"___Move Constructed Employee___"<<emp3<<endl;
	persons[i++] = &emp3;

	/**
	 * Testing Employee::copy assignment
	 */
	cout<<"Testing Employee:: copy assignment"<<endl;
	Employee emp4;
	emp4 =emp3;
	cout<<"__Copy Assgined Employee___"<<emp4<<endl;
	persons[i++] = &emp4;

	/**
	 * Testing Employee::move assignment
	 */
	cout<<"Testing Employee:: move assignment"<<endl;
	Employee emp5;
	emp5 = Employee("Humayun Kabir", "Victoria, BC", "humayun@domain.com", "250-555-7777", "EMP1000200", "SN2340889", 10000000.0);
	cout<<"___Move Assigned Employee___"<<emp5<<endl;
	persons[i++] = &emp5;

	/**
	 * Testing Student::default constructor
	 */
	cout<<"Testing Stdudent::default constructor"<<endl;
	Student anonymousStd;
	cout<<"___Default Constructed Student___"<<anonymousStd<<endl;

	/**
	 * Testing Student::operator>>
	 */
	/*
	cout<<"Testing Student::operator >>"<<endl;
	cin>>anonymousStd;
	cout<<"___Inserted Stduent___"<<anonymousStd<<endl;
	*/

	/**
	 * Testing Student:: regular constructor
	 */
	cout<<"Tesitng Student::regular constructor"<<endl;
	Student std1("Humayun Kabir", "Victoria, BC", "humayun@domain.com", "250-555-7777", "STD00000001", 140.0, 4.0);
	cout<<"___Regularly Constructed Student___"<<std1<<endl;
	persons[i++] = &std1;

	/**
	 * Testing Student::copy constructor
	 */
	cout<<"Testing Student::copy constructor"<<endl;
	Student std2(std1);
	cout<<"___Copy Constructed Student___"<<std2<<endl;
	persons[i++] = &std2;

	/**
	 * Testing Student::move constructor
	 */
	cout<<"Testing Student::move constructor"<<endl;
	Student std3 = Student("Humayun Kabir", "Victoria, BC", "humayun@domain.com", "250-555-7777", "STD00000001", 140.0, 4.0);
	cout<<"___Move Constructed Student__"<<std3<<endl;
	persons[i++] = &std3;

	/**
	 * Testing Student:: copy assignment
	 */
	cout<<"Testing Student::copy assignment"<<endl;
	Student std4;
	std4 = std3;
	cout<<"___Copy Assigned Student___"<<std4<<endl;
	persons[i++] = &std4;

	/**
	 * Testing Student:: move assignment
	 */
	cout<<"Testing Student::move assignment"<<endl;
	Student std5;
	std5 = Student("Humayun Kabir", "Victoria, BC", "humayun@domain.com", "250-555-7777", "STD00000001", 140.0, 4.0);
	cout<<"___Move Assigned Student__"<<std5<<endl;
	persons[i++] = &std5;

	/**
	 * Testing TeachingAssistant:: default constructor
	 */
	cout<<"Testing TeachingAssistant::default constructor"<<endl;
	TeachingAssistant ta;
	cout<<"___Default Constructed TA"<<ta<<endl;


	/**
	 * Testing TeachingAssistant:: operator>>
	 */
	/*
	cout<<"Testing TeachingAssistant::operator>>"<<endl;
	cin>>ta;
	cout<<"___Inserted Teaching Assistant___"<<ta<<endl;
	*/

	/**
	 * Testing TeachingAssistant::regular constructor
	 */
       	cout<<"Testing TeachingAssistant::regualr constructor"<<endl;
	TeachingAssistant ta1("Humayun Kabir", "Victoria, BC", "humayun@domain.com", "250-555-7777", "EMP1000200", "SN2340889", 10000000.0, "STD00000001", 140.0, 4.0);
	cout<<"___Regular Constructed Teaching Assistant___"<<ta1<<endl;
	
	persons[i++] = &ta1;
	/**
	 * Testing TeachingAssistant::copy constructor
	 */
	cout<<"Testing TeachingAssistant::copy constructor"<<endl;
	TeachingAssistant ta2(ta1);
	cout<<"___Copy Constructed Teaching Assiatant__"<<ta2<<endl;
	persons[i++] = &ta2;

	/**
	 * Testing TeachingAssistant::move constructor
	 */
	cout<<"Testing TeachingAssistant::move constructor"<<endl;
	TeachingAssistant ta3 = TeachingAssistant("Humayun Kabir", "Victoria, BC", "humayun@domain.com", "250-555-7777", "EMP1000200", "SN2340889", 10000000.0, "STD00000001", 140.0, 4.0);
	cout<<"___Move Constructed TeachingAssistant__"<<ta3<<endl;
	persons[i++] = &ta3;

	/**
	 * Testing TeachingAssistant::copy assignment
	 */
	cout<<"Testing TeachingAssistant::copy assignment"<<endl;
	TeachingAssistant ta4;
	ta4 = ta3;
	cout<<"___Copy Assigned Teaching Assistant__"<<ta4<<endl;
	persons[i++] = &ta4;

	/**
	 * Testing TeachingAssistant::move assignment
	 */
	cout<<"Testing TeachingAssistant::move assignment"<<endl;
	TeachingAssistant ta5;
	ta5 = TeachingAssistant("Humayun Kabir", "Victoria, BC", "humayun@domain.com", "250-555-7777", "EMP1000200", "SN2340889", 10000000.0, "STD00000001", 140.0, 4.0);
	cout<<"__Move Assigned Teaching Assistant__"<<ta5<<endl;
	persons[i++] = &ta5;

	/**
	 * Testing run-time polymorphism
	 */
	cout<<"Testing run-time polymorphism"<<endl;
	for (int j=0; j<i; j++) {
		cout<<"***********Person["<<j<<"]*********** "<<endl;
		cout<<*persons[j]<<endl;
	}

	return 0;
}
