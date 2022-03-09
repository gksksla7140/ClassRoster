#include <iostream>
#include <iomanip>
#include "student.h"
using namespace std;

Student::Student()
{
    this->studentID = "";
    this->fName = "";
    this->lName = "";
    this->emailAddress = "";
    this->age = 0;
    this->daysInCourse = new int[daysTilCompletionSize];
    for (int i = 0; i < daysTilCompletionSize; i++)
        this->daysInCourse[i] = 0;

}

Student::Student(string ID, string fName, string lName, string emailAddress, int age, int daysInCourse[], DegreeProgram program)
{
    this->studentID = ID;
    this->fName = fName;
    this->lName = lName;
    this->emailAddress = emailAddress;
    this->age = age;
    this->daysInCourse = new int[daysTilCompletionSize];
    for (int i = 0; i < daysTilCompletionSize; i++)
        this->daysInCourse[i] = daysInCourse[i];
    this->degreeProg = program;
}

// getters
string Student::getID()
{
    return studentID;
}

string Student::getfName()
{
    return fName;
}
string Student::getlName()
{
    return lName;
}
string Student::getEmailAddress()
{
    return emailAddress;
}
int Student::getAge()
{
    return age;
}
int *Student::getdaysInCourse()
{
    return daysInCourse;
}
DegreeProgram Student::getDegreeProg()
{
    return degreeProg;
}

void Student::setID(string ID)
{
    studentID = ID;
}

void Student::setfName(string fName)
{
    this->fName = fName;
}

void Student::setlName(string lName)
{
    this->lName = lName;
}

void Student::setEmailAddress(string emailAddress)
{
    this->emailAddress = emailAddress;
}

void Student::setAge(int age)
{
    this->age = age;
}

void Student::setdaysInCourse(int days[])
{
    this->daysInCourse = new int[daysTilCompletionSize];
    for (int i = 0; i < daysTilCompletionSize; i++)
        this->daysInCourse[i] = days[i];
}

void Student::setDegreeProg(DegreeProgram program)
{
    this->degreeProg = program;
}

void Student::print()
{
    cout << left << "Student ID: " << getID() << "\t";
    cout << left << "First Name: " << getfName() << "\t";
    cout << left << "Last Name: " << getlName() << "\t";
    cout << left << "Age: " << getAge() << "\t";
    cout << left << "Days Remaining: " << getdaysInCourse()[0] << ", ";
    cout << left << getdaysInCourse()[1] << ", ";
    cout << left << getdaysInCourse()[2] << "\t";
    cout << left << degreeProgramList[getDegreeProg()] << "\t";
}

Student::~Student()
{
}