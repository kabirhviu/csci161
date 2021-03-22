/**
 * @file: person.h
 * @author: Humayun Kabir
 */

#ifndef __PERSON_HEADER__
#define __PERSON_HEADER__

#include <string>
#include <istream>
#include <ostream>

using namespace std;

class Person {
	private:
		string name;
		string address;
		string email;
		string phone;
	public:
		Person(string name = string(), string address = string(), string email = string(), string phone = string()); //Regular constructor with default parameter values
		Person(const Person& person); //Copy constructor
		Person(Person&& person); //Move constructor
		Person& operator = (const Person& person); //Copy assignment
		Person& operator = (Person&& person); //Move assignment
		virtual ~Person(); //Destructor
		void setName(string name);
		void setAddress(string address);
		void setEmail(string email);
		void setPhone(string phone);
		string getName() const;
		string getAddress() const;
		string getEmail() const;
		string getPhone() const;
		virtual string getInfo() const;
		friend istream& operator >> (istream& in, Person& person);
		friend ostream& operator << (ostream& out, const Person& person);
};
#endif

