#pragma once
#include <iostream>
#include "roster.h"

int main()
{

    //My information
    cout << "*************************************************" << endl;
    cout << "Course: Scripting & Programming Applications - C867" << endl;
    cout << "Programming Language: C++" << endl;
    cout << "Student ID: 010055912" << endl;
    cout << "Student Name: Wendy Valbracht" << endl;
    cout << "*************************************************" << endl;
    
    //student data
    const string studentData[] =

    {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", 
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
        "A5,Wendy,Valbracht,wvalbra@wgu.edu,32,5,12,47,SOFTWARE"
    };

    //number of students on roster
    const int numStudents = 5; 

    //creates instance of roster class
    Roster roster;

    for (int i = 0; i < numStudents; i++) roster.parse(studentData[i]); //parses the string above

    cout << "Displaying all students:" << endl;
    roster.printAll(); //displays all students on the roster

    for (int i = 0; i < 3; i++) //loops through each degree program option and displays the student list for each degree program
    {
        cout << "Displaying by degree program:" << degreeProgramStrings[i] << endl;
        roster.printByDegreeType((DegreeProgram)i);
    }


    //Validates each email and displays those that do not meet the specified parameters
    cout << "Displaying students with invalid email addresses:" << endl;
    roster.printInvalidEmails();


    //Calculates and displays average days to complete each of the three courses, by student
    cout << "Displaying average days to complete each course:" << endl;
    for (int i = 0; i < numStudents; i++)
    {
        roster.printAverageDaysInCourse(roster.getStudents()[i]->getStudentID());
    }


    //Removes student A3 from the roster and prints the new roster without that student
    cout << "Removing student A3:" << endl;
    roster.remove("A3");


    //Attempts to remove student A3 a second time, producing a 'not found' message
    cout << "Removing student A3:" << endl;
    roster.remove("A3");


    //Implements destructor to release memory
    cout << "Complete. Destructors will automatically be called on exit." << endl;
    return 0;
}
