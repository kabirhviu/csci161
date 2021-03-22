#include <iostream>


using namespace std;

const int DEFAULT_CAPACITY = 10; 

class GpaCalculator {
	private:
		int _capacity;
		int _courses;
		double* grades;
	public:
		GpaCalculator();						//Default constructor
		GpaCalculator(int courses);					//Regular constructor
		GpaCalculator(const GpaCalculator& other);			//Copy constructor
		GpaCalculator(GpaCalculator&& temp);				//Move constructor
		GpaCalculator& operator = (const GpaCalculator& other);		//Copy assignment
		GpaCalculator& operator = (GpaCalculator&& temp);		//Move assignment
		~GpaCalculator();						//Destructor
		int capacity();
		int courses();
		void addGrade(double grade);
		void showGrades();
		double gpa();	
};

/*
 * Default constructor
 */
GpaCalculator::GpaCalculator(): _capacity(DEFAULT_CAPACITY), _courses(0), grades(new double[_capacity]) {}

/*
 * Regular constructor
 */
GpaCalculator::GpaCalculator(int capacity): _capacity(capacity), _courses(0), grades(new double[_capacity]) {}

/*
 * Copy constructor
 */
GpaCalculator::GpaCalculator(const GpaCalculator& other): _capacity(other._capacity), _courses(other._courses), grades(new double[_capacity]) {
	for(int i=0; i<_courses; i++) {
		grades[i] = other.grades[i];
	}
}

/*
 * Move constructor
 */
GpaCalculator::GpaCalculator(GpaCalculator&& temp): _capacity(temp._capacity), _courses(temp._courses), grades(temp.grades) {
	temp.grades = NULL;
}

/*
 * Copy assignment
 */
GpaCalculator& GpaCalculator::operator = (const GpaCalculator& other) {
	_capacity = other._capacity;
	_courses = other._courses;
	delete [] grades;
	grades = new double[_capacity];
	for( int i=0; i<_courses; i++) {
		grades[i] = other.grades[i];
	}
	return *this;
}

/*
 * Move assignment
 */
GpaCalculator& GpaCalculator::operator = (GpaCalculator&& temp) {
	_capacity = temp._capacity;
	_courses = temp._courses;
	delete [] grades;
	grades = temp.grades;
	temp.grades = NULL;
	return *this;
}

GpaCalculator::~GpaCalculator() {
	delete [] grades;
	cout<<"GpaCalculator dustructor ......"<<endl;
}

int GpaCalculator::capacity() {
	return _capacity;
}

int GpaCalculator::courses() {
       return _courses;
}       

void GpaCalculator::addGrade(double grade) {
	if(_courses < _capacity) {
		grades[_courses++] = grade;
	}
	else {
		cout<<"Error! can't add more grade, you have "<<_courses<<" (maximum) grades added already."<<endl;
	}
}

void GpaCalculator::showGrades() {
	for(int i=0; i<_courses; i++) {
		cout<<grades[i]<<" ";
	}
	cout<<endl;
}

double GpaCalculator::gpa() {
	double gpa = 0.0;
	
	if(_courses == 0) {
		return gpa;
	}

	for(int i=0; i<_courses; i++) {
		gpa += grades[i];
	}
	
	return gpa/_courses;
}


GpaCalculator createGpaCalculator(double* grades, int courses) {
	GpaCalculator temp(courses);
	for(int i=0; i<courses; i++) {
		temp.addGrade(grades[i]);
	}
	return temp;
}



int main() {
	
	GpaCalculator cal1;						//Calling default constructor	
	cout<<"cal1.capacity(): "<<cal1.capacity()<<endl;
	cout<<"cal1.courses(): "<<cal1.courses()<<endl;
	cout<<"cal1.gpa(): "<<cal1.gpa()<<endl;
	/*
	 * Adding grades into default constructed GpaCalculator
	 */
	double grade = 1.1;
	for(int i=0; i<cal1.capacity(); i++) {
		cal1.addGrade(grade);
		grade +=0.5;
	}
	cal1.addGrade(grade);

	cout<<"cal1.courses() after adding "<< cal1.capacity() << " course grades: "<<cal1.courses()<<endl;
	cout<<"cal1.gardes: ";
	cal1.showGrades();
	cout<<"cal1.gpa(): "<<cal1.gpa()<<endl;



	int capacity = 12;
	GpaCalculator cal2(capacity);					//Calling regular constructor	
	cout<<"cal2.capacity(): "<<cal2.capacity()<<endl;
	cout<<"cal2.courses(): "<<cal2.courses()<<endl;
	/*
	 * Adding grades into regular constructed GpaCalculator
	 */
	grade = 2.1;
	for(int i=0; i<cal2.capacity(); i++) {
		cal2.addGrade(grade);
		grade +=0.25;
	}
	cal2.addGrade(grade);
	cout<<"cal2.courses() after adding "<< cal2.capacity() << " course grades: "<<cal2.courses()<<endl;
	cout<<"cal2.gardes: ";
	cal2.showGrades();
	cout<<"cal2.gpa(): "<<cal2.gpa()<<endl;




	GpaCalculator cal3 = cal1; 					//Calling copy constructor;	
	cout<<"cal3.capacity() "<<cal3.capacity()<<endl; 
	cout<<"cal3.courses(): "<<cal3.courses()<<endl;
	cout<<"cal3.gardes: ";
	cal3.showGrades();
	cout<<"cal3.gpa(): "<<cal3.gpa()<<endl;



	int courses = 9;
	double grades[courses] = {1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9};
	GpaCalculator cal4 = createGpaCalculator(grades, courses);  	//Calling move constructor
	cout<<"cal4.capacity(): "<<cal4.capacity()<<endl;
	cout<<"cal4.courses(): "<<cal4.courses()<<endl;
	cout<<"cal4.gardes: ";
	cal4.showGrades();
	cout<<"cal4.gpa(): "<<cal4.gpa()<<endl;

	GpaCalculator cal5;						//Calling dafault constructor	
	cout<<"cal5.capacity(): "<<cal5.capacity()<<endl;
	cout<<"cal5.courses(): "<<cal5.courses()<<endl;

	cal5 = cal1; 							//Calling copy assignment

	cout<<"cal5.capacity(): "<<cal5.capacity()<<endl;
	cout<<"cal5.courses(): "<<cal5.courses()<<endl;
	cout<<"cal5.gardes: ";
	cal5.showGrades();
	cout<<"cal5.gpa(): "<<cal5.gpa()<<endl;

	GpaCalculator cal6;						//Calling dafault constructor	
	cout<<"cal6.capacity(): "<<cal6.capacity()<<endl;
	cout<<"cal6.courses(): "<<cal6.courses()<<endl;

	cal6 = createGpaCalculator(grades, courses); 			//Calling move assignment

	cout<<"cal6.capacity(): "<<cal6.capacity()<<endl;
	cout<<"cal6.courses(): "<<cal6.courses()<<endl;
	cout<<"cal6.gardes: ";
	cal6.showGrades();
	cout<<"cal6.gpa(): "<<cal6.gpa()<<endl;
	
	return 0;
}
