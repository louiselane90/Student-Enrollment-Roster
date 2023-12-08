#pragma once
#include "student.h"

class Roster
{
private:
	int lastRosterIndex = -1;
	const static int numStudents = 5;
	Student* classRosterArray[numStudents];

public:
	Roster(); //sets to default values
	

Student** getStudents();

//parses string of text provided in main.cpp that has the student data
void parse(string row);

//adds student to roster
void add(string studentID, string firstName, string lastName, string studentEmail, int studentAge, int daysToCompleteCourse1, int daysToCompleteCourse2, int daysToCompleteCourse3, DegreeProgram degreeProgram);

//displays all students on roster
void printAll();

//displays students with specified degree only
void printByDegreeType(DegreeProgram degreeProgram);

//completes verification on student emails and displays any invalid emails
void printInvalidEmails();

//computes and displays average course length for specific student by student ID
void printAverageDaysInCourse(string studentID);

//removes student from roster by student ID
void remove(string studentID);

~Roster(); //destructor
		
};
