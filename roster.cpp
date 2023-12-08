#include <string>
#include "degree.h"
#include "roster.h"
#include "student.h"


Student** Roster::getStudents()
{
	return Roster::classRosterArray;
}

Roster::Roster()
{}

	void Roster::parse(string studentData)
	{
		DegreeProgram degreeProgram = DegreeProgram::NA;
		if (studentData.back() == 'Y')
			degreeProgram = DegreeProgram::SECURITY;
		else if (studentData.back() == 'K')
			degreeProgram = DegreeProgram::NETWORK;
		else if (studentData.back() == 'E')
			degreeProgram = DegreeProgram::SOFTWARE;

		size_t rhs = studentData.find(",");
			string studentID = studentData.substr(0, rhs);
			size_t lhs = rhs + 1;

		rhs = studentData.find(",", lhs);
			string firstName = studentData.substr(lhs, rhs - lhs);
			lhs = rhs + 1;

		rhs = studentData.find(",", lhs);
			string lastName = studentData.substr(lhs, rhs - lhs);
			lhs = rhs + 1;

		rhs = studentData.find(",", lhs);
			string studentEmail = studentData.substr(lhs, rhs - lhs);
			lhs = rhs + 1;

		rhs = studentData.find(",", lhs);
			int studentAge = stoi(studentData.substr(lhs, rhs - lhs));
			lhs = rhs + 1;

		int days[3];
		for (int i = 0; i < 3; i++)
		{
			lhs = rhs + 1;
			rhs = studentData.find(",", lhs);
			days[i] = stoi(studentData.substr(lhs, rhs - lhs));
		}

		add(studentID, firstName, lastName, studentEmail, studentAge, days[0], days[1], days[2], degreeProgram);

	}

	void Roster::add(string studentID, string firstName, string lastName, string studentEmail, int studentAge, int days1, int days2, int days3, DegreeProgram degreeProgram)
	{
		int daysToCompleteCourseArray[3] = { days1,days2,days3 };
		classRosterArray[++lastRosterIndex] = new Student(studentID, firstName, lastName, studentEmail, studentAge, daysToCompleteCourseArray, degreeProgram);
		cout << "Student added to class roster at row " << lastRosterIndex + 1 << endl;
	}

	void Roster::printAll()
	{
		Student::printHeader();
		for (int i = 0; i <= Roster::lastRosterIndex; i++)
			Roster::classRosterArray[i]->print();
	}

	void Roster::printByDegreeType(DegreeProgram degreeProgram)
	{
		Student::printHeader();
		for (int i = 0; i <= Roster::lastRosterIndex; i++)
			if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram) classRosterArray[i]->print();
	}

	void Roster::printInvalidEmails()
	{
		for (int i = 0; i <= Roster::lastRosterIndex; i++)
		{
			string studentEmail = Roster::getStudents()[i]->getStudentEmail();
			if (studentEmail.find(' ') != string::npos || studentEmail.find('@') == string::npos || studentEmail.find('.') == string::npos)
				cout << studentEmail << " is invalid!" << endl;
		}
	}

	void Roster::printAverageDaysInCourse(string studentID)
	{
		for (int i = 0; i <= Roster::lastRosterIndex; i++)
		{
			if (classRosterArray[i]->getStudentID() == studentID)
			{
				cout << studentID << ":";
				cout << (classRosterArray[i]->getDaysToCompleteCourse()[0] +
					classRosterArray[i]->getDaysToCompleteCourse()[1] +
					classRosterArray[i]->getDaysToCompleteCourse()[2]) / 3.0 << endl;
			}
		}
	}

	void Roster::remove(string studentID)
	{
		bool found = false;
		for (int i = 0; i <= Roster::lastRosterIndex; i++)
		{
			if (classRosterArray[i]->getStudentID() == studentID)
			{
				found = true;
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[numStudents - 1];
				classRosterArray[numStudents - 1] = temp;
				Roster::lastRosterIndex--;
			}
		}
		if (found)
		{
			cout << "Student " << studentID << " removed." << endl;
			printAll();
		}
		else cout << "Student " << studentID << " not found." << endl;
	}

	Roster::~Roster()
	{
		for (int i = 0; i < numStudents; i++)
		{
			cout << "Destructor called" << classRosterArray[i]->getStudentID() << endl;
			classRosterArray[i] = nullptr;
		}
	}
