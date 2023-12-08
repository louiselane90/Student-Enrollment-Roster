#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"

using std::string;
using std::cout;
using std::endl;
using std::left;
using std::setw;

class Student
{
public:
	const static int daysToCompleteCourseArraySize = 3; 

private:
	string studentID;
	string firstName;
	string lastName;
	string studentEmail;
	int studentAge;
	int daysToCompleteCourse[daysToCompleteCourseArraySize];
	DegreeProgram degreeProgram;

public:
	Student(); //sets to default values

	//Full constructor
	Student(string studentID, string firstName, string lastName, string studentEmail, int studentAge, int daysToCompleteCourse[], DegreeProgram degreeProgram);

	//Destructor
	~Student();

	//getters
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getStudentEmail();
	int getStudentAge();
	const int* getDaysToCompleteCourse();
	DegreeProgram getDegreeProgram();

	//setters
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setStudentEmail(string studentEmail);
	void setStudentAge(int studentAge);
	void setDaysToCompleteCourse(const int daysToCompleteCourse[]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	//displays header that names each column of student information
	static void printHeader();

	//prints student information
	void print();
};
