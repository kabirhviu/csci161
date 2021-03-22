#include <iostream>
#include <string>

using namespace std;


class Employee {
	protected:
		string employeeNumber;
		string name;
		string address;
		string email;
		string phone;
		double salary;
	public:
		Employee();
		Employee(string, string, string, string, string, double);
		Employee(const Employee&);
		Employee(Employee&&);
		Employee& operator = (const Employee&);
		Employee& operator = (Employee&&);
		virtual ~Employee();			//Virtual destructor
		string getEmployeeNumber() const;
		string getName() const;
		string getAddress() const;
		string getEmail() const;
		string getPhone() const;
		double getSalary() const;
		virtual double payCheque() const;	//Virtual function
		friend ostream& operator << (ostream&, const Employee&);

};


class RegularEmployee: public Employee {
	public:
		RegularEmployee();
		RegularEmployee(string, string, string, string, string, double);
		RegularEmployee(const RegularEmployee&);
		RegularEmployee(RegularEmployee&&);
		RegularEmployee& operator = (const RegularEmployee&);
		RegularEmployee& operator = (RegularEmployee&&);
		~RegularEmployee();
		double payCheque() const override;	//Overriden furnction
		friend ostream& operator << (ostream&, const RegularEmployee&);
};


class HourlyContractEmployee: public Employee {
	private:
		double hoursWorked;
	public:
		HourlyContractEmployee();
		HourlyContractEmployee(string, string, string, string, string, double, double);
		HourlyContractEmployee(const HourlyContractEmployee&);
		HourlyContractEmployee(HourlyContractEmployee&&);
		HourlyContractEmployee& operator = (const HourlyContractEmployee&);
		HourlyContractEmployee& operator = (HourlyContractEmployee&&);
		~HourlyContractEmployee();
		double payCheque() const override;	//Overriden function
		void setHoursWorked(double hoursWorked);
		double getHoursWorked() const;
		friend ostream& operator << (ostream&, const HourlyContractEmployee&);

};

class OneTimeContractEmployee: public Employee {
	public:
		OneTimeContractEmployee();
		OneTimeContractEmployee(string, string, string, string, string, double);
		OneTimeContractEmployee(const OneTimeContractEmployee&);
		OneTimeContractEmployee(OneTimeContractEmployee&&);
		OneTimeContractEmployee& operator = (const OneTimeContractEmployee&);
		OneTimeContractEmployee& operator = (OneTimeContractEmployee&&);
		~OneTimeContractEmployee();
		//double payCheque() const;		//Inherited function
		friend ostream& operator << (ostream&, const OneTimeContractEmployee&);
};


/*
 * Employee function implementations
 */
Employee::Employee(): employeeNumber("Unkown"), name("Unknown"), address("Unknown"), email("Uknown"), phone("Unknown"), salary(0.0)  {}

Employee::Employee(string employeeNumber, string name, string address, string email, string phone, double salary): 
		 employeeNumber(employeeNumber), name(name), address(address), email(email), phone(phone), salary(salary) {}

Employee::Employee(const Employee& other):
		 employeeNumber(other.employeeNumber), name(other.name), address(other.address), email(other.email), phone(other.phone), salary(other.salary) {}

		
Employee::Employee(Employee&& temp):
		 employeeNumber(temp.employeeNumber), name(temp.name), address(temp.address), email(temp.email), phone(temp.phone), salary(temp.salary) {}


Employee& Employee::operator = (const Employee& other) {
	employeeNumber = other.employeeNumber;
	name = other.name;
	address = other.address;
	email = other. email;
	phone = other.phone;
	salary = other.salary;
	return *this;
}
		
Employee& Employee::operator = (Employee&& temp) {
	employeeNumber = temp.employeeNumber;
	name = temp.name;
	address = temp.address;
	email = temp. email;
	phone = temp.phone;
	salary = temp.salary;
	return *this;	
}
		
Employee::~Employee() {}

		
string Employee::getEmployeeNumber() const {
	return employeeNumber;
}

