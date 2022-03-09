#pragma once
#ifndef ROSTER_H
#define ROSTER_H

#include <list>
#include <iostream>
#include <string>
#include "student.h"
using namespace std;

class Roster
{
public:
    int lastIndex;
    int capacity;
    Student **classRosterArray;
    Roster();
    Roster(int capacity);
    // sets the instance variables from part D1 and updates the roster.
    void add(string studentInStr);
    // removes students from the roster by student ID.If the student ID does not exist, the function prints an error message indicating that the student was not found.void remove(string studentID);
    void remove(string studentID);
    // A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security
    void printAll(); 
    // correctly prints a student’s average number of days in the three courses. The student is identified by the studentID parameter.
    void printAverageDaysInCourse(string studentID); 
    // verifies student email addresses and displays all invalid email addresses to the user.
    void printInvalidEmails();
    // prints out student information for a degree program specified by an enumerated type.
    void printByDegreeProgram(DegreeProgram degreeProgram); 

    ~Roster();
};

#endif