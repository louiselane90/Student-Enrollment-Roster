#include "student.h"
#include "roster.h"

//Default constructor, sets all fields to default values
Student::Student() {

	this->studentID = "No Student ID";
	this->firstName = "No First Name";
	this->lastName = "No Last Name";
	this->studentEmail = "No Student Email";
	this->studentAge = -1;
	for (int i = 0; i < daysToCompleteCourseArraySize; i++) this->daysToCompleteCourse[i] = -1;
	this->degreeProgram = DegreeProgram::NA;
}

//Full constructor
Student::Student(string studentID, string firstName, string lastName, string studentEmail, int studentAge, int daysToCompleteCourse[], DegreeProgram degreeProgram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->studentEmail = studentEmail;
	this->studentAge = studentAge;
	for (int i = 0; i < daysToCompleteCourseArraySize; i++) this->daysToCompleteCourse[i] = daysToCompleteCourse[i];
	this->degreeProgram = degreeProgram;
}

//Destructor
Student::~Student() {}

//Getters
string Student::getStudentID() { return this->studentID; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getStudentEmail() { return this->studentEmail; }
int Student::getStudentAge() { return this->studentAge; }
const int* Student::getDaysToCompleteCourse() { return this->daysToCompleteCourse; }
DegreeProgram Student::getDegreeProgram() { return this->degreeProgram; }

//Setters
void Student::setStudentID(string studentID) { this->studentID = studentID; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setStudentEmail(string studentEmail) { this->studentEmail = studentEmail; }
void Student::setStudentAge(int studentAge) { this->studentAge = studentAge; }
void Student::setDaysToCompleteCourse(const int daysToCompleteCourse[])
{
	for (int i = 0; i < daysToCompleteCourseArraySize; i++) this->daysToCompleteCourse[i] = daysToCompleteCourse[i];
}

void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }


//Prints a header that names each column
void Student::printHeader()
{
	cout << "ID\t";
	cout << "First Name  ";
	cout << "Last Name\t";
	cout << "Email\t";
	cout << "Age\t";
	cout << "Course 1\t";
	cout << "Course 2\t";
	cout << "Course 3\t";
	cout << "Degree Program\t" << endl;
}

//Prints student info
void Student::print()
{
	cout << this->studentID << '\t';
	cout << this->firstName << '\t';
	cout << this->lastName << '\t';
	cout << this->studentEmail << '\t';
	cout << this->studentAge << '\t';
	cout << this->daysToCompleteCourse[0] << '\t';
	cout << this->daysToCompleteCourse[1] << '\t';
	cout << this->daysToCompleteCourse[2] << '\t';
	cout << degreeProgramStrings[(int)this->degreeProgram];
	cout << endl;
}
