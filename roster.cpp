#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "roster.h"
#include "student.h"
#include "student.cpp"

using namespace std;

// When Roster class is initialized with empty param, we set default values
Roster::Roster()
{
    this->capacity = 0;
    this->lastIndex = -1;
    this->classRosterArray = nullptr;
}

Roster::Roster(int capacity)
{
    this->capacity = capacity;
    this->lastIndex = -1;
    this->classRosterArray = new Student *[capacity];
}

void Roster::add(string studentInStr)
{
    if (lastIndex >= capacity)
    {
        cerr << "-- Maximum Capacity Reached \n";
        exit(-1);
    }
    lastIndex++;

    this->classRosterArray[lastIndex] = new Student();
    string studentData[9];
    stringstream ss(studentInStr);
    cout << studentInStr << endl;

    int i = 0;
    while (ss.good())
    {
        string token;
        getline(ss, token, ',');
        studentData[i] = token;
        i++;
    }

    classRosterArray[lastIndex]->setID(studentData[0]);
    classRosterArray[lastIndex]->setfName(studentData[1]);
    classRosterArray[lastIndex]->setlName(studentData[2]);
    classRosterArray[lastIndex]->setEmailAddress(studentData[3]);
    classRosterArray[lastIndex]->setAge(stoi(studentData[4]));
    int daysInCourse[Student::daysTilCompletionSize];
    daysInCourse[0] = stoi(studentData[5]);
    daysInCourse[1] = stoi(studentData[6]);
    daysInCourse[2] = stoi(studentData[7]);
    classRosterArray[lastIndex]->setdaysInCourse(daysInCourse);
    classRosterArray[lastIndex]->setDegreeProg(getPrgFromStr(studentData[8]));
    }

void Roster::remove(string studentID)
{
    for (int i = 0; i <= lastIndex; ++i)
    {
        if (studentID == classRosterArray[i]->getID())
        {
                classRosterArray[i] = classRosterArray[lastIndex];
                lastIndex--;
                cout << "Student removed" << endl;
                return;
        }
    }

    cout << "Student With ID: " << studentID << " Not Found" << endl;
}

void Roster::printAverageDaysInCourse(string studentID)
{
    for (int i = 0; i <= lastIndex; ++i)
    {
        if (classRosterArray[i]->getID() == studentID)
        {
            int *remainDays = classRosterArray[i]->getdaysInCourse();
            int sum = 0;
            for (int j = 0; j < 3; j++){
                sum += remainDays[j];
            }

            cout << "Student ID: " << studentID << " has an average days in course of " << sum / 3 << endl;
        }
    }
}

void Roster::printInvalidEmails()
{
    for (int i = 0; i <= lastIndex; i++)
    {
        string email = classRosterArray[i]->getEmailAddress();
        bool valid = false;
        // checking for space                       check for @                             check for .
        if ((email.find(" ") != string::npos) || (email.find("@") == string::npos) || (email.find(".") == string::npos))
        {
            cout << "The student: " << classRosterArray[i]->getfName() << " " << classRosterArray[i]->getlName() << " has invalid Email: " << email << endl;
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
    cout << "Students Enrolled in Degree Program: " << degreeProgramList[degreeProgram] << "are:" << "\n";
    for (int i = 0; i <= lastIndex; ++i)
    {
        if (classRosterArray[i]->getDegreeProg() == degreeProgram)
            classRosterArray[i]->print();
    }
}

void Roster::printAll()
{
    for (int i = 0; i < lastIndex + 1; i++)
    {
        (this->classRosterArray)[i]->print();
    }
}
// deconstructor
Roster::~Roster()
{
    for (int i = 0; i <= lastIndex; i++)
    {
        delete this->classRosterArray[i];
    }
    delete this;
}



