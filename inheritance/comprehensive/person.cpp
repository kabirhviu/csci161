/**
 * @file: person.cpp
 * @author: Humayun Kabir
 */
#include <iostream>
#include <string>
#include "person.h"

using namespace std;

/**
 * Regular Constructor
 */
Person::Person(string name, string address, string email, string phone) : name(name), address(address), email(email), phone(phone) {
	cout<<"Person::regular constructor......"<<endl;
}

/**
 * Copy Constructor
 */
Person::Person(const Person& person): name(person.name), address(person.address), email(person.email), phone(person.phone) {
	cout<<"Person::copy constructor......"<<endl;
}

/**
 * Move Constructor
 */
Person::Person(Person&& person): name(person.name), address(person.address), email(person.email), phone(person.phone) {
	cout<<"Person::move constructor....."<<endl;
}

/**
 * Copy Assignment
 */
Person& Person::operator = (const Person& person) {
	cout<<"Person::copy assignment ....."<<endl;
	name = person.name;
	address = person.address;
	email = person.email;
	phone = person.phone;
	return *this;
}

/**
 * Move Assignment
 */
Person& Person::operator = (Person&& person) {
	cout<<"Person:: move assignment...."<<endl;
	name = person.name;
	address = person.address;
	email = person.email;
	phone = person.phone;
	return *this;
}

/**
 * Destructor
 */
Person::~Person() {
	cout<<"Person::destructor......"<<endl;
}

void Person::setName(string name) {
	this->name = name;
}

void Person::setAddress(string address) {
	this->address = address;
}

void Person::setEmail(string email) {
	this->email = email;
}

void Person::setPhone(string phone) {
	this->phone = phone;
}

string Person::getName() const {
	return name;
}

string Person::getAddress() const {
	return address;
}

string Person::getEmail() const {
	return email;
}

string Person::getPhone() const {
	return phone;
}

string Person::getInfo() const {
	string info;
	info = "\nName: " +  name + "\nAddress: " + address + "\nEmail: "+ email + "\nPhone: " + phone;
	return info;
}

istream& operator >> (istream& in, Person& person) {
	in>>person.name>>person.address>>person.email>>person.phone;
	return in;
}

ostream& operator << (ostream& out, const Person& person) {
	out<<person.getInfo();
	return out;
}
