#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include "degree.h"
using namespace std;

class Student
{

protected:
    string studentID;
    string fName;
    string lName;
    string emailAddress;
    int age;
    int* daysInCourse;
    DegreeProgram degreeProg;

public:
    const static int daysTilCompletionSize = 3;
    Student();
    Student(string ID, string fName, string lName, string emailAddress, int age, int remainingDays[], DegreeProgram program);

    // accessor
    string getID();
    string getfName();
    string getlName();
    string getEmailAddress();
    int getAge();
    int* getdaysInCourse();
    DegreeProgram getDegreeProg();

    // mutator
    void setID(string ID);
    void setfName(string firstName);
    void setlName(string lastName);
    void setEmailAddress(string emailAddress);
    void setAge(int age);
    void setdaysInCourse(int days[]);
    void setDegreeProg(DegreeProgram d);
    void print();

    // deconstructor
    ~Student();
};
#endif