string Employee::getName() const {
	return name;
}

string Employee::getAddress() const {
	return address;
}
		
string Employee::getEmail() const {
	return email;
}
		
string Employee::getPhone() const {
	return phone;
}
		
double Employee::getSalary() const {
	return salary;
}
	
double Employee::payCheque() const {
	return salary;
}
		
ostream& operator << (ostream& out, const Employee& employee) {
	out<<"Employee Number: "<<employee.employeeNumber<<", Name: "<<employee.name<<
		", Adress: "<<employee.address<<", Email: "<<employee.email<<
		", Phone: "<<employee.phone<<", Salary: "<<employee.salary<<
		", Pay Cheque: "<<employee.payCheque()<<endl; 
	return out;
}



/*
 * RegularEmployee function implementations
 */
RegularEmployee::RegularEmployee(): Employee() {}
		
RegularEmployee::RegularEmployee(string employeeNumber, string name, string address, string email, string phone, double salary):
	Employee(employeeNumber, name, address, email, phone, salary) {}
		
RegularEmployee::RegularEmployee(const RegularEmployee& other): Employee(other) {}
		
RegularEmployee::RegularEmployee(RegularEmployee&& temp): Employee(temp) {}
		
RegularEmployee& RegularEmployee::operator = (const RegularEmployee& other) {
	Employee::operator = (other);
	return *this;
}
		
RegularEmployee& RegularEmployee::operator = (RegularEmployee&& temp) {
	Employee::operator = (temp);
	return *this;
}

RegularEmployee::~RegularEmployee() {}

double RegularEmployee::payCheque() const {
	return salary/26.0;
}
	
ostream& operator << (ostream& out, const RegularEmployee& employee) {
	out<<"Regular Employee Number: "<<employee.employeeNumber<<", Name: "<<
		employee.name<<", Adress: "<<employee.address<<", Email: "<<employee.email<<
		", Phone: "<<employee.phone<<", Annual Salary: "<<employee.salary<<
		", Pay Cheque: "<<employee.payCheque()<<endl; 
	
	return out;
}


/*
 * HourlyContractEmployee function implementations
 */
	
HourlyContractEmployee::HourlyContractEmployee(): Employee(), hoursWorked(0.0) {}
		
HourlyContractEmployee::HourlyContractEmployee(string employeeNumber, string name, string address, string email, string phone, double salary, double hoursWorked):
		Employee(employeeNumber, name, address, email, phone, salary), hoursWorked(hoursWorked) {}
		
HourlyContractEmployee::HourlyContractEmployee(const HourlyContractEmployee& other):
		Employee(other), hoursWorked(other.hoursWorked) {}
		
HourlyContractEmployee::HourlyContractEmployee(HourlyContractEmployee&& temp):
		Employee(temp), hoursWorked(temp.hoursWorked) {}
		
HourlyContractEmployee& HourlyContractEmployee::operator = (const HourlyContractEmployee& other) {
		Employee::operator = (other);
		hoursWorked = other.hoursWorked;
		return *this;
}
		
HourlyContractEmployee& HourlyContractEmployee::operator = (HourlyContractEmployee&& temp) {
		Employee::operator = (temp);
		hoursWorked = temp.hoursWorked;
		return *this;
}
		
HourlyContractEmployee::~HourlyContractEmployee() {}
		
		
double HourlyContractEmployee::payCheque() const {
	return salary*hoursWorked;
}
	
void HourlyContractEmployee::setHoursWorked(double hoursWorked) {
	this->hoursWorked = hoursWorked;
}
		
double HourlyContractEmployee::getHoursWorked() const {
	return hoursWorked;
}
	
ostream& operator << (ostream& out, const HourlyContractEmployee& employee) {
	
	out<<"Hourly Contract Employee Number: "<<employee.employeeNumber<<
		", Name: "<<employee.name<<", Adress: "<<employee.address<<", Email: "<<employee.email<<
		", Phone: "<<employee.phone<<", Hourly Salary: "<<employee.salary<<
		", Hours Worked: "<<employee.hoursWorked<<", Pay Cheque: "<<employee.payCheque()<<endl; 
	
	return out;
}

		

/*
 * OneTimeContractEmployee function implementations
 */

OneTimeContractEmployee::OneTimeContractEmployee(): Employee() {}
		
OneTimeContractEmployee::OneTimeContractEmployee(string employeeNumber, string name, string address, string email, string phone, double salary):
	Employee(employeeNumber, name, address, email, phone, salary) {}
		
OneTimeContractEmployee::OneTimeContractEmployee(const OneTimeContractEmployee& other) : Employee(other) {}
		
OneTimeContractEmployee::OneTimeContractEmployee(OneTimeContractEmployee&& temp) : Employee(temp) {} 
		
OneTimeContractEmployee& OneTimeContractEmployee::operator = (const OneTimeContractEmployee& other) {
	Employee::operator = (other);
	return *this;
}
		
OneTimeContractEmployee& OneTimeContractEmployee::operator = (OneTimeContractEmployee&& temp) {
	Employee::operator = (temp);
	return *this;
}
		
OneTimeContractEmployee::~OneTimeContractEmployee() {}
			

//double OneTimeContractEmployee::payCheque() const {
//	return salary;
//}

ostream& operator << (ostream& out, const OneTimeContractEmployee& employee) {
	out<<"One Time Employee Number: "<<employee.employeeNumber<<", Name: "<<
		employee.name<<", Adress: "<<employee.address<<", Email: "<<employee.email<<
		", Phone: "<<employee.phone<<", Onetime Salary: "<<employee.salary<<
		", Pay Cheque: "<<employee.payCheque()<<endl; 
	
	return out;
}

/*
 * Function to return Employee rvalue
 */
Employee createEmployee(string employeeNumber, string name, string address, string email, string phone, double salary) {
	return Employee(employeeNumber, name, address, email, phone, salary);
}

/*
 * Function to return RegularEmployee rvalue
 */
RegularEmployee createRegularEmployee(string employeeNumber, string name, string address, string email, string phone, double salary) {
	return RegularEmployee(employeeNumber, name, address, email, phone, salary);
}

/*
 * Function to return HourlyContractEmployee rvalue
 */
HourlyContractEmployee createHourlyContractEmployee(string employeeNumber, string name, string address, string email, string phone, double salary, double hoursWorked) {
	return HourlyContractEmployee(employeeNumber, name, address, email, phone, salary, hoursWorked);
}

/*
 * Function to return OneTimeEmployee rvalue
 */
OneTimeContractEmployee createOneTimeContractEmployee( string employeeNumber, string name, string address, string email, string phone, double salary){
	return OneTimeContractEmployee(employeeNumber, name, address, email, phone, salary);
}


int main() {

	cout<<"Objects from base and subclasses with individual obejct identifier no runtime polymorphism."<<endl;
	cout<<"***********************************************************************************************"<<endl;
	
	
	Employee employee0;
	cout<<employee0<<endl;
	Employee employee1("EMP001", "Humayun", "Victoria", "humayun@viu.ca", "250-727-0980", 200000.0);
	cout<<employee1<<endl;
	Employee employee2(employee1);
	cout<<employee2<<endl;
	Employee employee3 = createEmployee("EMP001", "Humayun", "Victoria", "humayun@viu.ca", "250-727-0980", 200000.0);
	cout<<employee3<<endl;
	Employee employee4;
	employee4 = createEmployee("EMP001", "Humayun", "Victoria", "humayun@viu.ca", "250-727-0980", 200000.0);
	cout<<employee4<<endl;


	RegularEmployee regEmp0;
	cout<<regEmp0<<endl;
	RegularEmployee regEmp1("REMP001", "Humayun", "Victoria", "humayun@viu.ca", "250-727-0980", 200000.0);
	cout<<regEmp1<<endl;
	RegularEmployee regEmp2(regEmp1);
	cout<<regEmp2<<endl;
	RegularEmployee regEmp3 = createRegularEmployee("REMP001", "Humayun", "Victoria", "humayun@viu.ca", "250-727-0980", 200000.0);
	cout<<regEmp3<<endl;
	RegularEmployee regEmp4;
	regEmp4 = createRegularEmployee("REMP001", "Humayun", "Victoria", "humayun@viu.ca", "250-727-0980", 200000.0);
	cout<<regEmp4<<endl;



	HourlyContractEmployee hourEmp0;
	cout<<hourEmp0<<endl;
	HourlyContractEmployee hourEmp1("HEMP001", "Humayun ", "Victoria ", "humayun@viu.ca ", "250-727-0980 ", 200.0, 40.0);
	cout<<hourEmp1<<endl;
	HourlyContractEmployee hourEmp2(hourEmp1);
	cout<<hourEmp2<<endl;
	HourlyContractEmployee hourEmp3 = createHourlyContractEmployee("HEMP001", "Humayun", "Victoria", "humayun@viu.ca", "250-727-0980", 200.0, 40.0);
	cout<<hourEmp3<<endl;
	HourlyContractEmployee hourEmp4;
	hourEmp4 = createHourlyContractEmployee("HEMP001", "Humayun", "Victoria", "humayun@viu.ca", "250-727-0980", 200.0, 40.0);
	cout<<hourEmp4<<endl;


	OneTimeContractEmployee onetimeEmp0;
	cout<<onetimeEmp0<<endl;
	OneTimeContractEmployee onetimeEmp1("TEMP001", "Humayun ", "Victoria ", "humayun@viu.ca ", "250-727-0980 ", 30000.0);
	cout<<onetimeEmp1<<endl;
	OneTimeContractEmployee onetimeEmp2(onetimeEmp1);
	cout<<onetimeEmp2<<endl;
	OneTimeContractEmployee onetimeEmp3 = createOneTimeContractEmployee("TEMP001", "Humayun", "Victoria", "humayun@viu.ca", "250-727-0980", 30000.0);
	cout<<onetimeEmp3<<endl;
	OneTimeContractEmployee onetimeEmp4;
	onetimeEmp4 = createOneTimeContractEmployee("TEMP001", "Humayun", "Victoria", "humayun@viu.ca", "250-727-0980", 30000.0);
	cout<<onetimeEmp4<<endl;

	cout<<endl;
	cout<<"Objects from sub-classes with base class references (pointers) to achieve runtime polymorphism"<<endl;
	cout<<"***********************************************************************************************"<<endl;
	Employee* employees[] = {
	new RegularEmployee ("REMP001", "Humayun Regular 1", "Victoria", "humayun@viu.ca", "250-727-0980", 200000.0),
	new RegularEmployee ("REMP002", "Humayun Regular 2", "Victoria", "humayun@viu.ca", "250-727-0980", 400000.0),
	new RegularEmployee ("REMP003", "Humayun Regular 3", "Victoria", "humayun@viu.ca", "250-727-0980", 300000.0),
	new HourlyContractEmployee ("HEMP001", "Humayun Hourly 1", "Victoria", "humayun@viu.ca", "250-727-0980", 200.0, 40.0),
	new HourlyContractEmployee ("HEMP002", "Humayun Hourly 2", "Victoria", "humayun@viu.ca", "250-727-0980", 300.0, 20.0),
	new RegularEmployee ("REMP004", "Humayun Regular 4", "Victoria", "humayun@viu.ca", "250-727-0980", 100000.0),
	new RegularEmployee ("REMP005", "Humayun Regular 5", "Victoria", "humayun@viu.ca", "250-727-0980", 500000.0),
	new OneTimeContractEmployee ("TEMP001", "Humayun Onetime 1", "Victoria", "humayun@viu.ca", "250-727-0980", 20000.0),
	new OneTimeContractEmployee ("REMP001", "Humayun Onetime 2", "Victoria", "humayun@viu.ca", "250-727-0980", 80000.0)
	};


	for(int i=0; i<9; i++) {
		cout<<*employees[i]<<endl;
	}	

	return 0;
}

